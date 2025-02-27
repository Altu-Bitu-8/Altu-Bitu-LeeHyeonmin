#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string n1, n2; 

    cin >> n1 >> n2; // string을 이용해 받기
    if (n1.length() < n2.length()) {
        swap(n1, n2);
    }
    
    for (int i = 0; i < n1.length(); i++) {
        int up = 0, sum;
        sum = (n1[i] - '0') + (n2[i] - '0');
        up = sum / 10;
        sum = sum % 10;
    }
}