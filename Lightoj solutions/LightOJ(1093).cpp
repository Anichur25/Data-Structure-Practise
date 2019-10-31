#include<bits/stdc++.h>
using namespace std;
int main()
{
    multiset<int> s;
    multiset<int> :: iterator it;
    int ans,maximum,minimum,a[100005],n,d,testCases;

    scanf("%d",&testCases);

    for(int test = 1; test <= testCases; test++)
    {
        ans = 0;
        s.clear();
        scanf("%d %d",&n,&d);
        for(int i = 0; i < n; i++) scanf("%d",&a[i]);
        for(int i = 0; i < d; i++) s.insert(a[i]);

        for(int i = 0; i < n; i++)
        {
            it = s.begin();
            minimum = *it;
            it = s.end();
            --it;
            maximum = *it;
            ans = max(ans,(maximum - minimum));
            it = s.find(a[i]);
            s.erase(it);
            if(i + d < n)
                s.insert(a[i + d]);
        }

        printf("Case %d: %d\n",test,ans);

    }

   return 0;
}
