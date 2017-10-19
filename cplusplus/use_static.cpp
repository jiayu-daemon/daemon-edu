#include <iostream>
using namespace std;

class Data
{
public:
    Data(){}
    ~Data(){}
    void show(){
        cout<<this->data<<" "<<number<<endl;
    }

    static void showData(){//先于类的对象而存在
        cout<<" "<<number<<endl;//这方法调用的时候不包含this指针
    }

private:
    int data;
public:
    static int number; //静态数据在声明时候类外初始化
};


int Data::number=0;//静态成员初始化

void fn()
{
    static int n = 10;
    cout<<n<<endl;
    n++;
}


int main()
{
    // Data::showData();//通过类名直接调用
    // Data::number = 100;//通过类名直接使用
    // Data d;
    // d.show();
    // d.showData();//通过对象调用

    // cout << "Hello World!" << endl;
     fn();
     fn();
     fn();
    return 0;
}