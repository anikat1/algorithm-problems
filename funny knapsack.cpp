#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define LL long long
#define N 31
#define CLR(a) memset((a),0,sizeof((a)))
int main(){
    int t,cse=0,n,i,j,k,p1,p2,sz;
    LL w,res,ls[N],sum,tp;
    vector<LL>W;
    vector<LL>::iterator up;
    scanf("%d",&t);
    while(t--){
        for(scanf("%d%lld",&n,&w),i=0;i<n;i++) scanf("%lld",&ls[i]);
        res=0;
        p1=n>>1;
        p2=n-p1;
        W.clear();
        //printf("p1=%d p2=%d\n",p1,p2);
        for(i=0;i<(1<<p1);i++){
            sum=0;
            for(j=0;j<p1;j++){
                if(i&(1<<j)) sum+=ls[j];
            }
            if(sum<=w) {
               // printf("sum1=%lld\n",sum);
                W.push_back(sum);
               // res++;
            }
        }
        sort(W.begin(),W.end());
        sz=W.size();
        for(i=0;i<(1<<p2);i++){
            sum=0;
            for(j=0;j<p2;j++){
                if(i&(1<<j)) sum+=ls[p1+j];
            }
            //printf("sum2=%lld\n",sum);
            tp=w-sum;
           // if(sum) {
             up=upper_bound (W.begin(), W.end(),tp);
            // printf("sum2=%lld up=%d\n",tp,up-W.begin());
             res+=(up-W.begin());
           // }
        }
        printf("Case %d: %lld\n",++cse,res);
    }
    return 0;
}

