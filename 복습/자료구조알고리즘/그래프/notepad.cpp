#include <iostream>

using namespace std;

int main(void) {
   int h, m, s;
   int is;
   cin >> h >> m >> s >> is;

   int ih, im, iis;
   iis = is % 60; is = is / 60;
   im = is % 60; is = is / 60;
   ih = is % 24;

   cout << ih << " " << im << " " << iis;

   return 0;
}