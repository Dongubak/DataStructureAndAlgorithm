#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>

using std::cin;
using std::cout;
using std::vector;
using std::pair;
using std::tuple;

// 방향을 나타내는 배열
int R[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int C[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};

int max = -1; // 최댓값을 저장하는 변수

void moveFish(vector<vector<pair<int, int>>>& s, tuple<int, int, int> cur) {
    auto& [cr, cc, cd] = cur;

    for (int i = 1; i <= 16; i++) {
        int r = -1, c, d;
        bool isFound = false;
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                if (s[j][k].first == i) {
                    r = j, c = k, d = s[j][k].second;
                    isFound = true;
                    break;
                }
            }
            if (isFound) break;
        }

        if (r == -1) continue;

        while (!(r + R[d] >= 0 && r + R[d] < 4 && c + C[d] >= 0 && c + C[d] < 4 &&
                !((r + R[d] == cr) && (c + C[d] == cc)))) {
            d++;
            if (d == 9) d = 1;
        }

        auto [dn, desDir] = s[r + R[d]][c + C[d]];
        if (desDir == 0) {
            s[r + R[d]][c + C[d]] = s[r][c];
            s[r][c] = {0, 0};
            s[r + R[d]][c + C[d]].second = d;
        } else {
            auto tmp = s[r][c];
            s[r][c] = s[r + R[d]][c + C[d]];
            s[r + R[d]][c + C[d]] = tmp;
            s[r + R[d]][c + C[d]].second = d;
        }
    }
}

void moveShark(tuple<int, int, int> cur, vector<vector<pair<int, int>>> s, int sum) {
    auto& [cr, cc, cd] = cur; 
    auto& [dn, dd] = s[cr][cc];

    cd = dd; 
    dd = 0; 

    sum += dn;
    dn = 0;

    moveFish(s, cur);

    bool canMove = false;
    for (int i = 1; i < 4; i++) {
        int nr = cr + i * R[cd];
        int nc = cc + i * C[cd];
        if (nr >= 0 && nr < 4 && nc >= 0 && nc < 4 && s[nr][nc].second != 0) {
            canMove = true;
            moveShark({nr, nc, cd}, s, sum);
        }
    }

    if (!canMove) {
        max = std::max(max, sum);
    }
}

void sol(vector<vector<pair<int, int>>>& s) {
    int initial_fish = s[0][0].first;
    s[0][0].first = 0;
    moveShark({0, 0, s[0][0].second}, s, initial_fish);
}

int main() {
    vector<vector<pair<int, int>>> s(4, vector<pair<int, int>>(4, {0, 0}));
    int n, d;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> n >> d;
            s[i][j] = {n, d};
        }
    }

    sol(s);

    cout << max;

    return 0;
}
