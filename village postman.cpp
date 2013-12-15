#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>

#include<cmath>
#include<iostream>
#include<fstream>

#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
using namespace std;
#define N 205
#define MOD 1000000007
#define inf 1<<28
#define LL long long
#define eps 1e-13
#define abs(a) (a)<0?(-a):(a)
#define CLR(a) memset((a),0,sizeof((a)))
#define CLR1(a) memset((a),-1,sizeof((a)))
#define FRIN freopen("F:\\input.txt","r",stdin)
#define FROUT freopen("F:\\output.txt","w",stdout)
struct point{
	int x,y;
	bool v;
};
vector<point>edge[N];
vector<int>path;
int n,m;
void reset(){
	int i;
	for(i=0;i<=n;i++) edge[i].clear();
	path.clear();
}
void dfs(int nde){
	int i,sz=edge[nde].size(),j,k;
	for(i=0;i<sz;i++){
		j=edge[nde][i].x;   	//opposite to edge
		k=edge[nde][i].y;		//to
		if(edge[nde][i].v||edge[k][j].v) continue;
		edge[nde][i].v=true;		
		edge[k][j].v=true;
		dfs(edge[nde][i].y);
	}
	path.push_back(nde);
}

int main(){
	//FRIN;
	point p;
	int test,i,j,t,pr,w,a;
	scanf("%d",&test);
	for(t=1;t<=test;t++){
		scanf("%d%d",&n,&m);
		pr=0;
		for(i=0;i<n;i++){
			scanf("%d",&w);
			pr+=w-(i+1);
		}
		pr-=m;
		reset();
		for(i=0;i<m;i++){
			scanf("%d%d",&j,&p.y);
			p.v=false;
			w=edge[j].size();
			a=edge[p.y].size();
			p.x=a;
			edge[j].push_back(p);
			p.x=w;
            swap(j,p.y);	
			edge[j].push_back(p);
		}
		dfs(1);
		printf("Case %d: %d\n",t,pr);
		j=path.size();
		for(i=0;i<j;i++){
			if(i) printf(" ");
			printf("%d",path[i]);
		}
		printf("\n");
	}
	return 0;
}
