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
#define N 1005
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
int a[N],n,k;
bool bs(int ky){
	int i=0,d,t=0;
	while(i<n){
		d=a[i++];
		if(d>ky) return false;
		for(;i<n;i++){
			if(d+a[i]<=ky) {
			   d+=a[i];
			   t++;
			}
			else break;
		}
	}
	if(t>=n-k) return true;
	return false;
}
int main(){
	//FRIN;
	int test,l,h,m,t,i,d;
	scanf("%d",&test);
	for(t=1;t<=test;t++){
		d=0;
		scanf("%d%d",&n,&k);
		n++;
		k++;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			d+=a[i];
		}
		//printf("%d %d %d\n",n,k,d);
		l=0;
		h=d;
		while(l<h){
			m=(l+h)>>1;
			//printf("l=%d h=%d m=%d\n",l,h,m);
			if(bs(m)) {
			  h=m;
			  //printf("true\n");
			}
			else {
			  l=m+1;
			  //printf("false\n");
			}
		}
		i=0;
		l=0;
		printf("Case %d: %d\n",t,h);
		while(i<n){
			m=a[i++];
			if(l<n-k){
			  for(;i<n;i++){
					if(l<n-k&&m+a[i]<=h) {
					  m+=a[i];
					  l++;
					}
				    else break;
			  }
			}
			printf("%d\n",m);
		}
	}
	return 0;
}
