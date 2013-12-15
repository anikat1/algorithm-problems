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
LL dp[61][61];
char s[63];
LL solve(int p1,int p2){
	if(p1>p2) return 0;
	if(dp[p1][p2]!=-1) return dp[p1][p2];
	LL x,y,z,m=0;
	if(p1==p2) return 1;
	else{
		x=solve(p1+1,p2-1);
		y=solve(p1+1,p2);
		z=solve(p1,p2-1);
		m+=y+z-x;
		if(s[p1]==s[p2]) m+=(x+1);
	}
	return dp[p1][p2]=m;
}
int main(){
	//FRIN;
	
	int test,t,l;
	LL x;
	scanf("%d",&test);
	for(t=1;t<=test;t++){
		scanf("%s",s);
		CLR1(dp);
		l=strlen(s);
		x=solve(0,l-1);
		printf("Case %d: %lld\n",t,x);
	}
	return 0;
}
