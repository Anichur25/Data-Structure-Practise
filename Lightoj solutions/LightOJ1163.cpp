#include<bits/stdc++.h>
using namespace std;
int main()
{
    int testCases;
    long double cal;
    unsigned long long first,last,d,ans;

    scanf("%d",&testCases);

    for(int test = 1; test <= testCases; test++)
    {
        cin >> d;
        cal = (10 * d) / 9;
        last = cal;
        first = last;

        while((first - (first / 10)) == d)
          --first;

         printf("Case %d:",test);

        for(ans = first + 1; ans <= last; ans++)
         cout << " "<< ans;
         printf("\n");
    }
    return 0;
}
