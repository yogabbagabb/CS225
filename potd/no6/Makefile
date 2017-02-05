EXENAME = q6

CXX = clang++
CXXFLAGS = -std=c++0x -g -O0 -Wall -Wextra

all : $(EXENAME)

$(EXENAME): q6.cpp 
	$(CXX) $(CXXFLAGS) q6.cpp -o $(EXENAME)

.PHONY: clean
clean:
	rm -f $(EXENAME)

.PHONY: upload
upload:
	@python .pl_upload.py || echo "Can't upload; if it is still before the deadline, email mattox@illinois.edu to turn in your submission."
