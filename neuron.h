#pragma once

#include <valarray>
#include <iostream>

class Neuron 
{
public:
	Neuron(size_t s); //(�d�݂̌�)
	void update(double w[], double t);
    void input(double input[]);
	double calc(); //���͂��Čv�Z���o�͂���
private:
	size_t mSize;                       //�d�݂̌�
	std::valarray<double>   mWeight;    //�d��
	std::valarray<double>   mInput;     //���͒l
	double                  mThreshold;	//臒l
    
	double f(double u);	                //�`�B�֐�
    
    void setThreshold(double t);
	void setWeight(double ary[]);
};