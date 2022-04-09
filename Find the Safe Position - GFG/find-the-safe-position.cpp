// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    int safePos(int n, int k) {
        int index = 0;
        vector<int> pos;
        
        for(int i=0; i<n; i++) pos.push_back(i+1);
        
        return kill(index, n, k, pos);
    }
   
   private: 
    
    int kill(int index, int n, int k, vector<int>& pos) {
        if(n == 1) {
            return pos[0];
        }
        
        index = (index + (k-1)) % n;
        pos.erase(pos.begin()  + index);
        return kill(index, n-1, k, pos);
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