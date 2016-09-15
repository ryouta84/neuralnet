#pragma once

#include <valarray>
#include <iostream>

class Neuron 
{
public:
	Neuron(size_t s); //(重みの個数)
	void update(double w[], double t);
    void input(double input[]);
	double calc(); //入力して計算し出力する
private:
	size_t mSize;                       //重みの個数
	std::valarray<double>   mWeight;    //重み
	std::valarray<double>   mInput;     //入力値
	double                  mThreshold;	//閾値
    
	double f(double u);	                //伝達関数
    
    void setThreshold(double t);
	void setWeight(double ary[]);
};