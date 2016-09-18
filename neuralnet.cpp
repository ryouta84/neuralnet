#include "neuralnet.h"

NeuralNet::NeuralNet(const std::string fileName)
: mData(fileName), mInputLayerSize(3), mHiddenLayerSize(3), mOutputLayerSize(1), count(0)
{
    init();
}


void NeuralNet::start()
{
	limit = 0.001;
    alpha = 10;
    double err = 100;

    while(err < limit){
        //計算
        hiddenOutput();
        outputLayerOutput();
        //学習

    }

}

void NeuralNet::hiddenOutput()
{
    for(int i=0; i<mHiddenLayerSize; ++i){
        mHidResult.push_back( mHiddenLayer.at(i).output(mInputLayer.at(i).data()) );
    }
}
void NeuralNet::outputLayerOutput()
{
    for(int i=0; i<mOutputLayerSize; ++i){
        mOutResult.push_back( mOutputLayer.at(i).output(&mHidResult.at(i)) );
    }
}

double NeuralNet::err(double& output)
{
    double e = mInputLayer.at(count).at(mData.endIndex()) - output;
    return e;
}

void backPropagation(double err)
{
    
}

double NeuralNet::drnd()
{
    std::random_device seedGen;
    std::mt19937 engine(seedGen());
    std::uniform_real_distribution<double> dist(-1.0, 1.0);

    return dist(engine);
}

/*--------------各層の初期化---------------*/

void NeuralNet::initInputLayer()
{
    mInputLayer.reserve(mInputLayerSize);

    for(int i=0; i<mInputLayerSize; ++i){
        mInputLayer.push_back(std::vector<double>(0.0)); //要素をvector内に作らないと範囲外
        mData.getSet( mInputLayer.at(i), i );
    }
}

void NeuralNet::initHiddenLayer()
{
    mHiddenLayer.reserve(mHiddenLayerSize);
    mHidResult.reserve(mHiddenLayerSize);

    for(int i=0; i<mHiddenLayerSize; ++i){
        mHiddenLayer.push_back(Neuron(mInputLayerSize));
        //重みと閾値の初期化
        double ary[mInputLayerSize];
        for(auto& i : ary){
            i = drnd();
        }
        mHiddenLayer.at(i).update(ary,drnd());
    }
}

void NeuralNet::initOutputLayer()
{
    mOutputLayer.reserve(mOutputLayerSize);
    mOutResult.reserve(mOutputLayerSize);
    for(int i=0; i<mOutputLayerSize; ++i){
        mOutputLayer.push_back(Neuron(2));
        //重みと閾値の初期化
        double ary[mInputLayerSize];
        for(auto& i : ary){
            i = drnd();
        }
        mOutputLayer.at(i).update(ary,drnd());
    }
}

void NeuralNet::init()
{
    initInputLayer();
    initHiddenLayer();
    initOutputLayer();
}
