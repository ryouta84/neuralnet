#include "neuralnet.h"

NeuralNet::NeuralNet(const std::string fileName) : mData(fileName), mInputLayerSize(2), mHiddenLayerSize(2)
{
    inputLayerSet();
    hiddenLayerSet();
}

void NeuralNet::inputLayerSet()
{
    //mInputLayer.reserve(mInputLayerSize);
    for(auto i : (mData.getData()).at(2) ){
        mInputLayerVal.push_back( i );
    }
}

void NeuralNet::hiddenLayerSet()
{
    mHiddenLayer.reserve(mHiddenLayerSize);
    for(int i=0; i<mHiddenLayerSize; ++i){
        mHiddenLayer.push_back(Neuron(2));
    }
    
    for(auto& n : mHiddenLayer){
        n.input( mInputLayerVal.data() );
        //n.updata();
    }
}

double NeuralNet::start()
{
	return 1;
}

void NeuralNet::setNN()
{
    
}
