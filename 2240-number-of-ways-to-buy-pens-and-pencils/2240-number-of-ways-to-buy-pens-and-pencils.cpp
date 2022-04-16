class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans = 0;
        for(int i=0; i<= total/cost1; i++) {
            long long ans1 = 1;
            ans1 += (total - cost1 * i)/cost2;
            ans += ans1;
        }
        
        return ans;
    }
};