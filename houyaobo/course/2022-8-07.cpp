#include<iostream>
using namespace std;
const int N=1000+10;
const int INF=0x3f3f3f3f;
int head[N];
int tot;
struct node{
    int to,w,next;
}edge[N<<1];
int f[N];
void init(){
    memset(head,-1,sizeof(head));
    for(int i=0;i<N;i++)f[i]=i;
    tot=0; 
}
int Find(int x){
    if(f[x]==x)return x;
    return Find(f[x]);
}
void Union(int x,int y){
    int xx=Find(x);
    int yy=Find(y);
    if(xx!=yy){
        f[xx]=yy;
    }
}
int dis[N];
int vis[N];
int n;
void Dijkstra(int u){
    memset(dis,INF,sizeof(dis));
    dis[u]=0;
    for(int k=1;k<=n;k++){
        int minn=INF;
        for(int i=1;i<=n;i++){
            if(dis[i]<minn&&vis[i]==0){
                u=i;
                minn=dis[i];
            }
        }
        vis[u]=1;
        for(int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].to;
            if(dis[v]>dis[u]+edge[i].w){
                dis[v]=dis[u]+edge[i].w;
            }
        }
    }

}
int cmp(node aa,node bb){
    return aa.w<bb.w;
}
int kruska(){
    sort(edge,edge+tot,cmp);
    int ans=0;
    for(int i=0;i<tot;i++){
        int v=edge[i].to;
        int u=edge[i^1].to;
        if(Find(u)!=Find(v)){
            Union(u,v);
            ans=ans+edge[i].w;
        }
    }
    return ans;

}


int Prime(int u){
    memset(dis,INF,sizeof(dis));
    dis[u]=0;
    int ans=0;
    for(int k=1;k<=n;k++){
        int minn=INF;
        for(int i=1;i<=n;i++){
            if(dis[i]<minn&&vis[i]==0){
                u=i;
                minn=dis[i];
            }
        }
        ans=ans+minn;
        vis[u]=1;
        for(int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].to;
            if(dis[v]>edge[i].w){
                dis[v]=edge[i].w;
            }
        }
    }
    return ans;

}
int main()
{
    freopen("in","r",stdin);
    freopen("out","w",stdout);
} 



/*
1. m*(logn+logm) 选边 克鲁斯卡尔 算法 稀疏图 点多边少
2. n*n           选点 prime   稠密图  点少边多
/*
1.选边
n m
n-1
1. 将所有的边排序 从小到大选取
2. 1 2 3 4 5

x1 x2 x3 x4 x5..... xm xm+1
xm
xi xi<xm

xm xi <1> 

1. n-1条边 不构成环
u--->v 
*/
