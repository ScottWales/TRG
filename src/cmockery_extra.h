/** 
 * @file cmockery_extra.h
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


#ifndef cmockery_extra_h
#define cmockery_extra_h 1

#define UNIT_TESTING 2

#include <stdarg.h>
#include <math.h>
#include <stdio.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdlib.h>
#include <google/cmockery.h>

#define assert_float_not_equal(_a,_b,abserr,relerr)		\
  do {								\
    if (fabs((_a)-(_b)) > fabs(abserr) + fabs(relerr*(_a))){	\
      /* SUCCESS */						\
    } else {							\
      /* FAIL */						\
      printf("%s:%d "#_a " and " #_b " equal\n"			\
	     #_a " => %e\n"					\
	     #_b " => %e\n",					\
	     __FILE__,__LINE__,_a,_b);				\
      fail();							\
    }								\
  } while(0)

#define assert_float_equal(_a,_b,abserr,relerr)			\
  do {								\
    if (fabs((_a)-(_b)) < fabs(abserr) + fabs(relerr*(_a))){	\
      /* SUCCESS */						\
    } else {							\
      /* FAIL */						\
      printf("%s:%d: "#_a " and " #_b " not equal\n\t"		\
	     #_a " => %e\n\t"					\
	     #_b " => %e\n",					\
	     __FILE__,__LINE__,_a,_b);				\
      fail();							\
    }								\
  } while(0)


#endif // cmockery_extra_h
