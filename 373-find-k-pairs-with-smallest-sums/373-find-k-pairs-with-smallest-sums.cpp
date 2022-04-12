class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        priority_queue<pair<int, pair<int, int>>> maxHeap;
        //create pairs
        for(int i=0; i<n; i++) {
            for(int j= 0; j<m; j++) {
                int sum = nums1[i] + nums2[j];
                
                if(maxHeap.size() < k) maxHeap.push({sum, {nums1[i], nums2[j]}});
                else if(sum < maxHeap.top().first) {
                    maxHeap.pop();
                    maxHeap.push({sum, {nums1[i], nums2[j]}});
                } else {
                    break;
                }
            }
        }
        
        vector<vector<int>> ans(maxHeap.size());
        int i = 0;
        while(!maxHeap.empty()) {
            int x = maxHeap.top().second.first;
            int y = maxHeap.top().second.second;
            ans[i].push_back(x);
            ans[i].push_back(y);
            maxHeap.pop();
            i++;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};