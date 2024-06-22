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

// 6월 16일
// 문제를 다시 읽어봤는데 첫번째 예시를 보면 알 수 있듯이
// 한번 회전시킨 톱니바퀴 주변이 회전한 이후에 다시 회전 조건이 된다고 해도
// 회전시키지 않는 것을 확인 했음
// 회전시킬때 극을 확인하는 것 같은데

// 첫번째 예시 분석해보면
// 3번 톱니 회전시킬때 서로 다른 극이니 오른쪽을 회전시킨다는것이 확정되고
// 왼쪽 톱니는 회전시키지 않는 다는 것이 확정된 이후 회전 시킴

// 그리고 첫번째 톱니를 회전시키기 전에
// 두번째 회전한다는 거 세번째 회전한다는거 확정시키고 회전시킴

// 즉 순서가
// 초기 상태에서 회전하는 톱니 기준으로 어디까지 회전하냐를 먼저 확정한다음
// 회전을 진행하는 것이 맞다고 생각함

// 하 걍 비트 쓰지 말자 더 헷갈리는 듯
// 그냥 벡터 쓰는게 나을 듯;
// 6월 17일
// 갈아엎자
// 그냥 머리가 딸림 ;; 풀긴했다
#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::vector;
using std::cout;
using std::string;

int gears[4][8];
int center[4];

int rotateRight(int k) {
   if(k == 7) {
      return 0;
   } else {
      return k + 1;
   }
}

int rotateLeft(int k) {
   if(k == 0) {
      return 7;
   } else {
      return k - 1;
   }
}

void rec(int gear, int dir, vector<int>& vis, vector<std::pair<int, int>>& rotatableGears) {
   int cleft = center[gear], cright = center[gear];
   for(int i = 0; i < 2; i++) {
      cleft = rotateLeft(cleft);
   }

   for(int i = 0; i < 2; i++) {
      cright = rotateRight(cright);
   }

   if(gear > 0) {
      int lright = center[gear - 1];

      for(int i = 0; i < 2; i++) {
         lright = rotateRight(lright);
      }
      // cout << "left index : " << lright << " , right index : " << cleft << '\n';
      // cout << "left gear comparison : " << gears[gear - 1][lright] << " " <<  gears[gear][cleft] << '\n';
      if(gears[gear - 1][lright] != gears[gear][cleft] && !vis[gear - 1]) {
         vis[gear - 1] = 1;
         rotatableGears.push_back({gear - 1, dir == 1 ? -1 : 1});
         rec(gear - 1, dir == 1 ? -1 : 1, vis, rotatableGears);
      }
   }

   if(gear < 3) {
      int rleft = center[gear + 1];
      for(int i = 0; i < 2; i++) {
         rleft = rotateLeft(rleft);
      }
      // cout << rleft << " " << cright << '\n';
      //  cout << "right gear comparison : " << gears[gear + 1][rleft] << " " << gears[gear][cright] << '\n';
      if(gears[gear + 1][rleft] != gears[gear][cright] && !vis[gear + 1]) {
         vis[gear + 1] = 1;
         rotatableGears.push_back({gear + 1, dir == 1 ? -1 : 1});
         rec(gear + 1, dir == 1 ? -1 : 1, vis, rotatableGears);
      }
   }
}

void rotate(int gear, int dir) { /// gear는 0 index
   vector<int> vis(4);
   vector<std::pair<int, int>> rotatableGears;

   vis[gear] = 1;
   rotatableGears.push_back({gear, dir});

   rec(gear, dir, vis, rotatableGears);
   // cout << "rotatable : " << '\n';
   for(auto i : rotatableGears) {
      // cout << i.first << " " << i.second << '\n';
      if(i.second == 1) {
         center[i.first] = rotateLeft(center[i.first]);
      } else {
         center[i.first] = rotateRight(center[i.first]);
      }
   }

   // cout << "\ncenter : ";
   // for(int i = 0; i < 4; i++) {
   //    cout << center[i] << " ";
   // }

   // cout << '\n';
}

int main(void) {
   char in;
   
   for(int i = 0; i < 4; i++) {
      for(int j = 0; j < 8; j++) {
         in = cin.get();
         gears[i][j] = in - '0';
      }
      cin.get();
   }

   int n, g, d;
   cin >> n;

   for(int i = 0; i < n; i++) {
      cin >> g >> d;
      rotate(g - 1, d);
   }

   int score = 0;

   for(int i = 0; i < 4; i++) {
      // cout << center[i] << " ";
      if(gears[i][center[i]] == 1) {
         score += (1 << i);
      }
      // cout << '\n';
   }

   cout << score << '\n';

   // for(int i = 0; i < 4; i++) {
   //    for(int j = 0; j < 8; j++) {
   //       cout << ce;
   //    }
   //    cout << '\n';
   // }

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



