#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

/*
 * [HINT]
 * 주어지는 a와 b는 0보다 크고 10의 100승보다 작은 정수로,
 * C++에서 사용할 수 있는 정수 자료형의 크기를 벗어나요.
 * 어떻게 하면 바로 a+b를 더하지 않는 방법으로, 그 결과를 구할 수 있을까요?
 */

// 결과를 출력하는 함수
void printResult(stack<int> result) {
    while (!result.empty()) { // 결과 스택이 빌 때까지
        cout << result.top(); // 스택의 top을 출력하고
        result.pop(); // 출력한 부분 삭제하기
    }
    cout << '\n';
}

// char을 int로 바꾸는 함수
int char2int(char c) {
    return c - '0'; // 0을 빼서 char을 int로 바꾸기
}

// A+B를 수행하는 함수
stack<int> addLargeNumbers(string &a, string &b) {
    stack<int> result; // 결과 저장 스택 선언

    int idx_a = a.length() - 1;  // 1의 자리 인덱스
    int idx_b = b.length() - 1;

    bool carry = false;  // 올림 숫자
    int sum = 0;

    while (idx_a >= 0 && idx_b >= 0) {  // 자릿 수 더하기
        sum = char2int(a[idx_a--]) + char2int(b[idx_b--]) + carry; // 같은 자릿수의 합 구하기
        carry = sum / 10; // 몫이 1을 넘으면 올림
        sum %= 10; // 나머지

        result.push(sum); // 나머지를 스택에 넣기
    }

    while (idx_a >= 0) {                     // a에서 남는 숫자 반영
        sum = char2int(a[idx_a--]) + carry;  // 이때도 계속 올림이 있을 수 있음 (ex. 9999 + 1)
        carry = sum / 10; // 몫이 1을 넘으면 올림
        sum %= 10; // 나머지

        result.push(sum); // 나머지를 스택에 넣기
    }

    if (carry) {  // 마지막으로 남아 있는 올림 수 확인
        result.push(carry); // 올림이 있으면 스택에 넣기
    }

    return result; // 결과 스택을 반환하기
}

/*
 * [큰 수 A+B]
 * 두 수의 자리수가 최대 10000으로, 매우 크기 때문에 절대 기본 자료형으로 저장할 수 없어요!
 * 직접 더하기를 구현해 주어야 해요.
 *
 * 1. 한 자릿수씩 더해서 스택(혹은 배열)에 저장
 * 2. 한 자릿수씩 더할 때, 값이 10을 넘어가는 경우 고려 -> 자릿수 올림
 * 3. A와 B의 길이가 같지만, 둘의 합의 길이는 다른 경우 고려 -> 마지막 자리에서 올림
 * 4. A와 B의 길이가 다른 경우 고려 -> 더 긴 길이 처리 주의,
 *                                코드 중복을 피하기 위해 A가 B보다 길도록 먼저 처리하고 시작
 *
 * 본 풀이에서 더한 결과 값을 스택에 넣는 이유는 일의 자릿수부터 더하기 때문입니다.
 * => 스택이 아닌 배열을 사용할 경우 마지막 인덱스부터 출력
 * */

int main() {
    string a, b; // 매우 큰 수이므로 string 자료형으로 받기
    cin >> a >> b; // 두 수 받기

    if (b.length() > a.length()) { // 만약 b 자릿수가 a 자릿수가 길다면
        swap(a, b); // swap 해서 항상 a 자릿수가 크거나 같도록
    }

    printResult(addLargeNumbers(a, b)); // 함수에 인자 전송
}