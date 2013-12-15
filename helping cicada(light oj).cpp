#include<cstdio>
#define LL long long
long long gcd(long long a,long long b){
    return a?gcd(b%a,a):b;
}
LL lcm(LL a,LL b){
    LL gc=gcd(a,b);
    return a*b/gc;
}      
int main()
{
    LL val[17],n,i,j,no,sum,LCM,m;
    int t,cnt=0;
    while(scanf("%d",&t)!=EOF){
      while(t--){ 
       scanf("%lld%lld",&n,&m);
       for(i=0;i<m;i++) scanf("%lld",&val[i]);
       sum=0;
       for(i=1;i<(1<<m);i++){
          LCM=1;
          no=0;
         for(j=0;j<m;j++){
           if(i&(1<<j)){         
             LCM=lcm(LCM,val[j]);
             if(LCM>n) break;
             no++;
           }
         }
         if(LCM>n) continue;
         if(no%2) sum+=n/LCM;
         else sum-=n/LCM;
       }
       printf("Case %d: %lld\n",++cnt,n-sum);
      }
    }
    return 0;
}                                                                                
