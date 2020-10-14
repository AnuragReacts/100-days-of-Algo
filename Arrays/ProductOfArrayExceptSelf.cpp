//problem: https://leetcode.com/problems/product-of-array-except-self/
// Runtime: 36 ms
// Memory Usage: 24.4 MB

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        int n=a.size();
        vector<int> res(n);
        res[0]=1;
        for(int i=1;i<n;i++){
            res[i]=res[i-1]*a[i-1];
        }
        int r=1;
        for(int i=n-1;i>=0;i--){
            res[i]*=r;
            r*=a[i];
        }
        return res;
    }
};