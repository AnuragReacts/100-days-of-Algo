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
	   for(long int i=n-1;i>=0;i--){
	       if(s.empty()){
	           arr.push_back(-1);
	           s.push(arr[i]);
	           continue;
	       }
	       if(!s.empty() && s.top() > arr[i]){
	           arr.push_back(s.top());
	           s.push(arr[i]);
	       }
	       else if(!s.empty() && s.top() < arr[i]){
	           while(!s.empty() && s.top() < arr[i])
	               s.pop();
	           if(s.empty()) arr.push_back(-1);
	           else arr.push_back(s.top());
	           s.push(arr[i]);
	       }
	   }
	   reverse(arr.begin(), arr.end());
	   for(int i =0; i<n;i++)
	      cout<< arr[i] <<" ";
	    cout<<"\n";
	    
	}
	return 0;
}
