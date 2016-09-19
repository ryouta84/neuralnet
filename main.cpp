#include "neuralnet.h"

#include <iostream>
#include <valarray>

using namespace std;

int main()
{
    string name;
    cout << "ファイルパスを入力：";
    cin >> name;
	NeuralNet nn(name);
	nn.start();

    cout << fixed;
    string dummy;
    cin.ignore();
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
        valarray<double> ary(buf, 3);
        cout << "result " << nn.forward(ary)[0] << endl;
    }
	return 0;
}
