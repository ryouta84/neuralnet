#pragma once

#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <stdexcept>
/*
-----使い方-----
コンストラクタに学習データが入ったファイルの名前を渡す。
getSet()にvector<vector>を渡せばそれにデータが格納される、
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
	size_t setOfDataNo;                     //データの組数
	size_t dataNo;                          //データの総数
};

template <typename T> Data<T>::Data(const std::string name) : setOfDataNo(0), dataNo(0)
{
	std::ifstream dataSet(name);
	if(!dataSet){
		std::cout << "ファイルが開けません。" << std::endl;
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