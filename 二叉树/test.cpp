


#include <iostream> 
using namespace std;
// #include<stdio.h>   

  
int f0(int x,int y){return x+y;} 

int f1(int x,int y){return x-y;} 

int f2(int x,int y){return x*y;} 

int f3(int x,int y){return x/y;} 

  

// int (*pfunc_array[4])(int,int); 

// pfunc_array[4] = {f0,f1,f2,f3}; 

  

// 用关键字typedef定义 函数指针类型 pType 

//typedef int (*pType)(int,int);         

  

// 声明一维数组，元素初始化为四个 pType函数指针  

int (*pfunc_array[4])(int,int) = {f0,f1,f2,f3};     

  

int main() 

{ 

    int a,b; 

    std::cin>>a>>b; 

    for(int i = 0; i < 4; ++i) 

    { 

        std::cout<<pfunc_array[i](a,b)<<std::endl; 

    } 

    return 0; 

}  


