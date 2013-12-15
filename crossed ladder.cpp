#include<cstdio>
#include<cmath>
#define EPS 1e-9
double cross_ladder(double x,double y,double c){
       double f,l=0.0,r,mid,a,b;
       r=x<y?x:y;
       while((r-l)>EPS){
         mid=(l+r)/2.0;
         a=sqrt(y*y-mid*mid);
         b=sqrt(x*x-mid*mid);               
         f=c-(a*b)/(a+b);
         if(f>EPS) r=mid;
         else if(f<-EPS) l=mid;
         else return mid;
       }
}
int main(){
    int i,n,cnt=0;
    double x,y,c;
    scanf("%d",&n);
    while(n--){
      scanf("%lf%lf%lf",&x,&y,&c);
      printf("Case %d: %.7lf\n",++cnt,cross_ladder(x,y,c));
    }         
    return 0;
}
