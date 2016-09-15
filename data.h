#pragma once

#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <stdexcept>
/*
-----�g����-----
�R���X�g���N�^�Ɋw�K�f�[�^���������t�@�C���̖��O��n���B
getSet()��vector<vector>��n���΂���Ƀf�[�^���i�[�����A
*/
template <typename T> class Data
{
public:
	Data(const std::string name);
    auto& getData();
	void getData(std::vector< std::vector<T> >& vecRef);
	void getSet(T ary[], size_t no);
private:
	std::vector< std::vector<T> > mData;
	size_t setOfDataNo;                     //�f�[�^�̑g��
	size_t dataNo;                          //�f�[�^�̑���
};

template <typename T> Data<T>::Data(const std::string name) : setOfDataNo(0), dataNo(0)
{
	std::ifstream dataSet(name);
	if(!dataSet){
		std::cout << "�t�@�C�����J���܂���B" << std::endl;
	}
	
	std::string strBuf;
	while( std::getline(dataSet, strBuf) ){
		std::stringstream ss;
		ss << strBuf;
		++setOfDataNo;
		T data;
        std::vector<T> vecBuf;
		while( ss >> data ){
			vecBuf.push_back(data);
			++dataNo;
		}
        mData.push_back(vecBuf);
	}
}

template <typename T> auto& Data<T>::getData()
{
    return mData;
}

template <typename T> void Data<T>::getData(std::vector< std::vector<T> >& vecRef)
{
	try{
	for(int i=0; i<setOfDataNo; ++i){
        vecRef.push_back(mData.at(i));
	}
	} catch(std::out_of_range& ex) {
		std::cerr << "out of range: " << ex.what () << std::endl;
	}
}
template <typename T> void Data<T>::getSet(T ary[], size_t no)
{
	size_t pos = no * (dataNo/setOfDataNo);
	try{
	for(int i=0; i<dataNo/setOfDataNo; ++i){
		ary[i] = mData.at(pos);
		++pos;
	}
	} catch(std::out_of_range& ex) {
		std::cerr << "out of range: " << ex.what () << std::endl;
	}
}