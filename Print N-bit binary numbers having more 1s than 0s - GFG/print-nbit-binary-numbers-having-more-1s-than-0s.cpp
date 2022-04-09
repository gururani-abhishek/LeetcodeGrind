// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
    vector<string> ans;
	vector<string> NBitBinary(int N) {
	   string op = "";
	   int O = N, Z = N;
	   create(op, O, Z, N);
	   
	   return ans;
	}
private: 
    void create(string op, int O, int Z, int N) {
        if(op.length() ==  N) {
            ans.push_back(op);
            return;
        }
        
        if(O > 0) {
            string op1 = op;
            op1.push_back('1');
            create(op1, O-1, Z, N);
        } 
        
        if(O < Z) {
            string op2 = op;
            op2.push_back('0');
            create(op2, O, Z-1, N);
        }
    }
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}  // } Driver Code Ends