#include<bits/stdc++.h>
using namespace std;

struct node
{
    int mx,mn;
};
node tree[400005],ans;

void build(int low,int high,int a[],int pos)
{
    if(low == high)
    {
        tree[pos].mx = a[low];
        tree[pos].mn = a[low];
        return;
    }

    int mid = (low + high) / 2;
    int L = 2 * pos + 1;
    int R = 2 * pos + 2;
    build(low,mid,a,L);
    build(mid + 1,high,a,R);

    tree[pos].mx = max(tree[L].mx,tree[R].mx);
    tree[pos].mn = min(tree[L].mn,tree[R].mn);
}

node query(int qlow,int qhigh,int low,int high,int pos)
{
    if(qlow > high || qhigh < low)
    {
        node x;
        x.mx = -1;
        x.mn = INT_MAX;
        return x;
    }

    if(low >= qlow && qhigh >= high)
        return tree[pos];

    int mid = (low + high) / 2;
    node L = query(qlow,qhigh,low,mid,2 * pos + 1);
    node R = query(qlow,qhigh,mid + 1,high,2 * pos + 2);

    ans.mx = max(L.mx,R.mx);
    ans.mn = min(L.mn,R.mn);
    return ans;
}

int main()
{
  int a[100005],n,testCases,d,diff;
  node x;
  scanf("%d",&testCases);

  for(int test = 1; test <= testCases; test++)
  {
      scanf("%d %d",&n,&d);
      diff = 0;

      for(int i = 0; i < n; i++) scanf("%d",&a[i]);
      build(0, n - 1, a, 0);

      for(int i = 0; i < n; i++)
      {
          if(i + d - 1 < n)
          {
              x = query(i, i + d - 1,0, n - 1, 0);
              diff = max(diff, x.mx - x.mn);
          }
      }

      printf("Case %d: %d\n",test,diff);
  }

  return 0;
}
