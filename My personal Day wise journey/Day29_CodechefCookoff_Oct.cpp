https://www.codechef.com/COOK123B/problems/DECREM/
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int l,r;
	    cin>>l>>r;
	    if(l==1 || r==1){
	        cout<<-1<<endl;
	        continue;
	    }
	    if(r-l >= l){
	        cout<<-1<<endl;
	        continue;
	    }
	    cout<<r<<endl;
	}
	return 0;
}



https://www.codechef.com/COOK123B/problems/SPLITIT/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n ;
	    cin>>n;
	    string s;
	    cin>>s;
	    int freq[26];
	    memset(freq, 0, sizeof(freq));
        for (int i = 0; i < n; i++)
          freq[s[i] - 'a']++;
	    if(freq[s[n-1]-'a'] > 1)cout<<"YES"<<endl;
	    else cout<<"NO"<<endl;
	    
	}
	return 0;
}

