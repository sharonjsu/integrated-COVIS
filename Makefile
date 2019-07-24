CXX = g++
CXXFLAGS = -std=c++0x -Wall -pedantic-errors -g

SRCS =  main.cpp neurons.cpp IZK.cpp network.cpp
OBJS = ${SRCS:.cpp=.o}
HEADERS = neurons.h IZK.h network.h

MAIN = output

all: ${MAIN}
		@echo   Woo hoo it compiled

${MAIN}: ${OBJS}
		${CXX} ${CXXFLAGS} ${OBJS} -o ${MAIN}

.cpp.o:
		${CXX} ${CXXFLAGS} -c $< -o $@

clean:
		${RM} ${PROGS} ${OBJS} *.o *~.