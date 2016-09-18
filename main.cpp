#include "neuralnet.h"

#include <iostream>

using namespace std;

int main()
{
	NeuralNet nn("/Users/I13I085/GitHub/neuralnet/data.txt");
	nn.start();

    string dummy;
    while(true){
        getline(cin, dummy);
        stringstream ss;
        ss << dummy;
        double d=0;
        double buf[3];
        int i=0;
        while(ss >> d){
            buf[i] = d;
            ++i;
        }
        cout << "output " << nn.input(buf) << endl;
    }
	return 0;
}
