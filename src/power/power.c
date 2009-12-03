/** 
 * @file power.c
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

#include <assert.h>
#include <stdlib.h>
#include <math.h>

#include "solver/solver.h"
#include "cosmos/cosmos.h"

struct Power {
  size_t size;
  size_t comp;
  double * k; // size
  double * Pk; // size*2*fluids*2*fluids
  double * dPk_deta;
};

struct Power * PowerCreate(size_t size, size_t fluids)
{
  struct Power * this = calloc(1,sizeof(*this));
  assert(this);

  this->size = size;
  this->comp = 2*fluids;

  this->k = malloc(size*sizeof(*(this->k)));
  this->Pk = malloc(size*4*fluids*fluids*sizeof(*(this->Pk)));
  this->dPk_deta = malloc(size*4*fluids*fluids*sizeof(*(this->dPk_deta)));

  return this;
}

void PowerDestroy(struct Power * this)
{
  free(this->k);
  free(this->Pk);
  free(this->dPk_deta);
  free(this);
}

void PowerDerivative(struct Solver * solver)
{
  struct Power * power = solver->power;
  struct Cosmos * cosmos = solver->cosmos;

  for (unsigned int a=0;a<power->comp;a++){
    for (unsigned int b=0;b<power->comp;b++){
      for (unsigned int c=0;c<power->comp;c++){

	double Omega_ac = CosmosOmega(cosmos,a,c);
	double Omega_bc = CosmosOmega(cosmos,b,c);
	
	double * restrict dP_deta_ab = power->dPk_deta + (a*comp->size+b)*power->size;
	double * P_cb = power->Pk + (c*comp->size+b)*power->size;
	double * P_ac = power->Pk + (a*comp->size+c)*power->size;

	for (size_t ki=0;ki<power->size;ki++){
	  dP_deta_ab[ki] = -Omega_ac*P_cb[ki] - Omega_bc*P_ac[ki];
	}

      }
    }
  }
}
