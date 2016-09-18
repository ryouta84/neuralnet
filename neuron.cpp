#include "neuron.h"

Neuron::Neuron(size_t s)
: mSize(s), mInput(0), mWeight(0), mThreshold(0), mOutput(0), alpha(10.0)
{
    mInput.resize(mSize);
	mWeight.resize(mSize);

    initNeuron();

    std::cout << "Neuron!" << std::endl;
}

//中間層のニューロンと結合している出力層の重みを渡す
void Neuron::hidNeuLearn(double err, double nextWeight)
{
    double d = mOutput * (1 - mOutput) * nextWeight * err * mOutput * (1 - mOutput);
    for(int i=0; i<mWeight.size(); ++i){
        mWeight[i] = mWeight[i] + alpha * mInput[i] * d;
    }
    mThreshold = mThreshold + alpha * (-1.0) * d;
}

void Neuron::outNeuLearn(double err)
{
    double d = err * mOutput * (1 - mOutput);
    for(int i=0; i<mSize; ++i){
        mWeight[i] = mWeight[i] + alpha * mInput[i] * d;
    }
    mThreshold = mThreshold + alpha * (-1.0) * d;
}

double Neuron::calc(double input[])
{
    std::valarray<double> buf(input, mSize);
    mInput = buf;
	buf = mWeight * mInput;
	double u = buf.sum();
	u -= mThreshold;
    mOutput = f(u);

	return mOutput;
}

double Neuron::drnd()
{
    std::random_device seedGen;
    std::mt19937 engine(seedGen());
    std::uniform_real_distribution<double> dist(-1.0, 1.0);

    return dist(engine);
}

double Neuron::getWeight(size_t i)
{
    return mWeight[i];
}

double Neuron::f(double u)
{
	//シグモイド関数
	return 1.0 / (1.0 + exp(-u));
}

void Neuron::initNeuron()
{
    for(auto& w : mWeight){
        w = drnd();
        std::cout << w << std::endl;
    }
    mThreshold = drnd();
}
