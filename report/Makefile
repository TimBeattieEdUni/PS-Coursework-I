##############################################################################
#  Makefile for project report.
#
#  Targets: report, clean.
#
#  Default target is "report".
#



##############################################################################
#  File names.

BIN = pdflatex
SRC = report.tex
CLEANFILES = report.aux report.log report.pdf report.toc



##############################################################################
#  Top-level targets.

default: report

.PHONY: report clean

report:
	$(BIN) $(SRC)

clean:
	rm -rf $(CLEANFILES)
