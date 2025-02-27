#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;

    queue<int> x; 

    for (int i = 1; i <= n; i++) {
        x.push(i);
    }
    
    while (x.size() != 1) {
        x.pop();
        x.push(x.front());
        x.pop(); 
    }
    
    cout << x.front();
}