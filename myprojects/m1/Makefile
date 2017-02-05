EXENAME = mp2 picRos list listd

CXX = clang++
CXXFLAGS = -std=c++0x -g -O0 -Wall -Wextra

all : $(EXENAME)

list: list.cpp
	$(CXX) $(CXXFLAGS) list.cpp -o list

mp2: mp2.cpp
	$(CXX) $(CXXFLAGS) mp2.cpp -o mp2

listd: listd.cpp
	$(CXX) $(CXXFLAGS) listd.cpp -o listd


picRos: picRos.cpp
	$(CXX) $(CXXFLAGS) picRos.cpp -o picRos

.PHONY: clean
clean:
	rm -f $(EXENAME)
