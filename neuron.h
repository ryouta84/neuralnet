#pragma once

#include <cmath>
#include <random>
#include <valarray>
#include <iostream>

class Neuron
{
public:
                Neuron(size_t s);           //重み(入力)の個数
    double      calc(double input[]);//計算して出力
    void        hidNeuLearn(double err, double nextWeight);//中間層の学習
    void        outNeuLearn(double err);    //出力層の学習
    double      getWeight(size_t i);
private:
    double      f(double u);                //出力関数
    double      drnd();                     //乱数生成
    void        initNeuron();

    size_t                  mSize;          //重み(入力)の個数
    std::valarray<double>   mInput;         //入力
    std::valarray<double>   mWeight;        //結合の重み
    double                  mThreshold;     //閾値
    double                  mOutput;        //出力
    double                  alpha;
};
