#include<bits/stdc++.h>
using namespace std;

int main()
{

int n;
cin >> n;
vector< int> v(n);
for(int i =0; i < n; i ++)
 {
    cin >> v[i];//taken
 }
 
 int x,a,b;
 cin>>x>>a>>b;
 v.erase( v.begin() + x-1 );  /*erasing the xth number its -1 bc indexing starts from 0 and therefore it was extra*/


 v.erase(v.begin()+a-1,v.begin()+b-1);   //earasing from  A to B removing the index 0 thus a-1 and b-1
 
 cout<<v.size()<<endl;
 for(auto x:v)
    cout << x << " ";

return 0;
}
