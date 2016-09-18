#pragma once

#include <cmath>
#include <valarray>
#include <iostream>

class Neuron
{
public:
                Neuron(size_t s);        //(重みの個数)
    void        update(double w[], double t);
    double      output(double input[]);  //計算して出力
private:
    size_t                  mSize;      //重み(入力)の個数
    std::valarray<double>   mWeight;    //重み
    double                  mThreshold; //閾値

    double      f(double u);            //出力関数
    void        setThreshold(double t);
    void        setWeight(double ary[]);
};
