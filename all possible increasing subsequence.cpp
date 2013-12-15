#include<cstdio>
#include<cmath>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;
#define FRIN freopen("lightojinput.txt","r",stdin)
#define FROUT freopen("lightojoutput.txt","w",stdout)
#define CLR(a) memset((a),0,sizeof(a))
#define LL long long
#define N 100005
#define MOD  1000000007
typedef struct st{
   int p,id;
   friend bool operator<(st x,st y);
};
bool operator<(st x,st y){
    if(x.p!=y.p) return x.p<y.p;
    return x.id>y.id;
}
st A[N];
int lst[N],n;
int query(int x){
    int val=0,i,j;
    for(i=x;i>0;i-=(i&-i)) val=(val+lst[i])%MOD;
    return val;
}
void update(int x){
     int i,j;
     j=query(x-1)+1;
     for(i=x;i<=n;i+=(i&-i)) lst[i]=(lst[i]+j)%MOD;
}
int main()
{
    int t,cse=0,i,j;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        lst[0]=0;
        for(i=0;i<n;i++){
            scanf("%d",&A[i].p);
            A[i].id=i+1;
            lst[i]=0;
        }
        lst[n]=0;
        sort(A,A+n);
        for(i=0;i<n;i++) update(A[i].id);
        printf("Case %d: %d\n",++cse,query(n));
    }
    return 0;
}
