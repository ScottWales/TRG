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
  
}

int main(int argc, char ** argv)
{
  struct UnitTest tests[] = {
    unit_test(test_cosmos_init),
    unit_test_setup_teardown(test_cosmos_set_scale,
			     cosmos_setup,
			     cosmos_teardown),
  };
  return run_tests(tests);
}
