#include "neuron.h"

Neuron::Neuron(size_t s) : mSize(s), mThreshold(0)
{
	mWeight.resize(mSize);
	mInput.resize(mSize);
    std::cout << "ニューロン作成" << std::endl;
}

void Neuron::input(double input[])
{
	for(int i=0; i<mInput.size(); ++i){
		mInput[i] = input[i];
	}
}

void Neuron::update(double w[], double t)
{
    setWeight(w);
    setThreshold(t);
}

double Neuron::calc()
{
	std::valarray<double> buf = mWeight * mInput;
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
	//ステップ関数
	if(u >= 0) return 1.0;
	else return 0.0;
	
	//シグモイド関数
	//return 1.0 / (1.0 + exp(-u));
}

