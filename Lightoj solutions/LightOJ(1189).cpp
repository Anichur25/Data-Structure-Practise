#include<bits/stdc++.h>
using namespace std;

long long factorial[25];
bool alreadyVisited[25];

void init_factorial(){

   factorial[0] = factorial[1] = 1;

   long long fact = 1;

   for(int i = 1; i <= 20; i++){
      fact *= i;
      factorial[i] = fact;
   }
}

int  getIdx(long long value){

   for(int i = 0; i <= 20; i++){

       if(factorial[i] == value && !alreadyVisited[i]){

          alreadyVisited[i] = true;
          return i;
       }
   }
  return -1;
}

int main(){

   init_factorial();
   int cases;
   int case_no = 0;
   long long n;

   scanf("%d",&cases);

   while(cases--){

     set<int> ans;
     memset(alreadyVisited,false,sizeof(alreadyVisited));

     scanf("%lld",&n);
     printf("Case %d: ",++case_no);

     for(int i = 20; i >= 0 && n > 0; i--){

        if(n >= factorial[i]){
            n-=factorial[i];
            ans.insert(i);
            alreadyVisited[i] = true;

            int Idx = getIdx(n);

            if(Idx != -1){
                ans.insert(Idx);
                n = 0;
            }
         }
       }

       if(n == 0){

       set<int> :: iterator it;
       bool plus_sign = false;

       for(it = ans.begin(); it != ans.end(); it++){

            if(plus_sign) printf("+");
             plus_sign = true;
             printf("%d!",*it);
         }

         printf("\n");
      }

     else
        printf("impossible\n");
   }

   return 0;
}
