#include<bits/stdc++.h>
using namespace std;

int main()
{
   long long n;
   int cases;

   scanf("%d",&cases);

   for(int i = 1; i <= cases; i++)
   {
       scanf("%lld",&n);
       int ans = sqrt(n);
       ans += sqrt(n / 2.0);
       printf("Case %d: %lld\n",i,n - ans);
   }
   return 0;
}
