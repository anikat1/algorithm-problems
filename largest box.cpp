#include<cstdio>
#include<cmath>
#define FRIN freopen("lightojinput.txt","r",stdin)
#define FROUT freopen("lightojoutput.txt","w",stdout)
#define LL long long
int main(){
   FRIN;
   FROUT; 
   int t,cnt=0;
   double v,x1,x2,s,l,w,a,b,c,v1,v2;
   scanf("%d",&t);
   while(t--){
      scanf("%lf%lf",&l,&w);
      b=-(4.0*(l+w));
      c=l*w;
      s=sqrt(b*b-48.0*c);
      x1=(-b+s)/24.0;
      x2=(-b-s)/24.0;
      v1=(24.0*x1)-(4.0*(l+w));
      v2=(24.0*x2)-(4.0*(l+w));
      if(v1<0) v=(4*x1*x1*x1)-(2.0*x1*x1*(l+w))+(l*w*x1);
      else if(v2<0) v=(4*x2*x2*x2)-(2.0*x2*x2*(l+w))+(l*w*x2);
      printf("Case %d: %.8lf\n",++cnt,v);
   }
   return 0;
}        
