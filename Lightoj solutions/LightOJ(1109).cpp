#include<bits/stdc++.h>
using namespace std;

struct v
{
    int n;
    int div;
};

bool cmp(const v& a,const v& b)
{
    if(a.div==b.div)
    {
        return a.n>b.n;
    }
    else return a.div<b.div;
}

int main()
{
  v arr[1001];
  for(int i=1;i<=1000;i++)
  {
      arr[i].n = i;
      arr[i].div = 0;
      for(int j=1;j*j<=i;j++)
      {
          if(i%j==0 && j*j!=i) arr[i].div+=2;
          else if(i%j==0) arr[i].div+=1;
      }
  }

  sort(arr+1,arr+1001,cmp);
  int kase,N;
  scanf("%d",&kase);
  for(int i=1;i<=kase;i++)
  {
      scanf("%d",&N);
      printf("Case %d: %d\n",i,arr[N].n);
  }
  return 0;
}
