#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int t,cse=0,n,k,i,w,a[50010],x;
    while(scanf("%d",&t)!=EOF){
       while(t--){
         scanf("%d%d",&n,&w);
         for(i=0;i<n;i++){
            scanf("%d%d",&x,&a[i]);
         }
         sort(a,a+n);
         x=0;
         for(i=0;i<n;){
            k=a[i]+w;
            while(a[i]<=k&&i<n)i++;
            x++;
         }
         printf("Case %d: %d\n",++cse,x);
       }
    }
    return 0;
}              
                                                        
