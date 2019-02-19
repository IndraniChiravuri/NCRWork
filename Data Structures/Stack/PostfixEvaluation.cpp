#include <iostream>
#include <stack>
using namespace std;

class PostfixEvaluation {
    string str;
    int len;
public:
    PostfixEvaluation() {
    }
    PostfixEvaluation(string str) {
        this -> str = str;
        this -> len = str.length();
    }

    bool isDigit(char ch) {
        return isdigit(ch);
    }

    int evaluate() {
        stack<int> st;
        char ch;
        for(int i = 0; i < len; i++) {
            ch = str[i];
            if(isdigit(ch))
                st.push(ch - '0');
            else {
                int n2 = st.top();
                st.pop();
                int n1 = st.top();
                st.pop();
                switch(ch) {
                    case '+':
                        st.push(n1+n2);
                        break;
                    case '-':
                        st.push(n1-n2);
                        break;
                    case '*':
                        st.push(n1 * n2);
                        break;
                    case '/' :
                        st.push(n1 / n2);
                        break;
                }
            }
        }
        return st.top();
    }
};

int main() {
	string exp;
	cin >> exp;
	PostfixEvaluation obj(exp);
	cout << obj.evaluate() << endl;
	return 0;
}