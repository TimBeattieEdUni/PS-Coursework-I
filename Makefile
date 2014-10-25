##############################################################################
#  Top-level makefile for popsim.
#
#  Targets: release, debug, doc, clean.
#
#  Default target is "release"
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

release: app test
debug:   app test

doc:
	make -C doc

clean:
	make -C app      clean
	make -C test     clean
	make -C classes  clean
	make -C doc      clean
	rm -rf $(TESTLIBDIR)



##############################################################################
#  Dependencies.

.PHONY: app test classes

app: classes	
	make -C app $(TARGET)

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
