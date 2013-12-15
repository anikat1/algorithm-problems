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
#define N 21
#define MOD 1000000007
#define inf 1<<28
#define abs(a) (a)<0?(-a):(a)
#define CLR(a) memset((a),0,sizeof((a)))
#define FRIN freopen("F:\\input.txt","r",stdin)
#define FROUT freopen("F:\\output.txt","w",stdout)
struct point{
	int x,y;
	bool operator==(point p){
		if(x==p.x&&y==p.y) return true;
		else return false;
	}
};
char board[N][N];
bool visit[N][N];
int dis[N][N],m,n;
point a,b,c,h;
int dx[]={0,0,-1,1},dy[]={1,-1,0,0};
inline bool valid(int x,int y){
	if(x>=0&&x<m&&y>=0&&y<n) {
		if(board[x][y]=='m'||board[x][y]=='#') return false;
		else return true;
	}
	return false;
}
int bfs(){
	point t,p;
	int x,y,z,i;
	queue<point>q;
    CLR(visit);
    CLR(dis);
    q.push(a);
    while(!q.empty()){
       t=q.front();
       q.pop();
       if(t==h) {
   	   		x=dis[h.x][h.y];
   	   		break;
	   }
       for(i=0;i<4;i++){
       	  p.x=t.x+dx[i];
		  p.y=t.y+dy[i];			 	
          if(valid(p.x,p.y)&&!visit[p.x][p.y]) {
             visit[p.x][p.y]=1;
             q.push(p);
             dis[p.x][p.y]=dis[t.x][t.y]+1;
          }
       }
    }
    while(!q.empty()) q.pop();
    CLR(visit);
    CLR(dis);
    q.push(b);
    while(!q.empty()){
       t=q.front();
       q.pop();
       if(t==h) {
   	   		y=dis[h.x][h.y];
   	   		break;
	   }
       for(i=0;i<4;i++){
       	  p.x=t.x+dx[i];
		  p.y=t.y+dy[i];			 	
          if(valid(p.x,p.y)&&!visit[p.x][p.y]) {
             visit[p.x][p.y]=1;
             q.push(p);
             dis[p.x][p.y]=dis[t.x][t.y]+1;
          }
       }
    }
    while(!q.empty()) q.pop();
    CLR(visit);
    CLR(dis);
    q.push(c);
    while(!q.empty()){
       t=q.front();
       q.pop();
       if(t==h) {
   	   		z=dis[h.x][h.y];
   	   		break;
	   }
       for(i=0;i<4;i++){
       	  p.x=t.x+dx[i];
		  p.y=t.y+dy[i];			 	
          if(valid(p.x,p.y)&&!visit[p.x][p.y]) {
             visit[p.x][p.y]=1;
             q.push(p);
             dis[p.x][p.y]=dis[t.x][t.y]+1;
          }
       }
    }
    i=max(x,max(y,z));
    return i;
}
int main(){
	int test,i,j,k;
	scanf("%d",&test);
	for(i=1;i<=test;i++){
		scanf("%d%d",&m,&n);
		for(j=0;j<m;j++) {
		  scanf("%s",board[j]);
		  for(k=0;k<n;k++){
		  	if(board[j][k]=='a') a.x=j,a.y=k;
		  	else if(board[j][k]=='b') b.x=j,b.y=k;
		  	else if(board[j][k]=='c') c.x=j,c.y=k;
		  	else if(board[j][k]=='h') h.x=j,h.y=k;
		  }
		}
		k=bfs();
		printf("Case %d: %d\n",i,k);
	}
	return 0;
}
