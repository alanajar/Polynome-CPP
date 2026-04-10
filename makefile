GCC=g++
FLAGS=-Wall -Wextra -Wpedantic

BUILDDIR=build
SOURCEDIR=src
TESTSDIR=tests

all: directories units-tests

units-tests: Polynome
	$(GCC) $(FLAGS) -o $(BUILDDIR)/units-tests $(TESTSDIR)/units-tests.cpp $(BUILDDIR)/Polynome.o -lboost_unit_test_framework

Polynome:
	$(GCC) $(FLAGS) -c $(SOURCEDIR)/Polynome.cpp -o $(BUILDDIR)/Polynome.o

directories:
	mkdir -p $(BUILDDIR)
	mkdir -p $(SOURCEDIR)
	mkdir -p $(TESTSDIR)