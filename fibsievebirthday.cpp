#include<cstdio>
#include<cmath>
int main()
{
    int t,cnt=0;
    long long n,s,x,y;
    while(scanf("%d",&t)!=EOF){
      while(t--){
        scanf("%lld",&n);
        s=(long long)ceil(sqrt(n));
        if(s*s-n<s) {
            x=s;
            y=s*s-n+1;
        }
        else{
             x=2*s-s*s+n-1;
             y=s;
        }
        if(s%2){
            s=x;
            x=y;
            y=s;
        }
        printf("Case %d: %lld %lld\n",++cnt,x,y); 
      }
    }
    return 0;
}                                             
