#include<bits/stdc++.h>
using namespace std;

void Quadratic()
{
    //we consider the equation : 2x^2 + 5x + 3 = 0
    double x1,x2,a,b,c;
    a = 2,b = 5,c = 3;

    x1 = (-b + sqrt((b * b) - (4 * a * c))) / (2 * a);
    x2 = (-b - sqrt((b * b) - (4 * a * c))) / (2 * a);
    cout <<"Roots are : x1 = " << x1 << ", x2 = " << x2 << endl;
}

void Cubic()
{
    //we consider the equation x^3 + 7x^2 + 14x + 8 = 0
    double x1,x2,x3,a,b,c,d;
    a = 1,b = 7,c = 14,d = 8;
    int ar[4] = {1,2,4,8}; // These are the divisors of 8

    for(int i = 0; i < 4; i++)
     for(int j = 0; j < 4; j++)
      for(int k = 0; k < 4; k++){
         if(j != i && k != i && k != j){
            if(ar[i] + ar[j] + ar[k] == b && ar[i] * ar[j] * ar[k] == d){
                x1 = -ar[i];
                x2 = -ar[j];
                x3 = -ar[k];
            }
         }
      }

    cout <<"Roots are : x1 = " << x1 << ", x2 = " << x2 << ", x3 = " << x3 << endl;
}

int main()
{
    Quadratic();
    Cubic();
}
