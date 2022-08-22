class Solution {
public:
    bool isPowerOfFour(int n) {
        
        // if(n == 1) return true; //1 can be simple 4 ^ 0,  return true;
        
        while(n > 0) {
            if(n == 1) return true; // if it is or during this process it becomes 1 return true;
            
            if(n % 4 != 0) return false; // any power of 4 must be divisible by 4 
            
            n /= 4; //decrement it by dividing with 4
        }
        
        //if it's less than or equal to 0, -ve too 
        return false;
    }
};