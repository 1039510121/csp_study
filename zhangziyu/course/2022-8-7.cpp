#include<iostream>
#include<cstring>
using namespace std;
const int N=10005;
const int INF=0x3f3f3f3f;
int a[N];
int dp1[N],dp2[N];
int n;
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)cin>>a[i];
    //dp[i]=max(dp[j])+1 j<i&&a[i]>a[j]
    for(int i=1;i<=n;i++){
        dp1[i]=1;
        for(int j=1;j<i;j++){
            if(a[i]>a[j])dp1[i]=max(dp1[j]+1,dp1[i]);
        }
    }
    for(int i=n;i>=1;i--){
        dp2[i]=1;
        for(int j=i+1;j<=n;j++){
            if(a[i]>a[j]){
                dp2[i]=max(dp2[j]+1,dp2[i]);
            }
        }
    }
    for(int i=1;i<=n;i++){

        ans=max(ans,dp1[i]+dp2[i]-1);
    }
    cout<<n-ans<<endl;
}

/*
1. 如何求最长上升子序列
8
186   1
186 186  1
186 186 150  1
186 186 150 200  2
186 186 150 200 160 2
186 186 150 200 160 130 

186 186 150 200 160 130 197 220
1    1  1   2   2    1  3   4
            3   2    1   1   1

以i为结尾的最长上升子序列长度

dp[i]=max(dp[j])+1 i<j&&a[i]>a[j]s

x<160

/*
3 3 100

10 20 15   <1>
15 17 13   <2>

10   5
20   -3
15   -2


15 25 16   <3> 
100
15 0
17 8
13 3

i  i+1

*/