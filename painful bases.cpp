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
#define N 16
#define MOD 1000000007
#define inf 1<<28
#define LL long long
#define abs(a) (a)<0?(-a):(a)
#define CLR(a) memset((a),0,sizeof((a)))
#define CLR1(a) memset((a),-1,sizeof((a)))
#define FRIN freopen("F:\\input.txt","r",stdin)
#define FROUT freopen("F:\\output.txt","w",stdout)
int b,k,ln,l;
LL dp[1<<N][20];
char d[20];
bool v[17];
LL f(int bitmask,int sum){
	if(bitmask==l){
		//printf("sum=%d\n",sum);
		if(sum==0) return 1;
		else return 0;
	}
	if(dp[bitmask][sum]!=-1) return dp[bitmask][sum];
	int j,x,m;
	LL p=0;
	for(j=0;j<ln;j++){
		if(!v[j]){
			if(d[j]>='0'&&d[j]<='9')x=d[j]-'0';
			else x=d[j]-'A'+10;
			v[j]=true;
			m=(sum*b+x)%k;
			p=p+f(bitmask|(1<<j),m);
			v[j]=false;
		}
	}
	return dp[bitmask][sum]=p;
}
LL solve(){
	int i,j;
	LL p;
	l=0;
	for(i=0;i<ln;i++) l|=(1<<i);
	/*for(i=0;i<ln;i++){
		if(d[i]>='0'&&d[i]<='9')j=d[i]-48;
		else j=d[i]-'A'+10;
		p|=(1<<j);
	}*/
	CLR(v);
	CLR1(dp);
	p=f(0,0);
	return p;
	//printf("l=%d p=%d\n",l,p);
}
int main(){
	//FRIN;
	//FROUT;
	int i,test,t;
	CLR1(dp);
	scanf("%d",&test);
	for(t=1;t<=test;t++){
		scanf("%d%d",&b,&k);
		scanf("%s",d);
		ln=strlen(d);
		//sort(d,d+ln);
		printf("Case %d: %lld\n",t,solve());
	}
	return 0;
}
