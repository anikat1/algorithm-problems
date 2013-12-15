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
#define N 10005
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
bool v[N];
int a[N];
int main(){
	//FRIN;
	int t,test,i,n;
	bool f;
	scanf("%d",&test);
	for(t=1;t<=test;t++){
		for(scanf("%d",&n),i=0;i<n;i++) scanf("%d",&a[i]);
		CLR(v);
		f=true;
		for(i=0;i<n&&f;i++){
			if((n-a[i])>0&&!v[n-a[i]]) v[n-a[i]]=true;
			else if((a[i]+1)<=n&&!v[a[i]+1]) v[a[i]+1]=true;
			else f=false;
		}
		printf("Case %d: ",t);
		if(f) puts("yes");
		else puts("no");
	}
	return 0;
}
