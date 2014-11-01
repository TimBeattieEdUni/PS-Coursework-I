##############################################################################
#  Makefile for project report.
#
#  Targets: report, clean.
#
#  Default target is "report".
#


##############################################################################
#  LaTeX compiler.

LTX    = pdflatex
FLAGS  = -halt-on-error


##############################################################################
#  Source and output.

SRC    = report.tex
OUT    = $(SRC:.tex=.pdf)
TOC    = $(SRC:.tex=.toc)
AUX    = $(SRC:.tex=.aux)

#  pdflatex writes its own log as well as lots of output, so we have two logs
LLOG   = $(SRC:.tex=.log)
MLOG   = make.log

CLEANFILES = $(OUT) $(TOC) $(AUX) $(LLOG) $(MLOG)


##############################################################################
#  Top-level targets.

default: report

.PHONY: report clean

report: $(OUT)

$(OUT) : $(SRC)
	$(LTX) $(FLAGS) $(SRC) > $(MLOG) 2>&1

clean:
	rm -rf $(CLEANFILES)
