#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

class info {
public:
   int weight;
   int height;

   info(int W = 0, int H = 0) : weight(W), height(H) {}

   bool operator>(const info& other) const {
      if(weight > other.weight &&
         height > other.height
      ) {
         return true;
      } else {
         return false;
      }
   }
};

int main(void) {
   int n;
   cin >> n;

   vector<info> m(n);

   for(int i = 0; i < n; i++) {
      cin >> m[i].weight >> m[i].height;
   }

   for(int i = 0; i < n; i++) {
      int c = 0;
      info key = m[i];
      for(int j = 0; j < n; j++) {
         if(m[j] > key) {
            c++;
         }
      }

      cout << c + 1 << " ";
   }

   return 0;
}