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
#define FRIN freopen("F:\\input.txt","r",stdin)
#define FROUT freopen("F:\\output.txt","w",stdout)
LL sum[32],powr[32],sum1[32],num[32];
bool bin[32];
int no_of_one(int z){
	int i,j=0,pw=1;
	while(z){
		if(z&1) bin[j++]=1;
		else bin[j++]=0;
		z>>=1;
	}
	num[0]=bin[0];
	for(i=1;i<j;i++){
		pw<<=1;
		if(bin[i]==1) num[i]=num[i-1]+pw;
		else num[i]=num[i-1];
	}
	return j;
}
LL solve(int n){
	int j=no_of_one(n),i,k,dif;
	LL sm=0;
	if(j<=1) return 0;
	//printf("binary rep:");
	//for(i=j-1;i>=0;i--) printf("%c",bin[i]==1?'1':'0');
	//printf("\n");
//	for(i=0;i<j;i++) printf("bit %d:%lld\n",i,num[i]);
	//printf("total bit %d=%lld\n",j,sum1[j]);
	for(i=j-1;i>0;i--){
		if(bin[i]&&bin[i-1]){
			k=powr[i]+powr[i-1];
			dif=num[i]-k+1;
			sm+=dif;
		}
		if(bin[i-1]) sm+=sum1[i-1];
	//	printf("%d dif=%d sm=%lld\n",i,dif,sm);
	}
	sm+=sum1[j-1];
	return sm;
}
int main(){
	int test,n,i,j;
	LL ans;
	scanf("%d",&test);
	powr[0]=1;
	for(i=1;i<32;i++) powr[i]=powr[i-1]*2;
	sum[0]=sum[1]=0;
	sum[2]=1;
	for(i=3;i<32;i++){
		sum[i]=powr[i]-powr[i-1]-powr[i-2];
		for(j=1;j<i;j++) sum[i]+=sum[j];
	}
	sum1[0]=0;
	for(i=1;i<32;i++) sum1[i]=sum1[i-1]+sum[i];
//	for(i=1;i<32;i++) printf("%d sum=%lld sum1=%lld\n",i,sum[i],sum1[i]);
	for(i=1;i<=test;i++){
		scanf("%d",&n);
		ans=solve(n);
		printf("Case %d: %lld\n",i,ans);
	}
	
}
