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
#define N 52
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
LL dp[N][N][N];
int n,k,m;
LL BC(int n1,int k1,int m1){
	if(n1<k1) return 0;
	else if(n1<=m1&&k1==1) return 1;
	else if(k1==1) return 0;
	if(dp[n1][k1][m1]!=-1) return dp[n1][k1][m1];
	int i;
	LL ans=0;
	for(i=1;i<=m;i++){
		ans+=BC(n1-i,k1-1,m1);
	}
	return dp[n1][k1][m1]=ans;
}
int main(){
	//FRIN;
	int test,t;
	scanf("%d",&test);
	CLR1(dp);
	for(t=1;t<=test;t++){
		scanf("%d%d%d",&n,&k,&m);
		printf("Case %d: %lld\n",t,BC(n,k,m));
	}
	return 0;
}
