OBJS	= main.o neuralnet.o layer.o neuron.o
PROGRAM = main

all:			$(PROGRAM)

$(PROGRAM):		$(OBJS)
				g++  $(OBJS) -o $(PROGRAM)

main.o:			main.cpp
				g++ -std=c++14 -c main.cpp

neuralnet.o:	neuralnet.cpp
				g++ -std=c++14 -c neuralnet.cpp

layer.o:		layer.cpp
				g++ -std=c++14 -c layer.cpp

neuron.o:		neuron.cpp
				g++ -std=c++14 -c neuron.cpp
