class Solution {
public:
    int mod = 1e9 + 7;
    unordered_set<int> toFind;
    int numFactoredBinaryTrees(vector<int>& arr) {
        
        sort(arr.begin(), arr.end());
        toFind.insert(arr.begin(), arr.end());
        
        int n = arr.size();
        unordered_map<int, long long> dp;
        // vector<long long> dp(arr[n-1] + 1, -1); huge mistake, didn't think of the size of arr[n-1];
        
        long long res = 0;
        for(auto root : arr) {
            res += create(arr, root, dp); 
            res %= mod;
        }
        
        return res;
    }
    
private: 
    long long create(vector<int>& arr, int root, unordered_map<int, long long> &dp) {
        
        if(dp.count(root)) return dp[root];
        long long count = 1;
        
        for(auto subRoot : arr) {
            if(root % subRoot) continue;
            
            if(toFind.count(root / subRoot)) {
                count += create(arr, subRoot, dp) * create(arr, root/subRoot, dp);
                count %= mod;
            }
        }
    
        return dp[root] = count;
    }
};