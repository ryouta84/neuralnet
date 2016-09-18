#pragma once

#include "neuron.h"
#include "data.h"
#include <vector>

class NeuralNet
{
public:
            NeuralNet(const std::string filename);
    void    start();
    double  input(double ary[]);
private:
    double  err(double& output);            //教師データと出力から誤差を求める
    void    init();                         //ニューラルネットの初期化

    std::vector< std::vector<double> > mInputLayer;//入力層
    size_t                        mInputSize;      //教師データの個数
    void initInputLayer();                            //入力層の初期化

    std::vector< Neuron >         mHiddenLayer;       //中間層
    size_t                        mHiddenLayerSize;   //中間層のニューロンの個数
    void initHiddenLayer();                           //中間層の初期化

    std::vector< Neuron >         mOutputLayer;       //出力層
    size_t                        mOutputLayerSize;   //出力層の個数
    void initOutputLayer();                           //出力層の初期化

    Data<double>                  mData;              //学習データセット
    double                        limit;              //誤差の上限
    size_t                        count;              //学習回数

};
