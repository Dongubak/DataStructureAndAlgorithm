#include <iostream>
#include <vector>

void swap(int &a, int& b) {			
    int tmp = a;
    a = b;	
    b = tmp;
}
	
int partition(std::vector<int>& v, int p, int r) { ///피벗의 인덱스는 주어진 r과 같다.
    int i = p - 1;
    int q = v[r]; ///pivot
    int j = p;
    while(j != r) {
        if(v[j] < q) {
            swap(v[++i], v[j]);
        }
        j++;
    }
//    std::cout << "pivot : " << q << '\n';
//    for(auto& a: v) {
//        std::cout << a << " ";
//    }
//    std::cout << '\n';
    swap(v[i + 1], v[r]);
    
    
    return i + 1;
}

int partition(std::vector<int>& v, int p, int q, int r) { ///기존의 퀵솔트와는 다르게 인자로 피벗의 인덱스를 받는다.
   int i = p - 1;
   int pi = v[q];
   int j = p;
   while(j != r) {
      if(v[j] < pi && j != q) {
         swap(v[++i], v[j]);
      }
      j++;
   }
    swap(v[i + 1], v[q]);
    
    return i + 1;
    
}

void quickSortRecursive(std::vector<int>& v, int p, int r) {///주어진 벡터를 재귀호출하여 퀵솔트하는 함수이다.
    if(p < r) {
        int q = partition(v, p, r); ///index of pivot
        quickSortRecursive(v, p, q - 1);
        quickSortRecursive(v, q + 1, r);
    }
}

void quickSort(std::vector<int>& v) {///주어진 벡터를 퀵솔트한다.
    quickSortRecursive(v, 0, int(v.size()) - 1);
}

void quickSort(std::vector<int>& v, int st, int end) { ///주어진 벡터를 시작과 끝값을 받아 부분 퀵정렬하는 함수이다.
   quickSortRecursive(v, st, end);
}

int findMedianValue(std::vector<int>& v, int p, int r) { ///주어진 벡터에서 중앙값을 찾는 함수이다.
   quickSortRecursive(v, p, r);

   return v[(p + r) / 2];
}



    /*
       v : 주어진 벡터
       p : 시작 인덱스
       r : 끝 인덱스
       i : i번째로 큰 값을 구하려고자 함

       과정 1: 주어진 인덱스를 이용하여 5개씩 분할하여 중앙값을 찾아 M에 넣음
       과정 2: M에서 중앙값을 찾아 주어진 벡터에서의 인덱스를 구한 뒤, 그 값을 피벗으로 파티션함
       과정 3: 피벗값과 i값이 일치하면 찾은거니 피벗의 인덱스를 반환
              i값이 피벗값보다 작은 경우 피벗의 전인덱스 값을 전달하여 함수를 재귀호출함
              i값이 피벗값보다 큰 경우 피벗의 후인덱스 값을 전달하여 함수를 재귀호출함
    */
int linTimeSelection(std::vector<int>& v, int p, int r, int i) {
    int size = r - p + 1;
    
    // 크기가 작을 때는 정렬해서 i번째 값을 찾음
    if (size <= 5) {
        quickSort(v, p, r);
        return p + i;
    }

    std::vector<int> medians;
    for (int j = p; j <= r; j += 5) {
        int subR = j + 4;
        if (subR > r) {
            subR = r;
        }

        int medianIdx = linTimeSelection(v, j, subR, (subR + 1 - j) / 2);
        medians.push_back(v[medianIdx]);
    }

    int medianOfMediansIdx = linTimeSelection(medians, 0, medians.size() - 1, medians.size() / 2) * 5 + p;
    
    
    int q = partition(v, p, medianOfMediansIdx, r);

    if (i == q - p) {
        return q;
    } else if (i < q - p) {
        return linTimeSelection(v, p, q - 1, i);
    } else {
        return linTimeSelection(v, q + 1, r, i - (q - p + 1));
    }
}


int main(void) {
   using namespace std;

   vector<int> s1 = {10, 8, 3, 4, 2, 9, 11, 14, 18};
   
    int result3 = linTimeSelection(s1, 0, int(s1.size()) - 1, 3);
    int result2 = linTimeSelection(s1, 0, int(s1.size()) - 1, 2);
    int result5 = linTimeSelection(s1, 0, int(s1.size()) - 1, 5);
    int result6 = linTimeSelection(s1, 0, int(s1.size()) - 1, 6);
    int result10 = linTimeSelection(s1, 0, int(s1.size()) - 1, 10);
    cout << "before sorting\n";
    for(auto s : s1) {
        cout << s << " ";
    }
    cout << '\n';
    
    cout << "3 Result: " << s1[result3] << endl;
    cout << "2 Result: " << s1[result2] << endl;
    cout << "5 Result: " << s1[result5] << endl;
    cout << "6 Result: " << s1[result6] << endl;
    cout << "10 Result: " << s1[result10] << endl;
    
    cout << "sorted vector" << '\n';
    quickSort(s1);
    for(auto s : s1) {
        cout << s << " ";
    }
    
    cout << '\n';

   return 0;
}
