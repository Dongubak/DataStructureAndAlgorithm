#include <cstdio>
#include <vector>
#include <queue>

int x[4] = {0, 0, 1, -1};
int y[4] = {1, -1, 0, 0};

class triple {
public:
   int first;
   int second;
   int date;

   
   triple(int f, int s, int d) : first(f), second(s), date(d) {}
};

int main(void) {
   using namespace std;

   int M, N; ///M은 가로(컬럼) N은 세로(로우)
   int tmp;
   scanf("%d %d", &M, &N);

   vector< vector<int> > v(N, vector<int>(M));

   for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++) {
         scanf("%d", &tmp);
         v[i][j] = tmp;
      }
   }

   queue< triple > q;


   for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++) {
         if(v[i][j] == 1) {
            for(int k = 0; k < 4; k++) {
               if(i + ::y[k] >= 0 && i + ::y[k] < N &&
                  j + ::x[k] >= 0 && j + ::x[k] < M &&
                  v[ i + ::y[k] ][ j + ::x[k] ] == 0
               ) {
                  v[ i + ::y[k] ][ j + ::x[k] ] = 2;
                  q.push(triple(i + y[k], j + x[k], 1));
               }
            }
         }
      }
   }

   if(q.empty()) {
      bool isFinished = true;
      for(int i = 0; i < N; i++) {
         for(int j = 0; j < M; j++) {
            if(v[i][j] == 0) {
               isFinished = false;
            }
         }
      }

      if(isFinished) {
         printf("%d", 0);
      } else {
         printf("%d", -1);  
      }
   } else {
      int date = 1;

      while(!q.empty()) {
         triple p = q.front();
         q.pop();

      
         int i = p.first;
         int j = p.second;
         int d = p.date;

         if(q.empty()) {
            date = d;
         }

         for(int k = 0; k < 4; k++) {
            if(i + ::y[k] >= 0 && i + ::y[k] < N &&
               j + ::x[k] >= 0 && j + ::x[k] < M &&
               v[ i + ::y[k] ][ j + ::x[k] ] == 0
            ) {
               v[ i + ::y[k] ][ j + ::x[k] ] = 1;
               q.push(triple(i + y[k], j + x[k], d + 1));
            }
         }
      }



      bool isFinished = true;
      for(int i = 0; i < N; i++) {
         for(int j = 0; j < M; j++) {
            if(v[i][j] == 0) {
               isFinished = false;
               break;
            }
         }
      }

      if(isFinished) {
         printf("%d", date);
      } else {
         printf("-1");
      }
   }

   

   return 0;
}