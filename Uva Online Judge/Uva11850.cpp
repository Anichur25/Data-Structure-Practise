#include<bits/stdc++.h>
using namespace std;
int maxV;
bool ispossible(int arr[],int n){

    bool visited[1443];
    memset(visited,false,sizeof(visited));

     for(int i = 0; i < n; i++){
        int coverup = arr[i] + 200;

        for(int j = arr[i]; j <= coverup; j++)
            if(j <= 1442)
             visited[j] = true;
     }

     int cnt = count(visited,visited+1442,false);
    int diff = (1442 - maxV) * 2;

    return diff <= 200 && cnt == 0;
}

int main()
{
    int n;

    while(scanf("%d",&n) && n){
        int arr[n];
        maxV = -1;

        for(int i = 0; i < n; i++){
             scanf("%d",&arr[i]);
             maxV = max(maxV,arr[i]);
        }

        if(ispossible(arr,n)) printf("POSSIBLE\n");
        else printf("IMPOSSIBLE\n");
    }

    return 0;
}
