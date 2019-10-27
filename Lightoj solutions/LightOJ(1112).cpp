#include<bits/stdc++.h>
using namespace std;
int segment_tree[400005];
int sack[100005];

void build(int low,int high,int pos)
{
    if(low == high)
    {
        segment_tree[pos] = sack[low];
        return;
    }

    int mid = (low + high) / 2;
    build(low,mid,2 * pos + 1);
    build(mid + 1,high,2 * pos + 2);
    segment_tree[pos] = segment_tree[2 * pos + 1] + segment_tree[2 * pos + 2];
}

int query(int low,int high,int qlow,int qhigh,int pos)
{
    if(qlow > high || qhigh < low)
     return 0;
    if(low >= qlow && qhigh >= high)
        return segment_tree[pos];
    int mid = (low + high) / 2;
    int Left = query(low,mid,qlow,qhigh,2 * pos + 1);
    int Right = query(mid + 1, high,qlow,qhigh, 2 * pos + 2);
    return Left + Right;
}

void update(int low,int high,int pos,int idx,int newValue,int choice)
{
    if(idx > high || idx < low)
        return;
    if(low >= idx && high <= idx)
    {
        if(choice == 1)
        {
            printf("%d\n",segment_tree[pos]);
           segment_tree[pos] = 0;
           return;
        }

        else
        {
             segment_tree[pos] += newValue;
             return;
        }
    }

    int mid = (low + high) / 2;
    update(low,mid,2 * pos + 1,idx,newValue,choice);
    update(mid + 1, high, 2 * pos + 2,idx,newValue,choice);
    segment_tree[pos] = segment_tree[2 * pos + 1] + segment_tree[2 * pos + 2];
}
int main()
{
    int testCases,n,q,idx,newValue,L,R,choice;
    scanf("%d",&testCases);

    for(int test = 1; test <= testCases; test++)
    {
        scanf("%d %d",&n,&q);
        for(int i = 0; i < n; i++) scanf("%d",&sack[i]);
        build(0,n - 1,0);
        printf("Case %d:\n",test);

        for(int i = 0; i < q; i++)
        {
            scanf("%d",&choice);
            if(choice == 1)
            {
                scanf("%d",&idx);
                update(0, n - 1,0,idx,0,1);
            }
            else if(choice == 2)
            {
                scanf("%d %d",&idx,&newValue);
                update(0,n-1,0,idx,newValue,2);
            }
            else
            {
                scanf("%d %d",&L,&R);
                printf("%d\n",query(0, n - 1,L ,R ,0));
            }
        }
    }

    return 0;
}
