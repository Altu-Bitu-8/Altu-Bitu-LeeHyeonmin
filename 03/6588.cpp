#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000000;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    /*
    problem
    "4보다 큰 모든 짝수는 두 홀수 소수의 합으로 나타낼 수 있다." 
    백만 이하의 모든 짝수에 대해 이 추측을 검증하기

    input
    입력은 하나 이상
    각 테스트 케이스는 짝수 정수 n 하나로 이루어져 있다. (6 ≤ n ≤ 1000000)
    입력의 마지막 줄에는 0

    output
    n = a + b 형태로 출력한다. 
    이때, a와 b는 홀수 소수
    숫자와 연산자는 공백 구분
    만약, n을 만들 수 있는 방법이 여러 가지라면, b-a가 가장 큰 것 출력
    또, 두 홀수 소수의 합으로 n을 나타낼 수 없는 경우에는 "Goldbach's conjecture is wrong."을 출력한다.
    */

   int n; 
   vector<bool> prime(MAX + 1, 1);

   prime[0] = prime[1] = false;
        for (int i = 2; i * i <= MAX; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= MAX; j += i) {
                    prime[j] = false;
                }
            }
        }

   while (1) {
        cin >> n;
        if (n == 0) break;
        bool judge = false;


        for (int a = 3; a <= n / 2; a += 2) {
            if (prime[a] && prime[n - a]) {
                cout << n << " = " << a << " + " << (n - a) << '\n';
                judge = true;
                break;
            }
        }
            
        if (!judge) {
            cout << "Goldbach's conjecture is wrong.\n";
        }
   }
}