#include<bits/stdc++.h>
using namespace std;
long long fact[21];
int len;
int cnt[27];
string ans = "";
void Init()
{
    long long mul = 1;
    fact[0] = 1;

    for(int i = 1; i <= 20; i++)
    {
        mul *= i;
        fact[i] = mul;
    }
}

void solve(long long &x,int idx)
{
    long long ways;
    for(int i = 0; i < 26; i++)
    {
        ways = 0;
        if(cnt[i])
        {
            ways = fact[len - idx];
            for(int j = 0; j < 26; j++)
            {
                if(cnt[j])
                {
                    if(j == i)
                        ways = ways / fact[cnt[j]-1];
                    else
                        ways = ways / fact[cnt[j]];
                }
            }
            if(ways >= x)
            {
                ans += i + 'a';
                cnt[i]--;
                break;
            }
            else
                x -= ways;
        }
    }
}

int main()
{

    Init();
    char s[25];
    int testCases;
    long long pos;
    scanf("%d",&testCases);

    for(int test = 1; test <= testCases; test++)
    {
        memset(cnt,0,sizeof(cnt));
        scanf("%s %lld",s,&pos);

        len = strlen(s);
        ans = "";
        long long permutation = fact[len];
        for(int i = 0; i < len; i++)
            cnt[s[i] - 'a']++;

        for(int i = 0; i < 26; i++)
        {
            if(cnt[i])
               permutation /= fact[cnt[i]];
        }

        if(pos > permutation) ans  = "Impossible";
        else
        {
            for(int p = 1; p <= len; p++)
            solve(pos,p);
        }
        printf("Case %d: %s\n",test,ans.c_str());
    }

    return 0;
}

