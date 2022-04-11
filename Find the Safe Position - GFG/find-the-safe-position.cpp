// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    int safePos(int n, int k) {
        vector<int> pos;
        for(int i=1; i<=n; i++) pos.push_back(i);
        int start = 0;
        return kill(start, k, pos);
    }
  private: 
  
    int kill(int start, int k, vector<int>& pos) {
        if(pos.size() == 1) {
            return pos[0];
        }      
        
        start = (start + (k-1)) % pos.size();
        //cout << start << " " << pos[start] << endl;
        pos.erase(pos.begin() + start);
        return kill(start, k, pos);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        
        cin>>n>>k;

        Solution ob;
        cout << ob.safePos(n,k) << endl;
    }
    return 0;
}  // } Driver Code Ends