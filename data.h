#pragma once

#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <stdexcept>
/*
-----使い方-----
コンストラクタに学習データが入ったファイルの名前を渡す。
getSet()にvector<vector>を渡せばそれにデータが格納される。
*/
template <typename T> class Data
{
public:
           Data(const std::string name);
    auto&  getData();
    void   getData(std::vector< std::vector<T> >& vecRef);
    void   getSet(std::vector<T>& vec, size_t no);
    size_t getSetsNo();
    size_t endIndex();  //１行の最後の添字（教師データを指す）
private:
    std::vector< std::vector<T> > mData;
    size_t                        setsNo;//教師データの数
    size_t                        dataNo;     //データの総数
};

template <typename T> Data<T>::Data(const std::string name) : setsNo(0), dataNo(0)
{
    std::ifstream dataSet(name);
    if(!dataSet){
        std::cout << "file is not open" << std::endl;
    }
std::cout << "---------------------DATA--------------------------" << std::endl;
    try{

    std::string strBuf;
    while( std::getline(dataSet, strBuf) ){
        std::stringstream ss;
        ss << strBuf;
        ++setsNo;
        T data;
        std::vector<T> vecBuf;
        while( ss >> data ){
            vecBuf.push_back(data);
            ++dataNo;
        }
        mData.push_back(vecBuf);
    }
    //表示
    for(auto i : mData){
        for(auto j : i){
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }

    }catch(std::out_of_range& ex) {
        std::cerr << "out of range : file reading" << ex.what () << std::endl;
    }
std::cout << "---------------------DATA--------------------------" << std::endl;
}

template <typename T> auto& Data<T>::getData()
{
    return mData;
}

template <typename T> void Data<T>::getData(std::vector< std::vector<T> >& vecRef)
{
    try{
    for(int i=0; i<setsNo; ++i){
        vecRef.push_back(mData.at(i));
    }
    } catch(std::out_of_range& ex) {
        std::cerr << "out of range!: " << ex.what () << std::endl;
    }
}
template <typename T> void Data<T>::getSet(std::vector<T>& vec, size_t index)
{
    try{
        vec = mData.at(index);
    } catch(std::out_of_range& ex) {
        std::cerr << "out of range!!: " << ex.what () << std::endl;
    }
}

template <typename T> size_t Data<T>::getSetsNo()
{
    return setsNo;
}
template <typename T> size_t Data<T>::endIndex()
{
    return dataNo/setsNo -1;
}
