#include<cstdio>
#include<cmath>
#include<cstring>
#include<map>
#include<iostream>
using namespace std;
#define FRIN freopen("lightojinput.txt","r",stdin)
#define FROUT freopen("lightojoutput.txt","w",stdout)
#define CLR(a) memset((a),0,sizeof(a))
#define LL long long
#define N 100005
int A[N],n=0;
LL lst[N];
LL query(int x){
    int i;
    LL val=0;
    for(i=x;i>0;i-=(i&-i)) val+=lst[i];
    return val;
}
void update(int x,LL val){
     int i;
     for(i=x;i<=n;i+=(i&-i)) lst[i]+=val;
}
int main(){
    int t,cse=0,i,v,q,c;
    LL j;
    scanf("%d",&t);
    while(t--){
        CLR(lst);
        scanf("%d%d",&n,&q);
        for(i=1;i<=n;i++){
          scanf("%d",&A[i]);
          update(i,A[i]);
        }
        printf("Case %d:\n",++cse);
        while(q--){
            scanf("%d%d",&c,&i);
            i++;
            if(c==1){
                //j=query(i)-query(i-1);
                printf("%d\n",A[i]);
                update(i,-A[i]);
                A[i]=0;

            }
            else if(c==2){
                scanf("%d",&v);
                update(i,v);
                A[i]+=v;
            }
            else{
                scanf("%d",&v);
                v++;
                j=query(v)-query(i-1);
                printf("%lld\n",j);
            }
        }
    }
  //  getchar();
    return 0;
}
