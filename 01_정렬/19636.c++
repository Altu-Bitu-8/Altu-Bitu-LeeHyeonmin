#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int w0, i0, t; cin >> w0 >> i0 >> t; // 전 체중, 전 섭 및 기초, 기초 역치
    int d, i, a; cin >> d >> i >> a; // 기간, 기간 섭, 기간 활동

    /* problem
    다이어트 전: 섭취, 기초 모두 i0, 활동 0
    다이어트 기간: 섭취 i, 활동 a
    체중 += 섭 - 소 (기 + 활)
    if ㅣ섭 - 소ㅣ > 변화역치 t 면 i += ㅣE섭취 - E소비ㅣ / 2 (체중 변화 다음에)
    체중 0 이하 or i 0 이하면 사망
    */

    int w = w0;
    int basal = i0;
    
    for (int k = 0; k < d; k++) {
        int daily = i - a - basal;
        w += daily;

        if (abs(daily) > t) {
            if (daily < 0) {
                basal -= (daily / 2) - daily;
            } else basal += daily / 2;
        }
    } 

    /* output
    1: 일일 기초대사량 변화 고려 X 예상체중, 일일 기초대사량
    도중 사망이 예상되면 대신 Danger Diet 출력
    2: 일일 기초대사량 변화 고려 O 예상체중, 일일 기초대사량
    */

    int nw = w0;

    for (int k = 0; k < d; k++) nw += (i - a - i0);

    if (nw <= 0) {
        cout << "Danger Diet" << '\n';
    } else {
        cout << nw << ' ' << i0 << '\n';
    }
    
    if (w <= 0 || basal <= 0) {
        cout << "Danger Diet" << '\n';
    } else {
        cout << w << ' ' << basal << ' ';
        if (i0 - basal > 0) cout << "YOYO";
        else cout << "NO";
    }

    
}