/** 
 * @file power_test.c
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

#include "power.h"

#include "cmockery_extra.h"

#include "power.c"

double CosmosOmega(struct Cosmos * cosmos, int a, int b)
{
  check_expected(a);
  check_expected(b);
  return (double)mock();
}

void test_power_init(void ** status)
{
  struct Power * power = PowerCreate(10,1);
  PowerDestroy(power);
}

void power_setup(void ** state)
{ 
  struct Power * power = PowerCreate(10,1);
  *state = power;
}

void power_teardown(void ** state)
{
  struct Power * power = *state;
  PowerDestroy(power);
}

void test_power_derivative(void ** state)
{
  struct Power * power = *state;
  struct Solver solver;
  solver.cosmos = NULL;
  solver.power = power;
  
  expect_value(CosmosOmega,a,0);
  expect_value(CosmosOmega,a,0);
  expect_value(CosmosOmega,a,1);
  expect_value(CosmosOmega,a,1);
  expect_value(CosmosOmega,b,0);
  expect_value(CosmosOmega,b,1);
  expect_value(CosmosOmega,b,0);
  expect_value(CosmosOmega,b,1);

  PowerDerivative(&solver);
}

int main(int argc, char ** argv)
{
  struct UnitTest tests[] = {
    unit_test(test_power_init),
    unit_test_setup_teardown(test_power_derivative,
			     power_setup,
			     power_teardown),
  };
  return run_tests(tests);
}
