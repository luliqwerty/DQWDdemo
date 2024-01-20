#include<iostream>
#include<fstream>
#include"Manager.h"
#include"NMemFunc.h"
#include"GoodsInfo.h"
using namespace std;
//获取用户名
string manager::GetUsername()
{
    return username;
}

//获取密码
string manager::GetPassward()
{
    return passward;
}

manager::manager(string user , string pass)
{
    username=user;
    passward=pass;
}

manager::manager()
{

}

    //保存文件
    void manager::Save()//包括 goods 的保存和 manager 的保存
    {
        ofstream ofs("account.txt",ios::out|ios::app);
        ofs<<this->username<<" "<<this->passward<<endl;
        //cout<<ofs.rdbuf()<<endl;
        ofs.close();
    }
    //读取文件
    //template<typename T>
    void manager::Read(manager * man , int n)//包括 goods 的读取和 manager 的读取
    {
        for(int i= 0;i< n;i++)
        {
            ifstream ifs("account.txt",ios::in);
            ifs>>man[i].username>>man[i].passward;
            ifs.close();
        }
    }

//注册账号
void manager::SignUp()
{
    string a,b;
    cout<<"注册：\n请输入您的账号：\n";
    cin>>a;
    cout<<"请输入您的密码：\n";
    cin>>b;
    manager man(a,b);
    man.Save();
//    systemManager * p = new manager (a,b);
//    p->Save();
}



bool operator ==( manager  man , manager ma)
{
    return (ma.GetUsername()==man.GetUsername()&&ma.GetPassward()==man.GetPassward());
}

//登录
bool  manager::LogIn()
{
    int n=CalculateManagerFileLen();
//   cout<<n;
    //this->Read( man , n);
if(n>0)
{
    manager man[n];
    cout<<"登录：\n请输入您的账号：\n";
    string a;
    cin>>a;
    cout<<"请输入您的密码：\n";
    string b;
    cin>>b;
//    manager  m (a,b);
    ifstream ifs("account.txt",ios::in);
//    ifstream ifs("goods.txt",ios::in);
//        if(!ifs.is_open())
//        {
//            ofstream ofs("goods.txt");
//        }
        for(int i=0;i<n;i++)
        {

            //ifs>>man[i].num>>Goods[i].name>>Goods[i].price;
            //cout<<Goods[i].num<<Goods[i].name<<Goods[i].price;
            ifs>>man[i].username>>man[i].passward;
        }
        ifs.close();

    for(int i= 0;i<=n;i++)
    {
        if(a==man[i].GetUsername()&&b==man[i].GetPassward())
        {
            cout<<"欢迎进入经营者系统\n";
            system("pause");
            system("cls");

            return true;
        }
    }
}
    cout<<"后台还没存储账户，请您先注册!\n";
    return false;
    //return false ;

}

void manager::ShowInfo()
{

}
//查询信息  继承来自goods的ShowGoods（）

//查询购买记录 继承来自goods的ShowInfo（）；

