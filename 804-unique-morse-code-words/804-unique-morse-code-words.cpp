class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> morseCoding;
        
        //setting up a size 26 vector, which will be used for mapping morse codes
        vector<string> morseCodes = {".-","-...","-.-.","-..",".","..-."
            ,"--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-"
            ,".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        for(int i=0; i<words.size(); i++) {
            string wrd = words[i];
            string mrsCoding = "";    
            for(int idx=0; idx<wrd.length(); idx++) {
                mrsCoding += morseCodes[wrd[idx] - 'a'];
            }
            
            morseCoding.insert(mrsCoding);
        }
        
        return morseCoding.size();
    }
};