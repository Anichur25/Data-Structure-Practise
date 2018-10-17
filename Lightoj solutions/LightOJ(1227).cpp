#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,p,q,x[30],kase,caseno = 0;
  scanf("%d",&kase);

  while(kase--)
  {
    scanf("%d %d %d ",&n,&p,&q);

    int total = 0,cnt = 0,ans = 0;

    for(int i = 0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }
    for(int i = 0;i<n;i++)
    {
       total+=x[i];
       ++cnt;

       if(total>q || cnt>p) break;
       else ++ans;
    }

    printf("Case %d: %d\n",++caseno,ans);
  }

  return 0;
}
