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
	//std::vector< Neuron > mInputLayer;        //���͑w
    std::vector<double>     mInputLayerVal;     //���͂̒l
	size_t                  mInputLayerSize;    //���͂̌�
    void inputLayerSet();                       //���͑w�̐ݒ�
    
	std::vector< Neuron >   mHiddenLayer;       //���ԑw
    size_t                  mHiddenLayerSize;   //���ԑw�̃j���[�����̌�
    void hiddenLayerSet();                       //���ԑw�̐ݒ�
    
	std::vector< Neuron >   mOutputLayer;       //�o�͑w
    
	Data<double>            mData;              //�w�K�f�[�^�Z�b�g
	
    
	
	void setNN();           //�j���[�����l�b�g�̐ݒ�
};