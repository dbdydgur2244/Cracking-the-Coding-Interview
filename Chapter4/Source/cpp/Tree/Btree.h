#include <cstdio>
#include <functional>
#include <queue>


class Node{
public:
    Node(int data){
        data = data;
        left = NULL;
        right = NULL;
    }
    ~Node(){
        left = NULL;
        right = NULL;
    }
private:
    int data;
    Node *left;
    Node *right;

    friend BinaryTree;
};

class BinaryTree{
public:
    BinaryTree(){
        root = NULL;
    }
    ~BinaryTree(){
        root = NULL;
    }

// Getter
    int getData(const Node* &node);
    Node *search(const int &data);
    const Node *getLeftmost(const Node* &node);
    const Node *getRightmost(const Node* &node);
// Setter
    void setData(Node* &node, const int &data);

// Replace method
    void replace(Node* &replaced, Node* &replacer);

// Delete method
    bool remove(const int &data); // not implemented..
    
// Checking method
    bool isEmpty(void);
    bool isExist(const int &data);

// Travelsal method
    void inorder_travelsal(void);
    void preorder_travelsal(void);
    void postorder_travelsal(void);
    void levelorder_travelsal(void);

// Insert method
    void insert(const Node* &node, const int &data, const bool &left=true);

private:
    Node *root;

    bool isExist(const Node* &node, const int &data);
    Node *search(Node* &node, const int &data);
   
    bool isLeftChild(const Node* &node);
    void insert_left(const Node* &node, const int &data);
    void insert_right(const Node* &node, const int &data);

    void inorder_travelsal(const Node* &node);
    void preorder_travelsal(const Node* &node);
    void postorder_travelsal(const Node* &node);
 

    bool remove(Node* &node, const int &data); // not implemented
};

int BinaryTree::getData(const Node* &node){
    return node->data;
}

const Node *BinaryTree::getLeftmost(const Node* &node){
    auto leftmost = node;
    for (auto tmp = node; tmp != NULL; tmp=tmp->left)
        leftmost = tmp;
    return leftmost;
}

const Node *BinaryTree::getRightmost(const Node* &node){
    auto rightmost = node;
    for (auto tmp = node; tmp != NULL; tmp=tmp->right)
        rightmost = tmp;
    return rightmost;
}

Node *BinaryTree::search(Node* &node, const int &data){
    Node* tmp;
    if (node == NULL)
        return node;
    if (node->data == data)
        return node;
    (tmp = search(node->left, data)) == NULL ?
        (tmp = search(node->right, data)) : (tmp);
    return tmp;
}

Node *BinaryTree::search(const int &data){
   return search(root, data);
}

void BinaryTree::setData(Node* &node, const int &data){
    node->data = data;
}

void BinaryTree::replace(Node* &replaced, Node* &replacer){
    if (replaced == root){
        root = replacer;
    }

    replacer->left = replaced->left;
    replacer->right = replaced->right;

    delete replaced;
}
/*
bool BinaryTree::remove(Node* &node, const int &data){
    Node *removed = search(root, data);
    if (removed){
        delete removed;
        return true;
    }
    return false;
}

bool BinaryTree::remove(const int &data){
    return remove(root, data);
}

bool BinaryTree::remove(Node* &node){
    
}
*/

bool BinaryTree::isEmpty(){
    return root != NULL ? true : false;
}


bool isExist(const Node* &node, const int &data){
    if(node == NULL)
        return false;
    if (node->data == data)
        return true;
    else
        return isExist(node->left, data) || isExsit(node->right, data);

}

bool BinaryTree::isExist(const int &data){
    return isExist(root, data);
}


void BinaryTree::inorder_travel(const Node* &node){
    if (node == NULL)
        return;
    inorder_travel(node->left);
    printf("%d\n", node->data);
    inorder_travel(node->right);
}

void BinaryTree::inorder_travelsal(void){
    Inorder_travel(root);
}

void BinaryTree::preorder_travel(const Node* &node){
    if (node == NULL)
        return;
    printf("%d\n", node->data);
    preorder_travel(node->left);
    preorder_travel(node->right);
}

void BinaryTree::preorder_travelal(void){
    preorder_travel(root);
}

void BinaryTree::postorder_travel(const Node* &node){
    if (node == NULL)
        return;
    postorder_travel(node->left);
    postorder_travel(node->right);
    printf("%d\n", node->data);
}

void BinaryTree::postorder_travelsal(void){
    postorder_travel(root);
}


void BinaryTree::levelorder_travelsal(void){
    std::queue < Node * > q;
    q.push(root);
    while(!que.empty()){
        Node *now = q.front();
        q.pop();
        printf("%d\n", now->data);
        if (now->left != NULL)
            q.push(now->left);
        if (now->right != NULL)
            q.push(now->right);
    }
}

void BinaryTree::insert_left(const Node* &parent, const int &data){
    new_node = new Node(data);
    parent->left = new_node;
}

void BinaryTree::insert_right(const Node* &parent, const int &data){
    new_node = new Node(data);
    parent->right = new_node;
}

void BinaryTree::insert(const Node* &node, const int &data, bool left){
    if (root != NULL){
        root = new Node(data);
        return;
    }
    else
        left ? insert_left(node, data) : insert_right(node, data);
}

bool is_balanced(class BinaryTree Btree){
    
}
