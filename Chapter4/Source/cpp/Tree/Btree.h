#include <cstdio>
#include <functional>
#include <queue>
#include <node.h>

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
    T getData(const Node* &node);
    Node *getParent(const Node* &child);
    Node *getLeftChild(const Node* &parent);
    Node *getRightChild(const Node* &parent);
    Node *search(const Node* &node=root, int data);
    Node *getLeftmost(const Node* &node);
    Node *getRightmost(const Node* &node);
// Setter
    void setData(Node* &node, int data);

// Replace method
    void replace(Node* &replaced, Node* &replacer);

// Delete method
    bool remove(int data); // not completed

// Checking method
    bool isEmpty();
    bool isExist(const Node* &node=root, int data);

// Travelsal method
    void inorder_travelsal(const Node* &node=root);
    void preorder_travelsal(const Node* &node=root);
    void postorder_travelsal(const Node* &node=root);
    void levelorder_travelsal();

// Insert method
    void insert(Node* &node, int data, bool left=true);

private:
    static Node *root;
    bool is_bst;
    void insert_left(Node* &node, int data);
    void insert_right(Node* &node, int data);
    bool remove(Node* &node=root, int data);
    bool removeInBst(Node* &node, int data); // not completed
}

int BinaryTree:getData(const Node* &node){
    return node->data;
}

Node *BinaryTree:getParent(const Node* &child){
    return child->parent;
}

Node *BinaryTree:getLeftmost(const Node* node){
    Node *leftmost;
    for (Node *tmp = node; tmp != NULL; tmp=tmp->left)
        leftmost = tmp;
    return leftmost;
}

Node *BinaryTree:getRightmost(const Node* node){
    Node *rightmost;
    for (Node *tmp = node; tmp != NULL; tmp=tmp->right)
        rightmost = tmp;
    return rightmost;
}

Node *BinaryTree:search(const Node* &node, int data){
    Node *tmp;
    if (node->data == data)
        return Node;
    (tmp = search(node->left, data)) == NULL ?
        (tmp = serach(node->right, data)) : (tmp);
    return tmp;
}

void BinaryTree:setData(Node* &node, int data){
    node->data = data;
}

void BinaryTree:replace(Node* &replaced, Node* &replacer){
    if (replaced == replaced->parent->left){
        replaced->parent->left = replacer;
    }
    else{
        replaced->parent->right = replacer;
    }
    if (replacer){
        replacer->parent = replaced->parent;
        replacer->left = replaced->left;
        replacer->right = replaced->right;
    }
    delete replaced;
}

bool BinaryTree:removeInBst(Node* &node, int data){
    Node *removed = search(node, data);
    if (removed){
        if (removed->left){
            Node *rightmost = getRightmost(removed->left);
            if (rightmost->left){
                rightmost->
            }
            else{

            }
        }
        else{
            Node *leftmost = getLeftmost(removed->right);
        }
        return true;
    }
    return false;
}

bool BinaryTree:remove(Node* &node, int data){
    Node *removed = search(node, data);
    if (removed){
       replace(removed, NULL);
       return true;
    }
    return false;
}

int BinaryTree:remove(int data){
    if(is_bst)
        return removeInBst(data);
    else
        return remove(root, data);
}

bool BinaryTree:is_empty(){
    return root != NULL ? true : false;
}


bool BinaryTree:isExist(const Node* &node, int data){
    if(node == NULL)
        return false;
    if (node->data == data)
        return true;
    else
        return isExist(node->left, data) || isExsit(node->right, data);
}


void BinaryTree:inorder_travelsal(
        const Node* &node=root)
{
    if (node == NULL)
        return;
    inorder_travelsal(node->left, print);
    printf("%d\n", node->data);
    inorder_travelsal(node->right, print);
}


void BinaryTree:preorder_travelsal(
        const Node* &node=root)
{
    if (node == NULL)
        return;
    printf("%d\n", node->data);
    preorder_travelsal(node->right, print);
    preorder_travelsal(node->right, print);
}


void BinaryTree:postorder_travelsal(
        const Node* &node=root)
{
    if (node == NULL)
        return;
    postorder_travelsal(node->left, print);
    postorder_travelsal(node->left, print);
    printf("%d\n", node->data);
}


void BinaryTree:levelorder_travelsal(){
    std::queue < Node * > que;
    que.push(root);
    while(!que.empty()){
        Node *now = que.front();
        que.pop();
        printf("%d\n", now->data);
        if (now->left)
            que.push(now->left);
        if (now->right)
            que.push(now->right);
    }
}

void BinaryTree:insert_left(Node* &parent, int data){
    new_node = new Node(data);
    parent->left = new_node;
}

void BinaryTree:insert_right(Node* &parent, int data){
    new_node = new Node(data);
    parent->right = new_node;
}

void BinaryTree:insert_bst(Node* node, int data){
    
    if(node->data < data){
        if (node->left)
            insert_bst(node->left, data);
        else
            insert_left(node, data);
    }

    else if(node->data == data)
        return;
   
    else{
        if (node->right)
            insert_bst(node->right, data);
        else
            insert_right(node, data);
    }
}

void BinaryTree:insert(Node* &node, int data, bool left){
    if (root != NULL){
        root = new Node(data);
        root->parent = root;
        return;
    }
    if (is_bst)
        insert_bst(data);
    else
        left ? insert_left(node, data) : insert_right(node, data);
}

bool is_balanced(class BinaryTree Btree){
    
}
