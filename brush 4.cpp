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
#define N 17
#define MOD 1000000007
#define inf 1<<28
#define LL long long
#define abs(a) (a)<0?(-a):(a)
#define CLR(a) memset((a),0,sizeof((a)))
#define CLR1(a) memset((a),-1,sizeof((a)))
#define FRIN freopen("F:\\input.txt","r",stdin)
#define FROUT freopen("F:\\output.txt","w",stdout)
struct point{
	int x,y;
};
point P[N];
int n,coll[N][N],dp[1<<N],pos[1<<N];
int solve(int p){
	if(p==0) return 0;
	if(dp[p]!=-1) return dp[p];
	int i,j,k,m,mn,p1,p2;
	m=p&-p;
	p1=pos[m];
	//printf("p=%d p1=%d %d\n",p,p1,(p&~p1));
	mn=solve(p&~m)+1;
	for(i=(p&~m);i>0;i&=~(i&-i)){
		j=pos[(i&-i)];
		k=p&~coll[p1][j];
		p2=solve(k)+1;
	//	printf("j=%d k=%d p2=%d",j,k,p2);
		if(mn>p2) mn=p2;
	}
	return dp[p]=mn;
}
int main(){
	//FRIN;
	int test,i,j,k,t;
	scanf("%d",&test);
	//CLR1(pos);
	for(i=0;i<17;i++) pos[(1<<i)]=i;
	/*for(i=1;i<(1<<16);i++){
		if(pos[i]==-1) pos[i]=pos[i-1];
	}*/
	for(t=1;t<=test;t++){
		scanf("%d",&n);
		for(i=0;i<n;i++) scanf("%d%d",&P[i].x,&P[i].y);
		CLR1(dp);
		for(i=0;i<n;i++){
			dp[1<<i]=1;
			for(j=0;j<n;j++){
				coll[i][j]=0;
				dp[(1<<i)|(1<<j)]=1;
				if(j<i) coll[i][j]=coll[j][i];
				else if(i==j) coll[i][j]=1;
				else{
				  for(k=0;k<n;k++){
				  	if(((P[j].y-P[i].y)*(P[k].x-P[j].x))==((P[k].y-P[j].y)*(P[j].x-P[i].x))){
							 coll[i][j]|=(1<<k);
							 //printf("i=%d j=%d k=%d %d\n",i,j,k,coll[i][j]);
					}
				  }
				}
			}
		}
		//for(i=0;i<(1<<n);i++) dp[i]=inf;
		//for(i=0;i<n;i++) dp[1<<i]=1;
		k=(1<<n)-1;
		j=solve(k);
		printf("Case %d: %d\n",t,j);
	}
	return 0;
}
