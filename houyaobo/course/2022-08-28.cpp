#include<bits/stdc++.h>
using namespace std;
const int N=100000;
struct node
{
	int l,r;
	int sum;
	int lazy;
	int len(){
		return r-l+1;
	}
}tree[4*N]; 
int a[N]; 
void pushup(int pos){
	tree[pos].sum=max(tree[pos*2].sum,tree[pos*2+1].sum);
	//tree[pos].sum=tree[pos*2].sum+tree[pos*2+1].sum;
}
void pushdown(int pos){
	if(tree[pos].lazy){
		tree[pos*2].sum+=tree[pos*2].len()*tree[pos].lazy;
		tree[pos*2+1].sum+=tree[pos*2+1].len()*tree[pos].lazy;
		tree[pos*2].lazy+=tree[pos].lazy;
		tree[pos*2+1].lazy+=tree[pos].lazy;
		tree[pos].lazy=0;
	}
}
void build(int pos,int l,int r){
	tree[pos].l=l;
	tree[pos].r=r;
	if(l==r){
		tree[pos].sum=a[l];
		return;
	}
	int mid=(l+r)/2;
	//[l,mid]  [mid+1,r];
	build(pos*2,l,mid);
	build(pos*2+1,mid+1,r);
	pushup(pos);
}
//更新单个节点 a[x]+=y;
void update(int pos,int x,int y){
	if(tree[pos].l==x&&tree[pos].r==x){
		tree[pos].sum+=y;
		return;
	}
	int mid=(tree[pos].l+tree[pos].r)/2;
	//pos*2             pos*2+1
	//[tree[pos].l,mid] [mid+1,tree[pos].r]
	if(x<=mid){
		update(pos*2,x,y);
	}else{
		update(pos*2+1,x,y);
	}
	pushup(pos);
}
// 更新一段区间 [x,y]+z
void update(int pos,int x,int y,int z){
	if(tree[pos].l==x&&tree[pos].r==y){
		tree[pos].sum+=tree[pos].len()*z;
		tree[pos].lazy+=z;
		return;
	}
	pushdown(pos);
	int mid=(tree[pos].l+tree[pos].r)/2;
	if(y<=mid){
		update(pos*2,x,y,z);
	}else if(x>mid){
		update(pos*2+1,x,y,z);
	}else{
		update(pos*2,x,mid,z);
		update(pos*2,mid+1,y,z);
	}
	pushup(pos);
}
int query(int pos,int x,int y){
	if(tree[pos].l==x&&tree[pos].r==y){
		return tree[pos].sum;
	}
	pushdown(pos);
	int mid=(tree[pos].l+tree[pos].r)/2;
	if(y<=mid){
		return query(pos*2,x,y);
	}else if(x>mid){
		return query(pos*2+1,x,y);
	}
	else{
		return max(query(pos*2,x,mid),query(pos*2+1,mid+1,y));
		//return query(pos*2,x,mid)+query(pos*2+1,mid+1,y);
	}
}

1. 
区间最大最小值
区间求和
2. 优化dp  优化构图
3. 树+线段树 

树状数组 
3 4 3
1 9
5 3
7 8


50


1 6 8 9 



[L R]


/*
a[l]=r

1. [l,r]+z  [l,r]=z





pos  
tree[pos]

tree[pos*2]  tree[pos*2+1]





int a[N];
int sum[N];
int n,m;//1e5
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=m;i++){
		int l,r;
		cin>>l>>r;
		cout<<sum[r]-sum[l-1]<<endl;
	}
}
线段树  维护区间


/*
长度为n的数组 m个询问
1 l r 求[l,r]区间的和
2 l r a[l]=r
*/