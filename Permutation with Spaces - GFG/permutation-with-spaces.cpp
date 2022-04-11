// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    vector<string> ans;
    vector<string> permutation(string S){
        string op = "";
        op.push_back(S[0]);
        S.erase(S.begin() + 0);
        create(op, S);
        return ans;
    }
private: 
    void create(string op, string ip) {
        if(ip.size() == 0) {
            ans.push_back(op);
            return;
        }
        
        string op1 = op;
        string op2 = op;
        
        op1.push_back(' ');
        op1.push_back(ip[0]);
        
        op2.push_back(ip[0]);
        
        ip.erase(ip.begin() + 0);
        create(op1, ip);
        create(op2, ip);
    }
};

// { Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}
  // } Driver Code Ends