#include<bits/stdc++.h>
using namespace std;

int minCoins(int coins[],int m,int target){
    //base case if target is 0 then return 0
    int res = INT_MAX;
    cout<<"m is "<<m<<" target is "<<target<<" res is "<<res<<endl;
     if(target==0) {cout<<"i am returning 0 "<<endl; return 0;}
     

     for(int i=0;i<m;i++){
         cout<<"i is "<<i<<" and target is "<<target<<endl;
         if(coins[i]<= target){
             cout<<"yes "<<coins[i]<<" is less/eq to "<<target<<endl;
             int sub = minCoins(coins,m,target- coins[i]);
             cout<<"*** Now sub is "<<sub<<" target is "<<target<<" m is "<<m<<endl;
             if(sub !=INT_MAX && sub+1<res){
                 res = sub +1;
                 cout<<"Now res is "<<res<<endl;
             }
         }
     }
     cout<<"---- returning final res ="<<res<<endl;
     return res;
}

int main(){
    int coins[] =  {2,1,3}; 
    int m = sizeof(coins)/sizeof(coins[0]); 
    int V = 5; 
    cout << "Minimum coins required is "
         << minCoins(coins, m, V); 
    return 0;
}
