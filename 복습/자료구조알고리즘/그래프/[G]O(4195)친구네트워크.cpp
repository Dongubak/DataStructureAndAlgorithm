#include <cstdio>
#include <unordered_map>
#include <string>

#define WBUF_SIZE (1 << 20)

using std::string;

char rbuf[WBUF_SIZE];
int ridx, nidx;

inline char read() {
   if (ridx == nidx) {
      nidx = fread(rbuf, 1, WBUF_SIZE, stdin);
      if (!nidx) {
         return 0;
      }
      ridx = 0;
   }
   return rbuf[ridx++];
}

inline int readInt() {
   int sum = 0;
   char now = read();
   bool flg = false;

   while (now <= ' ') {
      now = read();
   }
   if (now == '-') {
      flg = true, now = read();
   }

   while (now >= '0' && now <= '9') {
      sum = sum * 10 + now - '0';
      now = read();
   }

   return flg ? -sum : sum;
}

inline string readString() {
   string res;
   char now = read();

   while (now <= ' ') {
      now = read(); // Skip leading whitespace
   }
   while (now > ' ') { // Continue until whitespace or control character is encountered
      res += now;
      now = read();
   }

   return res;
}

class DisjointSet {
public:
   std::unordered_map<std::string, std::string> founder;
   std::unordered_map<std::string, int> count;

   DisjointSet() {
      founder = std::unordered_map<std::string, std::string>();
   }

   std::string find(const std::string &s1) {
      if (s1 == founder[s1]) {
         return s1;
      }

      return founder[s1] = find(founder[s1]);
   }

   void merge(const std::string &s1, const std::string &s2) {
      std::string f1 = find(s1);
      std::string f2 = find(s2);

      if (f1 != f2) {
         count[f2] += count[f1];
         founder[f1] = f2;
      }

      printf("%d\n", count[find(s1)]);
   }

   void addM(const std::string &s1, const std::string &s2) {
      if (founder.find(s1) == founder.end()) {
         founder[s1] = s1;
         count[s1] = 1;
      }

      if (founder.find(s2) == founder.end()) {
         founder[s2] = s2;
         count[s2] = 1;
      }

      merge(s1, s2);
   }
};

int main(void) {
   int t, n;
   t = readInt();

   for (int i = 0; i < t; i++) {
      DisjointSet djs;
      n = readInt();

      for (int j = 0; j < n; j++) {
         std::string s1 = readString();
         std::string s2 = readString();
         djs.addM(s1, s2);
      }
   }

   return 0;
}
