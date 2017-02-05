EXENAME = testimage testscene
OBJS =  png.o rgbapixel.o image.o testimage.o
OBJS2 = scene.o image.o testscene.o png.o rgbapixel.o

CXX = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lpng -lc++abi -lpthread

all : $(EXENAME)

testimage : $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o testimage

testscene: $(OBJS2)
	$(LD) $(OBJS2) $(LDFLAGS) -o testscene 

testimage.o : testimage.cpp image.h
	$(CXX) $(CXXFLAGS) testimage.cpp

testscene.o: testscene.cpp image.h scene.h
	$(CXX) $(CXXFLAGS) testscene.cpp

image.o : image.cpp image.h png.h

png.o : png.cpp png.h rgbapixel.h
	$(CXX) $(CXXFLAGS) png.cpp

rgbapixel.o : rgbapixel.cpp rgbapixel.h
	$(CXX) $(CXXFLAGS) rgbapixel.cpp

scene.o: image.h scene.cpp scene.h
	$(CXX) $(CXXFLAGS) scene.cpp
clean :
	-rm -f *.o $(EXENAME)
