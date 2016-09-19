#pragma once

#include "neuron.h"
#include <vector>
#include <valarray>

//コンストラクタでセルの数とどの層かを指定して、
//calc(入力)でneuralnetの配列に計算結果を出力する。
class layer
{
public:
    layer(size_t n=1, int m=1); //n:ニューロンの数　m==0:入力層　m==1:中間層
    void  init(size_t n, int m);
    std::valarray<double>& calc(const std::vector< std::valarray<double> >& input);
    void  status();
    void  updataNeuron(size_t no, double thr);
private:
    std::valarray<double>    mOutput;
    std::vector<Neuron>      mLayer;
    size_t                   mLayerSize;
    int                      mMode;
};
