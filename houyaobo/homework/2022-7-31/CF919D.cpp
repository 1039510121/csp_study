#include <bits/stdc++.h>
using namespace std;
const int MAXN=3*1e5+5;
int n,m;
int head[MAXN];
int in[MAXN];
struct Node{
	int next;
	int to;
}edge[MAXN];
int tot=0;
int ans;
int f[MAXN][30];
int cnt=0,fl=1;
string s;
void add(int x,int y){
	edge[++tot].to=y;
	edge[tot].next=head[x];
	head[x]=tot;
}
void init(){
	memset(head,0,sizeof(head));
	memset(f,0,sizeof(f));
}
void topo(){
	queue <int> q;
	//อุฦห
	for(int i=1;i<=n;i++){
		if(!in[i]) q.push(i);
		f[i][s[i-1]-'a']++;
	} 
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].to;
			for(int j=0;j<26;j++)
			f[v][j]=max(f[v][j],f[u][j]+((s[v-1]-'a'==j)?1:0));
			in[v]--;
			if(in[v]==0){
				q.push(v);
			}
		}
		cnt++;
	}
}
int main(){
	cin>>n>>m;
	
	cin>>s;
	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if(x==y){
			cout<<-1;
			return 0;
		} 
		in[y]++;
		add(x,y);
	}
	topo();
	if(cnt<n){
		cout<<-1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<26;j++){
			ans=max(ans,f[i][j]);
		}
	}
	cout<<ans;
	return 0;
}

