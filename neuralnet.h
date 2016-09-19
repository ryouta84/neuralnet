#pragma once

#include "layer.h"
#include "data.h"
#include <random>
#include <vector>

class NeuralNet
{
public:
            NeuralNet(const std::string filename);
    void    start();
    std::valarray<double>& forward(std::valarray<double>& input);   //入力層から出力層方向に計算
private:
    void    backPropagation(double err);          //学習
    void    outputLayerLearn(double e);
    void    hiddenLayerLearn(double e);
    double  error(double teacher, double output);
    void    initWeight();               //重みをランダムに初期化

    size_t          mInputLayerSize;    //入力層のニューロンの個数
    size_t          mHiddenLayerSize;   //中間層のニューロンの個数
    size_t          mOutputLayerSize;   //出力層ニューロンの個数

    layer           mInputLayer;        //入力層

    layer           mHiddenLayer;       //中間層

    layer           mOutputLayer;       //出力層

    std::vector< std::valarray<double> > mOutput;
    std::vector< std::valarray<double> > mWeight; //中間層以降の重みを保存する
    std::vector< std::valarray<double> > mBuf;

    Data<double>    mData;              //学習データセット
    double          mLimit;              //誤差の上限
    double          mAlpha;
    size_t          mLayerNum;
    uint64_t        mCount;              //学習回数

};
