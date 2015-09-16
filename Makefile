#
# ============================
# Generic Makefile
#
# Author: alexander.paniutin@gmail.com
#   Date: 2015-09-15
#


#
# 'make depend' uses makedepend to automatically generate dependencies 
#               (dependencies are added to end of Makefile)
# 'make'        build executable file 'mycc'
# 'make clean'  removes all .o and executable files
#

# define the C compiler to use
CC = g++

# define any compile-time flags
CFLAGS = -Wall -g
DEFINES =

# define any src or obj folders you will work with
#
SRCDIR = src
OBJDIR = obj
OUTDIR = output

# define any 3'rd party components
#
GTEST = thirdParty/GTest

# define any directories containing header files other than /usr/include
#
# -I<include_path>
INCLUDES =

# define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:
# -L<lib_path>
LFLAGS = 

# define any libraries to link into executable:
#   if I want to link in libraries (libx.so or libx.a) I use the -llibname 
#   option, something like (this will link in libmylib.so and libm.so:
# -l<lib_name>
LIBS =

# define the C source files
SRCS = $(SRCDIR)/Add.cpp
SRCS_GTEST = $(SRCDIR)/Add_gtest.cpp

# define the C object files 
#
# This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
#         For each word in 'name' replace 'string1' with 'string2'
# Below we are replacing the suffix .c of all words in the macro SRCS
# with the .o suffix
#
OBJS = $(SRCS:.cpp=.o)
OBJS_GTEST = $(SRCS_GTEST:.cpp=.o)
OBJS_TEST =

# define the executable file 
MAIN = my_add

#
# The following part of the makefile is generic; it can be used to 
# build any executable just by changing the definitions above and by
# deleting dependencies appended to the file from 'make depend'
#

.PHONY: depend clean

all:    $(MAIN)
	@echo  The Demo of GTest library has been compiled. the executable is $(MAIN)

wgtest: DEFINES += -DGTEST
wgtest: INCLUDES += -I$(GTEST)/include
wgtest: LFLAGS += -L$(GTEST)/lib
wgtest: LIBS += -lgtest
wgtest: OBJS_TEST += $(OBJS_GTEST)
wgtest: $(OBJS_GTEST)
wgtest: $(MAIN)
wgtest:
	echo Done!
	
$(MAIN): $(OBJS) 
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS) $(OBJS_TEST) $(LFLAGS) $(LIBS)

# this is a suffix replacement rule for building .o's from .cpp's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .cpp file) and $@: the name of the target of the rule (a .o file) 
# (see the gnu make manual section about automatic variables)
.cpp.o:
	$(CC) $(CFLAGS) $(DEFINES) $(INCLUDES) -c $<  -o $@

clean:
	$(RM) $(SRCDIR)/*.o $(SRCDIR)/*~ $(MAIN) *test_results.xml

depend: $(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it



