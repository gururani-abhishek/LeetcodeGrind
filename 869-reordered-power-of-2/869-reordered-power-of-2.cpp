class Solution {
public:
    bool reorderedPowerOf2(int n) {
        
        // break down n into it's digits
        vector<int> digsOfN = breakDown(n);
        sort(digsOfN.begin(), digsOfN.end());
        for(int i =0; i< int(log2(INT_MAX)); i++) {
            int powOfTwo = pow(2, i);
            vector<int> digsOfPow = breakDown(powOfTwo);
            sort(digsOfPow.begin(), digsOfPow.end());
            if(digsOfPow == digsOfN) return true;
        }
        
        return false;
    }
    
private:
    
    vector<int> breakDown(int n) {
        vector<int> res;
        while(n) {
            res.push_back(n % 10);
            n /= 10;
        }
        return res;
    }   
};

// n -> break it into digits, store in a vector. 
// check against all the powers of two. 
// if matches return true;