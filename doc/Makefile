##############################################################################
#  Makefile for Doxygen documentation.  Doc index can be found here:
#
#  doxygen/index.html
#
#  Targets: doc, clean.
#
#  Default target is "doc".
#


##############################################################################
#  File and directory names.

BIN = doxygen
CFG = doxygen.cfg

OUTDIR  = doxygen
LOG     = doxygen.log
DBG     = debug.txt

CLEANFILES = $(OUTDIR) $(LOG) $(DBG)


##############################################################################
#  Top-level targets.

default: doc

.PHONY: doc clean

doc: $(OUTDIR) 

#  Dependency on tests removed as tests now write files, which modifies the date on the test directory.
# $(OUTDIR): $(CFG) ../app ../classes ../test
$(OUTDIR): $(CFG) ../app ../classes
	$(BIN) $(CFG) > $(LOG) 2>&1

clean:
	rm -rf $(CLEANFILES)
