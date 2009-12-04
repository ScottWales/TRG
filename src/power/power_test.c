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
  double ret = (double)mock();

  printf("CosmosOmega(%p,%d,%d) : %e\n",cosmos,a,b,ret);

  return ret;
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

  power->comp = 1;
  expect_value(CosmosOmega,a,0);
  expect_value(CosmosOmega,b,0);
  will_return(CosmosOmega,1);
  expect_value(CosmosOmega,a,0);
  expect_value(CosmosOmega,b,0);
  will_return(CosmosOmega,1);
  for (size_t ki=0;ki<power->size;ki++){
    power->Pk[ki] = ki;
  }
  PowerDerivative(&solver);

  assert_float_equal(power->dPk_deta[1],
		     -2*power->Pk[1],
		     1e-6,1e-6);
  
  
  power->comp = 2;
  for (unsigned int a=0;a<2;a++){
    for (unsigned int b=0;b<2;b++){
      for (unsigned int c=0;c<2;c++){
	expect_value(CosmosOmega,a,a);
	expect_value(CosmosOmega,b,c);
	if (a == 0 && c == 0){
	  will_return(CosmosOmega,1);
	} else {
	  will_return(CosmosOmega,0);
	}

	expect_value(CosmosOmega,a,b);
	expect_value(CosmosOmega,b,c);
	if (b == 0 && c == 0){
	  will_return(CosmosOmega,1);
	} else {
	  will_return(CosmosOmega,0);
	}
      }
      for (size_t ki=0;ki<power->size;ki++){
	power->Pk[(a*2+b)*10+ki] = 1;
      }
    }
  }	

  PowerDerivative(&solver);

  assert_float_equal(power->dPk_deta[(0*2+0)*10+1],
		     -2*power->Pk[(0*2+0)*10+1],
		     1e-6,1e-6);
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
