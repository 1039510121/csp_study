#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n,m;
struct Node{
	int next;
	int to;
	int dis;
}edge[MAXN<<1];
int in[MAXN];
int head[MAXN];
int ma[MAXN];
queue<int> q;
int tot=0;
void init(){
	memset(ma,-0x7f,sizeof(ma));
	tot=0;
}
void add(int u,int v,int d){
	edge[++tot].to=v;
	edge[tot].next=head[u];
	edge[tot].dis=d;
	head[u]=tot;
}
void Topo(){
	
	for(int i=1;i<=n;i++){
		if(!in[i]) q.push(i);
		if(i==1) ma[i]=0;
		else ma[i]=-MAXN;
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].to;
			in[v]--;
			ma[v]=max(ma[v],ma[u]+edge[i].dis);
			if(in[v]==0){
				q.push(v);
			}
		}
	}
}
int main(){
	init();
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v,d;
		scanf("%d%d%d",&u,&v,&d);
		add(u,v,d);
		in[v]++;
	}
	Topo();
	if(ma[n]<0){
		cout<<-1;
		return 0;
	}
	cout<<ma[n];
	return 0;
}
