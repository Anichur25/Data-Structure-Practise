#include<bits/stdc++.h>
using namespace std;

int getDecimal(string binary){

    int decimal = 0;
    int pos = 0;

    for(int i = binary.size() - 1; i >= 0; i--){

        decimal+=((binary[i] - '0') << pos);
        ++pos;
    }

    return decimal;
}


int main(){

   int case_number;
   int case_no = 0;
   string decimal,binary;

   scanf("%d",&case_number);

   while(case_number--){

     cin >> decimal >> binary;
     decimal+=".";
     binary+=".";

     vector<int> checker;

     string store = "";
     string verdict = "Yes";
     int idx  = -1;

     for(int i = 0; i < decimal.size(); i++){

        if(decimal[i] != '.')
         store+=decimal[i];
        else{
            checker.push_back(atoi(store.c_str()));
            store.clear();
        }
     }

     for(int i = 0; i < binary.size(); i++){

        if(binary[i] != '.')
         store+=binary[i];
         else
         {
             ++idx;
             if(getDecimal(store) != checker[idx]){
                verdict = "No";
                break;
             }
             store.clear();
         }
     }

     printf("Case %d: %s\n",++case_no,verdict.c_str());
   }
}
