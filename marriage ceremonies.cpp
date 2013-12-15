#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define N 16
int dp[N+1][1<<N],pos[1<<N],pri[N+1][N+1];
int next(int n){ //returning same no. of bits present next to n
    int r,c;
    c=n&-n;
    r=n+c;
    //printf("next:c=%d r=%d ret=%d\n",((((r ^ n) >> 2) / c) | r));
    return (((r ^ n) >> 2) / c) | r;
}
int find_wife(int n){
    int tp,i,b,j,idx,w,k,maxi,curr;
    for(i=1;i<=n;i++) dp[1][1<<(i-1)]=pri[1][i];
    tp=1<<n;
    //printf("tp=%d ",tp);
    for(i=2;i<=n;i++){
       b=(1<<i)-1;
     //  printf("i=%d:\n",i);
       for(j=b;j<tp;j=next(j)){
         b=j;
        // printf("j=%d\n",b);
         maxi=0;
         while(b){
            w=b&-b;// extracting last lowest bit 1 is present
            idx=pos[w];
            curr=pri[i][idx]+dp[i-1][j&~w]; //j&~w(excluding idx from set)
            if(curr>maxi) maxi=curr;
            b&=~w;
          //  printf("w=%d idx=%d j&~w=%d curr=%d b=%d\n",w,idx,(j&~w),curr,b);
         }
         dp[i][j]=maxi;
         //printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
       }
    }
    return dp[n][(1<<n)-1];
}
int main(){
   int t,cse=0,n,i,j;
   scanf("%d",&t);
   while(t--){
    for(scanf("%d",&n),i=1;i<=n;i++){
        for(j=1;j<=n;j++) scanf("%d",&pri[i][j]);
    }
    memset(pos,0,sizeof(pos));
    for(i=0;i<n;i++) pos[1<<i]=i+1;
    printf("Case %d: %d\n",++cse,find_wife(n));
   }
   return 0;
}
