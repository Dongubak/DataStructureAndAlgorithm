#include <iostream>
#include <set>
using namespace std;

int l, k, c;

int main(void) {
    int t;
    
    cin >> l >> k >> c;
    set<int, greater<int>> s;

    for(int i = 0; i < k; i++) {
        cin >> t;
        s.insert(t);
    }

    int left = 1, right = l;
    int opt, pos;

    while(left <= right) { ///mid 찾는다.
        int mid = (left + right) / 2;
        int pre = l, cutable = c; // l부터 시작한다, cutable은 자를 수 있는 횟수임 ㅇㅋ?
        bool isCutable = true;
        for(auto ptr = s.begin(); ptr != s.end(); ptr++) { /// 9 8 2 1
            if(pre - *ptr > mid) { /// 이건 잘라야 해
                int prevC;
                if(ptr == s.begin()) {
                    prevC = l;
                } else {
                    prevC = *(prev(ptr));
                }

                if(prevC - *ptr > mid) { /// 이건 잘라도 의미가 없음
                    isCutable = false;
                    break;
                }

                cutable -= 1;
                pre = prevC;


                if(cutable == 0) { // 그만 자르셈
                    if(pre > mid) {
                        isCutable = false;
                    }
                    break;
                }
            }
        }

        if(cutable > 0) { /// 더 자를 수 있는 경우 여러 경우가 있으므로 가장 작은거 선택함
            pre = *(prev(s.end()));
            
            if(pre > mid) {
                isCutable = false;
            } // 젤루 작은게 mid보다 크면 넌 나가라
        }

        if(!isCutable) { /// 더 크게
            left = mid + 1;
        } else {
            right = mid - 1;
            opt = mid;
            pos = pre;
        }
        
    }
    
    cout << opt << " " << pos << '\n';

    return 0;
}