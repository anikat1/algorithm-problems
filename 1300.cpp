#include<cstdio>
#include<cstring>
#define MAXN 10005
int visit[MAXN],cycle[MAXN],par[MAXN],edge[MAXN][MAXN];
int low[MAXN],dfsnum[MAXN],counter,n,m;
int flag;
void dfs(int cur,int parent){
     visit[cur]=1;
     low[cur]=dfsnum[cur]=counter++;
     int i;
     for(i=0;i<n;i++){
       if(edge[cur][i]){
         if(i==parent) continue;
         if(!visit[i]){
           dfs(i,cur);
           low[cur]=low[cur]<low[i]?low[cur]:low[i];
           if(low[i]>dfsnum[cur]){
              edge[i][cur]=edge[cur][i]=0;
           }
         }
         else if(visit[i]==1&&i!=parent){
              low[cur]=low[cur]<dfsnum[i]?low[cur]:dfsnum[i];
         }
       }
     }
     visit[cur]=2;
}                                                                      
void find_cycle(int node,int pa){
     par[node]=pa;
     int i;
     for(i=0;i<n;i++){
         if(edge[node][i]){                
           if(!par[i]) find_cycle(i,-pa);
           else if(par[i]==par[node]) flag=1;
         }
     }
}
void path(int node){
     visit[node]=cycle[node]=1;
     int i;
     for(i=0;i<n;i++){
        if(edge[node][i]&&!visit[i]) path(i);
     }
}                                                              
int main(){
    int t,cnt,i,j,ans;
    scanf("%d",&t);
    for(cnt=1;cnt<=t;cnt++){
        scanf("%d%d",&n,&m);
        for(i=0;i<=n;i++){
          visit[i]=0,cycle[i]=0;
          par[i]=0,dfsnum[i]=0;
          for(j=0;j<=n;j++) edge[i][j]=0;
        }
        while(m--){
           int u,v;        
           scanf("%d%d",&u,&v);
           edge[u][v]=1,edge[v][u]=1;
        }
        counter=0;
        for(i=0;i<n;i++){
           if(!visit[i]) dfs(i,-1);
        }                             
        memset(visit,0,sizeof(visit));
        flag=0;
        for(i=0;i<n;i++){
           if(!par[i]){
             flag=0;
             find_cycle(i,1);
             if(flag) path(i);
           }
        }
        ans=0;
        for(i=0;i<n;i++) if(cycle[i]) ans++;
        printf("Case %d: %d\n",cnt,ans);
    }
    return 0;
}                                                                                                   
    
