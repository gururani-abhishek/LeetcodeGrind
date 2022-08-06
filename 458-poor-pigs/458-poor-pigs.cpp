class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int pigs = 0;
        while(pow((minutesToTest/minutesToDie + 1), pigs) < buckets) {
            pigs++;
        }
        
        return pigs;
    }
};


//choose the number of pigs, one pig can drink from any number of buckets
//minutesToDie -> total time to run experiments; minutesToTest -> time taken in one testing
//one testing could be anything, ranging from 1 pig drinking poison from 1 bucket, 
//1 pig drinking poison from 1000 buckets, 1000 pig drinking poison from 1 bottle each
//1000 pig drinking poison from 1000000 buckets, 1000 buckets each. 
//repeat till you run out of minutesToTest.
//find min number of pigs required to figure this out.

// 60/15 = 4 times,
/* let's build the solution, 
    take an example when minutesToDie = 60 and minutesToTest = 15, we can run at max -> 4 tests 
    
    if buckets are 5
    
    1 2 3 4 5 

    I can have 5 pigs, drinking water from the bucket, if a pig will die, that will be the bucket with poison
    but I've to minimize number of pigs, otherwise number of pigs equal to number of buckets is also a viable solution.
    
    In this case I've got 5 buckets, in one test I can test 1 bucket, so 
    1 st test -> pig will drink from the 1st bucket -> if the pig will die 1st bucket will be  poisoned
    2 nd test -> pig will drink from the 2nd bucket -> if the pig will die 2nd bucket will be poisoned
    3 rd test -> pig will drink from the 3rd bucket -> if the pig will die 3rd bucket will be poisoned
    4 th test -> pig will drink from the 4th bucked -> if the pig will die 4th bucket will be poisoned
    
    if the pig is still alive it's the 5th bucket
    
                            P1(move to right)
              (move to left)P2 1  2  3  4  5
                               6  7  8  9  10
                               11 12 13 14 15
                               16 17 18 19 20
                               21 22 23 24 25 

        same like atlas book game. to identify the  posioned bucket.
*/

