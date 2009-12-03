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

