class Solution {
public:
    
    string smallestNumber(string pattern) {
        int n = pattern.size();
        
        string ans = "";
        for(int i=0; i<n+1; i++) {
            ans += to_string(i+1);
        }
        cout << ans;
        //traverse through the arrray and find 'D'
        for(int idx = 0; idx < n; idx++) {
            if(pattern[idx] == 'D') {
                int idxI = findI(pattern, idx);
                reverseSeg(ans, idx, idxI);
                idx = idxI;
            }
        }
    
        return ans;
    }
    
private: 
    //find 'I', and if not found it means the sequence is like : 
    // something..DDDD, now you need to reverse it till the end.
    int findI(string &pattern, int idxOfD) {
        int n = pattern.size();
        for(int idx = idxOfD; idx < n; idx++) {
            if(pattern[idx] == 'I') return idx;
        }
        
        return n;
    }
    
    //reverse the given segment.
    void reverseSeg(string &ans,  int i, int j) {
        while(i < j) {
            swap(ans[i], ans[j]);
            i++, j--;
        }
    }
};