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
#define N 53
#define M 1003
#define MOD 1000000007
#define inf 1<<28
#define LL long long
#define eps 1e-13
#define abs(a) (a)<0?(-a):(a)
#define PB push_back
#define CLR(a) memset((a),0,sizeof((a)))
#define CLR1(a) memset((a),-1,sizeof((a)))
#define FRIN freopen("F:\\input.txt","r",stdin)
#define FROUT freopen("F:\\output.txt","w",stdout)
struct point{
	int x,y;
};
int n,A[N],C[N],coin[N][M];
int coin_change(int val){
    int i,j;
    sort(A+1,A+n+1);
    coin[0][0]=1;
    for(i=1;i<=n;i++){
        for(j=1;j<=val;j++){

        }
    }

}
int main(){
	int t,test,k;
	scanf("%d",&test);
	for(t=1;t<=test;t++){
        scanf("%d%d",&n,&k);
        for(i=1;i<=n;i++) scanf("%d",&A[i]);
        for(i=1;i<=n;i++) scanf("%d",&C[i]);
        printf("Case %d: %d\n",t,coin_change(k));
	}
	return 0;
}

