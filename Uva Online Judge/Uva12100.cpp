#include<bits/stdc++.h>
using namespace std;

int main(){

  int testCases;
  int priority;
  int n,m;

  scanf("%d",&testCases);

  while(testCases--){

     queue<pair<int,int> > Order;
     priority_queue<int> Q;

     scanf("%d%d",&n,&m);

     for(int i = 0; i < n; i++){
        scanf("%d",&priority);
        Order.push(make_pair(priority,i));
        Q.push(priority);
     }

     int ans = 0;
     bool found = false;

     while(!Q.empty()){
        int top = Q.top();
        Q.pop();

        while(!Order.empty()){

            pair<int,int> Front = Order.front();

            if(Front.first == top){
                ++ans;
                Order.pop();
                if(Front.second == m){
                    found = true;
                }
                break;
            }
            else
            {
                Order.pop();
                Order.push(Front);
            }
        }

        if(found) break;
     }

     printf("%d\n",ans);
  }
  return 0;
}


