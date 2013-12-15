#include<cstdio>
#include<cstring>
int a[100003];
int main(){
	//freopen("lojinput.txt","r",stdin);
	int j,t,n,i,d,k,m;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		scanf("%d",&n);
		k=0;
		a[0]=0;
		for(j=1;j<=n;j++){
			scanf("%d",&a[j]);
			d=a[j]-a[j-1];
			if(d>k) k=d;
		}
		m=k;
		for(j=1;j<=n;j++){
			d=a[j]-a[j-1];
			if(d==k) k--;
			else if(d>k) {
			  m++;
			  break;
			}
		}
		printf("Case %d: %d\n",i,m);
	}
	return 0;
}
