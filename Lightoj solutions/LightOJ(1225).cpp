#include<bits/stdc++.h>
using namespace std;

long long getReverse(long long n){

  long long rev = 0;

   while(n){

     rev = (rev * 10) + (n % 10);
     n /= 10;
   }

   return rev;
}


int main(){

  int cases;
  int case_no = 0;
  long long number;

  scanf("%d",&cases);

  while(cases--){

    scanf("%lld",&number);
    printf("Case %d: ",++case_no);
    printf("%s\n",(number == getReverse(number))? "Yes" : "No");
  }
  return 0;
}
