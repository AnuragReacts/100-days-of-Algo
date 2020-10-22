https://www.codechef.com/LTIME88B/problems/ROOTTREE
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int>indegree(n+1,0);
	    for(int i=0;i<n-1;i++){
	        int u,v;
	        cin>>u>>v;
	        indegree[v]++;
	    }
	    int count=0;
	    for(int i=1;i<=n;i++){
	        if(indegree[i]==0)count++;
	    }
	    cout<<count-1<<"\n";
	}
	return 0;
}
