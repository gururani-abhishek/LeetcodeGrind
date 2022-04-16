class ATM {
public:
    map<int, long long int, greater<int>> freq;
    ATM() {
        
    }
    
    void deposit(vector<int> banknotesCount) {
        freq[20] += banknotesCount[0];
        freq[50] += banknotesCount[1];
        freq[100] += banknotesCount[2];
        freq[200] += banknotesCount[3];
        freq[500] += banknotesCount[4];
    }
    
    vector<int> withdraw(int amount) {
        map<int, long long int, greater<int>> freq1 = freq;
        vector<int> ans;
        
        for(auto &u: freq1) {
            long long int x = min((long long int) amount / u.first, u.second);
            amount -= x * u.first;
            u.second -= x;
            ans.push_back(x);
        }
        
        if(amount) return {-1};
        
        freq = freq1;
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */