#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define N 1005
#define CLR(a) memset((a),0,sizeof((a)))
#define FRIN freopen("lojinput.txt","r",stdin)
#define FROUT freopen("lojoutput.txt","w",stdout)
inline int abs(int a){return (a<0?-a:a);}
vector<int>order,path;
vector<int>edge[2*N];
vector<int>edge2[2*N],tedge[2*N],tedge2[2*N];
int comp[2*N],C1[7][4],k,fi;
bool used[2*N];   
void reset(int m){
     int i;
     for(i=0;i<(m+2);i++){
        edge[i].clear();
        edge2[i].clear();
        tedge[i].clear();
        tedge2[i].clear();
     }
} 
void dfs1(int v){
     used[v]=true;
     int i,k,sz=tedge[v].size();
     for(i=0;i<sz;i++){
        k=tedge[v][i];
        if(!used[k]) dfs1(k);
     }
     order.push_back(v);
}
void dfs2(int v,int id){
     comp[v]=id;
     int i,k,sz=tedge2[v].size();
     for(i=0;i<sz;i++){                                 
        k=tedge2[v][i];
        if(comp[k]==-1) dfs2(k,id);
     }
}
              
void insert(int x,int y){
     edge[x^1].push_back(y);
     edge[y^1].push_back(x);
     edge2[y].push_back(x^1);
     edge2[x].push_back(y^1);
     tedge[x^1].push_back(y);
     tedge[y^1].push_back(x);
     tedge2[y].push_back(x^1);
     tedge2[x].push_back(y^1);     
}
bool two_sat(int n){
     int i,j,z;
     CLR(used);
     order.clear();
     path.clear();
     for(i=0;i<n;i++){
        if(!used[i]) dfs1(i);
      }
      memset(comp,-1,sizeof(comp));
      for(i=0,j=0;i<n;i++){
        z=order[n-i-1];
        if(comp[z]==-1) dfs2(z,j++);
      }
      for(i=0;i<n;i+=2){
        if(comp[i]==comp[i^1]) return false;
      }
      for(i=0;i<n;i+=2){                       
            j=comp[i]>comp[i^1]?i:i^1;
            if(j&1) path.push_back(j/2+1);
      }
      return true;
}                        
bool backtrack(int p,int n,vector<int>v){
     int z,f;
     bool res;
     for(int i=1;i<=3;i++){
       for(int j=0;j<n;j++){
         tedge[j].clear();
         tedge2[j].clear();               
         tedge[j].insert(tedge[j].begin(),edge[j].begin(),edge[j].end());
         tedge2[j].insert(tedge2[j].begin(),edge2[j].begin(),edge2[j].end());
       }               
       for(int j=0;j<p;j++){
         f=C1[j][0];
         z=C1[j][v[j]];
         if(f==1){     
            tedge[z^1].push_back(z);
            tedge2[z].push_back(z^1);
         }
         else{ 
            tedge[z].push_back(z^1);
            tedge2[z^1].push_back(z);
         }
       }
       f=C1[p][0];
       z=C1[p][i];
       if(f==1){    
            tedge[z^1].push_back(z);
            tedge2[z].push_back(z^1);
       }
       else{
            tedge[z].push_back(z^1);
            tedge2[z^1].push_back(z);
       }
       res=two_sat(n);
       if(p==k-1){
          if(res) return true;
       }
       else{
           if(!res) continue;
           v.push_back(i);
           if(backtrack(p+1,n,v)) return true; 
           v.pop_back();
       }
     }  
     return false;                                            
}
bool solve(int n){
     if(k==0) return two_sat(n);
     if(!two_sat(n)) return false;
     return backtrack(0,n,vector<int>());
}                                                         
int main(){
    int i,j,m,n,t,cse=0,x,y,z,tp;
    scanf("%d",&t); 
    while(t--){
      scanf("%d%d%d",&n,&m,&k);
      n*=2;
      reset(n);
      for(i=0;i<m;i++){
         scanf("%d%d%d",&tp,&x,&y);
         x=2*x-1;
         y=2*y-1;
         switch(tp){
            case 1: insert(x,y);
                    break;
            case 2: insert(x,y^1);
                    break;
            case 3: insert(x^1,y^1);
                    break;
            case 4: insert(x,y);
                    insert(x^1,y^1);
                    break;
         }        
         
      }
      for(i=0;i<k;i++) {
         scanf("%d%d%d%d",&j,&x,&y,&z);
         x=2*x-1;
         y=2*y-1;
         z=2*z-1;
            C1[i][0]=j;
            C1[i][1]=x;
            C1[i][2]=y;
            C1[i][3]=z;
      }
      printf("Case %d: ",++cse);                                                                                                        
      if(solve(n)){
          j=path.size();   
          printf("Possible %d",j);
          for(i=0;i<j;i++) printf(" %d",path[i]);
          printf(".\n");
      }
      else printf("Impossible.\n");
    }
    return 0;
}
