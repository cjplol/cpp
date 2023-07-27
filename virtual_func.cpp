//面向对象：封装、继承、多态

#include<iostream>
using namespace std;
class A{
    public:
        void func1(){}
        void func2(){}
        virtual void vfunc(){
            cout<<"A类func"<<endl;
        }
        virtual void vfunc2(){}
        A(){
            cout<<"A构造函数"<<endl;
        }
        virtual ~A(){
            cout<<"A析构函数"<<endl;
        } //析构函数（Destructer），对象销毁时执行
    
    // private:
    //     int m_a;
    //     int m_b;
};

class B:public A{
    public:
        B(){
            cout<<"B构造函数"<<endl;
        }
        void vfunc(){
            cout<<"B类func"<<endl;
        }
};
int main(){
    // A a;
    // cout<<"size of a is: "<<sizeof(a)<<endl; //sizeof:字节数
    //B b;
    A *pa=new B(); //父类指针指向子类对象
    pa->vfunc();
    system("pause");
}