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
#define ULL unsigned long long
#define abs(a) (a)<0?(-a):(a)
#define CLR(a) memset((a),0,sizeof((a)))
#define FRIN freopen("F:\\input.txt","r",stdin)
#define FROUT freopen("F:\\output.txt","w",stdout)
ULL ncr[31][31],fac[31],ans;
int main(){
	//FRIN;
	int test,i,j,n,r;
	fac[0]=1;
	for(i=1;i<31;i++) fac[i]=fac[i-1]*i;
	for(i=0;i<31;i++) {
	  ncr[i][0]=1;
	  ncr[i][i]=1;
	  ncr[0][i]=0;
	}
	for(i=1;i<31;i++){
		for(j=1;j<i;j++) ncr[i][j]=ncr[i-1][j-1]+ncr[i-1][j];
		//if(i>1&&i<10) for(j=1;j<=i;j++) printf("%dC%d: %llu\n",i,j,ncr[i][j]);
	}
	scanf("%d",&test);
	for(i=1;i<=test;i++){
		scanf("%d%d",&n,&r);
		if(n<r) ans=0;
		else ans=ncr[n][r]*fac[r]*ncr[n][r];
		printf("Case %d: %llu\n",i,ans);
	}
}
