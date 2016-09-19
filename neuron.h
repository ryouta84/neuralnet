#pragma once

#include <cmath>
#include <random>
#include <valarray>
#include <iostream>

class Neuron
{
public:
                Neuron(size_t s);           //入力の個数
    //入力と重みの積が計算済みの引数が渡される
    double      calc(const std::valarray<double>& input);
    void        updateThreshold(double thr);
private:
    double      f(double u);                //出力関数
    double      drnd();                     //乱数生成
    void        initNeuron();

    size_t      mSize;          //入力の個数
    double      mThreshold;     //閾値
};
