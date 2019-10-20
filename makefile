#target: dependencies
#	rule to build
#must use tab for rules

CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
OBJS = main.o Animal.o Collection.o Zoo.o Tiger.o Turtle.o Penguin.o getNumberBetween.o
SRCS = *.cpp
HEADERS = Animal.hpp BankAccount.hpp Collection.hpp Penguin.hpp Tiger.hpp Turtle.hpp Zoo.hpp getNumberBetween.hpp
#LDFLAGS = -lboost_date_time (any libraries you want to link)

proj1: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o proj2

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o proj2

valgrind:
	valgrind proj2