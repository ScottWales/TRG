/** 
 * @file solver_test.c
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

#include "cmockery_extra.h"

#include "solver.c"

struct Cosmos * CosmosCreate(double a,size_t fluids)
{
  return malloc(1);
}

void CosmosDestroy(struct Cosmos * c)
{
  free(c);
}

struct Power * PowerCreate(size_t size, size_t fluids)
{
  return malloc(1);
}

void PowerDestroy(struct Power * power)
{
  free(power);
}

void PowerDerivative(struct Solver * solver)
{

}

void PowerStep(struct Power * this,
	       double deta)
{

}

void CosmosSetTime(struct Cosmos * this, 
		    double eta)
{

}

void PowerDump(struct Power * this)
{

}

void CosmosDump(struct Cosmos * this)
{

}

void test_solver_init(void ** status)
{
  struct Solver * solver = SolverCreate(0.1,10,1);
  SolverDestroy(solver);
}

void solver_setup(void ** state)
{ 
  struct Solver * solver = SolverCreate(0.1,10,1);
  *state = solver;
}

void solver_teardown(void ** state)
{
  struct Solver * solver = *state;
  SolverDestroy(solver);
}

int main(int argc, char ** argv)
{
  struct UnitTest tests[] = {
    unit_test(test_solver_init),
  };
  return run_tests(tests);
}
