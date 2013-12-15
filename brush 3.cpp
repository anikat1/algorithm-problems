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
#define N 10000
#define MOD 1000000007
#define inf 1<<28
#define LL long long
#define abs(a) (a)<0?(-a):(a)
#define CLR(a) memset((a),0,sizeof((a)))
#define CLR1(a) memset((a),-1,sizeof((a)))
#define FRIN freopen("F:\\input.txt","r",stdin)
#define FROUT freopen("F:\\output.txt","w",stdout)
int n,dp[101][101],P[101],k,w;
int solve(int pos,int m){
	if(pos>=n||m>=k) return 0;
	if(dp[pos][m]!=-1) return dp[pos][m];
	int m1=0,m2=0,i,wd;
	wd=P[pos]+w;
	for(i=pos;i<n&&P[i]<=wd;i++) m1++;
	m1=m1+solve(i,m+1);
	m2=solve(pos+1,m);
	//printf("i=%d k=%d:m1=%d m2=%d\n",i,m,m1,m2);
	return dp[pos][m]=max(m1,m2);
}
int main(){
	//FRIN;
	int test,i,t,x;
	scanf("%d",&test);
	for(t=1;t<=test;t++){
		scanf("%d%d%d",&n,&w,&k);
		for(i=0;i<n;i++){
			scanf("%d%d",&x,&P[i]);
		}
		sort(P,P+n);
		CLR1(dp);
		x=solve(0,0);
		printf("Case %d: %d\n",t,x);
	}
	return 0;
	
}
