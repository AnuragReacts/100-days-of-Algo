//hackerrank question
//https://www.hackerrank.com/challenges/ctci-recursive-staircase/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=recursion-backtracking

#include <bits/stdc++.h>
#define MOD 10000000007
using namespace std;

// Complete the stepPerms function below.
int stepPerms(int n) {
   if(n==1) return 1;
   if(n==2) return 2;
   if(n==3) return 4;
   int dp[n+1];
   dp[1] = 1;
   dp[2] = 2;
   dp[3] = 4;
   for(int i=4;i<=n;i++){
       dp[i] = dp[i-1]+ dp[i-2] + dp[i-3];
   }
   return dp[n];
}

