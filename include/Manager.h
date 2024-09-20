#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED
#include<string>
using namespace std;
#include"Goods.h"
///class manager : public goods
class manager : public goods
{
private:
    //账号
    string username;

    //密码
    string passward;

public:
    //获取用户名
    string GetUsername();

    //获取密码
    string GetPassward();

    //注册账号
    void SignUp();

    void ShowInfo();
    manager();
    manager(string user , string pass);

    //登录
    bool LogIn();

    //用于判断账号和密码是否和文件中存储的相同
    friend bool operator==( const manager & man , const manager & ma);

    //查询信息  继承来自goods的ShowGoods（）

    //查询购买记录 继承来自goods的ShowInfo（）；


    //保存文件
    void Save();// manager 的保存

    //读取文件
    void Read(manager * man , int n);// manager 的读取

    /// 数组的尾插功能
    template<class T>
    void Push_back(T & t);

};

#endif // MANAGER_H_INCLUDED
