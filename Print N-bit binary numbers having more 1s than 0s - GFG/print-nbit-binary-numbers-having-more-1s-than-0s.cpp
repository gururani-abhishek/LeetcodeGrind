// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
    vector<string> ans;
	vector<string> NBitBinary(int N)
	{
	    string op = "";
	    create(op, N, N, N);
	    return ans;
	}
	
private: 
    void create(string op, int one, int zero, int n) {
        if(n == 0) {
            ans.push_back(op);
            return;
        }
        
        if(one > 0) {
            string op1 = op;
            op1.push_back('1');
            create(op1, one -1, zero, n -1);
        }
        
        if(one < zero) {
            string op2 = op;
            op2.push_back('0');
            create(op2, one, zero -1, n -1);
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