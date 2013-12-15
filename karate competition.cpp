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
#define N 55
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
int n,a[N],b[N],dp[N][N];
int rec(int p1,int p2){
	if(p1==n||p2==n) return 0;
	if(dp[p1][p2]!=-1) return dp[p1][p2];
	int i,m1,m2;
	if(a[p1]<b[p2]) m1=rec(p1+1,p2);
	else if(a[p1]>b[p2]) m1=2+rec(p1+1,p2+1);
	else{
		m1=1+rec(p1+1,p2+1);
		m2=rec(p1+1,p2);
		m1=max(m1,m2);
	} 
	return dp[p1][p2]=m1;
}
int main(){
	//FRIN;
	int test,t,i,j;
	scanf("%d",&test);
	for(t=1;t<=test;t++){
		scanf("%d",&n);
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		for(i=0;i<n;i++) scanf("%d",&b[i]);
		sort(a,a+n);
		sort(b,b+n);
		CLR1(dp);
		j=rec(0,0);
		printf("Case %d: %d\n",t,j);
	}
	return 0;
}
