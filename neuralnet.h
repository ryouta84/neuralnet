#pragma once

#include "neuron.h"
#include "data.h"
#include <vector>

class NeuralNet
{
public:
	NeuralNet(const std::string filename);
	double start();
    
private:
	//std::vector< Neuron > mInputLayer;        //入力層
    std::vector<double>     mInputLayerVal;     //入力の値
	size_t                  mInputLayerSize;    //入力の個数
    void inputLayerSet();                       //入力層の設定
    
	std::vector< Neuron >   mHiddenLayer;       //中間層
    size_t                  mHiddenLayerSize;   //中間層のニューロンの個数
    void hiddenLayerSet();                       //中間層の設定
    
	std::vector< Neuron >   mOutputLayer;       //出力層
    
	Data<double>            mData;              //学習データセット
	
    
	
	void setNN();           //ニューラルネットの設定
};