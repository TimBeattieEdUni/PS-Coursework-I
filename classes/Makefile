##############################################################################
#  Makefile for directory "classes".  Builds all C++ classes into a static
#  library for use by both the app and the unit test.



##############################################################################
#  Include project-global definitions.

include ../Makefile.inc


##############################################################################
#  Source, objects, and header dependencies.

SOURCE  = *.cpp
OBJS    = $(patsubst %.cpp,%.o,$(wildcard $(SOURCE)))
DEPS    = $(OBJS:.o=.d)



##############################################################################
#  Primary target rules.

default: release

.PHONY: release debug profile clean

release: $(CLASSLIB)
debug:   $(CLASSLIB)
profile: $(CLASSLIB)

clean:
	rm -f $(DEPS)
	rm -f $(OBJS)
	rm -f $(CLASSLIB)



##############################################################################
#  Automatically generated header dependency files.

-include $(DEPS)



##############################################################################
#  Build objects from source.

%.o : %.cpp
	$(CXX) $(PROFFLAGS) -c $(CXXFLAGS) $(WARNINGS) -MMD -o $@ $<



##############################################################################
#  Build library from objects.

$(CLASSLIB): $(OBJS)
	$(AR) $(ARFLAGS) $(CLASSLIB) $(OBJS)
