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

struct Solver {
  struct Cosmos * cosmos;
};

struct Solver * SolverCreate(double a0)
{
  struct Solver * this = calloc(1,sizeof(*this));
  assert(this);

  this->cosmos = CosmosCreate(a0);

  return this;
}

void SolverDestroy(struct Solver * this)
{
  CosmosDestroy(this->cosmos);

  free(this);
}

void SolverStep(struct Solver * this, double newa)
{

}

void SolverDump(struct Solver * solver)
{

}