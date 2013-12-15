#include<cstdio>
#include<cmath>
#include<cstring>
#include<map>
using namespace std;
#define FRIN freopen("lightojinput.txt","r",stdin)
#define FROUT freopen("lightojoutput.txt","w",stdout)
#define CLR(a) memset((a),0,sizeof(a))
#define LL long long
#define N 100005
int list[N],n;
char st[N];
int query(int x){
    int val=0,i,j;
    for(i=x;i>0;i-=(i&(-i))) val+=list[i];
    return val;
}
void update(int x,int y){
     int i,j;
     for(i=x;i<=n;i+=(i&-i)) list[i]++;
     for(i=y+1;i<=n;i+=(i&-i)) list[i]--;
}
int main(){
  int t,cse=0,q,i,m,p;
  scanf("%d",&t);
  char ch[4];
  while(t--){
    scanf("%s",st);
    n=strlen(st);
    CLR(list);
    printf("Case %d:\n",++cse);
    for(scanf("%d",&q),i=0;i<q;i++){
        scanf("%s %d",ch,&m);
        if(ch[0]=='I'){
          scanf("%d",&p);
          update(m,p);
        }
        else {
            p=query(m);
            if(p%2) printf("%c\n",(st[m-1]=='0'?'1':'0'));
            else printf("%c\n",st[m-1]);
        }
    }
  }
  return 0;
}
