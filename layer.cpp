#include "layer.h"

layer::layer(size_t n, int m) : mLayerSize(n), mMode(m)
{
    mOutput.resize(mLayerSize);
    mLayer.reserve(mLayerSize);
    for(int i=0; i<mLayerSize; ++i){
        mLayer.push_back(Neuron(mLayerSize));
        std::cout << "(construct)layer mMode" << mMode << std::endl << std::endl;
    }
}

void layer::init(size_t n, int m)
{
    mLayerSize = n;
    mMode = m;
    mOutput.resize(mLayerSize);
    mLayer.reserve(mLayerSize);
    for(int i=0; i<mLayerSize; ++i){
        mLayer.push_back(Neuron(mLayerSize));
        std::cout << "(init)layer mMode" << mMode << std::endl << std::endl;
    }

}

std::valarray<double>& layer::calc(const std::vector< std::valarray<double> >& input)
{
    switch (mMode) {
        case 0://入力層
            //mOutput = input;
            break;

        case 1:
            for(int i=0; i<mLayerSize; ++i){
                mOutput[i] = mLayer.at(i).calc( input.at(i) );
            }
            break;
    }
    return mOutput;
}

void layer::status()
{
    std::cout << "Layer Type " << mMode << std::endl;
    std::cout << mLayer.size() << "neuron(mLayer.size())" << std::endl;
    std::cout << mLayerSize << "neuron(mLayerSize)" << std::endl << std::endl;
}

void layer::updataNeuron(size_t no, double thr)
{
    try{
        mLayer.at(no).updateThreshold(thr);
    }catch(std::out_of_range& e){
        std::cerr << "error in updataNeuron()" << std::endl;
    }
}
