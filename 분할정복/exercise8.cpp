#include <iostream>
#include <vector>
#include <algorithm>


class Student {
public:
    std::pair<int, int> name;
    bool vaccinated;
    
public:
    Student(int firstName, int lastName, bool isVaccinated) :
    name(firstName, lastName), vaccinated(isVaccinated) {}
    
    Student() {
        name = std::pair<int, int>();
        vaccinated = true;
    }
};
std::vector<Student>::iterator binarySearchRecursively(std::pair<int, int>& find, int st, int end,  std::vector<Student>& s) {
    if(st > end) {
        return s.end();
    } else {
        int mid = (st + end) / 2;
        Student midStudent = s[mid];
        
        if(find.first != midStudent.name.first) { ///이름이 서로 다름
            if(find.first < midStudent.name.first) { ///이름 크기 비교후 재귀 호출
                return binarySearchRecursively(find, st, mid - 1, s);
            } else {
                return binarySearchRecursively(find, mid + 1, end, s);
            }
            
        } else{//(find.first == midStudent.name.first) ///이름이 같음
            if(find.second != midStudent.name.second) { ///이름이 같고 성이 다름
                if(find.second < midStudent.name.second) {//성크기 비교후 재귀호출
                    return binarySearchRecursively(find, st, mid - 1, s);
                } else {
                    return binarySearchRecursively(find, mid + 1, end, s);
                }
            } else { ///이름이 같고 성이 같음 ?
                return s.begin() + mid;
            }
        }
    }
}

std::vector<Student>::iterator binarySearch(std::pair<int, int>& find,  std::vector<Student>& s) {
    return binarySearchRecursively(find, 0, int(s.size() - 1), s);
}

bool shouldBeVacinate(int firstName, int secondName, std::vector<Student>& s) {
    std::pair<int, int> input(firstName, secondName);
    std::vector<Student>::iterator iter = binarySearch(input, s);
    std::cout << "조사하는 거 " << (*iter).name.first << " " << (*iter).name.second << " " << (*iter).vaccinated << '\n';
    if(iter == s.end()) {
        return true;
    } else {
        if((*iter).vaccinated == false) {
            return true;
        } else {
            return false;
        }
    }
}




int main(void) {
    using namespace std;
    
    vector<Student> v(100, Student());
    
    generate(v.begin(), v.end(), []() {
        return Student(rand() % 100, rand() % 100, rand() % 2);
    });
    
    for(auto i : v) {
        cout << i.name.first << " " << i.name.second << " " << i.vaccinated << '\n';
    }
    
    sort(v.begin(), v.end(), [](const Student& a, const Student& b) {
        if(a.name.first < b.name.first) {
            return true;
        } else if(a.name.first > b.name.first) {
            return false;
        } else {
            if(a.name.second < b.name.second) {
                return true;
            } else {
                return false;
            }
        }
    });
    
    
    for(auto i : v) {
        cout << i.name.first << " " << i.name.second << " " << i.vaccinated << '\n';
    }
    
    if(shouldBeVacinate(7, 50, v)) {
        cout << "추가해야함" << '\n';
    } else {
        cout << "추가하면 안됨" << '\n';
    }
    
}
