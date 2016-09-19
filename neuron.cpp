#include "neuron.h"

Neuron::Neuron(size_t s)
: mSize(s), mThreshold(0)
{
    initNeuron();
}

double Neuron::calc(const std::valarray<double>& input)
{
    double u = input.sum();
    u -= mThreshold;

    return f(u);
}

double Neuron::drnd()
{
    std::random_device seedGen;
    std::mt19937 engine(seedGen());
    std::uniform_real_distribution<double> dist(-1.0, 1.0);

    return dist(engine);
}

double Neuron::f(double u)
{
    //シグモイド関数
    return 1.0 / (1.0 + exp(-u));
}

void Neuron::updateThreshold(double thr)
{
    mThreshold += thr;
}

void Neuron::initNeuron()
{
    mThreshold = drnd();
    std::cout << "Neuron!" << std::endl;
}
