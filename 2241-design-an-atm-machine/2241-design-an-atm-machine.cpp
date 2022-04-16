class ATM {
public:
    //map<int, long long int, greater<int>> freq;
    vector<int> deno{20, 50, 100, 200, 500};
    vector<long long int> freq;
    ATM() {
        freq.resize(5);
    }
    
    void deposit(vector<int> banknotesCount) {
        // freq[20] += banknotesCount[0];
        // freq[50] += banknotesCount[1];
        // freq[100] += banknotesCount[2];
        // freq[200] += banknotesCount[3];
        // freq[500] += banknotesCount[4];
        
        for(int i = 0; i<5; i++) freq[i] += banknotesCount[i];
        
    }
    
    vector<int> withdraw(int amount) {
        //map<int, long long int, greater<int>> freq1 = freq;
        vector<int> ans(5);
        
        // for(auto &u: freq1) {
        //     long long int x = min((long long int) amount / u.first, u.second);
        //     amount -= x * u.first;
        //     u.second -= x;
        //     ans.push_back(x);
        // }
        
        for(int i =4; i>=0; i--) {
            long long int x = min((long long int)  amount/deno[i], freq[i]);
            amount -= x * deno[i];
            ans[i] = x;
        }
        
        if(amount != 0) return {-1};
        
        for(int i=0; i<5; i++) 
            freq[i] -= ans[i];
        
        //reverse(ans.begin(), ans.end());
        return ans;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */