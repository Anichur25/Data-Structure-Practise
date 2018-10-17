#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x1,x2,y1,y2,x,y,kase,query,k=0;
    scanf("%d",&kase);
    while(kase--)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        scanf("%d",&query);
        printf("Case %d:\n",++k);
        while(query--)
        {
            scanf("%d %d",&x,&y);
            if(x>=x1&&x<=x2&&y>=y1&&y<=y2)
            {
                printf("Yes\n");
            }
            else printf("No\n");
        }
    }
  return 0;
}
