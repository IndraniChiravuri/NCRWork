#include<bits/stdc++.h>
using namespace std;

class InfixToPostfix {
    string str;
    int len;
public:
    InfixToPostfix() {
    }
    InfixToPostfix(string str) {
        this -> str = str;
        this -> len = str.length();
    }
    int precedance(char c) {
        if(c == '*' || c == '/')
            return 3;
        else if(c == '+' || c == '-')
            return 2;
        return 1;
    }

    bool isAlpha(char ch) {
        return (ch >= 'a' && ch <= 'z')||(ch >= 'A' && ch <= 'Z');
    }

    string convert() {
        stack<char> st;
        st.push('0');
        string res;
        char ch;
        for(int i = 0; i < len; i++) {
            ch = str[i];
            if(isAlpha(ch))
                res += ch;
            else if(ch == '(' || ch == '[')
                st.push(ch);
            else if(ch == ')' || ch == ']') {
                while(st.top() != '0' && (st.top() != '(' || ch == '[')) {
                    char op = st.top();
                    st.pop();
                    res += op;
                }
                st.pop();
            } else {
                while(st.top() != '0' && precedance(ch) <= precedance(st.top())) {
                    char op = st.top();
                    st.pop();
                    res += op;
                }
                st.push(ch);
            }
        }
        //Popping remaining elements in stack.
        while(st.top() != '0') {
            char c = st.top();
            st.pop();
            res += c;
        } 
        return res;
    }
};

int main() {
	string exp;
	cin >> exp;
	InfixToPostfix obj(exp);
	cout << obj.convert() << endl;
	return 0;
}