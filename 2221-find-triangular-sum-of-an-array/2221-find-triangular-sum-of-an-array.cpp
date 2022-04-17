class Solution {
public:
    int triangularSum(vector<int>& nums) {
        queue<int> q;
        for(auto u: nums) q.push(u);
        
        while(q.size() != 1) {
            int size = q.size();
            while(size-- != 1){
                int x = q.front();  q.pop();
                q.push((x + q.front()) % 10);
            }
            q.pop();
        }
        
        return q.front();    
        
    }
};