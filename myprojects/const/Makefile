EXENAME = const
OBJS = main.o 
SECOND = second
CXX = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lpng -lc++abi -lpthread

all : $(EXENAME)

$(EXENAME) : $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o : main.cpp
	$(CXX) $(CXXFLAGS) main.cpp

$(SECOND) : secondmain.o
	$(LD) secondmain.o $(LDFLAGS) -o second

secondmain.o: secondmain.cpp
	$(CXX) $(CXXFLAGS) secondmain.cpp


clean :
	-rm -f *.o $(EXENAME)

