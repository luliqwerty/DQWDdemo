#include"NMemFunc.h"
using namespace std;
#include<fstream>
#include<string>
#include<iostream>
///计算manager个数
int CalculateManagerFileLen()
{
    int n=0;
    ifstream ifs("account.txt",ios::in);
    string buff;
    while(getline(ifs , buff))
    {
        n++;
        ///cout<<buff;
    }
    ifs.close();
    return n;

}


///计算goods个数
int CalculateGoodsFileLen()
{
    ifstream ifs("goods.txt",ios::in);
    int n=0;
    string buff;
    while(getline(ifs , buff))
    {

        n++;
    }
    ifs.close();
    return n;
}

///计算购买记录的数目
int  CalculateGoodsInfoFileLen()
{
    ifstream ifs("goodsinfo.txt",ios::in);
    int n=0;
    string buff;
    while(getline(ifs , buff))
    {

        n++;
    }
    ifs.close();
    return n;
}
