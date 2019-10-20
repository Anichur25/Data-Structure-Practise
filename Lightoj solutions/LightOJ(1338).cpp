#include<bits/stdc++.h>
using namespace std;
int main()
{
    int testCases;
    string s,p,first,second;
    scanf("%d",&testCases);
    getline(cin,s);

    for(int test = 1; test <= testCases; test++)
    {
       getline(cin,s);
       getline(cin,p);
       first = second = "";

       for(int i = 0; i < s.size(); i++)
           if(s[i] != ' ') first += tolower(s[i]);
        for(int i = 0; i < p.size(); i++)
           if(p[i] != ' ') second += tolower(p[i]);

       sort(first.begin(),first.end());
       sort(second.begin(),second.end());


       printf("Case %d: %s\n",test,(first == second)? "Yes" : "No");
    }
    return 0;
}
