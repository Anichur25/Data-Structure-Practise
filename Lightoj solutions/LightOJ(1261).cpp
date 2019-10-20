#include<bits/stdc++.h>
using namespace std;
set<int> s;
bool isOk(int number)
{
    int aVal;
    bool sign = false;
    if(number < 0) aVal = number * (-1),sign = true;
    else aVal = number;
    if(sign && s.find(aVal) == s.end())
        return true;
    if(!sign && s.find(aVal) != s.end())
     return true;
    return false;
}

int main()
{
    int testCases,n,m,K,p;
    int a[30][30],x;
    bool happy[30];

    scanf("%d",&testCases);

    for(int test = 1; test <= testCases; test++)
    {
        s.clear();
        scanf("%d %d %d",&n,&m,&K);
        memset(happy,false,sizeof(happy));

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < K; j++)
             scanf("%d",&a[i][j]);
        }

        scanf("%d",&p);
        for(int i = 0; i < p; i++)
        {
            scanf("%d",&x);
            s.insert(x);
        }

        for(int person = 0; person < n; person++)
        {
            for(int w = 0; w < K; w++)
            {
                if(isOk(a[person][w]))
                {
                    happy[person] = true;
                    break;
                }
            }
        }

        printf("Case %d: ",test);
        bool OK = true;
        for(int i = 0; i < n; i++)
        {
            if(happy[i] == false)
            {
                OK = false;
                break;
            }
        }

        printf("%s\n",OK? "Yes" : "No");
    }

    return 0;
}
