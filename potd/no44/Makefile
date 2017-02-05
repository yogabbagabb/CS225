EXENAME = q44

CXX = clang++
CXXFLAGS = -std=c++0x -g -O0 -Wall -Wextra

all : $(EXENAME)

$(EXENAME): q44.cpp
	$(CXX) $(CXXFLAGS) q44.cpp -o $(EXENAME)

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
	@echo Please do NOT email to resubmit your problem.  This question is graded on the basis of partipation.
	@echo If you have submitted it already, assuming it is really code, you already have credit.

