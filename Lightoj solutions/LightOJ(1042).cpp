#include<bits/stdc++.h>
using namespace std;
string bin;

void dec2bin(int n)
{
    bin = "";

    while(n)
    {
        bin += (n % 2) + '0';
        n /= 2;
    }

     bin += '0';
    reverse(bin.begin(),bin.end());
}

long long bin2dec()
{
    long long ans = 0;
    long long base = 1;
    int len = bin.size();

    for(int i = len - 1; i >= 0 ; i--)
    {
        if(bin[i] == '1')
         ans += base;
         base = base * 2;
    }
    return ans;
}

int main()
{
    int testCases,n;
    long long ans;
    scanf("%d",&testCases);

    for(int test = 1; test <= testCases; test++)
    {
        scanf("%d",&n);
        int cnt = 0;
        dec2bin(n);

        do
        {
            ++cnt;
            ans = bin2dec();
            if(cnt == 2) break;

        }while(next_permutation(bin.begin(),bin.end()));

        if(cnt != 2) ans = ans * 2;
        printf("Case %d: %lld\n",test,ans);
    }
    return 0;
}
