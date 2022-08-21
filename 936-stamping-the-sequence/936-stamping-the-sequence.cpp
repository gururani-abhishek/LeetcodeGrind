class Solution {
public:
    int qmCount, stampSize, targetSize;
    vector<int> res;
    vector<int> movesToStamp(string stamp, string target) {
        qmCount =0, stampSize = stamp.size(), targetSize = target.size();
        
        vector<bool> vis(targetSize, 0);
        
        while(qmCount < targetSize) {
            bool stripped = false;
            
            for(int idx = 0; idx <= targetSize - stampSize && qmCount < targetSize; idx++) {
                //if this idx is not pre-visited
                if(!vis[idx]) {
                    stripped = strip(target, idx, stamp);
                    vis[idx] = stripped;
                }
            }
            
            if(!stripped) return {};
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
    
private: 
    bool strip(string &target, int startIdx, string stamp) {
        for(int idx = 0; idx < stampSize; idx++) {
            if(target[idx+startIdx] != '?' && target[idx+startIdx] != stamp[idx]) return false;
        }
        
        res.push_back(startIdx);
        for(int idx = startIdx; idx - startIdx < stampSize; idx++) {
            qmCount += (target[idx] != '?');
            target[idx] = '?';
        }
            
        return true;
    }
};

/*
0123456 -> subarrays of size 3, how many & what indices can you start your subarray with ->
012,123,234,345,456, that's it 0,1,2,3,4 -> 5 indices.
arraySize - subarraySize = 7 - 3 = 4th index will be the last index


0123456 -> you have to take an entire segment of size 3, starting from idx,
1 -> 1 + 3
*/