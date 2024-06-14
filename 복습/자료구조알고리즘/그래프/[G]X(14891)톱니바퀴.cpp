// 6월 15일 한사이클 회전한 이 후에 서로 다른 극에 대해서
// 한번더 한 사이클 회전을 더 시킴
// 그니까 모든 극들이 서로 같을 때까지 회전시킨다는 거 같음
// 문제는 이전에 회전했던 방향을 기억해야 한다는 거임
// 만약 2때문에 3이 회전했고 3때문에 4가 회전했음
// 근데 2때문에 3이 회전할 당시 당연히 또 다른 극일 수 있으며
// 이때 2를 회전시킬지 3을 회전시킬지가 문제라는 거임

// 아니면 서로다른 극을 갖는 기어들을 조사한 다음
// 한번에 회전시키는 방법도 있음 이 경우에도
// 이전에 회전시킨 방향을 기억해야한다는 문제가 발생함


#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::vector;
using std::cout;
using std::string;

/// -1인 경우 회전 방향
unsigned char rotateLeft(unsigned char n) {
   return (n << 1) | (n >> 7);
}

/// 1인 경우 회전 방향
unsigned char rotateRight(unsigned char n) {
   return (n >> 1) | (n << 7);
}

void rec(vector<unsigned char> &gears, int i, int d) {
   // i: current gear의 index
   // d: current gear의 회전 방향

   if(i - 1 >= 0) {
      if(i - 1 == 0) {
         if((((gears[0] >> 2) & 1) % 2) ^
            ((gears[1] >> 6) & 1) % 2
         ) {
            if(d == 1) {
               gears[0] = rotateLeft(gears[0]);
            } else {
               gears[0] = rotateRight(gears[0]);
            }
            // rec(gears, i - 1, d == -1 ? 1 : -1);
         }
      } else {
            ///왼쪽
            if((((gears[i - 1] >> 2) & 1) % 2) ^
            ((gears[i] >> 6) & 1) % 2
         ) {
            if(d == 1) {
               gears[i - 1] = rotateLeft(gears[i - 1]);
            } else {
               gears[i - 1] = rotateRight(gears[i - 1]);
            }
            rec(gears, i - 1, d == -1 ? 1 : -1);
         }
      }
   }

   if(i + 1 <= 4) {
      if(i + 1 == 4) {
         if((((gears[3] >> 2) & 1) % 2) ^
            ((gears[4] >> 6) & 1) % 2
         ) {
            if(d == 1) {
               gears[4] = rotateLeft(gears[4]);
            } else {
               gears[4] = rotateRight(gears[4]);
            }
            // rec(gears, i + 1, d == -1 ? 1 : -1);
         }
      } else {
         ///오른쪽
         if((((gears[i] >> 2) & 1) % 2) ^
         ((gears[i + 1] >> 6) & 1) % 2
      ) {
         if(d == 1) {
            gears[i + 1] = rotateLeft(gears[i + 1]);
         } else {
            gears[i + 1] = rotateRight(gears[i + 1]);
         }
         rec(gears, i + 1, d == -1 ? 1 : -1);
      }
      }
   }
}

void rotate(vector<unsigned char>& gears, int initGear, int initDir) {
   // init is not zero index
   initGear -= 1;
   if(initDir == 1) {
      gears[initGear] = rotateRight(gears[initGear]);
   } else {
      gears[initGear] = rotateLeft(gears[initGear]);
   }
   rec(gears, initGear, initDir);
}

int main(void) {

   string in;

   vector<unsigned char> gears(4, 0);

   for(int i = 0; i < 4; i++) {
      cin >> in;
      std::bitset<8> bit(in);

      gears[i] = (unsigned char)bit.to_ulong();
   }


   int n; ///회전 횟수
   int g, d;
   cin >> n;

   for(int i = 0; i < n; i++) {
      cin >> g >> d;
      rotate(gears, g, d);
   }

   int score = 0;

   for(int i = 0; i < 4; i++) {
      if(gears[i] % 2 == 1) {
         score += 1 << i;
      }
   }

   cout << score;

   return 0;
}


// 음....
// 비트조작하면 편할 것 같음
// 1비트에 0또는 1 넣고 총 8개 비트 쓰면 되자늠

// 8비트면 char형임 char형에 대해서 비트연산 때리면 
// 즉 somebit = somebit >> 1; 이렇게 하면 오른쪽 사라지는 비트가
// 왼쪽으로 넘어가냐가 문제임
// 그리고 2번째 비트 나 6번째 비트 확인 할거면 
// 1 << 2 랑  1 << 6 한거랑 &연산 때리면 값을 알 수 있자늠

// 오케이 글면 이제 입력 받은 기어를 먼저 회전 시킨 후에
// 양쪽을 확인해야 함 양쪽을 확인 한 후에
// 각각의 양 옆에 있는거 확인함

// 4번째 기어가 회전하는 경우
// 1. 왼쪽꺼
// 2. 그 왼쪽꺼
// 3. 그 왼쪽꺼 3번 검사함

// 3번째 기어가 회전하는 경우
// 1. 오른쪽꺼 , 왼쪽꺼
// 2. 왼쪽의 왼쪽꺼

// 2번째 기어가 회전하는 경우
// 1. 오른쪽꺼, 왼쪽꺼
// 2. 오른쪽의 오른쪽꺼

// 1번째 기어가 회전하는 경우
// 1. 오른쪽 꺼
// 2. 오른쪽의 오른쪽꺼
// 3. 오른쪽의 오른쪽꺼

// 과정을 보니 이거는 재귀가 나을 듯 함

// 최초 회전 시키고
// rec(i: current gear, 현재 기어의 회전 방향) {
//    i가 유효한 인덱스가 아니면 종료 필요없을 듯

//    i왼쪽 기어 유효한 인덱스 and 
//    현재 기어랑 왼쪽 기어 확인하여 왼쪽 기어 회전 가능
//       왼쪽 기어를 회전한 뒤 rec(i - 1, 현재 기어의 회전방향의
//       반대방향 입력)
   
//    i오른쪽 기어 유효한 인덱스 and
//    현재 기어랑 오른쪽 기어 확인해서 오른쪽 기어가 회전가능
//       오른쪽 기어를 회전한 뒤 rec(i + 1, 현재 기어의 회전방향의
//       반대방향 입력)
// }

// 1번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 1점
// 2번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 2점
// 3번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 4점
// 4번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 8점