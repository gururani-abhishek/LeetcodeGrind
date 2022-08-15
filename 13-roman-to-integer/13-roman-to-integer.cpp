class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> conv;
        conv.insert({'I', 1});
        conv.insert({'V', 5});
        conv.insert({'X', 10});
        conv.insert({'L', 50});
        conv.insert({'C', 100});
        conv.insert({'D', 500});
        conv.insert({'M', 1000});

        int ans = 0;
        int flag = INT_MIN;
        for(int i=s.length()-1; i>=0; i--) {\
                if(flag <= conv[s[i]]) 
                    ans += conv[s[i]];
                else 
                    ans -= conv[s[i]];
            
            flag = conv[s[i]];
        }
        
        return ans;
    }
};


/*
//MCMXCIV
* 1000 + 100 + 1000 + 10 + 100 + 1 + 5
* (5-1) + (100 -10) + (1000 - 100) + (1000) = 4 + 90 + 900 + 1000 = 1994
    
//LVIII
* 50 + 5 + 1 + 1 + 1
* 58
*/    