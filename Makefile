# Makefile --- 
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

CFLAGS+=-Wall -Wextra -Werror
CFLAGS+=-std=c99
CFLAGS+=-g
CFLAGS+=-MMD -MP

MKDIR=mkdir -p

BIN=
SRC=
OBJ=
TEST=

TRG_bin:=$(BINDIR)/trg
TRG_src:=
TRG_obj:=

BIN+=$(TRG_bin)
SRC+=$(TRG_src)
OBJ+=$(TRG_obj)

BINDIR=bin
SRCDIR=src
OBJDIR=obj
TESTDIR=test

all: $(BIN) check
check: $(TEST)
	for test in $(TEST); do ./$$test; done;
clean:
	$(RM) $(BINDIR)
	$(RM) $(OBJDIR)
	$(RM) $(TESTDIR)

-include $(SRCDIR)/local.mk /dev/null

TRG_obj:=$(patsubst $(SRCDIR)/,$(OBJDIR)/,$(TRG_src))
$(TRG_bin):$(TRG_obj)

$(BIN):$(BINDIR)/empty
$(SRC):$(SRCDIR)/empty
$(OBJ):$(OBJDIR)/empty
$(TEST):$(TESTDIR)/empty

$(BINDIR)/empty:
	$(MKDIR) $(dir $@)
	touch $@
$(SRCDIR)/empty:
	$(MKDIR) $(dir $@)
	touch $@
$(OBJDIR)/empty:
	$(MKDIR) $(dir $@)
	touch $@

# end