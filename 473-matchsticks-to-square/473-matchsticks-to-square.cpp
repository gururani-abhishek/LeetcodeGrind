class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size(), tsum = 0;
        for(auto u: matchsticks) tsum += u;
        if(n < 4 || tsum % 4 != 0) return false;
        
        vector<int> visited(n, 0);
        return create(matchsticks, visited, 0, 0, tsum/4, 4);
    }

private: 
    bool create(vector<int>& matchsticks, vector<int>& visited, int idx, int sum, int target, int noOfSides) {
        if(noOfSides == 1) return true;
        if(idx == matchsticks.size()) {
            if(sum == target) {
                return create(matchsticks, visited, 0, 0, target, noOfSides - 1);
            }
            return false;
        }
        
         
//         for(int i = idx; i < matchsticks.size(); i++) {
            
//             if(!visited[i] && matchsticks[i] + sum <= target) {
//                 visited[i] = 1;
//                 if(create(matchsticks, visited, i + 1, sum + matchsticks[i], target, noOfSides)) return true;
//                 visited[i] = 0;
//             }
//         }
        
        if(!visited[idx] && matchsticks[idx] + sum <= target) {
            visited[idx] = 1;
            if(create(matchsticks, visited, idx + 1, sum + matchsticks[idx], target, noOfSides)) return true;
            visited[idx] = 0;
        }
        
        return create(matchsticks, visited, idx + 1, sum, target, noOfSides);
    }
};