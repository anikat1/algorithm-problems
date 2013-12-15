#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#define MAX 10010
using namespace std;
int ans,low[MAX],dfsnum[MAX],visit[MAX],ap[MAX],counter;
vector<int>v[MAX];
void dfs(int cur,int parent){
     visit[cur]=1;
     low[cur]=dfsnum[cur]=counter++;
     int i,j,child=0;
     for(i=0;i<v[cur].size();i++){
         j=v[cur][i];
         if(!visit[j]){
           dfs(j,cur);
           child++;
           low[cur]=low[cur]<low[j]?low[cur]:low[j];
           if((cur!=1&&dfsnum[cur]<=low[j])||(cur==1&&child>1)){
              if(!ap[cur]){
                 ans++;
                 ap[cur]=1;
              }
           }
         }
         else if(j!=parent){
              low[cur]=low[cur]<dfsnum[j]?low[cur]:dfsnum[j];
         }
     }
     visit[cur]=2;
}    
int main()
{
    int n,m,i,j,x,y,t,cnt=0;
    while(scanf("%d",&t)!=EOF){
      while(t--){
       scanf("%d%d",&n,&m);
       for(i=0;i<=n;i++) {
           v[i].clear();
           visit[i]=0;
           ap[i]=0;
           dfsnum[i]=0;
       }
       while(m--){
          scanf("%d%d",&x,&y);
          v[x].push_back(y);                   
          v[y].push_back(x);
       }
       ans=0;
       counter=1;
       dfs(1,-1);
       printf("Case %d: %d\n",++cnt,ans);
      }
    }                
    return 0;
}                                                                    
