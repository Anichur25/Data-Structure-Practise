#include<bits/stdc++.h>
using namespace std;

int main(){
  int p,c;
  int testCases = 0;
  char command[5];

  while(scanf("%d%d",&p,&c) && p && c){
    deque<int> DQ;

    for(int i = 1; i <= p && i <= 1000; i++)
     DQ.push_back(i);
     printf("Case %d:\n",++testCases);

     for(int i = 1; i <= c; i++){

        scanf("%s",command);
        if(command[0] == 'N'){

            int Front = DQ.front();
            DQ.pop_front();
            DQ.push_back(Front);
            printf("%d\n",Front);
        }
        else
        {
            int extend;
            scanf("%d",&extend);

            deque<int> :: iterator it;

            for(it = DQ.begin(); it != DQ.end(); it++){
                if(*it == extend){
                    DQ.erase(it);
                    break;
                }
            }

            DQ.push_front(extend);
        }
     }
  }

  return 0;
}
