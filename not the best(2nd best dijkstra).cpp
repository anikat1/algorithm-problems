#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>

#include<cmath>
#include<iostream>
#include<fstream>

#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
using namespace std;
#define N 5005
#define MOD 1000000007
#define inf 1<<28
#define LL long long
#define eps 1e-13
#define abs(a) (a)<0?(-a):(a)
#define CLR(a) memset((a),0,sizeof((a)))
#define CLR1(a) memset((a),-1,sizeof((a)))
#define FRIN freopen("F:\\input.txt","r",stdin)
#define FROUT freopen("F:\\output.txt","w",stdout)
struct point{
	int x,y,w;
	bool operator<(point p)const{
    	return w>p.w;
	}
};
vector<point>edge[N];
int v,e,d1[3][N];
bool vi[3][N];
void reset(int v){
     int i;
     for(i=0;i<=v;i++) {
       edge[i].clear();
       vi[1][i]=false;
       vi[2][i]=false;
       d1[1][i]=inf;
       d1[2][i]=inf;
	 }
}
int dijkstra(int s,int t){
    priority_queue<point>q;
    int i,sz,j;
    point te,cur;
    te.x=1;
    te.y=s;
    te.w=0;
    d1[1][s]=0;
    q.push(te);
    while(!q.empty()){
       te=q.top();
       q.pop();
       if(vi[te.x][te.y]) continue;
       vi[te.x][te.y]=true;
       //if(te.y==t) break;
       sz=edge[te.y].size();
       for(i=0;i<sz;i++){
             cur=edge[te.y][i];
             j=d1[te.x][te.y]+cur.w;
             if(j<d1[1][cur.y]){
               d1[2][cur.y]=d1[1][cur.y];
			   cur.x=2;
			   cur.w=d1[2][cur.y];
               q.push(cur);
               cur.x=1;
               d1[1][cur.y]=j;
               cur.w=d1[1][cur.y];
               q.push(cur);
               //if(cur.y==t) break;
             }
			 else if(j>d1[1][cur.y]&&j<d1[2][cur.y]){
			 	d1[2][cur.y]=j;
			 	cur.x=2;
			 	cur.w=d1[2][cur.y];
			 	q.push(cur);
			 }                   
       }
    }
   // printf("ds=%d\n",d1[t]);
    //printf("ds=%d\n",ds);
    return d1[2][t];
}                                     
int main(){
	//FRIN;
	int test,t,i,j;
	point tp;
	scanf("%d",&test);
	for(t=1;t<=test;t++){
		scanf("%d%d",&v,&e);
		reset(v);
		for(i=0;i<e;i++){
			scanf("%d%d%d",&tp.x,&tp.y,&tp.w);
			edge[tp.x].push_back(tp);
			j=tp.x;
			tp.x=tp.y;
			tp.y=j;
			edge[tp.x].push_back(tp);
		}
		j=dijkstra(1,v);
		printf("Case %d: %d\n",t,j);
	}
	return 0;
}
