/** 
 * @file solver.h
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


#ifndef solver_h
#define solver_h 1

#include <stddef.h>

struct Cosmos;
struct Power;

struct Solver {
  struct Cosmos * cosmos;
  struct Power * power;
};

struct Solver * SolverCreate(double a, size_t size, size_t fluids);
void SolverDestroy(struct Solver * this);

void SolverStep(struct Solver * this, double newa);

void SolverDump(struct Solver * solver);

#endif // solver_h
