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

.PHONY: release debug clean doc

release: TARGET=release
debug:   TARGET=debug

release: app doc test
debug:   app doc test

clean:
	make -C app      clean
	make -C test     clean
	make -C classes  clean
	make -C doc      clean
	rm -rf $(TESTLIBDIR)



##############################################################################
#  Dependencies.

.PHONY: app doc test classes

app: classes	
	make -C app $(TARGET)

doc:
	make -C doc

test: classes testlib
	make -C test $(TARGET)

classes:
	make -C classes $(TARGET)
	


##############################################################################
#  3rd-party unit test library.

testlib: $(TESTLIBDIR)
	make -C $(TESTLIBDIR) 

$(TESTLIBDIR): $(TESTLIBZIP)
	rm -rf $(TESTLIBDIR)
	unzip $(TESTLIBZIP)
	touch $(TESTLIBDIR)
