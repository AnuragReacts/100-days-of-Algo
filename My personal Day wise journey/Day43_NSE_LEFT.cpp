#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	   int n;
	   cin>>n;
	   vector<long long int> arr(n);
	   for(int i=0;i<n;i++)
	       cin>> arr[i];
	   stack<long long int> s;
       vector<int> ans;
	   for(long int i=0;i<n;i++){
	       if(s.empty()){
	           ans.push_back(-1);
	           s.push(arr[i]);
	           continue;
	       }
	       if(!s.empty() && s.top() < arr[i]){
	           ans.push_back(s.top());
	           s.push(arr[i]);
	       }
	       else if(!s.empty() && s.top() > arr[i]){
	           while(!s.empty() && s.top() > arr[i])
	               s.pop();
	           if(s.empty()) ans.push_back(-1);
	           else ans.push_back(s.top());
	           s.push(arr[i]);
	       }
	   }
	   for(int i =0; i<n;i++)
	      cout<< ans[i] <<" ";
	    cout<<"\n";
	    
	}
	return 0;
}
