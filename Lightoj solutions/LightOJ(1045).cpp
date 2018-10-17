#include<bits/stdc++.h>
using namespace std;

double digits[1000002];

void init_array(){

  for(int i = 1; i <= 1000000; i++){
    digits[i] = digits[i-1] + log(i);
  }
}

int main(){

   init_array();
   int case_number;
   int case_no = 0;
   int n,base;

   scanf("%d",&case_number);

   while(case_number--){
     scanf("%d%d",&n,&base);
     long long ans = (digits[n] / log(base)) + 1;
     printf("Case %d: %lld\n",++case_no, ans);
   }

   return 0;
}

