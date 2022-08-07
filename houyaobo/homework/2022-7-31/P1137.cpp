#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n,m;
int tot;
int head[MAXN],in[MAXN],r[MAXN];
int f[MAXN];
struct Node{
	int next;
	int to;
	
}edge[MAXN<<2];
void add(int x,int y){
	edge[++tot].to=y;
	edge[tot].next=head[x];
	head[x]=tot;
	
} 
void init(){
	for(int i=1;i<=n;i++){
		f[i]=1;
	}
}
void topo(){
	tot=0;
	queue <int> q;
	for(int i=1;i<=n;i++){
		if(in[i]==0){
			q.push(i);
			r[++tot]=i;
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].to;
			in[v]--;
			if(in[v]==0) q.push(v),r[++tot]=v;
		}
	}
}
void topo2(){
	for(int i=1;i<=n;i++){
		int u=r[i];
		for(int j=head[u];j;j=edge[j].next){
			int v=edge[j].to;
			f[v]=max(f[v],f[u]+1);//¾¡¿ÉÄÜ¶à 
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		in[v]++;
	}
	topo();
	init();
	topo2();
	for(int i=1;i<=n;i++){
		printf("%d\n",f[i]);
	}
	return 0;
}

