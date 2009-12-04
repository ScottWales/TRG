/** 
 * @file solver.c
 * @brief 
 *
 * Copyright (C) 2009 Scott Wales
 *
 * @author Scott Wales <scottwales@coater.physics.usyd.edu.au>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include "solver.h"

#include <assert.h>
#include <stdlib.h>
#include <math.h>

#include "cosmos/cosmos.h"
#include "power/power.h"

struct Solver * SolverCreate(double a0, size_t size, size_t fluids)
{
  struct Solver * this = calloc(1,sizeof(*this));
  assert(this);

  this->cosmos = CosmosCreate(a0,fluids);
  this->power = PowerCreate(size,fluids);

  return this;
}

void SolverDestroy(struct Solver * this)
{
  CosmosDestroy(this->cosmos);
  PowerDestroy(this->power);

  free(this);
}

void SolverStep(struct Solver * this, double newa)
{
  // Calculate the derivatives
  PowerDerivative(this);

  // Euler integration
  double current_time = 0;
  double new_time = 1;
  double time_step = new_time - current_time;
  PowerStep(this->power,time_step);
  
  // Set Omega to the new time
  CosmosSetTime(this->cosmos,new_time);
}

void SolverDump(struct Solver * solver)
{
  CosmosDump(solver->cosmos);
  PowerDump(solver->power);
}
