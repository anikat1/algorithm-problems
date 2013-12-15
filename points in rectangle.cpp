#include<cstdio>
#include<cmath>
#include<cstring>
#include<map>
using namespace std;
#define FRIN freopen("lightojinput.txt","r",stdin)
#define FROUT freopen("lightojoutput.txt","w",stdout)
#define CLR(a) memset((a),0,sizeof(a))
#define LL long long
int list[1010][1010];
int sum(int x,int y){
    int val=0,i,j;
    for(i=x;i>0;i-=(i&(-i))){
      for(j=y;j>0;j-=(j&(-j))) val+=list[i][j];
    }
    return val;
}
void update(int x,int y){
     int i,j;
     for(i=x;i<=1001;i+=(i&-i)){
        for(j=y;j<=1001;j+=(j&-j)){
          list[i][j]++;
        }
     }
}                                                 
                          
int main(){
    int d,no,t,cnt=0,q,x1,x2,y1,y2;
    scanf("%d",&t);
    while(t--) {
      CLR(list);         
      printf("Case %d:\n",++cnt);         
      scanf("%d",&q);
      while(q--){
         scanf("%d",&d);
         if(!d) {
           scanf("%d%d",&x1,&y1);
           x1++;
           y1++;
           no=sum(x1,y1)-sum(x1-1,y1)-sum(x1,y1-1)+sum(x1-1,y1-1);
           if(!no) update(x1,y1);           
         }
         else{
              scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
              x1++,y1++;
              x2++,y2++;
              no=sum(x2,y2)-sum(x1-1,y2)-sum(x2,y1-1)+sum(x1-1,y1-1);
              printf("%d\n",no);
         }
      }
    }
    return 0;
}      
               
