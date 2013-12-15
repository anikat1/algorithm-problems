#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int N[1020][1020],dp[1020][1020];
int y[]={-1,1};
int main()
{
    int t,i,j,n,p,a,cnt=0;
    while(scanf("%d",&t)!=EOF){
      while(t--){
        scanf("%d",&n);
        a=n;
        for(i=0;i<=n;i++){
          for(j=0;j<=i+1;j++) dp[i][j]=0; 
        }               
        for(i=1;i<=2*n-1;i++){
           if(i<=n){
             for(j=1;j<=i;j++){ 
               scanf("%d",&N[i][j]);
               dp[i][j]=N[i][j];
             }
           }
           else{
              a--;
              for(j=1;j<=a;j++){
                 scanf("%d",&N[i][j]);
                 dp[i][j]=N[i][j];
              }
           }
        }
        for(i=1;i<=n;i++){
           for(j=1;j<=i;j++){
             dp[i][j]+=max(dp[i-1][j-1],dp[i-1][j]);
           }
        }
        a=n;
        for(i=n+1;i<=n+n-1;i++){
           a--;
           for(j=1;j<=a;j++){
             dp[i][j]+=max(dp[i-1][j],dp[i-1][j+1]);
           }
        }
        printf("Case %d: %d\n",++cnt,dp[n+n-1][1]);
      }
    }
    return 0;
}                                                                    
        
                              
                                                                                                         
