#include <iostream>
#include <map>
#include <set>
using namespace std;

// 커스텀 비교자의 이름을 개선
struct CustomComparator {
    bool operator()(const string& a, const string& b) const {
        if (a.length() == b.length()) {
            return a < b;  // 길이가 같으면 사전순 비교
        }
        return a.length() > b.length();  // 길이에 따라 먼저 비교
    }
};

int main(void) {
    int n, l;
    string in;
    map<string, int> ma;
    map<int, set<string, CustomComparator>, greater<int>> rma;
    cin >> n >> l;

    for(int i = 0; i < n; i++) {
        cin >> in;
        if(in.size() < l) {
            continue;
        }

        ma[in]++;
    }

    for(const auto& entry : ma) {
        rma[entry.second].insert(entry.first);
    }

    for(const auto& rm_entry : rma) {
        const set<string, CustomComparator>& si = rm_entry.second;
        for(const string& name : si) {
            cout << name << '\n';
        }
    }

    return 0;
}
