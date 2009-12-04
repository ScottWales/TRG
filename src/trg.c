/** 
 * @file trg.c
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

#include <math.h>
#include <stddef.h>

#include "solver/solver.h"

int main(int argc, char ** argv)
{
  double a = 0.01;
  size_t nsteps = 1;

  struct Solver * solver = SolverCreate(a,10,1);
  SolverDump(solver);
  
  double logastep = (1-log(a))/(double)nsteps;
  for (double loga = log(a); loga <= 1; loga += logastep){
    double newa = exp(loga);
    SolverStep(solver,newa);
    SolverDump(solver);
  }
  double newa = 1.;
  SolverStep(solver,newa);
  SolverDump(solver);

  SolverDestroy(solver);

  return 0;
}

