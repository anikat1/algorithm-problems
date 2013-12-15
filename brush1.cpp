#include<cstdio>
int main()
{
    int t,cse=0,no,stu,dst;
    while(scanf("%d",&t)!=EOF){
       while(t--){
         scanf("%d",&stu);
         no=0;
         for(int i=0;i<stu;i++){
                scanf("%d",&dst);
                if(dst>0) no+=dst;
         }
         printf("Case %d: %d\n",++cse,no);
       }
    }
    return 0;
}                                  
    
    
