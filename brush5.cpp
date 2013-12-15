#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#define INF 2147483647
using namespace std;
typedef struct{
        int y;
        int cst;
}edge;
bool operator<(edge x,edge y){
     return x.cst>y.cst;
}
vector<edge>node[110];
bool visit[110];
int bellman(int n){
     int i,j;
     priority_queue<edge>q;
     edge t,p;
     t.y=1;
     t.cst=0;
     for(i=1;i<=n;i++) {
        visit[i]=0;
     }
     q.push(t);
     while(!q.empty()){
       t=q.top(); 
       q.pop();
       if(t.y==n) return t.cst;
       if(visit[t.y]) continue;
       visit[t.y]=1;                            
       for(j=0;j<node[t.y].size();j++){
           p=node[t.y][j];
           if(!visit[p.y]){
             p.cst=p.cst+t.cst;
             q.push(p);
           }
       }
     }
     return -1;
}
int main()
{
    int t,cse=0,n,m,i,u,v;
    edge w;
    while(scanf("%d",&t)!=EOF){
      while(t--){
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++) node[i].clear();
        while(m--){
          scanf("%d%d%d",&u,&v,&w.cst);
          w.y=v;
          node[u].push_back(w);
          w.y=u;
          node[v].push_back(w); 
        }
        i=bellman(n);
        printf("Case %d: ",++cse);
        if(i==-1) printf("Impossible\n");
        else printf("%d\n",i); 
      }
    }
    return 0;
}                                           
     
