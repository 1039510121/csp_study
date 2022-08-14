#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int N=1000000;
typedef long long ll;
2. 二分图




/*
int vis[N];
int prime[N];
//o(n*loglog(n))
void init_prime1(){
    int tot=0;
    for(int i=2;i<N;i++){
        if(vis[i]==0)prime[++tot]=i;
        for(int j=1ll*i*i;j<N;j=j+i){
            vis[j]=1;
        }
    }
}
//欧拉筛
void init_prime2(){
    int tot=0;
    for(int i=2;i<N;i++){
        if(vis[i]==0){
            prime[++tot]=i;
            f[i]=2;
            cnt[i]=1;
        }
        for(int j=1;i*prime[j]<N&&j<=tot;j++){
            f[i*prime[j]]=f[i]*2;
            cnt[i*prime[j]]=cnt[i];
            vis[i*prime[j]]=1;
            if(i%prime[j]==0){
                f[i*prime[j]]=f[i]*(cnt[i]+2)/(cnt[i]+1);
                cnt[i*prime[j]]=cnt[i]+1;
                break;
            }
        }
    }
}

f[i]

欧拉函数

ph[i] [1,i-1]与i互质的个数

15 5
f(x): x的因子个数
输入一个n n<=1e5
求f(1)+f(2)+f(3)+f(4)+....+f(n); 普及-
1 1-n   n
2 1-n   n/2
3 1-n   n/3
4 1-n   n/4
int ans=0;
for(int i=1;i<=n;i++)ans=ans+n/i;

f(x): x的因子个数

i=a1^p1*a2^p2*a3^p3.....*am^pm
a1,a2,a3,a4....am 质数
18=2^1*3^2 18=1 2 3 6 9 18
9=3^2 1 3 9
2=2^1
排列组合
f(i)=(p1+1)*(p2+1)*(p3+1).....*(pm+1);

f(i)
i*prime[j];
1.
假设prime[j]为i的最小质因子 i%prime[j]==0;
prime[j]=a1
i*prime[j]=a1^(p1+1)*a2^p2*a3^p3.....*am^pm
i*prime[j]=(p1+2)*(p2+1)*(p3+1).....*(pm+1);
          =f(i)/(p1+1)*(p1+2);

f[i*prime[j]]=f(i)/(cnt[i]+1)*(cnt[i]+2);
cnt[i*prime[j]]=cnt[i]+1;
p1 i的最小质因子的个数
cnt[i];
2.
i%prime[j]!=0

i=a1^p1*a2^p2*a3^p3.....^am*pm
prime[j]=prime[j]^1
i*prime[j]=a1^p1*a2^p2*a3^p3.....*am^pm*prime[j]^1
          =(p1+1)*(p2+1)*(p3+1).....*(pm+1)*(1+1);
          =f(i)*2

f(i*prime[j])=f(i)*2

m 1e5
l r
f[i]==????
sum[i]=sum[i-1]+f[i];
sum[r]-sum[l-1];

5 7

1 1
2 2
3 2
4 3
5 2
6 4

