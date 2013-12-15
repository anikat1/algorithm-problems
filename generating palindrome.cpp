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
#define eps 1e-13
#define abs(a) (a)<0?(-a):(a)
#define CLR(a) memset((a),0,sizeof((a)))
#define CLR1(a) memset((a),-1,sizeof((a)))
#define FRIN freopen("F:\\input.txt","r",stdin)
#define FROUT freopen("F:\\output.txt","w",stdout)
struct point{
	int x,y;
};
int dp[103][103],n;
char st[103];
int solve(int s,int e){
	if(s>e) return 0;
	if(dp[s][e]!=-1) return dp[s][e];
	int x,y;
	if(st[s]==st[e]) x=solve(s+1,e-1);
	else{
		x=1+solve(s,e-1);
		y=1+solve(s+1,e);
		x=min(x,y);
	}
	return dp[s][e]=x;
}
int main(){
	//FRIN;
	int test,t;
	scanf("%d",&test);
	for(t=1;t<=test;t++){
		scanf("%s",st);
		n=strlen(st);
		CLR1(dp);
		printf("Case %d: %d\n",t,solve(0,n-1));
	}
	return 0;
}
