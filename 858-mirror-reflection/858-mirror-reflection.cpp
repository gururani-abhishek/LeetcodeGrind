class Solution {
public:
    int mirrorReflection(int p, int q) {
    //we are extending our frame, and the ray will hit a corner if 
    //  noOfExtendedFrames * p = noOfRays * q
        int noOfExtendedFrames = 1, noOfRays = 1;
        
        while(noOfExtendedFrames * p != noOfRays * q) {
            noOfRays++;
            noOfExtendedFrames = noOfRays * q/ p;
        }
        
        if(noOfExtendedFrames % 2 && !(noOfRays % 2)) return 2;
        if(noOfExtendedFrames % 2 && noOfRays % 2) return 1;
        if(!(noOfExtendedFrames % 2) && noOfRays % 2) return 0;
        
        return -1; //impossible case;
        
    }
};

/*

noOfExtendedFrames | noOfRays | cornerHIT
even                even -> impossible(according to the equation both cannot be even )
even                odd
odd                 even
odd                 odd

*/