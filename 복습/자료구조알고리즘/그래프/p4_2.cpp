#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; // 테스트 케이스의 수
    cin >> t;

    for (int case_num = 1; case_num <= t; ++case_num) {
        int n, l;
        cin >> n >> l;

        vector<int> A(n), B(n);

        // 배열 A와 B 입력 받기
        for (int &x : A) cin >> x;
        for (int &x : B) cin >> x;

        // 배열 정렬
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        int max_diff = -1;

        // A의 첫 번째 원소와 B의 원소를 매칭
        for (int i = 0; i < n; ++i) {
            int diff = abs(A[0] - B[i]);
            if (diff > l) continue;
            
            bool valid = true;
            int current_max_diff = diff;
            int ai = 1;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                if (abs(A[ai] - B[j]) > l) {
                    valid = false;
                    break;
                }
                current_max_diff = max(current_max_diff, abs(A[ai] - B[j]));
                ai++;
            }
            if (valid) {
                max_diff = max(max_diff, current_max_diff);
            }
        }

        // B의 첫 번째 원소와 A의 원소를 매칭
        for (int i = 0; i < n; ++i) {
            int diff = abs(B[0] - A[i]);
            if (diff > l) continue;
            
            bool valid = true;
            int current_max_diff = diff;
            int bi = 1;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                if (abs(B[bi] - A[j]) > l) {
                    valid = false;
                    break;
                }
                current_max_diff = max(current_max_diff, abs(B[bi] - A[j]));
                bi++;
            }
            if (valid) {
                max_diff = max(max_diff, current_max_diff);
            }
        }

        // 결과 출력
        cout << "Case #" << case_num << endl << max_diff << endl;
    }

    return 0;
}
