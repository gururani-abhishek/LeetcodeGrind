class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int i =0, j = letters.size() - 1;
        while(i < j) {
            int mid = i + (j -i)/2;
            if(letters[mid] > target) j = mid; 
            else i = mid + 1;
        }
        if(letters[i] <= target) return letters[0];
        else return letters[i];
    }
};