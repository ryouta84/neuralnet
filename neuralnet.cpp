#include "neuralnet.h"

NeuralNet::NeuralNet(const std::string fileName)
: mInputLayerSize(3), mHiddenLayerSize(3), mOutputLayerSize(1),
  mInputLayer(0), mHiddenLayer(mHiddenLayerSize), mOutputLayer(mOutputLayerSize),
  mCount(0), mData(fileName), mLayerNum(3), mAlpha(10)
{
    mInputLayer.init(mInputLayerSize, 0); //入力層は引数が二つ必要なので関数で初期化
    mOutput.reserve(mInputLayerSize);
    mWeight.reserve(mHiddenLayerSize + mOutputLayerSize);
    mBuf.reserve(mInputLayerSize);
    try{
        //mOutput,mWeightを初期化
        //mOutputは各層に一つ必要
        std::valarray<double> tmp(0.0, mInputLayerSize);
        for(int i=0; i<mLayerNum; ++i){
            mOutput.push_back(tmp);
            mBuf.push_back(tmp);
        }
        for(int i=0; i<mHiddenLayerSize+mOutputLayerSize; ++i){
            mWeight.push_back(tmp);
        }
        initWeight();
    }catch(std::out_of_range& ex) {
        std::cerr << "out of range : construct : " << ex.what () << std::endl;
    }
    //各層の状態の表示
    mInputLayer.status();
    mHiddenLayer.status();
    mOutputLayer.status();
}

void NeuralNet::start()
{
    try{
        mLimit = 0.001;
        double totalErr = 100;

        while(totalErr > mLimit){
            totalErr = 0.0;
            //教師データ全てを学習
            for(int i=0; i<mData.getSetsNo(); ++i){
                std::valarray<double> input( mData.getData().at(i).data(), mInputLayerSize );
                forward(input);
                //std::cout << i+1 << " output " << mOutput.at(2)[0] << std::endl;
                double err = error(mData.getData().at(i)[3], mOutput.at(2)[0]);
                backPropagation(err);
                totalErr += err * err;
            }
            ++mCount;
            std::cout << std::fixed;
            std::cout << mCount << "times" << std::endl;
            std::cout << "total error " << totalErr << std::endl;
        }
        std::cout << "学習終了" << std::endl;
    }catch(std::out_of_range& ex) {
        std::cerr << "out of range : start : " << ex.what() << std::endl;
    }
}

std::valarray<double>& NeuralNet::forward(std::valarray<double>& output)
{
    //入力層の計算
    mOutput.at(0)  = output; //入力層からの出力は３個
    //中間層の計算
    for(int i=0; i<mHiddenLayerSize; ++i){
        mBuf.at(i) = output * mWeight.at(i);
    }
    mOutput.at(1)  = mHiddenLayer.calc(mBuf);
    //出力層の計算
    mBuf.at(0) = mOutput.at(1) * mWeight.at(3);
    mOutput.at(2)  = mOutputLayer.calc(mBuf);

    return mOutput.at(2);
}

void NeuralNet::backPropagation(double err)
{
    //出力層の学習
    outputLayerLearn(err);
    //中間層の学習
    hiddenLayerLearn(err);
}

void NeuralNet::outputLayerLearn(double e)
{
    double o = mOutput.back()[0]; //ニューラルネットの最終出力
    double d = e * o * (1 - o);
    for( int i=0; i<mHiddenLayerSize; ++i ){
        mWeight.at(3)[i] = mWeight.at(3)[i] + mAlpha * mOutput.at(1)[i] * d;
    }
    double threshold = mAlpha * (-1.0) * d;
    mOutputLayer.updataNeuron(0, threshold);
}

void NeuralNet::hiddenLayerLearn(double e)
{
    double o = mOutput.back()[0];
    for(int i=0; i<mHiddenLayerSize; ++i){
        double hi = mOutput.at(1)[i]; //中間層のi番目のニューロンの出力
        double d = hi * (1 - hi) * mWeight.at(3)[i] * e * o * (1 - o);
        for(int j=0; j<mInputLayerSize; ++j){
            mWeight.at(i)[j] = mWeight.at(i)[j] + mAlpha * mOutput.at(0)[j] * d;
        }
        double threshold = mAlpha * (-1.0) * d;
        mHiddenLayer.updataNeuron(i, threshold);
    }
}

double NeuralNet::error(double teacher, double output)
{
    return teacher - output;
}

void NeuralNet::initWeight()
{
    std::random_device seedGen;
    std::mt19937 engine(seedGen());
    std::uniform_real_distribution<double> dist(-1.0, 1.0);

    for(auto& valary : mWeight){
        for(auto& w : valary){
            w = dist(engine);
            std::cout << w << " ";
        }
        std::cout << std::endl;
    }
}
