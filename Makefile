OBJS	= main.o neuralnet.o neuron.o
PROGRAM = main.exe

all:			$(PROGRAM)

$(PROGRAM):		$(OBJS)
			g++  $(OBJS) -o $(PROGRAM)

main.o:			main.cpp
			g++ -std=c++14 -c main.cpp

neuralnet.o:		neuralnet.cpp
			g++ -std=c++14 -c neuralnet.cpp

neuron.o:		neuron.cpp
			g++ -std=c++14 -c neuron.cpp