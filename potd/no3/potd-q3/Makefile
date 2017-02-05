EXENAME = q3

CXX = clang++
CXXFLAGS = -std=c++0x -g -O0 -Wall -Wextra

all : $(EXENAME).o

$(EXENAME).o: q3.cpp 
	$(CXX) $(CXXFLAGS) -c q3.cpp 

.PHONY: clean
clean:
	rm -f $(EXENAME)

.PHONY: upload
upload:
	@python .pl_upload.py || echo "Can't upload; please upload your code using your browser."
