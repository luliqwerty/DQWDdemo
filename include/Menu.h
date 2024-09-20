#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
//菜单/界面类
class menu
{
public:
    //显示主菜单
    virtual void ShowInfo();

    //显示经营者登录和注册界面

    void ShowManagerMenu1();

    //显示经营者登录成功后界面和实现所有的功能
    void ShowManagerMenu2();

    //显示消费者界面
    void ShowConsumerMenu();

    //实现经营者添加goods的界面和功能
    void ShowManagerMenu2_3();

};

#endif // MENU_H_INCLUDED
