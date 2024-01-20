#include"Menu.h"
#include"Manager.h"
#include"Goods.h"
#include<iostream>
#include<string>
#include<fstream>
#include"NMemFunc.h"
using namespace std;
    //显示主菜单
    void menu::ShowInfo()
    {
        cout<<"*****************************************************\n";
        cout<<"*****************************************************\n";
        cout<<"***********                               ***********\n";
        cout<<"***********   东秦味道自主咖啡奶茶机系统  ***********\n";
        cout<<"***********   1  购买入口                 ***********\n";
        cout<<"***********   2  管理入口                 ***********\n";
        cout<<"***********   0  退出系统                 ***********\n";
        cout<<"***********                               ***********\n";
        cout<<"*****************************************************\n";
        cout<<"*****************************************************\n";
        cout<<"请输入您的选择：\n";

    }
    //显示经营者菜单


    //1\显示经营者登录和注册界面

    void menu::ShowManagerMenu1()
    {
        //注册账号和密码
        cout<<"1、没有账号，注册账号\n";
        cout<<"2、已有账号，直接登录\n";
        cout<<"0、退出注册，返回主界面\n";
        cout<<"请输入您的选择：\n";
    }


void tongjishumu()
{

    int n = CalculateGoodsFileLen();
    int cnt = 0;
    if(n>0)
    {
        goods Goods[n];
        ifstream ifs("goods.txt",ios::in);

        for(int i=0;i<n;i++)
        {
            ifs>>Goods[i].num>>Goods[i].name>>Goods[i].price;
            //cout<<Goods[i].num<<Goods[i].name<<Goods[i].price;
        }
        ifs.close();
        string buff;
        cout<<"请输入您想要查询的饮品名称：\n";
        cin>>buff;
        for(int i = 0;i < n;i++)
        {
            if(buff==Goods[i].name)
                    cnt++;
        }
        if(cnt!=0)
            cout<<"名称为："<<buff<<" 的饮品的数量是： "<<cnt<<endl;
        else
            cout<<"货架上还没有该商品呢！\n";
    }
        else
            cout<<"货架一件商品都没有，快去补货吧！\n";
}
float sumprice()
{
    int n = CalculateGoodsInfoFileLen();
    goods Goods[n];
    float sum = 0;
    ifstream ifs("goodsinfo.txt",ios::in);
    for(int i=0;i<n;i++)

    {

        ifs>>Goods[i].num>>Goods[i].price>>Goods[i].buytime;
        //cout<<Goods[i].num<<Goods[i].name<<Goods[i].price;
        sum+=Goods[i].price;

    }
    ifs.close();
    return sum;
}
//2\显示经营者登录成功后界面
void menu::ShowManagerMenu2()
{
    menu mm;
    while(true)
    {

        //添加商品
     ///cout<<"登陆成功，欢迎您！\n";
        cout<<"1、查询所有饮品信息\n";                       //直接输出
        cout<<"2、按饮品名称统计改饮品个数\n";               //直接输出
        cout<<"3、添加饮品\n";                               //添加饮品菜单
        cout<<"4、查询所有购买记录\n";                       //直接输出
        cout<<"5、统计当日营业额\n";                           //直接输出
        cout<<"输入其他数字返回主界面\n";                           //直接输出
        cout<<"请输入您的选择：\n";

        int choice3;
        //int flag = -1;
            cin>>choice3;
            {
                if(choice3==1)               //显示所有商品信息
                {

                    manager man;
                    ///man.ShowGoods();
                    ifstream ifs("goods.txt",ios::in);

                    string buff;
                    int n = CalculateGoodsFileLen();
                    if(n>0)
                    {
                    while(getline(ifs , buff))
                    {
                        cout<<buff<<endl;
                    }

                    }
                    else cout<<"没货了，快去进货吧老板!\n";
                    system("pause");
                    system("cls");

                   // flag = 1;
                    continue;
                }
                if(choice3==2)                 //输出饮品个数
                {

                    tongjishumu();
                    system("pause");
                    system("cls");
                    //flag = 1;
                    continue;
                }
                if(choice3==3)                //添加饮品
                {
                    mm.ShowManagerMenu2_3();

                    //flag = 1;
                    continue;
                }
                if(choice3==4)                 //输出所有购买记录
                {
                    ifstream ifs("goodsinfo.txt",ios::in);

                    string buff;
                    int n = CalculateGoodsInfoFileLen();
                    if(n>0)
                    {
                    while(getline(ifs , buff))
                    {
                        cout<<buff<<endl;
                    }

                    system("pause");
                    system("cls");
                    }
                    else
                    {
                        cout<<"今天还没有购买记录呢！\n";
                        system("pause");
                        system("cls");

                    }
                    //flag = 1;
                    continue;
                }
                if(choice3==5)                 //输出当日营业额
                {
                    float sum=sumprice();
                    cout<<"今天的营业额为："<<sum<<" 元 "<<endl;
                    system("pause");
                    system("cls");

                    //flag = 1;
                    continue;
                }

            }
//            if(flag==-1)
//                    {
//                        //system("pause");
//                        //system("cls");
//                        //break;
//                        return;
//                        //goto FLAG;
//                    }
            return;


    }
}
        //登陆成功后xuan

    //显示消费者菜单
    void menu::ShowConsumerMenu()
    {
        //显示所有goods的信息

        manager man;
        man.ShowGoods();
//        cout<<"请根据编号选择您中意的商品：\n";
//        int number;
//        cin>>number;
//        cout<<"欢迎下次光临\n";
        //删除文件中的商品
        //cutout(Goods ,number);
    }
        //添加饮品菜单

    void menu::ShowManagerMenu2_3()
    {
            system("cls");
            goods goo;
            cout<<"请输入您要添加的饮品名称和价格\n";
            cin>>goo;
            goo.Save1();
            //goo.Read( & goo,1);
            cout<<"成功添加饮料\n";
            system("pause");

    }
