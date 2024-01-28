// #include <deque>
// #include <cstdio>
// #include <algorithm>

// int max(const int& a, const int& b) {
//    return a > b ? a : b;
// }

// int main(void) {
//    int c, cn;
//    std::deque<int> cards;
//    scanf("%d", &c);
   
//    for(int i = 0; i < c; i++) {
//       bool bit = 1;
//       int sum1 = 0;
//       int card;

//       scanf("%d", &cn);
//       for(int i = 0; i < cn; i++) {
//          scanf("%d", &card);
//          cards.push_back(card);
//       }

//       while(!cards.empty()) {
//          std::deque<int>::iterator fiter = cards.begin();
//          std::deque<int>::reverse_iterator biter = cards.rbegin();
         
      
//          if(cards.size() > 4) {
//             int left = *fiter - max(*(fiter + 1), *biter);
//             int right = *biter - max(*(biter + 1), *fiter);
//             if(left > right) {
//                if(bit) {
//                   sum1 += *fiter;
//                } 
//                cards.pop_front();
//             } else if(right > left) {
//                if(bit) {
//                   sum1 += *biter;
//                } 
//                cards.pop_back();
//             } else { ///left == right
//                if(*fiter > *biter) {
//                if(bit) {
//                   sum1 += *fiter;
//                }
//                cards.pop_front();
//                } else {
//                   if(bit) {
//                      sum1 += *biter;
//                   }
//                   cards.pop_back();
//                }
//             }
//          } else if(cards.size() == 4) {
//             std::deque<int> dq(cards);
//             sort(dq.begin(), dq.end());

//             if(find(cards.begin(), cards.end(), dq.back()) != cards.begin() &&
//                find(cards.begin(), cards.end(), dq.back()) != (cards.begin() + 3)
//             ) {
//                int left = *fiter + *(biter + 1);
//                int right = *biter + *(fiter + 1);

//                if(left > right) {
//                   if(bit) {
//                      sum1 += *fiter;
//                   }
//                   cards.pop_front();
//                } else if(right > left) {
//                   if(bit) {
//                      sum1 += *biter;
//                   }
//                   cards.pop_back();
//                } else {
//                   if(*fiter > *biter) {
//                      if(bit) {
//                         sum1 += *fiter;
//                      }
//                      cards.pop_front();
//                   } else {
//                      if(bit) {
//                         sum1 += *biter;
//                      }
//                      cards.pop_back();
//                   }
//                }
//             } else {
//                if(*fiter > *biter) {
//                   if(bit) {
//                      sum1 += *fiter;
//                   }
//                   cards.pop_front();
//                } else {
//                   if(bit) {
//                      sum1 += *biter;
//                   }
//                   cards.pop_back();
//                }
//             }
            
//          } else {
//             if(*fiter > *biter) {
//                if(bit) {
//                   sum1 += *fiter;
//                }
//                cards.pop_front();
//             } else {
//                if(bit) {
//                   sum1 += *biter;
//                }
//                cards.pop_back();
//             }
//          }

//          bit = !bit;
//       }
//       printf("%d\n", sum1);

//       cards.clear();
//    }

//    return 0;
// }

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int T, N, arr[1001], dp[1001][1001];

int CardGame(int left, int right, int turn) {
	if (left > right) return 0;
	if (dp[left][right]) return dp[left][right];

	if (turn % 2) // 근우 차례
	   return dp[left][right] = max(arr[left] + CardGame(left + 1, right, turn + 1), arr[right] + CardGame(left, right - 1, turn + 1));
	else // 명우 차례 
	   return dp[left][right] = min(CardGame(left + 1, right, turn + 1), CardGame(left, right - 1, turn + 1));
}

int main() {
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		for (int n = 0; n < N; n++) cin >> arr[n];
		CardGame(0, N - 1, 1);
		cout << dp[0][N - 1] << "\n";
		memset(dp, 0, sizeof(dp));
	}
	return 0;
}