#include<bits/stdc++.h>
using namespace std;

vector<int> ans;

int generate_sequence(int a,int b,int mod)
{
     int f1 = a % mod;
     int f2 = b % mod;
     int f3;
    a = a % mod;
    b = b % mod;
    ans.push_back(a);
    ans.push_back(b);

    for(int i = 2;; i++)
    {
        if(f1 == a && f2 == b && i != 2)
        {
            return i - 2;
        }

        f3 = f2 + f1;
        f3 %= mod;
        f1 = f2;
        f2 = f3;
        ans.push_back(f3);
    }
}


int main()
{
    int cases;
    int  case_no = 0;
    int a,b,n,m;

    scanf("%d",&cases);

    while(cases--)
    {
       ans.clear();
       scanf("%d %d %d %d",&a,&b,&n,&m);
       int  mod = 1;

       for(int i = 1; i <= m; i++)
         mod *= 10;

       int c = generate_sequence(a,b,mod);
       printf("Case %d: %d\n",++case_no,ans[n % c]);
    }

    return 0;
}
