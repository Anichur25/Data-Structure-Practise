#include<bits/stdc++.h>
using namespace std;

string getBinary(int n){

  string binNumber = "";

  while(n){

    binNumber += (n % 2) + '0';
    n  = n / 2;
  }

  reverse(binNumber.begin(),binNumber.end());

  return binNumber;
}

int main(){

   int kaseNumber,m,numIterations,position;
   string token;
   string binNumber;

   scanf("%d",&kaseNumber);

   while(kaseNumber --){

    scanf("%d %d %d",&m,&position,&numIterations);
    binNumber = getBinary(m);
    token = binNumber;

    for(int i = 1; i <= numIterations + 1; i++){

        binNumber = token;
        token = "";

        for(int j = 0; j < binNumber.size(); j++){

            if(binNumber[j] == '0')
                token+="01";
            else token+="10";
        }
   }

   cout << binNumber[position] << endl;
}

   return 0;
}
