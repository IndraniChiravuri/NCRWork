#include <bits/stdc++.h>

using namespace std;

/* int prec(char q) {
	if ((q == '*') || (q == '/'))
	{
		return 10;
	}
	if ((q == '+') || (q == '-'))
	{
		return 7;
	}
	if ((q == '(') || (q == ')'))
	{
		return 1;
	}
	if ((q == '[') || (q == ']'))
	{
		return 1;
	}
	if ((q == '{') || (q == '}'))
	{
		return 1;
	}

} */

int precedance(char C) {
	if (C == '-' || C == '+')
		return 1;
	else if (C == '*' || C == '/')
		return 2;
	return 0;
}
bool isAlpha(char ch) {
    return (ch >= 'a' && ch <= 'z')||(ch >= 'A' && ch <= 'Z');
}

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '/' || ch == '*');
}

string infixToPrefix(string infix)  {
    int len = infix.size();
    string prefix;
    int index = 0;
    stack<char> st;
    st.push('0');
	for (int i = len-1; i >= 0; i--) {
        char ch = infix[i];
		if (isAlpha(ch)) {
			prefix[index++] = ch;
		} else if (ch == '(' || ch == '[' || ch == '{' || st.top() == '0')
                st.push(ch);
        else if (isOperator(ch)) {
            if (precedance(ch) > precedance(st.top())) {
                st.push(ch);
            } else if (precedance(ch) == precedance(st.top())) {
                char op = st.top();
                st.pop();
                prefix[index++] = op;
                st.push(ch);
            } else {
                char op = st.top();
                st.pop();
                prefix[index++] = op;
            }
            st.push(ch);
        } else {
            while(st.top() != '0' && (st.top() != '(' || ch == '[')) {
                    char op = st.top();
                    st.pop();
                    prefix[index++] = op;
                }
                st.pop();
        }
    }
    return prefix;
}

int main() {
	string s = ("[[a+b]*e-[f/g]]");
	cout << infixToPrefix(s) << endl;
	return 0;
}