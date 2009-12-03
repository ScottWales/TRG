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

CFLAGS+=-Wall -Werror -Wstrict-prototypes
CFLAGS+=-std=c99
CFLAGS+=-g
CFLAGS+=-MMD -MP

CFLAGS+=-Isrc

MKDIR=mkdir -p

BIN=
SRC=
OBJ=
TEST=

BINDIR=bin
SRCDIR=src
OBJDIR=obj
TESTDIR=test

TRG_bin:=$(BINDIR)/trg
TRG_src:=
TRG_obj:=
BIN+=$(TRG_bin)
SRC+=$(TRG_src)
OBJ+=$(TRG_obj)

all: $(BIN) check

-include $(SRCDIR)/local.mk /dev/null

check: $(TEST)
	for test in $(TEST); do ./$$test; done;
clean:
	$(RM) -r $(BINDIR)
	$(RM) -r $(OBJDIR)
	$(RM) -r $(TESTDIR)

TRG_obj:=$(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(TRG_src))
$(TRG_bin):$(TRG_obj)
	$(CC) $(LDFLAGS) -o $@ $(filter %.o,$^) $(LDLIBS)

$(BIN):$(BINDIR)/empty
$(SRC):$(SRCDIR)/empty
$(OBJ):$(OBJDIR)/empty
$(TEST):$(TESTDIR)/empty

%/empty:
	$(MKDIR) $(dir $@)
	touch $@

$(OBJDIR)/%.o:$(SRCDIR)/%.c $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(THISDIR))empty
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(TEST):CFLAGS+=-I/usr/local/cmockery/include
$(TEST):LDFLAGS+=-L/usr/local/cmockery/lib
$(TEST):LDLIBS+=-lcmockery

$(TESTDIR)/%_test:$(OBJDIR)/%_test.o \
		$(patsubst $(SRCDIR)/%,$(TESTDIR)/%,$(THISDIR))empty
	$(CC) $(LDFLAGS) -o $@ $(filter %.o,$^) $(LDLIBS)

# end
