#include <iostream>
using namespace std;

const int MAX = 1000000;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    /* input
    1. 지구, 태양, 달 나타내는 수
    */

    int e, s, m; cin >> e >> s >> m;
    int i;

    for (i = 1; i < MAX; i++) {
        if (e == 15) e = 0;
        if (s == 28) s = 0;
        if (m == 19) m = 0;
        if (i % 15 == e && i % 28 == s && i % 19 == m) {
            break;
        }
    }
 
    cout << i;
}