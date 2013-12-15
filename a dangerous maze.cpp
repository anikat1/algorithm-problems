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
#define CLR1(a) memset((a),-1,sizeof((a)))
#define FRIN freopen("F:\\input.txt","r",stdin)
#define FROUT freopen("F:\\output.txt","w",stdout)
int d[102],n;
int gcd(int a, int b)
{
        if(a%b==0) return b;
        else return gcd(b,a%b);
}
int main(){
	//FRIN;
	int t,test,i,tn,td,en,ed,e;
	scanf("%d",&test);
	for(t=1;t<=test;t++){
		scanf("%d",&n);
		tn=0;
		en=0;
		for(i=0;i<n;i++){
			scanf("%d",&d[i]);
			tn+=abs(d[i]);
			if(d[i]<0) en++;
		}
		e=n-en;
		tn=tn*n;
		td=n*e;
		printf("Case %d: ",t);
		if(td==0||tn<0||td<0)  printf("inf\n");
		else {
			e=gcd(tn,td);
			td/=e;
			tn/=e;
			printf("%d/%d\n",tn,td);
		}
	}
	return 0;
}
