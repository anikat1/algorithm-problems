#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define N 8005
#define CLR(a) memset((a),0,sizeof((a)))
#define FRIN freopen("lojinput.txt","r",stdin)
#define FROUT freopen("lojoutput.txt","w",stdout)
inline int abs(int a){return (a<0?-a:a);}
vector<int>order;
vector<int>edge[2*N];
vector<int>edge2[2*N];
int comp[2*N];
bool used[2*N];
void reset(int n,int m){
     order.clear();
     int i;
     CLR(used);
     for(i=0;i<(m+2);i++){
        edge[i].clear();
        edge2[i].clear();
     }
     memset(comp,-1,sizeof(comp));
}

void dfs1(int v){
     used[v]=true;
     int i,k,sz=edge[v].size();
     for(i=0;i<sz;i++){
        k=edge[v][i];
        if(!used[k]) dfs1(k);
     }
     order.push_back(v);
}
void dfs2(int v,int id){
     comp[v]=id;
     int i,k,sz=edge2[v].size();
     for(i=0;i<sz;i++){               
        k=edge2[v][i];
        if(comp[k]==-1) dfs2(k,id);
     }
}
int main(){
    int i,j,n,m,ca,cb,_a,_b,t,cse=0,k,a,b;
    vector<int>path;
    scanf("%d",&t); 
    while(t--){
      scanf("%d%d",&n,&m);
      m*=2;
      reset(n,m);
      path.clear();
      for(i=0;i<n;i++){
         scanf("%d%d",&a,&b);
         _a=a;
         _b=b;
         a=abs(a);
         b=abs(b);
         a=2*a-1;
         b=2*b-1;
         if(_a<0) a--;
         if(_b<0) b--;
         ca=a^1;
         cb=b^1;
         edge[ca].push_back(b);
         edge[cb].push_back(a);
         edge2[b].push_back(ca);
         edge2[a].push_back(cb);
      }
      for(i=0;i<m;i++){
        if(!used[i]) dfs1(i);
      }
      for(i=0,k=0;i<m;i++){
        j=order[m-i-1];
        if(comp[j]==-1) dfs2(j,k++);
      }
      printf("Case %d: ",++cse);
      for(i=0;i<m;i++){               
        if(comp[i]==comp[i^1]) break;
      }
      if(i!=m) printf("No\n");                                                           
      else{
          printf("Yes\n");
          for(i=0;i<m;i+=2){
            j=comp[i]>comp[i^1]?i:i^1;
            if(j%2) path.push_back(j/2+1);
          }
          j=path.size();
          printf("%d",j);
          for(i=0;i<j;i++) printf(" %d",path[i]);
          printf("\n");
      }
    }
    return 0;
}
                                                 
