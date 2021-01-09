#include<iostream>

using namespace std;

class A
{
private:
    int a,b;
public:
    A(int a,int b){
        this->a = a;
        this->b = b;
        cout<<"A 构造"<<endl;
    }
    void display(){
        cout<<a<<endl;
        cout<<b<<endl;
    }
};

class B:public A{
private:
    int c,d;
public:
    B(int c,int d):A(7,4){
        this->c = c;
        this->d = d;
        cout<<"B 构造"<<endl;
    }
    void display(){
        cout<<c<<endl;
        cout<<d<<endl;
    }
};

class C:public B{
private:
    int e,f;
public:
    C():B(5,6){
        e = 10;
        f = 20;
    }
};

int main(){
    A a(1,2);
    a.display();
    B b(3,4);
    b.display();
    C c;
    c.display();
    return 0;
}