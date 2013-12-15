#include<algorithm>
#include<cmath>
using namespace std;
#define MAX 50005
#define sq(x) ((x)*(x))
#define PI 3.1415926535897932384626433832795
#define EPS 1e-11
struct point
{
    int x,y;
    double arg;
} points[MAX+3], hull[MAX+3],base,hold;
double dist(point a)
{
    return (a.x-base.x)*(a.x-base.x) + (a.y-base.y)*(a.y-base.y);
}
bool cmp(point a, point b)
{
    if (fabs(a.arg-b.arg)<EPS) return dist(a) < dist(b);
    else return a.arg<b.arg;
}
inline double sqDist(point a, point b) {
	    return (sq(a.x-b.x) + sq(a.y-b.y));
}
void initialise(int n_point)
{
    int i;
    base.x = base.y = 1000000;
    for (i=0; i<n_point; ++i)
    {
        scanf("%d%d",&points[i].x,&points[i].y);
        if (points[i].y<base.y) base = points[i];
        else if (points[i].y==base.y && points[i].x<base.x) base = points[i];
    }
    for (i=0; i<n_point; ++i)
    {
        if (points[i].y == base.y) points[i].arg = 0;
        else if (points[i].x==base.x) points[i].arg = PI/2.0;
        else
        {
            double x = points[i].x - base.x;
            double y = points[i].y - base.y;
            points[i].arg = atan((double) y/x);
            if (points[i].arg<0) points[i].arg = points[i].arg + PI;
        }
    }
    sort(points, points+n_point, cmp);
}
int sign(double x)
{
    if (x<0) return -1;
    else if (x>0) return 1;
    else return 0;
}
int find_hull(int n_point)
{
    double x1,x2,y1,y2,a,b,c,g1,g2;
    int H=2,i=1;
    hull[0] = base;
    while(points[i].x==points[i-1].x && points[i].y==points[i-1].y) ++i;
    hull[1] = points[i];
    ++i;
    for (; i<n_point; ++i)
    {
        if (points[i].x == points[i-1].x && points[i].y == points[i-1].y) continue;
        hull[H] = points[i];
        while(H>1)
        {
            x1 = hull[H].x, y1 = hull[H].y, x2 = hull[H-2].x, y2 = hull[H-2].y;
            a = y1 - y2, b = x2 - x1, c = x1*y2-x2*y1;
            g1 = a*base.x + b*base.y + c, g2 = a*hull[H-1].x + b*hull[H-1].y + c;
            if (fabs(g2)<EPS || sign(g1)==sign(g2))
            {
                hull[H-1] = hull[H];
                --H;
            }
            else break;
        }
        ++H;
    }
    i = H-2;
    x1 = points[i].x, y1 = points[i].y, x2 = base.x, y2 = base.y;
    a = y1 - y2, b = x2 - x1, c = x1*y2-x2*y1;
    g1 = a*base.x + b*base.y + c, g2 = a*hull[H-1].x + b*hull[H-1].y + c;
    if (fabs(g2)<EPS || sign(g1)==sign(g2)) --H;
    return H;
}
void print(int n_point)
{
    int i;
    printf("base :: %d %d : %lf\n",base.x,base.y,base.arg);
    for (i=0; i<n_point; ++i) printf("%d %d : %lf\n",points[i].x,points[i].y,points[i].arg);
    puts("");
}
bool cmp2(point a, point b)
{
    double x = (a.x-hold.x)*(a.x-hold.x) + (a.y-hold.y)*(a.y-hold.y);
    double y = (b.x-hold.x)*(b.x-hold.x) + (b.y-hold.y)*(b.y-hold.y);
    return x<y;
}
void modify(long long n_point)
{
    long long i,j;
    for (i=2; i<n_point-1; ++i)
    {
        for (j=1; i+j<n_point; ++j)
        {
            if (fabs(hull[i+j-1].arg-hull[i+j].arg)<EPS) continue;
            else break;
        }
        if (j>1)
        {
            hold = hull[i-1];
            sort(hull+i, hull+i+j,cmp2);
        }
        i += (j-1);
    }
}
void print_hull(int n_point,double d,int cnt)
{
    int i;
    double dist=0.0;
    //puts("points on hull");
    for (i=0; i<n_point; ++i) printf("%d %d\n",hull[i].x,hull[i].y);
    for (i=1; i<n_point; ++i) dist+=sqrt(sqDist(hull[i],hull[i-1]));
    dist+=sqrt(sqDist(hull[0],hull[i-1]));
    dist+=(2*PI*d);
    printf("Case %d: %.8lf\n",cnt,dist);
}
int main()
{
    /*freopen("data.txt","r",stdin);*/
    int N,H,T,cnt=0;
    double d;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%lf",&N,&d);
        initialise(N);
       // print(N);
        H = find_hull(N);
        modify(H);
        print_hull(H,d,++cnt);
    }
    return 0;
}
