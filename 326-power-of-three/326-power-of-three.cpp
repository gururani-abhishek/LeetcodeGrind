class Solution {
public:
    bool isPowerOfThree(int n) {
    
        // find max power of 3, smaller than INT_MAX, so that 
        // we can check it against all smaller integers.
        
    
        // n must be greater than zero, and as it's power of 3 it 
        // must divide another greater power of 3
        int greaterPowerOf3 = pow(3, int(log(INT_MAX)/ log(3)));
        if(n > 0 && greaterPowerOf3 % n == 0) return true;
        return false;
    }
};

// 3 is a prime number, hence any power of 3, should be completely
// divisible by any smaller power of 3. 
        
// eg : 3 x 3 x 3 x 3 x 3 = 243, if n = 9(3 x 3) it should completely divide 243. 
// whereas n = 8 won't divide 243. 

// this won't work with a non-prime as it will also have other factors than the prime number.
// won't work with 6 x 6 = 36, if n = 3(3), it should completely divide 36, 
// but 3 is not a power of 6, the problem is that 6 is not a prime number(3 x 2), any combination of 3 and // 2 will also divide power of 6, which necessarily need not to be a power of 6.