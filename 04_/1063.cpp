#include <iostream>
#include <string>
using namespace std;

/* problem

1.  체스판은 8 * 8 크기
2.  킹의 현재 위치 주어짐 (알파벳 : 열, 숫자 : 행)
3.  킹의 움직임 
R : 한 칸 오른쪽으로
L : 한 칸 왼쪽으로
B : 한 칸 아래로
T : 한 칸 위로
RT : 오른쪽 위 대각선으로
LT : 왼쪽 위 대각선으로
RB : 오른쪽 아래 대각선으로
LB : 왼쪽 아래 대각선으로
4.  돌과 같은 곳으로 이동할 때는 돌도 킹과 움직인 방향으로 한 칸 이동
5.  체스판 밖으로 나갈 경우 그 이동은 건너뛰고 다음 이동
6.  킹과 돌의 마지막 위치 구하기

*/

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    /* input
    1.  킹의 위치, 돌의 위치, 움직이는 횟수 n
    2.  n개의 줄에 킹이 어떻게 움직여야 하는지 주어짐
    */

   int kln, sln, n;
   char kla, sla;
   cin >> kla >> kln >> sla >> sln >> n;

   while (n--) {
    string com;
    cin >> com;
    int tx = 0, ty = 0;

    switch(com[0]) {
        case 'R':
            tx++;
            if (com[1] == 'T') {
                ty++;
            } else if (com[1] == 'B') {
                ty--;
            }
            break;
        case 'L':
            tx--;
            if (com[1] == 'T') {
                ty++;
            } else if (com[1] == 'B') {
                ty--;
            }
            break;
        case 'B':
            ty--;
            break;
        case 'T': 
            ty++;
            break;
    }

    if (kln + ty > 8 || kln + ty < 1 || kla + tx > 'H' || kla + tx < 'A') {
        continue;
    }
    if (kln + ty == sln && kla + tx == sla) {
        if (sln + ty > 8 || sln + ty < 1 || sla + tx > 'H' || sla + tx < 'A') {
            continue;
        }
        sln += ty;
        sla += tx;
    }

    kln += ty;
    kla += tx;

   }

   cout << kla << kln << '\n' << sla << sln;

}