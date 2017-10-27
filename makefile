##################################################
#   GENERIC G++ MAKEFILE
#   MODIFY BELOW
##################################################
# REPLACE THIS WITH THE NAME OF YOUR EXECUTABLE
EXE = main.exe

# Modify compiler flags as desired
CXXFLAGS = -std=c++11 -Wextra -Wconversion -Wall -pedantic -Os

######################################################
#	GENERALLY WON'T CHANGE ANY OF THIS
######################################################
ifeq ($(strip $(EXE)),)
empty-exe-error:
	@echo FORGOT TO SUPPLY A NAME TO EXE IN MAKEFILE
endif

# All cpp files in folder
SRC = $(wildcard *.cpp)

# .o file for every .cpp
OBJS = $(SRC:.cpp=.o)

# C++ Compiler
CXX = g++

# Run if not out of date
run: $(EXE)
	.\$(EXE)

# Rule to build the executable
$(EXE): $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $@

# Rule for g++ to build .o files from .cpp files
%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $<

