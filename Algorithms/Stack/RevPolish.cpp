class Solution {
    public:
        int evalRPN(vector<string> &tokens) {
            stack<int> st;
            for(int i = 0; i < tokens.size(); ++i) {
                if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                    int v1=st.top();
                    st.pop();
                    int v2=st.top();
                    st.pop();
                    switch(tokens[i][0]) {
                        case '+':
                            st.push(v2 + v1);
                            break;
                        case '-':
                            st.push(v2 - v1);
                            break;
                        case '*':
                            st.push(v2 * v1);
                            break;
                        case '/':
                            st.push(v2 / v1);
                            break;
                    }
                } else {
                    st.push(atoi(tokens[i].c_str()));
                }
            }
            return st.top();
        }
};

int Solution::evalRPN(vector<string> &A) {
    stack<int> S;
    for (auto &token : A) {
        if (token.size() > 1 || (token[0] >= '0' && token[0] <= '9')) {
            S.push(atoi(token.c_str()));
            continue;
        }

        int op2 = S.top(); S.pop();
        int op1 = S.top(); S.pop();
        char op = token[0];
        int result;
        if (op == '+') {
            S.push(op1 + op2);
        } else if (op == '-') {
            S.push(op1 - op2);
        } else if (op == '*') {
            S.push(op1 * op2);
        } else if (op == '/') {
            S.push(op1 / op2);
        }
    }
    return S.top();
}

// https://www.interviewbit.com/problems/evaluate-expression/