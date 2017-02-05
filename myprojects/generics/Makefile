EXENAME = gen
OBJS = gen.o

CXX = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lpng -lc++abi -lpthread

all : $(EXENAME)

$(EXENAME) : $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

gen.o.o : gen.cpp
	$(CXX) $(CXXFLAGS) gen.cpp


clean :
	-rm -f *.o $(EXENAME)
