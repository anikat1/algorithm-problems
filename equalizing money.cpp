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
#define N 1007
#define MOD 1000000007
#define inf 1<<28
#define LL long long
#define eps 1e-13
#define abs(a) (a)<0?(-a):(a)
#define CLR(a) memset((a),0,sizeof((a)))
#define CLR1(a) memset((a),-1,sizeof((a)))
#define FRIN freopen("F:\\input.txt","r",stdin)
#define FROUT freopen("F:\\output.txt","w",stdout)
#define YES printf("Yes\n")
#define NO printf("No\n")

vector<int> ed[N];
int n,tk[N],p,q,ttl;
bool vs[N];
void init(){
	int i;
	for(i=0;i<=n;i++) ed[i].clear();
	CLR(vs);
}
void dfs(int s){
	vs[s]=true; 
	if(tk[s]<ttl) q+=ttl-tk[s];
	else if(tk[s]>ttl) p+=tk[s]-ttl;
	int i,j,sz=ed[s].size();
	   for(i=0;i<sz;i++) {
	     j=ed[s][i];
		 if(!vs[j]) dfs(j);
	   }
}
int main(){
	//FRIN;
	int test,m,i,j,t,u,v;
	bool f;
	scanf("%d",&test);
	for(t=1;t<=test;t++){
		init();
		scanf("%d%d",&n,&m);
		ttl=0;
		f=false;
		for(i=0;i<n;i++) {
		   scanf("%d",&tk[i+1]);
		   ttl+=tk[i+1];
		}
		for(i=0;i<m;i++){
			scanf("%d%d",&u,&v);
			ed[u].push_back(v);
			ed[v].push_back(u);
		}
		//printf("ttl=%d\n",ttl);
		printf("Case %d: ",t);
		if(ttl%n) printf("No\n");
		else{
			ttl/=n;
			for(i=1;i<=n;i++){
				if(!vs[i]){
					p=0;
					q=0;
					dfs(i);
					if(p!=q) f=true;
				}
			}
			if(f) printf("No\n");
			else printf("Yes\n");	
		}
	}
	return 0;
}
