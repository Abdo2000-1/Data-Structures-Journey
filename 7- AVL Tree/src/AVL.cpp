// Abdo Al Adawy 
#include <iostream>
#include <vector>
#include <cassert> 
#include <queue> 


using namespace std;

    struct Node {

        int data{ };

        Node* left;

        Node* right;

        int height;




        Node(int value) : data(value), right(nullptr), left(nullptr), height(1) {};
    };// AVL Implementation
class AVL {
private:

    Node* root;

    int get_Height(Node* node) {

        if (!node) return 0;
        return node->height;
    }

    int get_Balance(Node* node) 
    {
        if (!node) return 0;
        return get_Height(node->left) - get_Height(node->right);

    }
    void update_Height(Node* node) {

        if (!node) return;

        node->height = max(get_Height(node->left), get_Height(node->right)) + 1;
    }



    Node* right_Rotate(Node* node) 
    {
        Node* newRoot = node->left;
        Node* temp = newRoot->right;

        newRoot->right = node;
        node->left = temp;

        update_Height(newRoot);
        update_Height(node);

        return newRoot;
      
    }

    Node* left_Rotate(Node* node) 
    {
        Node* newRoot = node->right;
        Node* temp = newRoot->left;

        newRoot->left = node;
        node->right = temp;

        update_Height(newRoot);
        update_Height(node);

        return newRoot;

    }

    Node* balance_Node(Node* node)
    {
        int balanceFactorForNode = get_Balance(node);
        int balanceFactorForRight = get_Balance(node->right);
        int balanceFactorForLeft = get_Balance(node->left);


        // LL
        if (balanceFactorForNode > 1 && balanceFactorForLeft >= 0) 
        {
            return right_Rotate(node);
        }
        // LR
        else if (balanceFactorForNode > 1 && balanceFactorForLeft < 0) 
        {
            node->left = left_Rotate(node->left);
            return right_Rotate(node);
        }
        // RR
        else if (balanceFactorForNode < -1 && balanceFactorForRight <= 0) 
        {
            return left_Rotate(node);
        }
        // RL
        else if (balanceFactorForNode < -1 && balanceFactorForRight > 0)
        {
            node->right = right_Rotate(node->right);

            return left_Rotate(node);
        }
        return node;
    }

    /**
     * @brief Helper function to find the minimum value node (Successor).
     */
    Node* Successor(Node* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }

    /**
     * @brief Private recursive function to insert a value into the AVL tree.
     */
    Node* insert(Node* node, int value) {
        if (!node) return new Node(value);

        if (value < node->data) {
            node->left = insert(node->left, value);
        }
        else if (value > node->data) {
            node->right = insert(node->right, value);
        }
        else {
            return node; 
        }

        
        update_Height(node);
        return balance_Node(node);
    }

    /**
     * @brief Private recursive function to delete a value from the AVL tree.
     */
    Node* Delete(Node* node, int value) {
        if (!node) return nullptr;

        if (value < node->data) {
            node->left = Delete(node->left, value);
        }
        else if (value > node->data) {
            node->right = Delete(node->right, value);
        }
        else { // Node Found
            if (!node->left && !node->right) {
                delete node;
                return nullptr;
            }
            else if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            else {
                Node* successor = Successor(node->right);
                node->data = successor->data;
                node->right = Delete(node->right, successor->data);
            }
        }

       
        update_Height(node);
        return balance_Node(node);
    }

    /**
     * @brief Private helper for In-Order traversal.
     */
    void in_Order(Node* node) {
        if (!node) return;
        in_Order(node->left);
        cout << node->data << " (H:" << node->height << ") ";
        in_Order(node->right);
    }

    /**
     * @brief Private helper for BFS (Level-Order) traversal.
     */
    void bfs(Node* node) {
        if (!node) return;
        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* u = q.front();
            q.pop();

            cout << u->data << " ";

            if (u->left) q.push(u->left);
            if (u->right) q.push(u->right);
        }
        cout << "\n";
    }

    /////////////////////////////////////////////////////////////////////////////   
     // Encapsulation & Abstraction (Public Interface)
    /////////////////////////////////////////////////////////////////////////////   
public:
    AVL() : root(nullptr) {}

    /**
     * @brief Public method to insert a value into the AVL Tree.
     */
    void insert(int value) {
        root = insert(root, value);
    }

    /**
     * @brief Public method to delete a value from the AVL Tree.
     */
    void Delete(int value) {
        root = Delete(root, value);
    }

    /**
     * @brief Prints the tree using In-Order traversal (with heights).
     */
    void in_Order() {
        in_Order(root);
        cout << "\n";
    }

    /**
     * @brief Prints the tree using Level-Order traversal (BFS).
     */
    void bfs() {
        bfs(root);
    }

};

int main() 
{
    AVL tree;

    cout << "--- Inserting elements that would cause imbalance in normal BST ---\n";
    
    tree.insert(10);
    tree.insert(20);
    tree.insert(30); 
    tree.insert(40);
    tree.insert(50);
    tree.insert(25); 

    cout << "In-Order Traversal (Should be sorted with correct heights):\n";
    tree.in_Order();

    cout << "\nBFS / Level-Order Traversal (Should show auto-balanced structure):\n";
    tree.bfs();

    cout << "\n--- Deleting node 30 (Root or Sub-root) ---\n";
    tree.Delete(30);

    cout << "BFS after deletion (Tree re-balanced automatically):\n";
    tree.bfs();


  return 0;
}
       