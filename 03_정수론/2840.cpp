#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, char> ic; // 회전 횟수, 글자를 저장하는 pair
const int ALPHA = 26; // 알파벳 사용 상수

// 바퀴 출력 함수
string printWheel(int n, int index, vector<char>& wheel) {
    string ans = "";
    // 바퀴를 돌릴 때와 반대방향으로 출력
    for (int i = index + n; i > index; i--) {
        ans += wheel[i % n]; 
    }
    return ans;
}

// 행운의 바퀴 반환
string makeWheel(int n, int k, vector<ic>& record) {
    vector<char> wheel(n, '?'); // 바퀴의 모든 알파벳을 ?로 초기화
    vector<bool> is_available(ALPHA, false); // 알파벳 중복 체크

    int index = 0; // 현재 화살표가 가리키는 위치

    for (int i = 0; i < k; i++) {
        int s = record[i].first; // 회전하는 횟수
        char ch = record[i].second; // 해당 위치의 글자

        index = (index + s) % n; // 회전한 후 화살표 위치 (바퀴는 순환하므로 n으로 나눈 나머지를 위치로 설정)

        if (wheel[index] == ch) { // 이미 같은 글자가 있다면
            continue; // 건너뛰기
        }

        if (wheel[index] != '?' || is_available[ch - 'A']) { // 이미 다른 글자가 있거나, 같은 알파벳이 다른 위치에 존재하면
            return "!"; // ! 반환
        }

        wheel[index] = ch; // 현재 위치에 글자 저장하기
        is_available[ch - 'A'] = true; // 사용되었으므로 중복 방지를 위해 true
    }
    return printWheel(n, index, wheel); // 결과 문자열 반환
}

int main() { 
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //입력
    int n, k;
    cin >> n >> k; // 바퀴 칸 수, 바퀴 돌리는 횟수 입력

    vector<ic> record(k);
    for (int i = 0; i < k; i++) {
        cin >> record[i].first >> record[i].second; // 화살표 가리키는 글자 바뀐 수, 회전 멈췄을 때 가리키던 글자
    }

    //연산 & 출력
    cout << makeWheel(n, k, record);

    return 0;
}