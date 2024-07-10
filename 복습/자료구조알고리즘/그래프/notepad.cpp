#include <iostream>
#include <vector>
/// -------
#define WBUF_SIZE (1 << 20)

char rbuf[WBUF_SIZE];
int ridx, nidx;

inline char read() {
	if (ridx == nidx) {
		nidx = fread(rbuf, 1, 1 << 20, stdin);
		if (!nidx) return 0;
		ridx = 0;
	}
	return rbuf[ridx++];
}
inline int readInt() {
	int sum = 0;
	char now = read();
	bool flg = false;

	while (now <= 32) now = read();
	if (now == '-') flg = true, now = read();
	while (now >= 48) sum = sum * 10 + now - '0', now = read();

	return flg ? -sum : sum;
}





// void fastscan(int &number) 
// { 
//     //variable to indicate sign of input number 
//     bool negative = false; 
//     register int c; 
  
//     number = 0; 
  
//     // extract current character from buffer 
//     c = getchar(); 
//     if (c=='-') 
//     { 
//         // number is negative 
//         negative = true; 
  
//         // extract the next character from the buffer 
//         c = getchar(); 
//     } 
  
//     // Keep on extracting characters if they are integers 
//     // i.e ASCII Value lies from '0'(48) to '9' (57) 
//     for (; (c>47 && c<58); c=getchar()) 
//         number = number *10 + c - 48; 
  
//     // if scanned input has a negative sign, negate the 
//     // value of the input number 
//     if (negative) 
//         number *= -1; 
// } 
/// -------

using namespace std;

class DisjointSet {
public:
   int founder[1000000 + 1] {1};

   DisjointSet(int n) {
      for(int i = 0; i < n; i++) {
         founder[i] = i;
      }
   }

   int find(int ch) {
      if(founder[ch] == ch) {
         return ch;
      }

      return founder[ch] = find(founder[ch]);
   }

   void merge(int ch1, int ch2) {
      ch1 = find(ch1);
      ch2 = find(ch2);

      if(ch1 != ch2) {
         founder[ch1] = ch2;
      }
   }

   void isSameFounder(int ch1, int ch2) {
      if(find(ch1) == find(ch2)) {
         cout << "YES" << '\n';
      } else {
         cout << "NO" << '\n';
      }
   }
};

int main(void) {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);
   
   int n, qn;
   n = readInt();
   qn = readInt();
   // fastscan(n);
   // fastscan(qn);

   DisjointSet djs(n + 1);

   int q, u, v;
   ///q: 질문
   for(int i = 0; i < qn; i++) {
      q = readInt();
      u = readInt();
      v = readInt();
      // fastscan(q);
      // fastscan(u);
      // fastscan(v);

      if(q == 1) {
         djs.isSameFounder(u, v);
      } else {
         djs.merge(u, v);
      }
   } 

   return 0;
}