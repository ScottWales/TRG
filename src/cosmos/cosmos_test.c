/** 
 * @file cosmos_test.c
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

#include "cosmos.h"

#include "cmockery_extra.h"

#include "cosmos.c"

void test_cosmos_init(void ** status)
{
  struct Cosmos * cosmos = CosmosCreate(0.01);
  CosmosDestroy(cosmos);
}

void cosmos_setup(void ** state)
{ 
  struct Cosmos * cosmos = CosmosCreate(0.01);
  *state = cosmos;
}

void cosmos_teardown(void ** state)
{
  struct Cosmos * cosmos = *state;
  CosmosDestroy(cosmos);
}

void test_cosmos_set_scale(void ** state)
{
  struct Cosmos * cosmos = *state;

  double neweta = 10;
  CosmosSetTime(cosmos,neweta);
  assert_float_equal(cosmos->a,eta2a(neweta),1e-6,1e-6);
}

void test_cosmos_omega(void ** state)
{
  struct Cosmos * cosmos = *state;
  double a = cosmos->a;

  // Values for eds
  double omega_00 = CosmosOmega(cosmos,0,0);
  assert_float_equal(omega_00,1.,1e-6,1e-6);
  double omega_01 = CosmosOmega(cosmos,0,1);
  assert_float_equal(omega_01,-1.,1e-6,1e-6);
  double omega_10 = CosmosOmega(cosmos,1,0);
  assert_float_equal(omega_10,-3./2.,1e-6,1e-6);
  double omega_11 = CosmosOmega(cosmos,1,1);
  assert_float_equal(omega_11,2.,1e-6,1e-6);
}

int main(int argc, char ** argv)
{
  struct UnitTest tests[] = {
    unit_test(test_cosmos_init),
    unit_test_setup_teardown(test_cosmos_omega,
			     cosmos_setup,
			     cosmos_teardown),
    unit_test_setup_teardown(test_cosmos_set_scale,
			     cosmos_setup,
			     cosmos_teardown),
  };
  return run_tests(tests);
}
