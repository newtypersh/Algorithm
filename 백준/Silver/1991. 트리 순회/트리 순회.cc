#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
    Node(char data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    void insertLeft(Node* chi) {
        this->left = chi;
    }
    void insertRight(Node* chi) {
        this->right = chi;
    }
};

class Tree {
    Node* root;
    vector<Node*> node_list;
public:
    Tree() {
        root = new Node('A');
        node_list.push_back(root);
    }
    void insertChild(char par, char left, char right) {
        Node* parNode = findNode(par);
        if (left != '.') {
            Node* leftNode = new Node(left);
            parNode->insertLeft(leftNode);
            node_list.push_back(leftNode);
        }
        if (right != '.') {
            Node* rightNode = new Node(right);
            parNode->insertRight(rightNode);
            node_list.push_back(rightNode);
        }
    }
    Node* findNode(char data) {
        for (int i = 0; i < node_list.size(); i++) {
            if (node_list[i]->data == data) {
                Node* newNode = node_list[i];
                return newNode;
            }
        }
    }
    Node* getRoot() {
        return root;
    }
    void preorder(Node* node) {
        if (node != NULL) {
            cout << node->data;
            preorder(node->left);
            preorder(node->right);
        }
    }
    void inorder(Node* node) {
        if (node != NULL) {
            inorder(node->left);
            cout << node->data;
            inorder(node->right);
        }
    }
    void postorder(Node* node) {
        if (node != NULL) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data;
        }
    }
};

int main()
{
    Tree tree;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        char a, b, c;
        cin >> a >> b >> c;
        tree.insertChild(a, b, c);
    }
    tree.preorder(tree.getRoot());
    cout << '\n';
    tree.inorder(tree.getRoot());
    cout << '\n';
    tree.postorder(tree.getRoot());


    return 0;
}
