#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int r,c,i,w,b,maxi,m,n,t,cnt=0;
    while(scanf("%d",&t)!=EOF){
      while(t--){
        scanf("%d%d",&r,&c);
        n=r<c?r:c;
        m=r>c?r:c;
        if(n==1) maxi=m;
        else if(n==2) maxi=2*((m+3)/4+(m+2)/4);
        else maxi=((n+1)/2)*((m+1)/2)+((n/2)*(m/2));            
        printf("Case %d: %d\n",++cnt,maxi);
      }
    }
    return 0;
}                              
