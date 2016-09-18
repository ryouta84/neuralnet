#include "neuron.h"

Neuron::Neuron(size_t s) : mSize(s), mWeight(0), mThreshold(0)
{
	mWeight.resize(mSize);
    std::cout << "Neuron!" << std::endl;
}

void Neuron::update(double w[], double t)
{
    setWeight(w);
    setThreshold(t);
    for(int i=0; i<mSize; ++i){
        std::cout << w[i] << " ";
    }
    std::cout << t << std::endl;
}

double Neuron::output(double input[])
{
    std::valarray<double> data(input, mSize);
	std::valarray<double> buf = mWeight * data;
	double                u   = buf.sum();

	u -= mThreshold;

	return f(u);
}

/*********************private********************************/
void Neuron::setWeight(double ary[])
{
	for(int i=0; i<mWeight.size(); ++i){
		mWeight[i] = ary[i];
	}
}

void Neuron::setThreshold(double t)
{
	mThreshold = t;
}

double Neuron::f(double u)
{
	//シグモイド関数
	return 1.0 / (1.0 + exp(-u));
}
