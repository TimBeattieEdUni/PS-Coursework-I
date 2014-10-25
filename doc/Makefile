##############################################################################
#  Makefile for documentation.
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

doc:
	$(BIN) $(CFG) > $(LOG) 2>&1

clean:
	rm -rf $(CLEANFILES)
