#include<cstdio>
int main()
{
    int t,cnt=0,n,i;
    double dp[105];
    while(scanf("%d",&t)!=EOF){
      while(t--){
        for(scanf("%d",&n),i=0;i<n;i++) scanf("%lf",&dp[i]);
        for(i=n-1;i>=0;i--){
          int x=n-1<i+6?n-1:i+6;
          x-=i;
          for(int j=i+1;j<=x+i;j++) dp[i]+=(dp[j]/x);
        }
        printf("Case %d: %.8lf\n",++cnt,dp[0]);    
      }
    }
    return 0;
}              
                                                                           
    
