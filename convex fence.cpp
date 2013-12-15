#include<iostream>
#include<cstdio>
#include<cmath>
#include <algorithm>	
using namespace std;	 
#define MAX 50006
#define LL long long
#define sq(x) ((x)*(x))
#define PI  3.1415926535897932384626433832795
#define EPS 1e-10
	struct point {
	    LL x, y;
	} P[MAX], C[MAX], P0;
	 
	int nc; 
	inline LL TriArea2(point a, point b, point c) {
	    return (a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y));
	}
	 
	inline LL sqDist(point a, point b) {
	    return (sq(a.x-b.x) + sq(a.y-b.y));
	}
	 
	bool comp(point a, point b) {
	    LL d = TriArea2(P0, a, b);
	    if(d<0) return false;
	    if(!d && sqDist(P0, b) > sqDist(P0, a)) return false;
	    return true;
	}	 
	void ConvexHull(int np) {
	    int i, j, pos = 0;
	    for(i=1; i<np; i++){
	        if(P[i].y<P[pos].y || (P[i].y==P[pos].y && P[i].x>P[pos].x)) pos = i;
         }
	    swap(P[0], P[pos]);
	    P0 = P[0];
	    sort(&P[1], P+np, comp);
	    C[0] = P[0], C[1] = P[1],C[2]=P[2];
	    for(i=j=3; i<np; i++) {
	        while(TriArea2(C[j-2], C[j-1], P[i]) < 0) j--;
	        C[j++] = P[i];
	    }
	    nc = j;
	}
	int main(){
        int t,i,cnt=0,n;
        LL d;
        double dist;
        scanf("%d",&t);
        while(t--){
          nc=0;         
          scanf("%d%lld",&n,&d);
          for(i=0;i<n;i++) scanf("%lld%lld",&P[i].x,&P[i].y);
          dist=0.0;
          if(n>=3) {
            ConvexHull(n);       
            for(i=1;i<nc;i++) dist+=sqrt((double)(sqDist(C[i],C[i-1])));
            dist+=sqrt((double)(sqDist(C[0],C[i-1])));
          }
          else if(n==2) dist+=(2.0*sqrt((double)(sqDist(P[0],P[1]))));
          dist+=(2.0*PI*(double)d);
          printf("Case %d: %.8lf\n",++cnt,dist);
        }
        return 0;
  }         
