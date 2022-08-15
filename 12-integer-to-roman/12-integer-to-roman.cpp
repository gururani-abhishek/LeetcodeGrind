class Solution {
public:
    string intToRoman(int num) {
        
        vector<int> val {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> romanNumeral {"M", "CM", "D", "CD", "C","XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string res = "";
        
        for(int idx = 0; idx < val.size(); idx++) {
            int valCurr = val[idx];
            string romanNumeralCurr = romanNumeral[idx];
            
            while(num >= valCurr) {
                num -= valCurr;
                res += romanNumeralCurr;
            }
        }
        
        return res;
    }
};


//1747 -> 
// >= 1000 -> M -> 747
// >= 500 -> D -> 247
// >= 100 -> C -> 147
// >= 100 -> C -> 47
// >= 40 -> XL -> 7
// >= 5 -> V -> 2
// >= 1 -> I -> 1
// >= 1 -> I -> 0


//this algorithm will be heavy implementation, as my range of number is from 1 - 3999,
//I can also mark other numerals like : 4, 9, 40, 90, 400, 900  
/*

1 : I 
2 : II
3 : III
4 : IV
5 : V
6 : VI
7 : VII
8 : VIII
9 : IX
10 : X

11 : XI
12 : XII
13 : XIII
14 : XIV
15 : XV
16 : XVI
17 : XVII
18 : XVIII
19 : XIX
20 : XX

39 : XXXIX
49 : XLIX
*/