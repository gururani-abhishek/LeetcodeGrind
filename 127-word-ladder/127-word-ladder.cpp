class Solution {
public:
    //this problem can be imagined as a graph problem, 
    //where every vertex is a word present in wordList, and 
    //the final vertex to be reached is the endWord.
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //I'll use BFS : hint -> shortest path.
        
        //while traversing, I'll also have to search  if a transformation
        //is present in wordList, so for easy and fast check(O(1)) i'll use an unordered_set
        
        unordered_set<string> wList(wordList.begin(), wordList.end());
        queue<pair<string, int>> q; // {word, countOfWord}
        
        //push beginWord to q
        q.push({beginWord, 1});
        
        
        while(!q.empty()) {
            auto it = q.front();
            string word = it.first;
            int countOfWord = it.second;
            q.pop();
            
            if(word == endWord) {
                return countOfWord;
            }
            //delete this word, so that control doesn't come back to it
            wList.erase(word);
            
            //trasverse each char in word, and change it with a char from [a-z]
            for(int idx=0; idx < word.length(); idx++) {
                char beforeChange = word[idx];  //store it to revert back
                for(char afterChange = 'a'; afterChange <= 'z'; afterChange++) {
                    word[idx] = afterChange;
                    
                    //if a word is found in wList, then make it a new vertex
                    if(wList.find(word) != wList.end()) {
                        q.push({word, countOfWord+1});
                    }
                }
                word[idx] = beforeChange;   //revert back
            }
        }
            
        return 0; //if not found
    }
};