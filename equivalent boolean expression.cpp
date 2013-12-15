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
#define N 505
#define MOD 1000000007
#define inf 1<<28
#define LL long long
#define eps 1e-13
#define abs(a) (a)<0?(-a):(a)
#define CLR(a) memset((a),0,sizeof((a)))
#define CLR1(a) memset((a),-1,sizeof((a)))
#define FRIN freopen("F:\\input.txt","r",stdin)
#define FROUT freopen("F:\\output.txt","w",stdout)
#define CHECK_BIT(n,i) (n&(1<<i))
#define CHECK_BIT1(n,i) ((n>>i)&1)
/*******************************************************************/
char c1[103],c2[103];
char *c;
int msk,l1,l2;
int find_end(int f,int l){
	stack<int> ands,ors;
	bool va_found=false;
	int stacked=0,cnd; // first curly brace (
	for(;f<=l;f++){
		if(c[f]>='a'&&c[f]<='j') va_found=true;
		else if(c[f]=='(') stacked++;
		else if(c[f]==')') stacked--;
		if(!stacked&&va_found){
			if(c[f]=='&') ands.push(f);
			else if(c[f]=='|') ors.push(f);
			else cnd=f;
		}
	}
	if(!ors.empty()) return ors.top()-1;
	else if(!ands.empty()) return ands.top()-1;
	else return cnd;
}
bool rec(int f,int l){
	if(f==l) return CHECK_BIT(msk,c[f]-'a');
	int e=find_end(f,l);
	if(l==e){
		if(c[f]=='!') return !(rec(f+1,l));
		return rec(f+1,l-1);
	}
	bool b1,b2;
	b1=rec(f,e);
	b2=rec(e+2,l);
	if(c[e+1]=='|') return b1||b2;
	else return b1&&b2;
}
bool equival(){
	int i,lim/*,v*/;
	bool b1,b2;
	//v=0;
	//for(i=0;i<l1;i++) if(c1[i]>='a'&&c1[i]<='j') v=max(v,c1[i]-'a');
	//for(i=0;i<l2;i++) if(c2[i]>='a'&&c2[i]<='j') v=max(v,c2[i]-'a');
	//v++;
	lim=1<<10;
	for(msk=0;msk<lim;msk++){
		c=c1;
		b1=rec(0,l1);
		c=c2;
		b2=rec(0,l2);
		if(b1!=b2) return false;
	}
	return true;
}
int main(){
	//FRIN;
	int test,t,i,j;
	bool b1,b2;
	scanf("%d",&test);
	for(t=1;t<=test;t++){
		scanf("%s %s",c1,c2);
		l1=strlen(c1)-1;
		l2=strlen(c2)-1;
		printf("Case %d: %s\n",t,equival()?"Equivalent":"Not Equivalent");
	}
	return 0;
}
