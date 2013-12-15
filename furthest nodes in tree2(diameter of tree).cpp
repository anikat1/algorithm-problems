#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<sstream>
#define MAX 30010
using namespace std;
#define FRIN freopen("lojinput.txt","r",stdin)
#define FRINI freopen("sample.in.txt","r",stdin)
#define FROUT freopen("lojoutput2.txt","w",stdout)
#define LL long long
#define CLR(a) memset((a),-1,sizeof((a)))
struct edge{
       int a,c;
};
vector<edge>v[MAX];
int dis1[MAX],dis2[MAX],n;
void bfs(int st){
    queue<int>q;
    CLR(dis1);
    CLR(dis2);
    dis1[st]=0;
    q.push(st);
    int max_dist=0,i,sz,tmp,p;
    while(!q.empty()){
        tmp=q.front();
        q.pop();
        sz=v[tmp].size();
        for(i=0;i<sz;i++){
            p=v[tmp][i].a;
            if(dis1[p]<0){
                dis1[p]=dis1[tmp]+v[tmp][i].c;
                q.push(p);
                if(max_dist<dis1[p]) {
                        max_dist=dis1[p];
                        st=p;
                }
            }
        }
    }
    CLR(dis1);
    q.push(st);
    dis1[st]=0;
    max_dist=0;
    while(!q.empty()){
        tmp=q.front();
        q.pop();
        sz=v[tmp].size();
        for(i=0;i<sz;i++){
            p=v[tmp][i].a;
            if(dis1[p]<0){
                dis1[p]=dis1[tmp]+v[tmp][i].c;
                q.push(p);
                if(max_dist<dis1[p]) {
                    max_dist=dis1[p];
                    st=p;
                }
            }
        }
    }
    q.push(st);
    dis2[st]=0;
    while(!q.empty()){
        tmp=q.front();
        q.pop();
        sz=v[tmp].size();
        for(i=0;i<sz;i++){
            p=v[tmp][i].a;
            if(dis2[p]<0){
                dis2[p]=dis2[tmp]+v[tmp][i].c;
                q.push(p);
            }
        }
    }
    //for(i=0;i<n;i++) printf("%d %d\n",dis1[i],dis2[i]);
}
int main(){
  //  FRINI;
  //  FROUT;
    int i,j,t,cnt=0,u,vi;
    scanf("%d",&t);
    edge tmp;
    while(t--){
      scanf("%d",&n);
      for(i=0;i<n;i++) v[i].clear();
      for(i=1;i<n;i++) {
        scanf("%d%d%d",&u,&vi,&tmp.c);
        tmp.a=vi;
        v[u].push_back(tmp);
        tmp.a=u;
        v[vi].push_back(tmp);
      }
      printf("Case %d:\n",++cnt);
      bfs(0);
      for(i=0;i<n;i++){
        printf("%d\n",max(dis1[i],dis2[i]));
      }
    }
    return 0;
}
