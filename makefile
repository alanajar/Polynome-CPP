GCC=g++
FLAGS=-Wall -Wextra -Wpedantic

BUILDDIR=build
SOURCEDIR=src
TESTSDIR=tests
LATEXDIR=latex
HTMLDIR=html

all: directories units-tests documentations

units-tests: Polynome
	$(GCC) $(FLAGS) -o $(BUILDDIR)/units-tests $(TESTSDIR)/units-tests.cpp $(BUILDDIR)/Polynome.o -lboost_unit_test_framework

Polynome:
	$(GCC) $(FLAGS) -c $(SOURCEDIR)/Polynome.cpp -o $(BUILDDIR)/Polynome.o

directories:
	mkdir -p $(BUILDDIR)
	mkdir -p $(SOURCEDIR)
	mkdir -p $(TESTSDIR)

documentations:
	doxygen

clean:
	rm -rf $(BUILDDIR)
	rm -rf $(LATEXDIR)
	rm -rf $(HTMLDIR)