#include<bits/stdc++.h>
using namespace std;

void singleTerm(int a[],int n)
{
   long long sum = 0; // series a + b + c + ......

   for(int i = 0; i < n; i++) sum += a[i];
   cout <<"Sum using single term: " << sum << endl;
}

void twoTerm(int a[],int n)
{
    long long sum = 0; // series ab + bc + ca + ....

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i != j)
             sum += a[i] * a[j];
        }
    }

    cout << "Sum using two terms: " << sum / 2 << endl;
}

void threeTerm(int a[],int n)
{
    long long mul = 1,sum = 0; // series abc + def + .....
    for(int i = 0; i < n; i++)
    {
        mul *= a[i];
        if((i+1) % 3 == 0)
        {
            sum += mul;
            mul = 1;
        }
    }

    cout <<"Sum using three terms : " << sum << endl;
}

void sinSeries()
{
    int n;
    double ans = 0;
    cout << "How many terms : ";
    cin >> n;

}

int main()
{
    int n;
    cin >> n;
    int a[n];

    for(int i = 0; i < n; i++) cin >> a[i]; //getting input
    singleTerm(a,n);
    twoTerm(a,n);
    threeTerm(a,n);

    return 0;
}
