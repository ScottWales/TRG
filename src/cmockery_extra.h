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

#define assert_float_not_equal(a,b,abserr,relerr)		\
  do {								\
    if (fabs((a)-(b)) > fabs(abserr) + fabs(relerr*(a))){	\
      /* SUCCESS */						\
    } else {							\
      /* FAIL */						\
      printf("%s:%d "#a " and " #b " equal\n"			\
	     #a " => %e\n"					\
	     #b " => %e\n",					\
	     __FILE__,__LINE__,a,b);				\
      fail();							\
    }								\
  } while(0)

#define assert_float_equal(a,b,abserr,relerr)			\
  do {								\
    if (fabs((a)-(b)) < fabs(abserr) + fabs(relerr*(a))){	\
      /* SUCCESS */						\
    } else {							\
      /* FAIL */						\
      printf("%s:%d: "#a " and " #b " not equal\n\t"		\
	     #a " => %e\n\t"					\
	     #b " => %e\n",					\
	     __FILE__,__LINE__,a,b);				\
      fail();							\
    }								\
  } while(0)


#endif // cmockery_extra_h
