#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> a,pair<int,int> b){
    return max(a.first,a.second) > max(b.first,b.second);
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	        int n,rahul,ankit;
	        cin>>n>>rahul>>ankit;
	        vector<pair<int,int> > v(n);

	        for(int i=0;i<n;i++)
	            cin>>v[i].first;
	           for(int i=0;i<n;i++)
	                cin>>v[i].second;

	       sort(v.begin(),v.end(),compare);
	       int sum=0;
	       for(int i=0;i<n;i++){
	           if(ankit==0 || (rahul>0 && v[i].first>=v[i].second)){
	               sum+=v[i].first;

	               rahul--;
	           }
	           else{
	               sum+=v[i].second;
	               ankit--;
	           }
	       }
	    cout<<sum<<endl;
	}
	return 0;
}
