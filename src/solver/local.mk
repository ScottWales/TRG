# local.mk --- 
#
# Copyright (C)  Scott Wales
#
# Author: Scott Wales <scottwales@coater.physics.usyd.edu.au>
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License as
# published by the Free Software Foundation; either version 2, or (at
# your option) any later version.

# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
# Boston, MA 02110-1301, USA.

THISDIR:=$(dir $(lastword $(MAKEFILE_LIST)))
-include $(wildcard $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(THISDIR))*.d) /dev/null

SOLVER_srcdir:=$(THISDIR)
SOLVER_testdir:=$(patsubst $(SRCDIR)/%,$(TESTDIR)/%,$(SOLVER_srcdir))
SOLVER_src:=$(SOLVER_srcdir)solver.c
SOLVER_test:=$(SOLVER_testdir)solver_test
$(SOLVER_test):$(SOLVER_testdir)empty

TRG_src+=$(SOLVER_src)
TEST+=$(SOLVER_test)

# end
