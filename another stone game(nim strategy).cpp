#include<cstdio>
#define FRIN freopen("lightojinput.txt","r",stdin)
#define FROUT freopen("lightojoutput.txt","w",stdout)
#define LL long long
int grundy(LL n){
    while(n%2) n/=2;
    return (n/2);
}           
int main(){
    LL x,p/*,y*/;
    int t,n,i,cnt=0;
    scanf("%d",&t);
    while(t--){
      scanf("%d",&n);
      scanf("%lld",&p);
      x=grundy(p);
      //y=p%(p/2+1);
      for(i=1;i<n;i++) {
       scanf("%lld",&p);
       x^=grundy(p);
       //y^=(p%(p/2+1));
      }
      if(!x) printf("Case %d: Bob\n",++cnt);
      else printf("Case %d: Alice\n",++cnt);
      //printf("y=%lld\n",y);
    }
    return 0;
}                         
    
