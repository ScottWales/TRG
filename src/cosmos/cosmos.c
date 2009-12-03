/** 
 * @file cosmos.c
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

#include <assert.h>
#include <stdlib.h>
#include <math.h>

const double M = 1; // Reduced planck mass sqrt(8*pi*G)
const double ain = 1e-6; // For calculating eta

struct Cosmos {
  double a;
};

static double hubble_a(double a){
  return M/sqrt(3.);
}

static double dhubble_da(double a){
  return 0;
}

static double eta2a(double eta)
{
  return ain*exp(eta);
}

static double a2eta(double a)
{
  return log(a/ain);
}

static double deta_da(double a)
{
  return 1./a;
}

static double da_deta(double a)
{
  return a;
}

static double dhubble_deta(double a)
{
  return da_deta(a)*dhubble_da(a);
}

struct Cosmos * CosmosCreate(double a0)
{
  struct Cosmos * this = calloc(1,sizeof(*this));
  assert(this);

  this->a = a0;

  return this;
}

void CosmosDestroy(struct Cosmos * this)
{
  free(this);
}

void CosmosSetTime(struct Cosmos * this,
		   double eta)
{

}

double CosmosOmega(struct Cosmos * this,
		   int a,
		   int b)
{
  if (a == 0){
    if (b == 0){
      return 1.;
    } else if (b == 1){
      return -1.;
    }
  } else if (a == 1) {
    if (b == 0){
      return -3./2.;
    } else if (b == 1){
      return 2.+dhubble_deta(a)/hubble_a(a);
    }
  }
  return NAN;
}
