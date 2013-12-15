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
#define N 505
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
int r[N][N],c[N][N],d[N][N];
int main(){
	int test,i,j,t,n,m;
	scanf("%d",&test);
	for(t=1;t<=test;t++){
		scanf("%d%d",&n,&m);
		CLR(d);
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++) scanf("%d",&r[i][j]);
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++) scanf("%d",&c[i][j]);
		}
		for(i=1;i<=m;i++){
			for(j=1;j<=n;j++) c[j][i]+=c[j-1][i];
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++) r[i][j]+=r[i][j-1];
		}
	/*	printf("row:\n");
		for(i=1;i<=n;i++) printf("%d ",r[i][m]);
		puts("");
		printf("col:\n");
		for(i=1;i<=m;i++) printf("%d ",c[n][i]);
		puts("");*/
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				d[i][j]=max(d[i-1][j]+r[i][j],d[i][j-1]+c[i][j]);
			}
		}
		printf("Case %d: %d\n",t,d[n][m]);
	}
	return 0;
}
