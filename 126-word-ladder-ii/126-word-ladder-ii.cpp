class Solution {
public:
    unordered_map<string, int> mp; //will map words with their distance from the beginWord
    vector<vector<string>> res; //will store answer
    vector<string> oneRoute; //will store strings encouted in one route
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        //I'm applying BFS to map distance of each word in wordList from beginWord 
        //and then will use DFS to trace back and output all the required words in the sequence.
        
        unordered_set<string> wList(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        mp[beginWord] = 0;  //distance of beginWord from itself = 0
        
        
        while(!q.empty()) {
            string word = q.front();
            int countOfWord = mp[word];
            
            q.pop();
            
            wList.erase(word);
            for(int idx = 0; idx < word.size(); idx++) {
                char charBefore = word[idx];
                for(char charAfter = 'a'; charAfter <= 'z'; charAfter++) {
                    word[idx] = charAfter;
                    
                    if(wList.find(word) != wList.end() && mp.find(word) == mp.end()) {
                        mp[word] = countOfWord + 1;
                        q.push(word);
                    }
                }
                word[idx] = charBefore;
            }
            
        }
        

        if(mp.find(endWord) != mp.end()) traceBack(endWord, beginWord);
        return res;
    }
    
private:
    void traceBack(string word, string &beginWord) {
        
        oneRoute.push_back(word);
        if(word == beginWord) {
            vector<string> toBeReversed = oneRoute;
            reverse(toBeReversed.begin(), toBeReversed.end());
            res.push_back(toBeReversed);
            oneRoute.pop_back();
            
            return;
        }
        
        int countOfWord = mp[word];
        for(int idx = 0; idx < word.length(); idx++) {
            char charBefore = word[idx];
            for(char charAfter = 'a'; charAfter <= 'z'; charAfter++) {
                word[idx] = charAfter;  
                if(mp.find(word) != mp.end() && mp[word] == countOfWord -1) {
                    traceBack(word, beginWord);
                }
            }
            word[idx] = charBefore;
        }
        
        oneRoute.pop_back();
        return;
    }

};