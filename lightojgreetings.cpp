#include<cstdio>
int main()
{
    int t,a,b,cnt=0;
    while(scanf("%d",&t)!=EOF){
      while(t--){
         scanf("%d%d",&a,&b);
         printf("Case %d: %d\n",++cnt,a+b);
      }
    }
    return 0;
}                                 
