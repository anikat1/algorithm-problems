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
#define N 31
#define MOD 1000000007
#define inf 1<<28
#define LL long long
#define abs(a) (a)<0?(-a):(a)
#define CLR(a) memset((a),0,sizeof((a)))
#define FRIN freopen("F:\\input.txt","r",stdin)
#define FROUT freopen("F:\\output.txt","w",stdout)
int dp1[N][N];
LL dp2[N][N];
int main(){
//	FRIN;
//	FROUT;
	int test,k,i,j,l1,l2;
	char st1[N],st2[N];
	scanf("%d",&test);
	for(k=1;k<=test;k++){
		scanf("%s%s",st1,st2);
		l1=strlen(st1);
		l2=strlen(st2);
		for(i=0;i<=l1;i++){
			dp1[i][0]=i;
			dp2[i][0]=1;
		}
		for(i=0;i<=l2;i++){
			dp1[0][i]=i;
			dp2[0][i]=1;
		}
		for(i=1;i<=l1;i++){
			for(j=1;j<=l2;j++){
				if(st1[i-1]==st2[j-1]) dp1[i][j]=dp1[i-1][j-1]+1;
				else{
					dp1[i][j]=min(dp1[i-1][j],dp1[i][j-1])+1;
				}
				//printf("dp1[%d][%d]=%d dp1(i-1,j)=%d dp1(i,j-1)=%d\n",i,j,dp1[i][j],dp1[i-1][j],dp1[i][j-1]);
			}
		}
		//cout<<endl<<endl;
		for(i=1;i<=l1;i++){
			for(j=1;j<=l2;j++){
				if(st1[i-1]==st2[j-1]) dp2[i][j]=dp2[i-1][j-1];
				else if(dp1[i-1][j]<dp1[i][j-1]) dp2[i][j]=dp2[i-1][j];
				else if(dp1[i][j-1]<dp1[i-1][j]) dp2[i][j]=dp2[i][j-1];
				else dp2[i][j]=dp2[i][j-1]+dp2[i-1][j];
				//printf("dp2[%d][%d]=%d dp2(i-1,j)=%d dp2(i,j-1)=%d\n",i,j,dp2[i][j],dp2[i-1][j],dp2[i][j-1]);
			}
		}
		//cout<<endl<<endl;
		printf("Case %d: %d %lld\n",k,dp1[l1][l2],dp2[l1][l2]);
	}
	
	
}
