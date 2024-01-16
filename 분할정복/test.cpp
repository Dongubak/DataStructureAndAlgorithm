#include <cstdio>

struct node {
    int data;
    node* left;
    node* right;
}

struct Tree_ {
    node* root;
    
    static Tree_ createTree_(int initialData) {
        Tree_ tr;
        tr.root = new node{initialData, NULL, NULL};
        return tr;
    }
};

int main(void) {
    using namespace std;
    Tree_ tr = tr.createTree_(1);
    
    
    
}
