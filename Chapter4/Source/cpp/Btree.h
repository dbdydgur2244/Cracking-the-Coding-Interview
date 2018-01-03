#include <cstdio>
#include <functional>
#include <queue>
#include <node.h>

template <typename T>
class BinaryTree{
public:
    BinaryTree(bool is_bst){
        is_bst = is_bst;
        root = NULL;
    }
    ~BinaryTree(){
        root = NULL;
    }

// Getter
    T getData(Node<T> node);
    Node<T> getParent(Node<T> child);
    Node<T> getLeftChild(Node<t> parent);
    Node<T> getRightChild(Node<T> parent);
    Node<T> search(T data);

// Setter
    T setData(Node<T> &node, T data);

// Replace method
    T replace(Node<T> &replaced, Node<T> &replacer);

// Delete method
    T remove(T data);
    T remove(Node<T> node);
    T removeInBst();

// Checking method
    bool isEmpty();
    bool isExist(T data, 
            std::function < bool (const T &, const T &) > &comp);

// Travelsal method
    void inorder_travelsal(std::function < void (const T ) > &print);
    void preorder_travelsal(std::function < void (const T ) > &print);
    void postorder_travelsal(std::function < void (const T ) > &print);
    void levelorder_travelsal(std::function < void (const T ) > &print);

// Insert method
    void insert(Node<T> &node, bool left=true);

private:
    static Node<T> *root;
    bool is_bst;
    void insert_left(Node<T>* &node, T data);
    void insert_right(Node<T>* &node, T data);
}

template <typename T>
T BinaryTree<T>:get_data(Node<T> node){

}

template <typename T>
Node<T> BinaryTree<T>:get_parent(Node<T> child){

}

template <typename T>
Node<T> BinaryTree<T>:search(T data){

}

template <typename T>
T BinaryTree<T>:set_data(Node<T> &node, T data){

}

template <typename T>
T BinaryTree<T>:replace(Node<T> &replaced, Node<T> &replacer){

}

template <typename T>
T BinaryTree<T>:remove(T data){

}

template <typename T>
T BinaryTree<T>:remove(Node<T> node){

}

template <typename T>
T BinaryTree<T>:removeInBst(Node<T> node){

}


template <typename T>
bool BinaryTree<T>:is_empty(){
    return root != NULL ? true : false;
}

template <typename T>
bool BinaryTree<T>:is_exist(T data,
        std::function < bool (const T &, const T &) > &comp){
    
}

template <typename T>
void BinaryTree<T>:inorder_travelsal(){

}

template <typename T>
void BinaryTree<T>:preorder_travelsal(){

}

template <typename T>
void BinaryTree<T>:postorder_travelsal(){

}

template <typename T>
void BinaryTree<T>:levelorder_travelsal(
        std::function < void (const T ) > &print){
    std::queue < Node<T> > que;
    que.push(root);
    while(!que.empty()){
        Node<T> now = que.front();
        que.pop();
        print(now.data);
        if (now.left)
            que.push(now.left);
        if (now.right)
            que.push(now.right);
    }
}


template <typename T>
void BinaryTree<T>:insert_left(Node<T>* &parent, T data){
    new_node = new Node<T>(T);
    parent->left = new_node;
}

template <typename T>
void BinaryTree<T>:insert_right(Node<T>* &parent, T data){
    new_node = new Node<T>(T);
    parent->right = new_node;
}

template <typename T>
void BinaryTree<T>:insert_bst(Node<T> node=root, T data){
    
}

template <typename T>
void BinaryTree<T>:insert(Node<T> &node, bool left){
    if (is_bst)
        insert_bst(T data);
    else{
    
    }
}

template <typename T>
bool is_balanced(class BinaryTree<T> Btree){

}
