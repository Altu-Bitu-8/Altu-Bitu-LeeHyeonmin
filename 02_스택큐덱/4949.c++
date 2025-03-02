#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    while (true) {
        string sen;
        stack<char> s;
        bool judge = true;

        getline(cin, sen); 

        if (sen == ".") break;

        for (char i : sen) {
            if (i == '(' || i == '[') {
                s.push(i);
            } else if (i == ')') {
                if (!s.empty() && s.top() == '(') {
                    s.pop();
                } else {
                    judge = false;
                    break;
                }
            } else if (i == ']') {
                if (!s.empty() && s.top() == '[') {
                    s.pop();
                } else {
                    judge = false;
                    break;
                }
            }
        }

        if (!s.empty()) judge = false; 

        cout << (judge ? "yes" : "no") << '\n';
    }

}
