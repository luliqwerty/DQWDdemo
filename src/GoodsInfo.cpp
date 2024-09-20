#include<iostream>
#include<fstream>
#include<ctime>
#include<string>
using namespace std;
#include"GoodsInfo.h"
    //构造函数产生购买时间

    goodsinfo ::goodsinfo()
    {
        time_t nowtime;
        time (&nowtime);
        tm *p = localtime(& nowtime);
        buytime = to_string(p->tm_year + 1900) + ":" + to_string(p->tm_mon + 1) +":" +to_string(p->tm_mday) + to_string(p->tm_hour)+ to_string(p->tm_min)+ to_string(p->tm_sec);
         cout<<buytime<<endl;
    }

//    goods::ShowInfo()
//    {
//
//    }
    ///储存购买记录
    void goodsinfo::Save()
    {

    }

    ///经营者读取文件中的购买记录
    void goodsinfo::Read( goodsinfo * info ,int n)
    {

    }
