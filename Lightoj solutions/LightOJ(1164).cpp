#include<bits/stdc++.h>
using namespace std;

struct node
{
    long long sum;
    long long propValue;
} tree[400005];


void build(int low,int high,int pos)
{
    if(low == high)
    {
        tree[pos].sum = 0;
        tree[pos].propValue = 0;
        return;
    }

    int mid = (low + high) / 2;
    int L = (2 * pos) + 1;
    int R = (2 * pos) + 2;

    build(low,mid,L);
    build(mid + 1,high,R);
    tree[pos].sum = tree[L].sum + tree[R].sum;
    tree[pos].propValue = 0;
}

void update(int low,int high,int qlow,int qhigh,int pos,long long x)
{
    if(qlow > high || qhigh < low)
     return;

    if(qlow <= low && qhigh >= high)
    {
        tree[pos].sum += ((high - low + 1) * x);
        tree[pos].propValue += x;
        return;
    }

    int mid = (low + high) / 2;
    int L = (2 * pos) + 1;
    int R = (2 * pos) + 2;
    update(low,mid,qlow,qhigh,L,x);
    update(mid+1,high,qlow,qhigh,R,x);
    tree[pos].sum = tree[L].sum + tree[R].sum + (tree[pos].propValue * (high - low + 1));
}

long long query(int low,int high,int qlow,int qhigh,int pos,long long carry = 0)
{
   if(qlow > high || qhigh < low)
     return 0;

   if(qlow <= low && qhigh >= high)
   {
       return tree[pos].sum + carry * (high - low + 1);
   }

   int mid = (low + high) / 2;
   int L = (2 * pos) + 1;
   int R = (2 * pos) + 2;
   long long Lsum = query(low,mid,qlow,qhigh,L,carry + tree[pos].propValue);
   long long Rsum = query(mid+1,high,qlow,qhigh,R,carry + tree[pos].propValue);
   return Lsum + Rsum;
}

int main()
{
    int testCases,n,q,Q,x,y,v;
    scanf("%d",&testCases);

    for(int test = 1; test <= testCases; test++)
    {
        scanf("%d %d",&n,&q);
        build(0,n-1,0);
        printf("Case %d:\n",test);

        for(int i = 1; i <= q; i++)
        {
            scanf("%d",&Q);
            if(Q == 0)
            {
              scanf("%d %d %d",&x,&y,&v);
              update(0,n-1,x,y,0,v);
            }
            else
            {
                scanf("%d %d",&x,&y);
                printf("%lld\n",query(0,n-1,x,y,0,0));
            }
        }
    }
    return 0;
}
