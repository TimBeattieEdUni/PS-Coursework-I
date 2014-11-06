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
REPORT = $(SRC:.tex=.pdf)

DEP    = BuildTools.tex Conclusion.tex Debugging.tex Design.tex FurtherWork.tex Introduction.tex Performance.tex Planning.tex ProgramLanguage.tex RevisionControl.tex Taskassignment.tex Testing.tex
TOC    = $(wildcard *.toc)
AUX    = $(wildcard *.aux)

#  two logs because pdflatex writes its own log as well as lots of output
LLOG   = $(SRC:.tex=.log)
MLOG   = make.log

#  pdflatex writes errors to individual file logs
ALLLOG = $(wildcard *.log)
CLEANFILES = $(REPORT) $(TOC) $(AUX) $(LLOG) $(MLOG) $(ALLLOG) *.backup *~


##############################################################################
#  Top-level targets.

default: report

.PHONY: report clean

report: $(REPORT)

$(REPORT) : $(SRC) $(DEP)
	$(LTX) $(FLAGS) $(SRC) > $(MLOG) 2>&1

clean:
	rm -rf $(CLEANFILES)
