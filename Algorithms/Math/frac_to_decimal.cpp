/ { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	string fractionToDecimal(int numerator, int denominator) {
	    float frac = (float)numerator/(float)denominator;
	    string fraction = to_string(frac);
	    map<int, int> rem_map;
	    int rem = numerator%denominator;
	    string res;
	    res += to_string(numerator/denominator);
	    if(rem==0)
	        return res;
	    res += ".";
	    string decimal;
	    
	    while(rem!=0 and rem_map.find(rem)==rem_map.end()){
	        rem_map[rem] = decimal.length();
	        
	        rem = rem*10;
	        
	        decimal+=to_string(rem/denominator);
	        
	        rem = rem%denominator;
	        
	    }
	    
	    if(rem==0)
	        return (res+decimal);
	    return (res+decimal.substr(0, rem_map[rem])+"("+decimal.substr(rem_map[rem])+")");
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int numerator, denominator;
		cin >> numerator >> denominator;
		Solution ob;
		string ans = ob.fractionToDecimal(numerator, denominator);
		cout << ans <<"\n";
	}
	return 0;
}	
