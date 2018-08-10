#include<bits/stdc++.h>
using namespace std;

long long getSum(int n){

   return ( n * (n+1) ) / 2;
}

int main(){

  int testCases,number,Size;
  int array[100001];
  long long sum;
  int maxNumber, minNumber;

  scanf("%d",&testCases);

  while(testCases--){

    scanf("%d",&Size);
    memset(array,0,sizeof(array));
    sum = 0;
    maxNumber = -1;
    minNumber = 100001;

    for(int i = 0; i < Size; i++){
      scanf("%d",&number);

      if(maxNumber < number)
        maxNumber = number;

      if(minNumber > number)
        minNumber = number;

        array[number]++;

        if(array[number] == 1)
         sum += number;
    }

    if(sum == (getSum(maxNumber) - getSum(minNumber - 1)))
        printf("Yes\n");
    else printf("No\n");

  }
  return 0;
}
