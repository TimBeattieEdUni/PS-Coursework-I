##############################################################################
#  Makefile for project report.
#
#  Targets: report, clean.
#
#  Default target is "report".
#



##############################################################################
#  File names.

BIN   = pdflatex
SRC   = report.tex
FLAGS = -halt-on-error
OUT   = report.pdf

CLEANFILES = $(OUT) report.aux report.log report.toc



##############################################################################
#  Top-level targets.

default: report

.PHONY: report clean

report: $(OUT)

$(OUT) : $(SRC)
	$(BIN) $(FLAGS) $(SRC) > make.log 2>&1

clean:
	rm -rf $(CLEANFILES)
