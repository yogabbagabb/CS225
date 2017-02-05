CXX = clang++
CXXFLAGS = -std=c++0x -g -O0 -Wall -Wextra

all:
	@echo These programs break, so use the following targets to test things:
	@echo make leak -- to make the leaking program
	@echo make nonCompile -- to make the program that does not compile.
	@echo make segFault -- to make the segfaulting program.
	@echo make upload -- to turn them in.
	@echo make noupload -- use this ONLY if the make upload option fails.

leak: leak.cpp 
	$(CXX) $(CXXFLAGS) leak.cpp -o leak

nonCompile: nonCompile.cpp 
	$(CXX) $(CXXFLAGS) nonCompile.cpp -o nonCompile

segFault: segFault.cpp 
	$(CXX) $(CXXFLAGS) segFault.cpp -o segFault

.PHONY: clean
clean:
	rm -f $(EXENAME)

.PHONY: upload
upload:
	@python .pl_upload.py || echo "Can't upload; if it is still before the deadline, run 'make noupload' (ONCE ONLY) and follow the instructions to turn in your submission."

.PHONY: noupload
noupload:
	tar czf noupload.tar.gz Makefile .pl_upload.cfg *.cpp
	@echo Email the file "'noupload.tar.gz'" to mattox@illinois.edu to turn in your assignment.
