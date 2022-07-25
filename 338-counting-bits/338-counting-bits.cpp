class Solution {
public:
    vector<int> countBits(int n) {
        //if you'll go by logic the only way to solve this question was through O(nlogn);
        //but there's an underlying pattern, ans[0] = 0, ans[1] = 1;
        //then, if odd then -> (no. of ones = no. of ones in it's half + 1);
        //if even then -> (no. of ones = no. of ones in it's half);
        
        //tc : o(n), sc : o(n);
        
        //edge cases: 
        if(n == 0) return {0};
        if(n == 1) return {0, 1};
        vector<int> ans(n+1); 
        //ans[0] = 0, ans[1] = 1;
        ans[0] = 0;
        ans[1] = 1;
        
        for(int num = 2; num <= n; num++) {
            if(num % 2) ans[num] = ans[num/2] + 1; //odd num
            else ans[num] = ans[num/2]; //even num
        }
        
        return ans;
    }
};