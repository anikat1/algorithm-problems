#include<cstdio>
#include<cmath>
#include<cstring>
unsigned long long euler[5000006];
bool check[5000002];
int m;
long euphi(){
     long i,j;
     for(i=2;i<=5000000;i++) euler[i]=i;
     for(i=2;i<=5000000;i++){  
       if(!check[i]){
          euler[i]=i-1;
          for(j=2*i;j<=5000000;j+=i){
             check[j]=1;
             euler[j]/=i;
             euler[j]*=(i-1);
          }
       }
     }                        
}    
int main()
{
    int i,j,a,b,t,cnt=0;
    long long sum;
    euphi();
    euler[0]=euler[1]=0;
    for(i=2;i<=5000000;i++) {
       if(i<21) printf("%lld\n",euler[i]);
       euler[i]*=euler[i];
       euler[i]+=euler[i-1];
    }
    while(scanf("%d",&t)!=EOF){
      while(t--){
        scanf("%d%d",&a,&b);
        printf("Case %d: %llu\n",++cnt,euler[b]-euler[a-1]);
      }
    }
    return 0;
}
                                                                                     
    
