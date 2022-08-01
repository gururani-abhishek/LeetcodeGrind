class Solution {
public:
    
    //idea is very simple and in a way similar to coin change problem, 
    //But in coin change, we were not thinking of permutations, out idea was to simply count coins, 
    //if a combination was 1+1+2 = 4
    //we would count it as 1 case and will go home happily, but here, 1,1,2 could manifiest itself as 
    //{(1,1,2), (1,2,1), (2,1,1)}, and we have to count 'em all.
    
    //in every create call, I'm allowing it to pick any element out of all the possible elements
    //from the entire array.
    
    //tc: O(how many choices in each call(at max) ^ how many calls(at max)), sc: O(max call stack)
    //tc: O(target ^ size of Nums) ~ O(T^N)
    //sc: O(T)
    
    //after memoization of recursive solution :
    //because, there will be at max, T*N combination, and the computed ones will simply be used,
    //instead of computing them again and again.
    //tc: O(T*N), sc: O(T) + O(T), stack sapce + dp array
    
    
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        
        for(int targetdp = 1; targetdp <= target; targetdp++) {
            long resForThisCall = 0;
            for(auto integer : nums) 
                resForThisCall += (integer <= targetdp ? dp[targetdp - integer] : 0);
        
        dp[targetdp] = resForThisCall;
        }
        
        return dp[target];
    }
    
// private: 
//     int create(vector<int>& nums, int target, vector<int>& dp) {
//         if(target == 0) return 1;
        
//         if(dp[target] != -1) return dp[target];
//         int resForThisCall = 0;
//         for(auto integer : nums) 
//             resForThisCall += (integer <= target ? create(nums, target - integer, dp) : 0);
        
//         return dp[target] = resForThisCall;
        
//     }
};