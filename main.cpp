#include "neuralnet.h"

#include <iostream>

using namespace std;

int main()
{
    string name;
    cout << "ファイルパスを入力：";
    cin >> name;
	NeuralNet nn(name);
	nn.start();

    cout << fixed;
    cin.ignore();
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
        cout << "result " << nn.input(buf) << endl;
    }
	return 0;
}
