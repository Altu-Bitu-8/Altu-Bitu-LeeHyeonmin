#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while (1) {
        string sen;
        stack<char> s;
        bool judge = 1;

        getline(cin, sen);

        if (sen == ".")
            break;
        

        for (char i : sen) {
            if (i == '(' || i == '[') {
                s.push(i);
            } else if (i == ')') {
                if (!s.empty() && s.top() == '(') {
                    s.pop();
                } else {
                    judge = 0;
                    break;
                }
            } else if (i == ']') {
                if (!s.empty() && s.top() == '[') {
                    s.pop();
                } else {
                    judge = 0;
                    break;
                }
            } else continue;
        }

        if (!s.empty()) judge = 0;

        if (judge) {
            cout << "yes" << '\n';
        } else {
            cout << "no" << '\n';
        }
    }
}