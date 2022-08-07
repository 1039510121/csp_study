#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
const int INF=0x7fffffff;
int s[MAXN];
struct Node{
	int next;
	int to;
	int dis;
}edge[MAXN];
int head[MAXN];
int in[MAXN];
int n,m,c;
int tot=0;
queue <int> q;
void add(int a,int b,int x){
	edge[++tot].next=head[a];
	edge[tot].to=b;
	edge[tot].dis=x;
	head[a]=tot;
}
void init(){
	memset(head,0,sizeof(head));
	tot=0;
}
void topo(){
	
	for(int i=1;i<=n;i++){
		if(!in[i]) q.push(i);
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].to;
			in[v]--;
			s[v]=max(s[v],s[u]+edge[i].dis);
			if(!in[v]) q.push(v);
		}
	}
}
int main(){
	init();
	cin>>n>>m>>c;
	for(int i=1;i<=n;i++){
		scanf("%d",&s[i]);
	}
	int a,b,x;
	for(int i=1;i<=c;i++){
		scanf("%d%d%d",&a,&b,&x);
		add(a,b,x);
		in[b]++;
	}
	topo();
	for(int i=1;i<=n;i++){
		printf("%d\n",s[i]);
	}
	return 0;
}

