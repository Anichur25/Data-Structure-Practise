#include<bits/stdc++.h>
using namespace std;
 
pair<int,int> ncr[1000001];
 
void solve(int,int []);
 
void init()
{
    int result[6];
 
    for(int i = 1; i <= 1000000; i++)
    {
        result[2] = result[5] = 0;
 
        if(i % 2 == 0 || i % 5 == 0)
            solve(i,result);
 
        ncr[i].first = result[2] + ncr[i-1].first;
        ncr[i].second = result[5] + ncr[i-1].second;
    }
}
 
 
 
void solve(int n,int ans[])
{
    int factors[] = {2,5};
 
    for(int i = 0; i < 2 ; i++)
    {
        while(n % factors[i] == 0)
        {
            ans[factors[i]]++;
            n /= factors[i];
        }
    }
}
 
 
int main()
{
 
    int cases;
    init();
 
    scanf("%d",&cases);
 
    for(int case_no = 1; case_no <= cases; case_no++)
    {
 
        int ans = 0;
 
        int n,r,store,p,q;
 
        scanf("%d%d%d%d",&n,&r,&p,&q);
 
        int arr[6] = {};
        arr[2] = arr[5] = 0;
        solve(p,arr);
 
        arr[2] *= q;
        arr[5] *= q;
 
        int two = (ncr[n].first + arr[2]) - (ncr[r].first + ncr[n - r].first);
        int five = (ncr[n].second + arr[5]) - (ncr[r].second + ncr[n - r].second);
 
        ans+=min(two,five);
 
        printf("Case %d: %d\n",case_no,ans);
    }
 
    return 0;
}