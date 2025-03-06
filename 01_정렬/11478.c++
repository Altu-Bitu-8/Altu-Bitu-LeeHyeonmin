#include <iostream>
#include <string>
#include <set>
using namespace std;

// 분류 : 자료구조, 해시를 사용한 집합과 맵, 문자열, 트리를 사용한 집합과 맵

int main()
{
    /* problem
    부분 문자열 : S의 연속된 일부분 
    substr(시작 위치, 길이) 으로 문자열 자르고
    set에 저장해서 중복 없이 개수 세기
    */

    string s; cin >> s;
    set<string> n;

    for (int i = 0; i < s.length(); i++) {
        for (int j = 1; j < s.length() + 1; j++) {
            n.insert(s.substr(i, j));
        }
    }

    cout << n.size();

}