#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    /* problem
    add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
    remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
    check x: S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
    toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
    all: S를 {1, 2, ..., 20} 으로 바꾼다.
    empty: S를 공집합으로 바꾼다.
    */

    
    int m; 
    cin >> m; 

    int b = 0; // 비트마스킹을 이용할 수
    int x;
    while (m--) {
        string com;
        cin >> com;

        if (com == "add") {
            cin >> x;
            b |= (1 << x); // or 연산
        } else if (com == "remove") {
            cin >> x;
            b &= ~(1 << x); // not 후 and 연산 (없다면 0과 0 연산으로 그대로, 있다면 1에 0과 and 연산)
        } else if (com == "check") {
            cin >> x;
            if (b & (1 << x)) { // 있다면(1) 1과 and 연산했을 때 1, 없다면 0
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        } else if (com == "toggle") {
            cin >> x;
            if (b & (1 << x)) {
                b &= ~(1 << x);
            } else {
                b |= (1 << x);
            }
        } else if (com == "all") {
            for (int i = 1; i <= 20; i++) {
                b |= 1 << i;
            }
        } else if (com == "empty") {
            b = 0;
        }
    }
}