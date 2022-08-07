#include<iostream>
#include<cstring>
using namespace std;
const int N=2000005;
const int INF=0x3f3f3f3f;
int n;
int a[N];
int ans=-INF;
void DFS(int x,int maxx){
    //cout<<maxx<<endl;
    ans=max(ans,maxx);
    if(x>=n)return;
    if(maxx<0){
        DFS(x+1,a[x+1]);
    }else{
        DFS(x+1,a[x+1]+maxx);
    }
}
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    DFS(1,a[1]);
    cout<<ans<<endl;
}


/*
子串 连续
子序列 可以不连续 但是位序要递增

最长上升子序列 a[i]<a[j] i<j  

/*
7
-2 5 -3 -1 -2 -4 -3



/*
int a[N][N];
int dp[N][N];
int r;
int DFS(int x,int y)
{
	if(x==r)return dp[x][y]=a[x][y];
	if(dp[x][y]!=-1)return dp[x][y];
	return dp[x][y]=max(DFS(x+1,y),DFS(x+1,y+1))+a[x][y];
}
int main()
{
    memset(dp,-1,sizeof(dp));
	cin>>r;
	for(int i=1;i<=r;i++){
		for(int j=1;j<=i;j++){
			cin>>a[i][j];
        }
    }
    //dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+a[i][j]
    for(int i=r;i>=1;i--){
        for(int j=1;j<=i;j++){
            if(i==r)dp[i][j]=a[i][j];
            else{
                dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+a[i][j];
            }
        }
    }
    int ans=0;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=r;i++){
        for(int j=1;j<=i;j++){
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+a[i][j];
        }
    }
    for(int j=1;j<=r;j++){
        ans=max(ans,dp[r][j]);
    }
    cout<<ans<<endl;
    // for(int i=1;i<=r;i++){
	// 	for(int j=1;j<=i;j++){
	// 		dp[i][j]+=max(a[i+1][j+1],a[i+1][j]);
	// 	}
	// }
	//cout<<dp[1][1]<<endl;
}


/*
int DFS(int x,int y)
{
	if(x==r)return dp[x][y]=a[x][y];
	if(dp[x][y])return dp[x][y];
	return dp[x][y]=max(DFS(x+1,y),DFS(x+1,y+1))+a[x][y];
}
*/