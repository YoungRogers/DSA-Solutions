/*
	WIP.
	THIS WAS C lul
*/

/*

bool isOperator(char x) {
	return (x == '+' || x == '-' || x == '*' || x == '/' || x == '^');
}

char* helper(char *exp) {

	std::unordered_map<char, int> precedence = {{'(', 1}, {'+', 2}, {'-', 2}, {'*', 3}, {'/', 3}, {'^', 4}};

	// Left to Right -> 1 , Right to Left -> 2
	std::unordered_map<char, int> assoc = {{'+', 1}, {'-', 1}, {'*', 1}, {'/', 1}, {'^', 2}};


	char* res = "";

	stack<int> s;

	for (int i = 0 ; i < exp.size() ; i++) {
		if (exp[i] == '(') {
			s.push(exp[i]);
		} else if (')') {
			while (s.top() != '(') {
				s.pop();
			}
			s.pop();
		} else if (isOperator(exp[i])) {
			if (s.empty()) {
				s.push(exp[i]);
			} else {
				if (precedence[exp[i]] > precedence[s.top()]) {
					s.push(exp[i]);
				} else {
					while ((precedence[exp[i]] < precedence[s.top()]) {
					res += s.top();
						s.pop();
					}
				}
			}
		} else {
			res += exp[i];
		}
	}

	// Empty the stack.

	while (!s.empty()) {
		res += s.top();
		s.pop();
	}

	return res;

}

/*

//Function to convert an infix expression to a postfix expression.
char* infixToPostfix(char *exp) {
	// Your code here
	return helper(exp);
}

/*
	Changed to CPP
	$: SIGSEGV
*/

// { Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:

	bool isOperator(char x) {
		return (x == '+' || x == '-' || x == '*' || x == '/' || x == '^');
	}

	string helper(string& s) {
		std::unordered_map<char, int> precedence = {{'(', 1}, {'+', 2}, {'-', 2}, {'*', 3}, {'/', 3}, {'^', 4}};

		// Left to Right -> 1 , Right to Left -> 2
		std::unordered_map<char, int> assoc = {{'+', 1}, {'-', 1}, {'*', 1}, {'/', 1}, {'^', 2}};


		string res = "";

		std::stack<int> st;

		for (int i = 0 ; i < s.size() ; i++) {
			if (s[i] == '(') {
				st.push(s[i]);
			} else if (')') {
				while (st.top() != '(') {
					st.pop();
				}
				st.pop();
			} else if (isOperator(s[i])) {
				if (st.empty()) {
					st.push(s[i]);
				} else {
					if (precedence[s[i]] > precedence[st.top()]) {
						st.push(s[i]);
					} else {
						while (precedence[s[i]] < precedence[st.top()]) {
							res += st.top();
							st.pop();
						}
					}
				}
			} else {
				res += s[i];
			}
		}

		// Empty the stack.

		while (!s.empty()) {
			res += st.top();
			st.pop();
		}

		return res;
	}


	//Function to convert an infix expression to a postfix expression.
	string infixToPostfix(string s) {
		// Your code here
		return helper(s);
	}
};


// { Driver Code Starts.
//Driver program to test above functions
int main()
{
	int t;
	cin >> t;
	cin.ignore(INT_MAX, '\n');
	while (t--)
	{
		string exp;
		cin >> exp;
		Solution ob;
		cout << ob.infixToPostfix(exp) << endl;
	}
	return 0;
}
// } Driver Code Ends

