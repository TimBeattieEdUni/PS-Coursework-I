##############################################################################
#  Makefile for directory "app".  Builds the application from main.cpp and the
#  class library.


##############################################################################
#  Include project-global definitions.

include ../Makefile.inc


##############################################################################
#  Header include directories.

INCLUDE = -I../classes


##############################################################################
#  Source, objects, and header dependencies.  There should only be main.*, but
#  we use well-tested patterns just in case.

SOURCE  = $(wildcard *.cpp)
OBJS    = $(SOURCE:.cpp=.o)
DEPS    = $(SOURCE:.cpp=.d)


##############################################################################
#  Primary target rules.

default: release

.PHONY: release debug profile clean

release: $(APP)
debug:   $(APP)
profile: $(APP)

clean:
	rm -f $(DEPS)
	rm -f $(OBJS)
	rm -f $(APP)


##############################################################################
#  Autogenerated header dependencies.

-include $(DEPS)


##############################################################################
#  Build objects from source.

%.o : %.cpp
	$(CXX) $(PROFFLAGS) -c $(CXXFLAGS) $(WARNINGS) $(INCLUDE) -MMD -o $@ $<


##############################################################################
#  Build executable from objects.

$(APP): $(OBJS) ../classes/$(CLASSLIB)
	$(CXX) $(PROFFLAGS) -o $(APP) $(OBJS) $(CLASSLIBFLAGS) $(LIBS)
