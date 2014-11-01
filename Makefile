##############################################################################
#  Top-level makefile for popsim.
#
#  Top-level targets: release, debug, clean.
#  Low-level targets: app, doc, test.
#
#  Default target: release.
#
#  To do: switching between release and debug builds requires a "make clean"
#  first.


##############################################################################
#  Include project-global definitions.

include Makefile.inc


##############################################################################
#  Top-level targets.

default: release

.PHONY: release debug clean doc profile

release: TARGET=release
debug:   TARGET=debug
profile: TARGET=profile

release: doc app test
debug:   doc app test
profile: app

clean:
	$(MAKE) -C app      clean
	$(MAKE) -C test     clean
	$(MAKE) -C classes  clean
	$(MAKE) -C doc      clean
	$(MAKE) -C report   clean
	rm -rf $(TESTLIBDIR)


##############################################################################
#  Dependencies.

.PHONY: doc classes app test

app: classes
	$(MAKE) -C app $(TARGET)

doc: classes app test
	$(MAKE) -C doc
	$(MAKE) -C report

test: classes testlib
	$(MAKE) -C test $(TARGET)

classes:
	$(MAKE) -C classes $(TARGET)


##############################################################################
#  3rd-party unit test library.

testlib: $(TESTLIBDIR)
	$(MAKE) -C $(TESTLIBDIR)

$(TESTLIBDIR): $(TESTLIBZIP)
	rm -rf $(TESTLIBDIR)
	unzip  $(TESTLIBZIP)
	touch  $(TESTLIBDIR)
