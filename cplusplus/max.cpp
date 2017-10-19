#include <iostream>
using namespace std;


int max(int a, int b)
{
	return (a>b?a:b);
}

int sum(int a, int b=20)
{
	int result;
	result = a + b;
	return (result);
}


int main (int argc, char * argv[])
{
   //局部变量声明
   int a = 100;
   int b = 200;
   int result;

   result = sum(a,b);//调用函数来添加值
   cout << "Total value is :" << result << endl;

   result = sum(a); //再次调用函数
   cout << "Total value is :" << result << endl;

   return 0;
}


// int main(int argc, char * argv[])
// {
// 	int a = 3,b = 5;
// 	cout << "Max is " << max(a,b) << endl;
// }

