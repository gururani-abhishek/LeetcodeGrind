class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        
        for(int i=0; i<=n; i++) 
            ans.push_back(count(i));
    
        return ans;
    }

int count(int num) {
        int res = 0;
        while(num > 0) {
            res += (num %2);
            num /= 2;
        }

    return res;
    }
};