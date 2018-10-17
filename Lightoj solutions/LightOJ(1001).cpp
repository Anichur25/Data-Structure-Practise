#include<bits/stdc++.h>
using namespace std;
int main()
{
    int kase,a;
    scanf("%d",&kase);
    while(kase--)
    {
        scanf("%d",&a);
       if(a>10)
       {
           if(a%2)
           {
               printf("%d %d\n",(a/2)+1,(a/2));
           }
           else printf("%d %d\n",(a/2),(a/2));
       }
       else printf("%d %d\n",0,a);
    }
    return 0;
}
