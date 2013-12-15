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
int a[103],n;
double dp[103];
double solve(int p){
	//if(n==1) return a[0];
	if(p>=n) return 0;
	if(dp[p]!=-1) return dp[p];
	int i,j;
	double m,pb=0.0;
	j=p+6<n-1?p+6:n-1;
	j-=p;
	if(j!=0) pb=(1.0/(j*1.0));
	m=a[p];
	for(i=p+1;i<=j+p;i++) m+=pb*(solve(i));
	//printf("p=%d j=%d m=%lf pb=%lf\n",p,j,m,pb);
	return dp[p]=m;
}
int main(){
	//FRIN;
	//FROUT;
	int t,test,i;
	scanf("%d",&test);
	for(t=1;t<=test;t++){
		scanf("%d",&n);
		for(i=0;i<n;i++){
		  scanf("%d",&a[i]);
		  dp[i]=-1.0;
		}
		dp[n]=-1.0;
		printf("Case %d: %.8lf\n",t,solve(0));
	}
	return 0;
}
