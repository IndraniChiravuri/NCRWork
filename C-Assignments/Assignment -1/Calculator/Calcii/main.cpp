#include <iostream>
#include <stack>
#include <cstdio>
#include <cstring>
#include <climits>

using namespace std;

int res = INT_MIN;
int add(int n1, int n2);
int diff(int n1, int n2);
int product(int n1, int n2);
int divide(int n1, int n2);

int precedance(char c) {
    if(c == '*' || c == '/')
        return 3;
    else if(c == '+' || c == '-')
        return 2;
    return 1;
}


string toPostfix(string str) {
    stack<char> st;
    st.push('0');
    string res;
    char ch;
    for(int i = 0; i < str.length(); i++) {
        ch = str[i];
        if(isdigit(ch))
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

int evaluate(string str) {
    stack<int> st;
    char ch;
    for(int i = 0; i < str.length(); i++) {
        ch = str[i];
        if(isdigit(ch)) {
            st.push(ch - '0'); // IT IS'S A DIGIT CONVERT IT INTO INTEGER AND PUSH IT INTO STACK.
        } else { //IF WE GET AN OPERATOR
            int n2 = st.top();
            st.pop();
            int n1 = st.top();
            st.pop();
            switch(ch) { //CALLING APPROPRIATE FUNCITON.
                case '+':
                    st.push(add(n1,n2));
                    break;
                case '-':
                    st.push(diff(n1,n2));
                    break;
                case '*':
                    st.push(product(n1,n2));
                    break;
                case '/' :
                    if (n2 == 0) {
                        printf("Divided by 0 error\n");
                        return INT_MIN;
                    }
                    st.push(divide(n1,n2));
                    break;
            }
        }
    }
    return st.top();
}

int main() {
	string expression;
	printf("Enter expression: ");
	cin >> expression;
	expression = toPostfix(expression);
	res = evaluate(expression);
	if (res != INT_MIN)
        printf("%d\n", res);
	return 0;
}
