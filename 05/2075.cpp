#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    /* problem
    n : n * n 표
    모든 수는 자신의 한 칸 위에 있는 수보다 큼
    n번째 큰 수를 찾는 프로그램
    */
    
    // 입력
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int> > q; // greater: 작은 값이 top -> 작은 수부터 제거

    for (int i = 0; i < n * n; i++) {
        int num;
        cin >> num;

        if (q.size() < n) {
            q.push(num);
        }  else if (q.top() < num) { // q.size() >= n일 때, top이 다음 수보다 작으면
            q.pop(); // top을 제거하고
            q.push(num); // 새로운 수 넣기
        } 
    }

    // 출력
    cout << q.top() << '\n';
}