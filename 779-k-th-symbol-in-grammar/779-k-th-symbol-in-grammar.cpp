class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1 && k == 1) return 0;
        int size = pow(2,n-1)/2;
        if(k <= size) return kthGrammar(n-1, k);
        
        return (!kthGrammar(n-1, k-size));
    }
};