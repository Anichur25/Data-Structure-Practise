#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long kase,a,b,c,k=0;
    scanf("%lld",&kase);
    while(kase--)
    {
        scanf("%lld%lld%lld",&a,&b,&c);
        a=(a*a);
        b=(b*b);
        c=(c*c);
        if(a==(b+c) || b==(a+c) || c==(a+b)) printf("Case %lld: yes\n",++k);
        else printf("Case %lld: no\n",++k);
    }
    return 0;
}
