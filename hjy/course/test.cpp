#include<stdio.h>
int f(int x){
    return x*x;
}
int main(){
    for(int i=1;i<=10;i=i+2){
        printf("%d\n",i);
    }
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