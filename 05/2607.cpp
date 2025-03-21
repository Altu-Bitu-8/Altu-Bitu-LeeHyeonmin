#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 알파벳 개수를 세는 함수
void countAlphabet(string word, vector<int> &count)
{
    for (char x: word) {
        count[x - 'A']++; // 알파벳의 횟수 기록
    }
}

// 단어가 비슷한지 판별하는 함수
bool similar(vector<int> &pre_count, string af_word) {
    vector<int> word_count(26, 0);
    countAlphabet(af_word, word_count);
    
    int ptaf = 0, atpf = 0;

    for (int i = 0; i < 26; i++) {
        if (pre_count[i] > word_count[i]) {
            ptaf += pre_count[i] - word_count[i]; // pre true, af false
        } else {
            atpf += word_count[i] - pre_count[i]; // af true, pre false
        }
    }

    return (ptaf <= 1 && atpf <= 1); 
}

int main()
{
    int n;
    cin >> n;

    string word;
    cin >> word;

    vector<int> pre_count(26, 0);
    countAlphabet(word, pre_count);
    
    int similar_count = 0;
    for (int i = 1; i < n; i++) {
        string af_word;
        cin >> af_word;
        if (similar(pre_count, af_word)) similar_count++;
    }

    cout << similar_count;
}