//#include <iostream>
#include"Menu.h"
//#include"SystemManager.h"
#include"Manager.h"
#include"Goods.h"
//#include"GoodsInfo.h"
#include"NMemFunc.h"
using namespace std;

enum struct choiceq
{
    zero = 0,one , two ,three ,four ,five ,six,seven,eight,nine
};

int main()
{
//菜单调试                                              对
    menu mm;
//    mm.ShowInfo();
//    mm.ShowConsumerMenu();
//    mm.ShowManagerMenu1();
//    mm.ShowManagerMenu2();
//对输入输出运算符重载的调试                            对
//    goods d;
//    cin>>d;
//    cout<<d;
//    d.Save();

//    goods Goods[3];
//    Goods[0].Read( Goods , 3);
//    cout<<Goods[2];
//    Goods[2].cutout(Goods ,3 , 126);
//    goodsinfo info;
    system("color C");

    ///编号设置
//    goods goo;
//    goo.Save();
//    int n = CalculateGoodsFileLen();
//    if(n>0)
//    {
//        goods Goods[n];
//        Goods[0].Read(Goods , n);
//        for(int i = 0;i<n;i++)
//        {
//
//        cout<<Goods[i]<<endl;
//        }
//
//    }
//    else cout<<"抱意思哦，小的还没补货，请下次再来吧\n";

    while(true)
    {

        mm.ShowInfo();
        int choice1;
        cin>>choice1;

        if(choice1 == int(choiceq::one))
        {
            mm.ShowConsumerMenu();
            continue;
            //break;
        }
        else if(choice1 == int(choiceq::two))
        {
            mm.ShowManagerMenu1();

            int choice2;
            cin>>choice2;
            if(choice2 == 1)
            {
               manager man;
               man.SignUp();
                if(man.LogIn()==true)
               {
                    mm.ShowManagerMenu2();
                    ;
                    ;


               }
               else
                    cout<<"账号或密码输入错误\n";
               continue;
            }
            else if(choice2 == 2)
            {
                manager man;
                if(CalculateManagerFileLen()>0)

                {
                if(man.LogIn()==true)
                {
                    mm.ShowManagerMenu2();
                    ;
                }

                //;
                else
                {
                    cout<<"账号或密码输入错误\n";
                    ;
                    ;
                    continue;
                }
                }
                else
                {
                    cout<<"抱歉，后台没检测到账户，请您先注册吧！\n";
                    ;
                    ;
                }

                //break;
            }
            else if(choice2 == 0)
            {
                ;
                continue;

            }
        }
        else if(choice1 == int(choiceq::zero))
        {
            cout<<"欢迎下次光临\n";
            return 0;
        }
        else
        {
            ;
            cout<<"输入有误\n";
            continue;

        }


    }
    return 0;
}
