#include<bits/stdc++.h>
using namespace std;

struct Chocolate{

   int volume;
   string name;
};

bool cmp(Chocolate A,Chocolate B){

   return A.volume < B.volume;
}

int main(){

 int cases;
 int case_no = 0;
 int n;
 int a,b,c;

 scanf("%d",&cases);

 while(cases--){

    scanf("%d",&n);
    Chocolate x[n];

    for(int i = 0; i < n; i++){
        cin >> x[i].name >> a >> b >> c;
        x[i].volume = a * b * c;
    }

    sort(x,x+n,cmp);

    printf("Case %d: ",++case_no);

    if(x[0].volume == x[n-1].volume)
      printf("no thief\n");
    else
        printf("%s took chocolate from %s\n",x[n-1].name.data(),x[0].name.data());
 }
 return 0;
}
