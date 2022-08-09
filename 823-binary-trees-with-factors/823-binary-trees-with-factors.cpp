class Solution {
public:
    int mod = 1e9 + 7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        
        sort(arr.begin(), arr.end(), greater<int>()); //sorting in rev order will pick larger elements first
        //a large element will have more factors, and hence most of the dp will be filled during the
        //initial create function calls only.

        //will be used to check if an element is present or not  using count() stl function
        //in O(1) search time(average cases)
        unordered_set<int> toFind(arr.begin(), arr.end()); 
        unordered_map<int, long long> dp;
        
        long long res = 0;
        for(auto root: arr) {
            //create function returns number of binary trees that I can create while having 
            //root as my "root node", root here is nothing but array element and
            //I'm exhaustively picking each array element as root and counting how many binary
            //trees with it as the "root node" can be created.
            res += create(arr, root, toFind, dp); 
            res %= mod;
        }
        
        return res;
    }

private:
    long long create(vector<int>& arr, int root, unordered_set<int>& toFind, unordered_map<int, long long> &dp) {
        
        if(dp.count(root) == 1) return dp[root]; //if [root] has already been explored and it has an entry in dp
        
        //count keeps the  count of number of binary trees that can be created using root as the "root node"
        long long count = 1;  //1 single root node will itself be a binary tree.
        
        //now I'll check for the conditions
        //I already have my root, now I'm looking for it's children.
        //we are bound to consider only those cases where each non-leaf node has exactly two children, 
        //and product of them forms up our root node.
        
        //traversing the entire array to find such pair
        //oth the pairs should be a factor of root node
        for(auto subRoot : arr) {
            if(root % subRoot != 0) continue; //subRoot is not a factor of root
            
            //if we reached here, it means that subRoot is a factor of root, the other factor will automatically be "root / subRoot"
            //using count() checking if it's in the array or not.
            if(toFind.count(root / subRoot) == 1) {
                //both the  factors are present in the array, let's make recursive calls, 
                //with them being passed as the new root, 
                
                
                //create(root) is returning me : no. of binary trees that can be created using root as 
                //the root node. Now how to calculate number of binary trees that can be created using [subRoot] and [root / subRoot] as 
                //the descendants of [root]
                
                /* let's do a game of counting
                * suppose you have a set1 = {create(subRoot) = [ABCD]} and another set 2 = {create(root / subRoot)  = [EFG]}
                * as root will have two descendants, in how many ways can I fill two places using the elements 
                * present in set 1 and set 2
                * I can fill them in :  countOfSet1 * countOfSet2 ways -> 4 * 3 -> 12 ways. 
                * that's what we are doing when we are multiplying number of Binary Trees that can be created with 
                * [subRoot] and [root / subRoot]  as descendants of [root]
                */
                
                count += create(arr, subRoot, toFind, dp) * create(arr, root / subRoot, toFind, dp);
                count %= mod;
            
            }
        }
        
        return dp[root] = count;
        
    }
};