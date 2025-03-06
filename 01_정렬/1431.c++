#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n; 

bool dict(const string& g1, const string& g2) {
    
    // 시리얼 번호 순으로 정렬
    // 1. 길이가 짧은 게 먼저
    // 2. 길이가 같으면 숫자만 더해서 더 작은 게 먼저
    // 3. 합도 같으면 사전순으로 비교 (숫자 < 알파벳)

    if (g1.length() != g2.length()) 
		return g1.length() < g2.length(); // g1이 g2보다 길면 false니까 swap
    
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < g1.length(); i++) {
        if (isdigit(g1[i]))
            sum1 += int(g1[i]) - '0';
    }
    for (int i = 0; i < g2.length(); i++) {
        if (isdigit(g2[i])) 
            sum2 += int(g2[i]) - '0';
    }

    if (sum1 != sum2)
        return sum1 < sum2; // 앞의 합이 뒤의 합보다 크면 false니까 swap

    for (int i = 0; i < g1.length(); i++) {
        if (isdigit(g1[i]) && !isdigit(g2[i]))
            return true;
        if (!isdigit(g1[i]) && isdigit(g2[i]))
            return false;
        if (g1[i] != g2[i])
            return g1[i] < g2[i];
    }
    return true;
}



int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n; // 기타의 개수 <= 50
    vector<string> g;
    string input;

    for (int i = 0; i < n; i++) {
        cin >> input;
        g.push_back(input);
    }

    sort(g.begin(), g.end(), dict);

    for (int i = 0; i < n; i++) {
        cout << g[i] << '\n';
    }
    
}