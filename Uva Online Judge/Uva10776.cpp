#include<bits/stdc++.h>
using namespace std;
int r,freq[150];
char ans[35];

void solve(int idx,char prev)
{
    if(idx == r)
    {
        ans[r] = '\0';
        printf("%s\n",ans);
        return;
    }

    for(int i = 0; i < 26; i++)
    {
        char ch = i + 'a';
        if(prev <= ch &&  freq[ch])
        {
            ans[idx] = ch;
            freq[ch] -= 1;
            solve(idx + 1,ch);
            freq[ch] += 1;
        }
    }
}
int main()
{
    char str[35];

    while(scanf("%s %d",str,&r) != EOF)
    {
        memset(freq,0,sizeof(freq));
        int len = strlen(str);
        for(int i = 0; i < len; i++)
        freq[str[i]]++;
        solve(0,'A');
    }

    return 0;
}
