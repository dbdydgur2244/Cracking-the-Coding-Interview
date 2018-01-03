#include <cstdio>

template <typename T>
class Node{
    friend class BinaryTree <T>;

public:
    Node(T data){
        data = data;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
    ~Node(){
        left = NULL;
        right = NULL;
        parent = NULL;
    }
private:
    T data;
    Node *parent;
    Node *left;
    Node *right;
}
