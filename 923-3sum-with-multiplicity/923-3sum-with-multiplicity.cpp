class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int, long> freq;
        
        for(auto u: arr) freq[u]++;
        long ans = 0;
        
        for(auto u: freq) {
            for(auto x: freq) {
                int i = u.first, j = x.first;
                int k = target - i - j;
                
                if(!freq.count(k)) continue;
                if(i == j && j == k) 
                    ans += (freq[i] * (freq[i]-1) * (freq[i]-2))/6; //nC3
                
                else if(i == j && j != k)
                    ans += (freq[i] * (freq[i]-1)/2) * freq[k]; //nC2 * nC1
                
                else if(i < j  && j < k) 
                    ans += freq[i] * freq[j] * freq[k];
            }
        }
        
        return ans%int(1e9+7);
    }
};