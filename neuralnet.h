#pragma once

#include "neuron.h"
#include "data.h"
#include <random>
#include <vector>

class NeuralNet
{
public:
    NeuralNet(const std::string filename);
    void start();

private:
    std::vector< std::vector<double> > mInputLayer;//入力層の値
    size_t                        mInputLayerSize;    //入力の個数
    void initInputLayer();                            //入力層の設定

    std::vector< Neuron >         mHiddenLayer;       //中間層
    size_t                        mHiddenLayerSize;   //中間層のニューロンの個数
    void initHiddenLayer();                           //中間層の初期化
    void hiddenOutput();
    std::vector<double>           mHidResult;         //中間層の出力結果

    std::vector< Neuron >         mOutputLayer;       //出力層
    size_t                        mOutputLayerSize;   //出力層の個数
    void initOutputLayer();                           //出力層の設定
    void outputLayerOutput();
    std::vector<double>           mOutResult;         //出力層の出力結果

    Data<double>                  mData;              //学習データセット
    double                        limit;              //誤差の上限
    double                        alpha;
    size_t                        count;              //学習回数

    double  drnd();                         //乱数生成
    double  err(double& output);            //教師データと出力から誤差を求める
    void    backPropagation(double err);    //学習
    void    init();                         //ニューラルネットの初期化
};
