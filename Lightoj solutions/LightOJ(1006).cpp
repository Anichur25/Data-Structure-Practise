#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long kase,caseno = 0,fn[10001],n;
  scanf("%lld",&kase);
  while(kase--)
  {
      scanf("%lld%lld%lld%lld%lld%lld%lld",&fn[0],&fn[1],&fn[2],&fn[3],&fn[4],&fn[5],&n);
      if(n>=6)
      {
      for(int i = 6 ;i<=n;i++)
      {
          fn[i] = fn[i-1]+fn[i-2]+fn[i-3]+fn[i-4]+fn[i-5]+fn[i-6];
          fn[i]%=10000007;
      }
      printf("Case %lld: %lld\n",++caseno,fn[n]);
      }
      else
      {
          printf("Case %lld: ",++caseno);

          printf("%lld\n",fn[n]%10000007);
      }
  }
  return 0;
}

