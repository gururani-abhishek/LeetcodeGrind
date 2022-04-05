class Solution {
public:
    int trap(vector<int>& height) {
        
        int mx = 0, mxR= 0, Left[height.size()], Right[height.size()];
        Left[0] = 0;
        Right[height.size() -1] = 0;
        
        for(int i =1; i<height.size(); i++) {
            mx = max(mx, height[i-1]);
            Left[i] = mx;
        }
        
        mx = 0;
        for(int i =height.size() -2; i>=0; i--) {
            mx = max(mx, height[i + 1]);
            Right[i] = mx;
        }
        
        int ans = 0;
        for(int i =0; i<height.size(); i++) 
            if(min(Left[i], Right[i]) > height[i]) ans += (min(Left[i], Right[i]) - height[i]);
        
        return ans;
        
    }
};