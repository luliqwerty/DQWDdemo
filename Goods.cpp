#include<iostream>
#include<ctime>
#include<string>
#include<fstream>
#include<iomanip>
#include"NMemFunc.h"
#include"Goods.h"
///#include<random>
using namespace std;

goods::goods()
{
//        random_device r;
//        mt19937 e(r());
//        uniform_int_distribution<int> dis(100001,110000);
        //default_random_engine e(r());
        srand((unsigned int)time(NULL));
        num = rand()% 110000+100000;

}

istream & operator>>(istream & cin , goods & g)
{
    cin>>g.name>>g.price;
    return cin;
}
ostream & operator<<(ostream & cout , goods & g)
{
    cout<<g.num<<" "<<g.name<<" "<<g.price<<endl;
    return cout;
}

//显示购买信息  编号 名称 购买时间（怎么把这个时间读到文件中还不会啊）
void goods::ShowInfo()
{

}

//显示商品信息  输出编号 名称 价格
void goods::ShowGoods()
{


    ifstream ifs("goods.txt",ios::in);
    string buff;
    int n = CalculateGoodsFileLen();
    if(n>0)
    {
        while(getline(ifs , buff))
        {
            cout<<buff<<endl;
        }
        //system("pause");
        while(true)
        {
            cout<<"请根据编号选择您中意的商品或者输入0退出购买：\n";
            int number;
            cin>>number;
        ///
            if(number == 0)
            {
                system("pause");
                system("cls");
                return;
            }
            goods Goods[n];
            Goods[0].Read(Goods , n);
//            systemManager * p = new manager;
//            p->GoodsAccount =n;

            if(number != 0)
            {
                if(Goods[0].cutout(Goods , n , number))
                {
//                    cout<<"欢迎下次光临\n";
                    break;
                }
                else
                    continue;
            }
        }
    }
    else
    {
        cout<<"抱意思哦，小的还没补货，请下次再来吧!\n";
        system("pause");
        system("cls");
    }
}




//用于添加的构造函数
goods::goods(string na,float pri)
{
        //计算文件中商品数目 n
        //num=n;
//        unsigned seed;
//        srand(seed);
//        seed=time(0);

///        srand((unsigned)time(nullptr));
//        ///num=CalculateGoodsFileLen() + 1000;

//

//        unsigned seed;
//        srand((unsigned int)time(NULL));
       //srand(unsigned int seed);
       //srand(seed(0));
       //num= CalculateGoodsFileLen() + 10000;

        name = na;
        price = pri;
}

    //保存文件  一件商品
    void goods::Save1()         //goods 的保存
    {
        ofstream ofs("goods.txt",ios::out|ios::app);
        ofs<<left<<setw(10)<<num<<setw(15)<<left<<name<<setw(10)<<left<<price<<endl;
        ofs.close();
    }
    void goods::Save2()         //goods 的保存
    {
        ofstream ofs("goods.txt",ios::out|ios::trunc);
        ofs<<left<<setw(10)<<num<<setw(15)<<left<<name<<setw(10)<<left<<price<<endl;
        ofs.close();
    }
    //读取文件
    void goods::Read(goods * Goods , int n )// goods 的读取 Goods 必须n+1长度
    {

        ifstream ifs("goods.txt",ios::in);
//        if(!ifs.is_open())
//        {
//            ofstream ofs("goods.txt");
//        }
        for(int i=0;i<n;i++)
        {

            ifs>>Goods[i].num>>Goods[i].name>>Goods[i].price;
            //cout<<Goods[i].num<<Goods[i].name<<Goods[i].price;


        }
        ifs.close();
    }


//string to_string(int a)
//{
//	char count=0,b[100];
//	while(a!=0)
//	{
//		b[count]=a%10+'0';
//		a=a/10;
//		count++;
//	}
//	char c[100],i,j;
//	i=count-1;
//	j=0;
//	for(j;j<count;j++)
//	{
//		c[j]=b[i];
//		i--;
//	}
//	c[j]='\0';
//	return c;
//}

    //删除文件中被购买的的商品
    bool goods::cutout(goods * Goods ,int n,int number)
    {
        this->Read(Goods ,n);
        int flag = 1;
            ofstream ofs("goods.txt",ios::trunc);
            ofs.close();
            for(int i=0;i<n;i++)
            {

            if(Goods[i].num == number)
            {
                flag = 2;
                time_t nowtime;
                time (&nowtime);
                tm * p=localtime(& nowtime);
                Goods[i].buytime = to_string(p->tm_year + 1900) + "-" + to_string(p->tm_mon + 1) +"-" + to_string(p->tm_mday)
                +" "+ to_string(p->tm_hour)+ ":"+to_string(p->tm_min)+ ":"+to_string(p->tm_sec);
                cout<<left<<setw(10)<<Goods[i].num<<left<<setw(7)<<Goods[i].price<<left<<setw(20)<<Goods[i].buytime<<endl;
                cout<<"欢迎下次光临,按任意键返回主界面\n";
                ofstream ofs1("goodsinfo.txt",ios::out|ios::app);
                ofs1<<left<<setw(10)<<Goods[i].num<<left<<setw(7)<<Goods[i].price<<left<<setw(20)<<Goods[i].buytime<<endl;
                ofs.close();
                system("pause");
                system("cls");
                return true;
            }
            else
                {
                    Goods[i].Save1();
                }
            }
            if(flag==1)
                {
                            cout<<"输入有误\n";
                            system("pause");
                }
                    return false;

    }

//            else
//                ofstream ofs("goods.txt",ios::trunc);
//                ofs.close();
//                {
//                    cout<<
//                    Goods[i].Save1();
//                }
//
//
//
//            }
//            if(flag==1)
//                {
//                    ifstream ifs("goods.txt",ios::in);
//                    string buff;
//                    while(getline(ifs , buff))
//                        {
//                            cout<<buff<<endl;
//                        }
//                            cout<<"输入有误\n";
//                            system("pause");
//                            system("cls");
//                }
//
//                    return false;

//    }

