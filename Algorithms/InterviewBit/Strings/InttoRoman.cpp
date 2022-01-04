class Solution {
public:
    string intToRoman(int num) {
        // 1000, 2000, 3000
        string M[] = {"", "M", "MM", "MMM"};
        // 100, 200, 300, .. 900
        string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        // 10, 20, ... 90
        string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        // 1, 2, ... 9
        string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
    }
};

string Solution::intToRoman(int num) {
         
      vector<int>   numbers={1 , 4 , 5, 9, 10 , 40 , 50 , 90 , 100 , 400 , 500 , 900 , 1000};
        vector<string> syms =  {"I" , "IV"  , "V" , "IX" , "X" , "XL" , "L" , "XC" , "C" , "CD" , "D" , "CM" , "M" };
        int i = 12; string s = "";
        while(num > 0){
            int div = num / numbers[i];
            num = num % numbers[i];
            
            while(div--){
                s += syms[i];    
            }
            i--;
        }
        
        return s;

}

string Solution::intToRoman(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n = A;
	vector<pair<char,int>> rti;

	rti.push_back(make_pair('I',1));
	rti.push_back(make_pair('V',5));
	rti.push_back(make_pair('X',10));
	rti.push_back(make_pair('L',50));
	rti.push_back(make_pair('C',100));
	rti.push_back(make_pair('D',500));
	rti.push_back(make_pair('M',1000));

	string roman;

	for (int i = rti.size()-1; n ; ) {
		if (i == 0) {
			while (n > 0) {
				n--;
				roman += 'I';
			}
		}
		else {
			if (rti[i].second <= n) {
				int q = n / rti[i].second;
				for (int j = 0; j < q; j++)
					roman += rti[i].first;
				n -= q*rti[i].second;
			}
			else if ((rti[i].second/rti[i-1].second == 5 && rti[i].second-rti[i-1].second <= n)) {
				roman += rti[i-1].first;
				roman += rti[i].first;
				n -= rti[i].second - rti[i-1].second;
				i--;
			}
			else if (rti[i].second-rti[i-2].second <= n) {
				roman += rti[i-2].first;
				roman += rti[i].first;
				n -= rti[i].second - rti[i-2].second;
				i--;
			}
			else
				i--;
		}
	}
    return roman;
}


// https://www.interviewbit.com/problems/integer-to-roman/