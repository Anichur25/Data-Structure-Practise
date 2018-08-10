#include<bits/stdc++.h>
using namespace std;

bool compare(int a,int b){

   if(a < 0 && b < 0){
     return a > b;
   }

   return false;
}

int main(){

  int testCases,Size;
  int array[1000];
  bool spaceVisible;
  vector<pair<int,int> > result;

  scanf("%d",&testCases);

  while(testCases--){
    scanf("%d",&Size);

    for(int i = 0; i < Size; i++){
        scanf("%d",&array[i]);
    }

    spaceVisible = false;
    bool mark[1001];
    memset(mark,false,sizeof(mark));
    result.clear();

    for(int i = 0; i < Size; i++){

      if(array[i] <= 0){

        for(int j = 0; j < Size; j++){

           if(array[j] > 0 && array[j] == abs(array[i]) && !mark[j]){
             mark[j] = true;
             result.push_back(make_pair(array[i],array[j]));
           }
        }
      }
    }

    sort(result.begin(),result.end(),greater<pair<int,int> >());

    if(result.size() == 0)
        printf("0");

    for(int i = 0; i < result.size(); i++){

      if(spaceVisible) printf(" ");
      printf("%d %d",result[i].first,result[i].second);
      spaceVisible = true;
    }

    printf("\n");
  }
  return 0;
}
