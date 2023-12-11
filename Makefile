# Define the compiler and the linker. The linker must be defined since
# the implicit rule for linking uses CC as the linker. g++ can be
# changed to clang++.
CXX = g++
CC  = $(CXX)

# Generate dependencies in *.d files
DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

# Define preprocessor, compiler, and linker flags. Uncomment the # lines
# if you use clang++ and wish to use libc++ instead of GNU's libstdc++.
# -g is for debugging.
CPPFLAGS = -std=c++11 -I.
CXXFLAGS = -O0 -Wall -Wextra -Werror -pedantic-errors -Wold-style-cast 
CXXFLAGS += -g
CXXFLAGS += $(DEPFLAGS)
LDFLAGS = -g
# CPPFLAGS += -stdlib=libc++
# CXXFLAGS += -stdlib=libc++
# LDFLAGS += -stdlib=libc++

# Targets
PROGS = test_graph_small test_nodeset test_dijkstra my_test_graph test_graph_nofile

all: $(PROGS)
# Targets rely on implicit rules for compiling and linking
# Use $(CXX) for linking
test_graph_small: test_graph_small.o 
test_nodeset: test_nodeset.o nodeset.o
test_dijkstra: test_dijkstra.o dijkstra.o nodeset.o
my_test_graph: my_test_graph.o graph.o dijkstra.o nodeset.o
test_graph_nofile: test_graph_nofile.o graph.o

test_components:
	./test_dijkstra
	./test_graph_small
	./test_graph_nofile
	./test_nodeset
test_complex:
	./my_test_graph

# Phony targets
.PHONY: all test clean distclean

# Standard clean
clean:
	rm -f *.o $(PROGS)

distclean: clean
	rm -f *.d

# Include the *.d files
SRC = $(wildcard *.cc)
-include $(SRC:.cc=.d)

