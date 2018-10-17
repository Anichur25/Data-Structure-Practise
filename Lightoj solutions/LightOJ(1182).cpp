#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long kase,caseno = 0,n;
  scanf("%lld",&kase);
  while(kase--)
  {
      scanf("%lld",&n);
      long long cnt  = 0;
      printf("Case %lld: ",++caseno);
      while(n)
      {
          if(n&1) ++cnt;
          n >>=1;
      }
      if(cnt%2) printf("odd\n");
      else printf("even\n");
  }
  return 0;
}
