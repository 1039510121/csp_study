#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int N=1000000;
//int c,-c
int head[N];
int tot;
struct node{
    int to,next;
}edge[N<<1];
int n,m;
int color[N];
void init(){
    memset(head,-1,sizeof(head));
    tot=0;
}
void add(int u,int v){
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot;
    tot++;
}
bool DFS(int u,int c){
    color[u]=c;
    for(int i=head[u];i!=-1;i=edge[i].next){
        int v=edge[i].to;
        if(color[v]==c)return false;
        if(color[v]==0&&DFS(v,-c)==false)return false;
    }
    return true;
}
int main(){
    init();
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    for(int i=1;i<=n;i++){
        if(color[i]==0){


            if(DFS(i,1)==0){
                cout<<"no"<<endl;
                return 0;
            }
        }
    }

    cout<<"yes"<<endl;
    for(int i=1;i<=n;i++){
        cout<<i<<":"<<color[i]<<endl;
    }

}



/*
二分图


5
有奇数个点构成的环肯定不是二分图

if(n%2==1&&)






/*
int a[N];
int n,m;
int cnt=0;
int vis[N];
int num[N];
int main(){
	cin>>n>>m;
	int minn=INF;
	for(int i=1;i<=m;i++){
       cin>>num[i];
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	int ansl,ansr;
	for(int l=1,r=0;l<=n;){
		while(r<n&&cnt<m){
			r++;
			vis[a[r]]++;
			if(vis[a[r]]==num[a[r]])cnt++;
		}
		//cout<<cnt<<endl;
		if(cnt==m&&r-l+1<minn){
			minn=r-l+1;
			ansl=l;
			ansr=r;
		}
		vis[a[l]]--;
		if(vis[a[l]]==num[a[l]]-1)cnt--;
		l++;

	}
	cout<<ansl<<" "<<ansr<<endl;
}
/*
12 5
3 1 2 1 1
2 5 3 1 3 2 4 1 1 5 4 3
12 5
2 5 3 1 3 2 4 1 1 5 4 3








/*
int mp[200][200];
int dis[N];
int vis[N];
int n;
void BFS(int u,int flag){
	memset(vis,0,sizeof(vis));
	queue<int>q;
	q.push(u);
	vis[u]=1;
	dis[u]=0;
	while(q.empty()==0){
		u=q.front();
		q.pop();
		for(int i=1;i<=n;i++){
			if(mp[u][i]==flag&&u!=i&&vis[i]){
				dis[i]=dis[u]+1;
				q.push(i);
				vis[i]=1;
			}
		}
	}
	return;
}
BFS(1,1);
BFS(1,0);




mp[i][j]=1

mp[i][j]=0;




原图


补图
BFS DFS Dijkstra Spfa


int mp[100][100];

mp[i][j]=1 原图

mp[i][j]=0 补图


1 2
1 3

for(int i=1;i<=n;i++){
	for(int j=i+1;j<=n;j++){
		if(mp[i][j]==1||mp[j][i]==1){
			continue;
		}
		add(i,j);
		add(j,i);
	}
}


2 3

*/
