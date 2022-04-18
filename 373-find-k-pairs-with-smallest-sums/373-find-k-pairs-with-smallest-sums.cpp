class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, pair<int, int>>> maxHeap;
        
        for(int i=0; i<nums1.size(); i++) {
            for(int j = 0; j<nums2.size(); j++) {
                int sum = nums1[i]  + nums2[j];
                
                /*this doesn't use the fact that these two arrays are sorted
                maxHeap.push({nums1[i] + nums2[j], {nums1[i], nums2[j]}});
                if(maxHeap.size() > k) maxHeap.pop();
                I'm just making all the pairs in brute-force way. I can optimize this.*/\
                   
                //if k element pairs are not filled, add this pair.    
                if(maxHeap.size() < k) maxHeap.push({sum, {nums1[i], nums2[j]}});
                //if k or more elements are filled, check whether new element pair
                //has a sum less than the top most element pair.
                //if yes, pop top element pair and add this instead.
                else if(sum < maxHeap.top().second.first + maxHeap.top().second.second) {
                    maxHeap.pop(); 
                    maxHeap.push({sum, {nums1[i],  nums2[j]}});
                } else break;
            
            }
        }
        
        vector<vector<int>> ans(maxHeap.size());
        int i = 0;
        while(!maxHeap.empty()) {
            ans[i].push_back(maxHeap.top().second.first);
            ans[i].push_back(maxHeap.top().second.second);
            maxHeap.pop();
            i++;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};