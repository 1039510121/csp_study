#include<stdio.h>
int main(){
    for(int i=1;i<=10;i=i+2)
        printf("%d\n",i);
    int score=100;
    if(score<=100&&score>=90){
        printf("perfect");
    }else if(score<90&&score>=80){
        printf("good");
    }else{
        printf("mid");
    }
}
/*
1.语法
2. 输入，输出
3. 逻辑
//1. 语言 英语  语法
*/


<1> 输入两个未知数 x ,y
输出 x*x+y*y
<2> 输出0-100所以的质数
<3> 输入两个未知数 x ,y, 输出 x,y的最大公约数 最小公倍数


1 x
[2,x)
5/3=1
5%3=2
for(int i=2;i<x;i++){
    if(x/i==0){

    }
}

x y 最大公约数

if(y%x==0)

[1,min(x,y)]
for(int i=1;i<=min(x,y);i++){
    
}

x, y 最小公倍数
gcd(x,y)
xx=x/gcd(x,y)
yy=y/gcd(x,y)
gcd(x,y)*xx*yy
=x*y/gcd(x,y)
lcm(x,y)=x*y/gcd(x,y);



大一上 acm参加
大一下 4级 

大二上 6级
大二下
2-3  5%

大三上 
大三下 




