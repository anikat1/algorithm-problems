#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAX 1000003
#define FRIN freopen("lightojinput.txt","r",stdin)
#define FROUT freopen("lightojoutput.txt","w",stdout)
char text[MAX],pattern[MAX];
int next[MAX];
void compute(int m){
     next[0]=-1;
     int k=-1;
     for(int q=1;q<m;q++){
         while(k>-1&&pattern[k+1]!=pattern[q]) k=next[k];
         if(pattern[k+1]==pattern[q]) k++;
         next[q]=k;
     }
}        
int KMP(int len){
    int n=len,m=len,i,q=-1;
    compute(m);
    for(i=0;i<n;i++){
      while(q>-1&&pattern[q+1]!=text[i])  q=next[q];
      if(pattern[q+1]==text[i]) q++;
      if(q==m) q=next[q];
    }
    return n-q-1;
}                                         
int main(){
    int i,j,n,t,cnt=0;
    scanf("%d",&t);
    while(t--){
      scanf("%s",text);         
      n=strlen(text);
      j=0;
      for(i=n-1;i>=0;i--) pattern[j++]=text[i];
      pattern[j]=0;
      printf("Case %d: %d\n",++cnt,KMP(n)+j);
    }
    return 0;
}             
