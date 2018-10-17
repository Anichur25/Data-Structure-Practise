#include<bits/stdc++.h>
using namespace std;

int main(){

  long long sum;
  long long n,m;
  int test_case;
  int t = 0;

   cin >> test_case;

   while(test_case--){
   cin >> n >> m;
   sum = (n / 2) * m;
   cout<<"Case "<<++t<<": "<<sum<<endl;
}
  return 0;
}
