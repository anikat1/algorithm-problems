#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define N 100010
#define LL long long
#define CLR(a) memset((a),0,sizeof((a)));
#define FRIN freopen("lojinput.txt","r",stdin)
#define FROUT freopen("lojoutput3.txt","w",stdout)
typedef struct{
    int st,ed,id;
}node;
node Q[50005];
int prev[N],tree[N],n;
bool cmp(const node&a,const node &b){return a.ed<b.ed;}
void update(int x,int val){
     while(x<=n){
         tree[x]+=val;
         x+=(x&(-x));
     }
}
int query(int x){
    int val=0;
    while(x){
        val+=tree[x];
        x-=(x&(-x));
    }
    return val;
}

int main(){
   // FRIN;
   // FROUT;
    int t,j,k,q,cse=0,num[N],a[N];
    register int i;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&q);
        for(i=1;i<=n;i++) scanf("%d",&num[i]);
        for(i=0;i<q;i++) {
             scanf("%d%d",&Q[i].st,&Q[i].ed);
             Q[i].id=i;
        }
        sort(Q,Q+q,cmp);
        j=1;
        CLR(tree);
        CLR(prev);
        for(i=0;i<q;i++){
          for(;j<=Q[i].ed;j++){
            k=num[j];
            if(!prev[k]) {
                update(j,1);
                prev[k]=j;
            }
            else{
                update(prev[k],-1);
                update(j,1);
                prev[k]=j;
            }
        }
        a[Q[i].id]=query(Q[i].ed)-query(Q[i].st-1);
        //  int k=query(Q[i].ed)-query(Q[i].st-1);
        }
      printf("Case %d:\n",++cse);
      for(i=0;i<q;i++) printf("%d\n",a[i]);
    }
    return 0;
}
