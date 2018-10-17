#include<bits/stdc++.h>
using namespace std;

int main(){

 int test_cases;
 int case_no = 0;
 int sum;
 int n;
 int dust;

 scanf("%d",&test_cases);

 while(test_cases--){

    scanf("%d",&n);
    sum = 0;

    for(int i = 0; i < n; i++)
    {
        scanf("%d",&dust);
        if(dust > 0) sum+=dust;
    }

    printf("Case %d: %d\n",++case_no,sum);
 }
 return 0;
}
