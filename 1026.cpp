#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define MAX 10010
using namespace std;
struct node{
       int u,v;
       node(){}
       node(int &a,int &b){u=a;v=b;}
       bool operator<(const node &B)const{
            if(u!=B.u) return u<B.u;
            else return v<B.v;
       }
};
int dfsnum[MAX],low[MAX],visit[MAX],n,ans;
vector<int>v[MAX];
vector<node>bridge;
void dfs(int cur,int parent,int counter){
     visit[cur]=1;
     low[cur]=dfsnum[cur]=counter;
     int i,j,sz;
     for(sz=v[cur].size(),i=0;i<sz;i++){
         j=v[cur][i];
         if(j==parent) continue;
         if(!visit[j]){
           dfs(j,cur,counter+1);
           low[cur]=low[cur]<low[j]?low[cur]:low[j];
           if(low[j]>dfsnum[cur]){
              ans++;
              if(cur<j) bridge.push_back(node(cur,j));
              else bridge.push_back(node(j,cur));
           }
         }
         else if(visit[j]==1){
              low[cur]=low[cur]<dfsnum[j]?low[cur]:dfsnum[j];
         }
     }
     visit[cur]=2;
}                                                                      
int main()
{
    int i,j,u,vi,k,t,cnt=0;
    scanf("%d",&t);
     while(t--){
      scanf("%d",&n);           
      for(i=0;i<=n;i++){
        dfsnum[i]=0;
        visit[i]=0;               
        v[i].clear();
      }
      bridge.clear();
      ans=0;
      for(i=0;i<n;i++){
         scanf("%d (%d)",&u,&j); 
         for(k=0;k<j;k++){
           scanf("%d",&vi);
           v[u].push_back(vi);
         }
      }
      for(i=0;i<n;i++){
         if(!visit[i]) dfs(i,0,0);
      }
      sort(bridge.begin(),bridge.end());
      printf("Case %d:\n",++cnt);
      printf("%d critical links\n",ans);
      for(i=0;i<bridge.size();i++){
             printf("%d - %d\n",bridge[i].u,bridge[i].v);
      }            
     }
   return 0;
}                                            
