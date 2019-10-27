#include<bits/stdc++.h>
using namespace std;

long long solve(int a[],int n)
{
    long long ans = 0,area;
    int i = 0;
    stack<int> s;

    while(i < n)
    {
        if(s.empty() || a[s.top()] <= a[i])
         s.push(i++);
        else
        {
            int topidx = s.top();
            s.pop();
            area = (s.empty())? a[topidx] * i : (i - s.top() - 1) * a[topidx];
            ans = max(ans,area);
        }
    }

    while(!s.empty())
    {
        int topidx = s.top();
        s.pop();
        area = (s.empty())? a[topidx] * i : (i - s.top() - 1) * a[topidx];
        ans = max(ans,area);
    }

    return ans;
}
int main()
{
  int testCases,n,a[30002];
  scanf("%d",&testCases);

  for(int test = 1; test <= testCases; test++)
  {
      scanf("%d",&n);
      for(int i = 0; i < n; i++) scanf("%d",&a[i]);
      printf("Case %d: %lld\n",test,solve(a,n));
  }
  return 0;
}
