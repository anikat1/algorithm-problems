#include<cstdio>
#include<cmath>
#include<cstring>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;
#define FRIN freopen("lightojinput.txt","r",stdin)
#define FROUT freopen("lightojoutput.txt","w",stdout)
#define CLR(a) memset((a),0,sizeof(a))
#define LL long long
#define MN 300005
#define MX 100005
int A[MX],mx,ans;
LL lst[MN];
LL query(int x){
    int i;
    LL val=0;
    for(i=x;i>0;i-=(i&-i)) val+=lst[i];
    return val;
}
void update(int x,LL val){
     int i;
     for(i=x;i<=mx;i+=(i&-i)) lst[i]+=val;
}
int main(){
   int t,cse=0,i,j,k,d,n;
   scanf("%d",&t);
   while(t--){
    for(scanf("%d",&n),i=0;i<n;i++) scanf("%d",&A[i]);
    sort(A,A+n);
    CLR(lst);
    mx=3*A[n-1];
    ans=0;
   // printf("mx=%d\n",mx);
    for(i=n-3;i>=3;i--){
        for(j=i+1;j<n;j++){
            for(k=j+1;k<n;k++){
                d=A[k]-A[j]-A[i];
                if(d<1) d=1;
                //printf("update=%d\n",d);
                update(d,1);
            }
        }
        for(j=i-2;j>=1;j--){
            for(k=j-1;k>=0;k--){
                d=A[i-1]+A[j]+A[k];
                //printf("d=%d ans=%d\n",d,ans);
                //if(d>A[n-1]) d=A[n-1];
                ans+=query(d-1);
            }
        }
    }
    printf("Case %d: %d\n",++cse,ans);
   }
   return 0;
}

