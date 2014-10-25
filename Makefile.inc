##############################################################################
#  Global Make options.



##############################################################################
#  Binary names.

APP           = popsim
TESTAPP       = popsim-test
CLASSLIB      = libpopsim.a
CLASSLIBFLAG  = -L../classes -lpopsim


##############################################################################
#  Compiler.

CXX      = g++
WARNINGS = -Wall -Wextra -pedantic -Weffc++ -Werror

CXXFLAGS             =
release:  CXXFLAGS  += -O3
debug:    CXXFLAGS  += -g -D_DEBUG



##############################################################################
#  Library archiver.

AR       = ar
ARFLAGS  = rcs



##############################################################################
#  System libraries.

LIBS      = 

# To add a library, uncomment its line.
#LIBS      += -lboost_system-mt 
#LIBS      += -lboost_thread-mt



##############################################################################
#  3rd-party unit test library: UnitTest++.

DOWNLOADDIR   = downloads
TESTLIBZIP    = $(DOWNLOADDIR)/unittest-cpp-1.4.zip
TESTLIBDIR    = UnitTest++

