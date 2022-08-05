#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

class DFS {

    static stack<Node*> stk;

    public:

    static void preorder_traversal(Node *node) {
        if(node) {
            cout << node->data << " ";
            preorder_traversal(node->left);
            preorder_traversal(node->right);
        }
    }

    static void inorder_traversal(Node *node) {
        if(node) {
            inorder_traversal(node->left);
            cout << node->data << " ";
            inorder_traversal(node->right);
        }
    }

    static void postorder_traversal(Node *node) {
        if(node) {
            postorder_traversal(node->left);
            postorder_traversal(node->right);
            cout << node->data << " ";
        }
    }

    static void preorder_without_recursion_traversal(Node *root) {
        Node *curr_node = root;
        while(curr_node || (!stk.empty())) {
            if (curr_node) {
                stk.push(curr_node);
                cout << curr_node->data << " ";
                curr_node = curr_node->left;
            } else {
                curr_node = stk.top();
                stk.pop();
                curr_node = curr_node->right;
            }
        }
    }

    static void inorder_without_recursion_traversal(Node *root) {
        Node *curr_node = root;
        while(curr_node || (!stk.empty())) {
            if (curr_node) {
                stk.push(curr_node);
                curr_node = curr_node->left;
            } else {
                curr_node = stk.top();
                stk.pop();
                cout << curr_node->data << " ";
                curr_node = curr_node->right;
            }
        }
    }

    static void postorder_without_recursion_traversal_2_stack(Node *root) {
        stack<Node*> stk1, stk2;
        stk1.push(root);
        Node * curr_node;
        while(!stk1.empty()) {
            curr_node = stk1.top();
            stk2.push(curr_node);
            stk1.pop();
            if(curr_node->left) {
                stk1.push(curr_node->left);
            }
            if(curr_node->right) {
                stk1.push(curr_node->right);
            }
        }

        while(!stk2.empty()) {
            cout << stk2.top()->data << " ";
            stk2.pop();
        }
    }

    static void postorder_without_recursion_traversal(Node *root) {
        Node * curr_node;
        curr_node = root;
        while(curr_node || (!stk.empty())) {
            if(curr_node) {
                if(curr_node->right) {
                    stk.push(curr_node->right);
                }
                stk.push(curr_node);
                curr_node = curr_node->left;
            } else {
                curr_node = stk.top();
                stk.pop();
                if ((stk.size()) && (curr_node->right == stk.top())) {
                    // cout << "testing ";
                    Node *temp = curr_node;
                    curr_node = curr_node->right;
                    stk.pop();
                    stk.push(temp);
                } else {
                    cout << curr_node->data << " ";
                    curr_node = NULL;
                }
            }
            // cout << stk++ << endl;
        }
    }

    static void postorder_without_recursion_traversal_v2(Node *root) {
        Node * curr_node;
        curr_node = root;
        while(curr_node || (!stk.empty())) {
            if(curr_node) {
                stk.push(curr_node);
                stk.push(curr_node);
                curr_node = curr_node->left;
            } else {
                curr_node = stk.top();
                stk.pop();
                if ((stk.size()) && (curr_node == stk.top())) {
                    curr_node = curr_node->right;
                } else {
                    cout << curr_node->data << " ";
                    curr_node = NULL;
                }
            }
        }
    }
};

stack<Node*> DFS::stk;

int main() {
    cout << "Welcome!!!\n";
    Node root = Node(10);
    root.left = new Node(15);
    root.right = new Node(17);
    root.right->right = new Node(21);
    root.right->right->left = new Node(2);
    root.right->left = new Node(5);
    root.left->right = new Node(1);
    root.left->left = new Node(8);
    DFS::preorder_traversal(&root);
    cout << endl;
    DFS::inorder_traversal(&root);
    cout << endl;
    DFS::postorder_traversal(&root);
    cout << endl;
    DFS::preorder_without_recursion_traversal(&root);
    cout << endl;
    DFS::inorder_without_recursion_traversal(&root);
    cout << endl;
    DFS::postorder_without_recursion_traversal(&root);
    cout << endl;
    DFS::postorder_without_recursion_traversal_v2(&root);
    return 0;
}
