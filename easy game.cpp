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
#define N 105
#define MOD 1000000007
#define inf 1<<27
#define LL long long
#define eps 1e-13
#define abs(a) (a)<0?(-a):(a)
#define CLR(a) memset((a),0,sizeof((a)))
#define CLR1(a) memset((a),-1,sizeof((a)))
#define FRIN freopen("F:\\input.txt","r",stdin)
#define FROUT freopen("F:\\output.txt","w",stdout)
int n,dp[N][N],nm[N],sm[N][N];
void init(){
	int i,j,m;
	CLR(sm);
	for(i=1;i<=n;i++){
		sm[i][i]=nm[i];
		for(j=i+1;j<=n;j++) sm[i][j]+=sm[i][j-1]+nm[j];
	}
	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++) dp[i][j]=inf;
	}
	/*for(i=1;i<=n;i++){
		for(j=i;j<=n;j++) printf("%d %d:%d\n",i,j,sm[i][j]);
	}*/
}
inline int sum(int s,int e){
	if(s>e) return 0;
	return sm[s][e];
}
int solve(int s,int e){
	if(s>e||s>n) return 0;
	if(dp[s][e]!=inf) return dp[s][e];
	int mx,i,k,m,lft=sum(s,e),rgt=sum(s,e);
	for(i=s;i<e;i++){
		mx=sum(s,i);
		k=solve(i+1,e);
		m=solve(s,i);
		lft=max(lft,mx-k);
		//printf("%d %d %d: LFT=%d k=%d\n",s,e,i+1,lft,k);
		mx=sum(i+1,e);
		rgt=max(rgt,mx-m);
		//printf("%d %d %d: rgt=%d k=%d\n",s,e,i+1,rgt,k);
	}
	return dp[s][e]=max(lft,rgt);
}
int main(){
	//FRIN;
	//FROUT;
	int test,t,i;
	scanf("%d",&test);
	for(t=1;t<=test;t++){
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&nm[i]);
	    init();
		printf("Case %d: %d\n",t,solve(1,n));
	}
	return 0;
}
