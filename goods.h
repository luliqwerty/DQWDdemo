
#ifndef GOODS_H_INCLUDED
#define GOODS_H_INCLUDED
#include<string>
#include<iostream>
using namespace std;
#include"Menu.h"

//商品类   继承自systemManager
class goods : public menu///: public systemManager
{
private:
    //编号
    int num;
    //名称
    string name;
    //价格
    float price;
    string buytime;

public:
    goods();


    //显示购买信息  编号 名称 购买时间（怎么把这个时间读到文件中还不会啊）
    void ShowInfo();

    //显示商品信息  输出编号 名称 价格
    void ShowGoods();

//添加商品

    friend void tongjishumu();
    friend float sumprice();

    //用于添加的构造函数
    goods(string na,float pri);//编号随机生成还没找到解决办法

    friend istream & operator>>(istream & cin , goods & g);

    friend ostream & operator<<(ostream & cout , goods & g);
    //保存文件
    void Save1();//包括 goods 的保存

    void Save2();///顾客购买后删除该商品后的读取

    //读取文件
    void Read(goods * Goods ,int n);//包括 goods 的读取

    //删除文件中的商品并重置所有的编号
    bool cutout(goods * Goods ,int n,int number);



};

#endif // GOODS_H_INCLUDED
