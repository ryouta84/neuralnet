#include "neuralnet.h"

NeuralNet::NeuralNet(const std::string fileName)
: mData(fileName), mInputSize(8), mHiddenLayerSize(3), mOutputLayerSize(1), count(0)
{
    init();
}


void NeuralNet::start()
{
	limit = 0.001;
    double error = 100.0;

    while(error > limit){
        error = 0.0;
        double buf[mHiddenLayerSize];
        for(int i=0; i<mInputSize; ++i){
            //計算
            for(int j=0; j<mHiddenLayerSize; ++j){
                buf[j] = mHiddenLayer.at(j).calc( mInputLayer.at(i).data() );
            }
            double output = mOutputLayer.at(0).calc(buf);
            //学習
            mOutputLayer.at(0).outNeuLearn( err(output) );
            int index = 0;
            for(auto n : mHiddenLayer){
                n.hidNeuLearn( error, mOutputLayer.at(0).getWeight(index) );
                ++index;
            }
            //誤差がマイナスの値にならないように
            error +=  err(output) * err(output);
            count++;
        }
        std::cout << count << "回目の学習　誤差は" << error << std::endl;
    }

}

double NeuralNet::input(double ary[])
{
    double buf[mHiddenLayerSize];
    int i=0;
    for(auto n : mHiddenLayer){
        buf[i] = n.calc(ary);
        ++i;
    }
    return mOutputLayer.at(0).calc(buf);
}

double NeuralNet::err(double& output)
{
    double e = mInputLayer.at(count % mInputSize).at(mData.endIndex()) - output;
    return e;
}

/*--------------各層の初期化---------------*/

void NeuralNet::initInputLayer()
{
    mInputLayer.reserve(mInputSize);

    for(int i=0; i<mInputSize; ++i){
        mInputLayer.push_back(std::vector<double>(0.0)); //要素をvector内に作らないと範囲外
        mData.getSet( mInputLayer.at(i), i  );
    }
}

void NeuralNet::initHiddenLayer()
{
    mHiddenLayer.reserve(mHiddenLayerSize);

    for(int i=0; i<mHiddenLayerSize; ++i){
        mHiddenLayer.push_back(Neuron(mHiddenLayerSize));
    }
}

void NeuralNet::initOutputLayer()
{
    mOutputLayer.reserve(mOutputLayerSize);

    for(int i=0; i<mOutputLayerSize; ++i){
        mOutputLayer.push_back(Neuron(mHiddenLayerSize));
    }
}

void NeuralNet::init()
{
    initInputLayer();
    initHiddenLayer();
    initOutputLayer();
}
