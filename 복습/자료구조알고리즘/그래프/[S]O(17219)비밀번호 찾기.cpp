#include <iostream>
#include <map>

using namespace std;

int main(void) {
   cin.tie(NULL);
   ios::sync_with_stdio(false);
   
   int N, M;
   string k, v;

   cin >> N >> M;

   map<string, string> m;

   for(int i = 0; i < N; i++) {
      cin >> k >> v;

      m[k] = v;
   }

   for(int i = 0; i < M; i++) {
      cin >> k;

      cout << m[k] << '\n';
   }

   return 0;
}