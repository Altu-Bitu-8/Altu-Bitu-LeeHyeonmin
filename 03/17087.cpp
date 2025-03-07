#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 최대공약수 구하는 함수
int getGcd(int a, int b) 
{
    if (b == 0)
        return a;
    
    return getGcd(b, a % b);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    /* 
    유클리드 호제법, 수학, 정수론
    
    problem
    수빈이는 동생 N명과 숨바꼭질을 하고 있다. 
    수빈이는 현재 점 S에 있고, 동생은 A1, A2, ..., AN에 있다.
    수빈이는 걸어서 이동을 할 수 있다. 
    수빈이의 위치가 X일때 걷는다면 1초 후에 X+D나 X-D로 이동할 수 있다. 
    수빈이의 위치가 동생이 있는 위치와 같으면, 동생을 찾았다고 한다.
    모든 동생을 찾기위해 D의 값을 정하려고 한다. 가능한 D의 최댓값을 구해보자.

    input
    첫째 줄에 N(1 ≤ N ≤ 10^5)과 S(1 ≤ S ≤ 10^9)가 주어진다. 
    둘째 줄에 동생의 위치 Ai(1 ≤ Ai ≤ 109)가 주어진다. 
    동생의 위치는 모두 다르며, 수빈이의 위치와 같지 않다.

    output
    가능한 D값의 최댓값을 출력한다.

    hint
    수빈이는 특정 거리만큼 반복해서 이동할 수 있어요. 
    모든 동생에게 도달하려면 이 거리는 어떤 성질을 만족해야 할까요? 
    예제를 잘 관찰해봐요.
    */

   int n, s; cin >> n >> s; // 동생 수, 수빈이 현재 위치

    vector<int> dif(n); // 차이

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        dif[i] = abs(a - s);
    }

    int res = dif[0];

    for (int i = 1; i < n; i++) {
        res = getGcd(res, dif[i]); // 결과에 공약수
    }

    cout << res << '\n';

}