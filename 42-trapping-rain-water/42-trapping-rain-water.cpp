class Solution {
public:
    int trap(vector<int>& height) {
        int mx = 0, n = height.size();
        int lH[n], rH[n];
        
        lH[0] = rH[n-1] = 0;
        for(int i=1; i<n; i++) {
            mx = max(mx, height[i-1]);
            lH[i] = mx;
        }
        mx = 0; //reset mx
        for(int i = n-2; i>=0; i--) {
            mx = max(mx, height[i+1]);
            rH[i] = mx;
        }
        
        int ans = 0;
        
        for(int i=0; i<n; i++) {
            int x = (min(lH[i], rH[i]) - height[i]);
            ans += x > 0 ? x : 0;
        }
        
        return ans;
    }
};

