// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        int mid = (sizeOfStack + 2 -1)/2;
        mid = sizeOfStack - mid + 1;
        dM(s, mid);
        
    }
    
    private: 
    void dM(stack<int>& stk, int count) {
        if(count == 1) {
            stk.pop();
            return;
        }   
        
        int endRemoved = stk.top(); 
        stk.pop();
        dM(stk, count - 1);
        
        stk.push(endRemoved);
        
    }
    
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}
  // } Driver Code Ends