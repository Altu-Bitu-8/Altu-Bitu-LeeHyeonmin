#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

// 결과를 출력하는 함수
void printResult(stack<int> result) { 
    while (!result.empty()) { // 결과 스택이 비어있지 않는 동안
        cout << result.top(); // 결과 스택의 top 출력
        result.pop(); // 출력한 부분 제거
    }
    cout << '\n'; // 줄바꿈
}

// 인자로 char을 받아 int를 리턴하는 함수
int char2int(char c) { 
    return c - '0'; // char 을 int로 바꾸기
}

// A+B를 수행하는 함수
stack<int> addLargeNumbers(string &a, string &b) {
    stack<int> result; // 결과를 저장할 스택 선언

    int idx_a = a.length() - 1;  // 1의 자리 인덱스
    int idx_b = b.length() - 1;

    bool carry = false;  // 올림 숫자
    int sum = 0; // 합

    while (idx_a >= 0 && idx_b >= 0) {  // 자릿 수 더하기
        sum = char2int(a[idx_a--]) + char2int(b[idx_b--]) + carry; // char을 int로 바꿔서 
        carry = sum / 10; // 몫이 1이 넘으면 true -> 올림
        sum %= 10; // 나머지

        result.push(sum); // 구한 나머지를 result 스택에 넣기
    }

    while (idx_a >= 0) {                     // a에서 남는 숫자 반영
        sum = char2int(a[idx_a--]) + carry;  // 이때도 계속 올림이 있을 수 있음 (ex. 9999 + 1)
        carry = sum / 10; //몫이 1이 넘으면 true -> 올림
        sum %= 10; // 나머지

        result.push(sum); // 구한 나머지를 result 스택에 넣기 
    }

    if (carry) {  // 마지막으로 남아 있는 올림 수 확인
        result.push(carry); // 있다면 result 스택에 넣기
    }

    return result; // result 스택 반환하기
}

/*
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
    string a, b; // 큰 수라서 정수 자료형으로 저장이 불가능 -> string 사용
    cin >> a >> b; // 두 수 입력받기

    if (b.length() > a.length()) { // b의 길이가 a의 길이보다 더 길다면
        swap(a, b); // swap -> a의 자릿수가 b 자릿수와 같거나 더 길도록 만들기
    }

    printResult(addLargeNumbers(a, b)); // 출력하는 함수의 인자에 A+B를 수행하는 함수의 리턴값인 스택을 넣어 출력하기
}