#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int N=1000;
二分图





/*
for(int i=1;i<=m;i++){
	int u,v;
	cin>>u>>v;
	mp[u][v]=mp[v][u]=1;
}

void DFS(int u){
	for(int i=1;i<=n;i++){
		if(mp[u][i]==1){
			dfs(mp[u][i]);
		}
	}
}

for(int i=1;i<=10;i++){
	for(int j=i+1;j<=10;j++){
		if(mp[i][j]==0){
			mp[i][j]=mp[j][i]=0;
		}
	}
}
void DFS(int u){
	for(int i=1;i<=n;i++){
		if(mp[u][i]==0){
			dfs(mp[u][i]);
		}
	}
}

/*
//前向星
u-->v w
mp[u][v]=w;
mp[u][v]=1;
int mp[N][N];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		mp[u][v]=mp[v][u]=1;
	}
}
mp[u][v]=1;

mp[u][v]=0;


1.内存限制
2.访问当前点的邻点
前向星
for(int i=head[u];i!=-1;i=edge[i].next){
	int v=edge[i].to;
}
二维数组
int u;
for(int i=1;i<=n;i++){
	if(mp[u][i]){
		int v=mp[u][i];
	}
}

/*
补图
1. 完全图
任意两点都有边
n --->n*(n-1)/2

2. 补图 
完全图-当前图



/*
int head1[N],head2[N];
int tot1,tot2;
1.如何构两个图
n m 
for(int i=1;i<=m;i++){
	int u,v;
	cin>>u>>v;
	add(u,v)
	vis[u][v]=1;
	vis[v][u]=1;
}


for(int i=1;i<=10;i++){
	for(int j=i+1;j<=10;j++){
		if(vis[i][j]==0){
			add(i,j);
		}
	}
}

*/