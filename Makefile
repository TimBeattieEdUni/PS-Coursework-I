##############################################################################
#  Top-level makefile for popsim.
#
#  Targets: all, all-debug, app, app-debug, test, test-debug, classes, classes-debug, clean
#
#  Default target is "all"
#
#  To do: switching between release and debug builds requires a clean.



##############################################################################
#  Include project-global definitions.

include Makefile.inc



##############################################################################
#  Top-level target rules.

default: all

.PHONY: all
all: app test

.PHONY: all-debug
all-debug: app-debug test-debug 

.PHONY: clean
clean:
	make -C app clean
	make -C test clean
	make -C classes clean
	make -C $(TESTLIBDIR) clean



##############################################################################
#  Subirectory target rules.

.PHONY: app
app: classes	
	make -C app

.PHONY: app-debug
app-debug: classes-debug
	make -C app debug

.PHONY: test
test: classes testlib
	make -C test
	test/$(TESTAPP)

.PHONY: test-debug
test-debug: classes-debug testlib
	make -C test debug
	test/$(TESTAPP)

.PHONY: classes
classes:
	make -C classes

.PHONY: classes-debug
classes-debug:
	make -C classes debug



##############################################################################
#  3rd-party unit test library rules.

testlib: $(TESTLIBDIR)
	make -C UnitTest++

$(TESTLIBDIR): $(TESTLIBZIP)
	rm -rf $(TESTLIBDIR)
	unzip $(TESTLIBZIP)
	touch $(TESTLIBDIR)
