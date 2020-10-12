//https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size() ;

        unordered_map<char,int> omap ;

        int ans = 0 ,curr=0, prev = -1;

        for(int i=0;i<n;i++){

            if(omap.count(s[i])==0){
                curr++ ;
                omap[s[i]] = i ;
            }
            else{

                prev = max(prev,omap[s[i]]) ;
                curr = i -prev ;
                omap[s[i]] = i ;
            }

            ans = max(ans,curr) ;
        }


        return ans ;

    }
};
