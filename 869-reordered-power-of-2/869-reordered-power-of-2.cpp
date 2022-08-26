class Solution {
public:
    bool reorderedPowerOf2(int n) {
        
        // break down n into it's digits
        vector<int> digsOfN = breakDown(n);
        
        //sort the digit vector, so that direct comparision can be done.
        sort(digsOfN.begin(), digsOfN.end());
        
        // I'll be comparing digsOfN with all the possbile powers of two within the range 
        // INT_MAX
        for(int i =0; i< int(log2(INT_MAX)); i++) {
            //new power of two
            int powOfTwo = pow(2, i);
            
            //breakdown it's digits and store it in a vector
            vector<int> digsOfPow = breakDown(powOfTwo);
            
            //sort it for easy comparision : 
            sort(digsOfPow.begin(), digsOfPow.end());
            
            // if the digits in number are same as digits in power of two, return true
            // this means that digits in number can be reordered to form a power of 2
            if(digsOfPow == digsOfN) return true;
        }
        
        // if here none of the power of two matched, hence return false.
        return false;
    }
    
private:
    
    // function to break down a number into it's digits and return them by storing them
    // in a vector.
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