#include <iostream>
using namespace std;

class Test1
{
public:
    Test1(int n){ //普通构造函数
        num=n;
    }
    void print_num(void){
        cout << num << endl;
    }
private:
    int num;
};


class Test2
{
public:
    explicit Test2(int n){ //explicit(显式)构造函数
        num = n;
    }
    void print_num(void){
        cout << num << endl;
    }
private:
    int num;
};


int main()
{

    Test1 t1 = 12;//隐式调用其构造函数,成功
    t1.print_num();
    //Test2 t2 = 12;//编译错误,不能隐式调用其构造函数
    Test2 t2(12);//显式调用成功
    t2.print_num();
    return 0;
}