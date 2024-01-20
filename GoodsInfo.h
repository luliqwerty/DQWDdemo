
#ifndef GOODSINFO_H_INCLUDED
#define GOODSINFO_H_INCLUDED

#include"Goods.h"
#include<string>
using namespace std;

class goodsinfo : public goods
{
    string buytime;
public:
    //构造函数产生购买时间
    //void ShowInfo();
    goodsinfo();

    ///储存购买记录
    void Save();

    ///经营者读取文件中的购买记录
    void Read( goodsinfo * info ,int n);
};

#endif // GOODSINFO_H_INCLUDED
