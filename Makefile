##############################################################################
#  Top-level makefile for popsim.
#
#  Top-level targets: release, debug, clean.
#  Low-level targets: app, doc, test.
#
#  Default target: release.
#
#  To do: Switching between release and debug builds requires a "make clean" in
#         between, as does switching from a profiling build to a release or
#         debug build.
#


##############################################################################
#  Include project-global definitions.

include Makefile.inc


##############################################################################
#  Top-level targets.

default: release

.PHONY: release debug clean doc profile tar

release: TARGET=release
debug:   TARGET=debug
profile: TARGET=profile

release: doc report app test
debug:   doc report app test

tar: clean
	tar -cvzf $(TARFILE) $(TARBITS)

clean:
	$(MAKE) -C app      clean
	$(MAKE) -C test     clean
	$(MAKE) -C classes  clean
	$(MAKE) -C doc      clean
	$(MAKE) -C report   clean
	rm -rf $(TARFILE)
	rm -rf $(TESTLIBDIR)


##############################################################################
#  Dependencies.

.PHONY: doc report classes app test

app: classes
	$(MAKE) -C app $(TARGET)

doc: classes app
	$(MAKE) -C doc

report:
	$(MAKE) -C report

test: classes testlib
	$(MAKE) -C test $(TARGET)

classes:
	$(MAKE) -C classes $(TARGET)

profile:
	$(MAKE) -C classes clean
	$(MAKE) -C app clean
	$(MAKE) -C classes $(TARGET)
	$(MAKE) -C app $(TARGET)


##############################################################################
#  3rd-party unit test library.

testlib: $(TESTLIBDIR)
	$(MAKE) -C $(TESTLIBDIR)

$(TESTLIBDIR): $(TESTLIBZIP)
	rm -rf $(TESTLIBDIR)
	unzip  $(TESTLIBZIP)
	touch  $(TESTLIBDIR)
