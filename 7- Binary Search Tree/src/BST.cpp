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


    Node(int value) : data(value), right(nullptr), left(nullptr) {}; 
};

// BST Implementation

class BST {
private:
    Node* root;



    /**
    * @brief Helper function to recursively insert a value into the BST.
    * @param node The current sub-tree root node.
    * @param value The integer value to insert.
    * @return Node* The updated node pointer after insertion.
    */

    Node* insert(Node* node, int value)
    {

        if (!node) return new Node(value);

        else if (value < node->data) { // Go left
            node->left = insert(node->left, value);
        }
        else if (value > node->data) { // Go right
            node->right = insert(node->right, value);
        }
        return node;
    }

    /**
 * @brief Helper function to recursively search for a value in the BST.
 * @param node The current sub-tree root node.
 * @param value The target integer to search for.
 * @return true if the value exists in the sub-tree, false otherwise.
 */

    bool search(Node* node, int value)
    {
        if (!node) return false;

        if (node->data == value) {
            return true;
        }
        else if (node->data < value)
        {
            return search(node->right, value);
        }
        else
        {
            return search(node->left, value);
        }
        
    }


    Node* Successor(Node* node)//min in right
    {
        while (node && node->left)
        {
            node = node->left;
        }
        return node;
    }
    Node* predecessor(Node* node)// max in left
    {
        while (node && node->right)
        {
            node = node->right;
        }
        return node;
    }



    /**
      * @brief Helper function to recursively delete a node with a specific value from the BST.
      * @param node The current sub-tree root node.
      * @param value The integer value to delete.
      * @return Node* The updated node pointer after deletion.
      */

    Node* Delete(Node* node, int value)
    {
        if (!node) return nullptr;
        else if (value < node->data) {
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
            else if (!node->left) { // no left 
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right) { // no left 
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
        return node;
    }

//Traversal
//
//DFS
//

/**
  * @brief Helper function for Pre-Order traversal (Root -> Left -> Right).
  * @param node The current sub-tree root node.
  */
    void pre_Order(Node* node) {
        if (!node) return;

        cout << node->data << " ";
        pre_Order(node->left);
        pre_Order(node->right);


    }
    /**
      * @brief Helper function for In-Order traversal (Left -> Root -> Right).
      * @note In a BST, this traversal prints the elements in sorted ascending order.
      * @param node The current sub-tree root node.
      */

    // The Data will be Sorted In In-Order
    void in_Order(Node* node) {
        if (!node) return;

        in_Order(node->left);
        cout << node->data << " ";
        in_Order(node->right);


    }
    /**
      * @brief Helper function for Post-Order traversal (Left -> Right -> Root).
      * @param node The current sub-tree root node.
      */

    void post_Order(Node* node) {
        if (!node) return;

        post_Order(node->left);
        post_Order(node->right);
        cout << node->data << " ";

    }

//
// BFS
//

    /**
 * @brief Helper function for Breadth-First Search (BFS) / Level-Order traversal.
 * @details Prints the tree level by level from top to bottom and left to right using a queue.
 * @param node The current node to start traversal from.
 */

    void bfs(Node*node) 
    {
        if (!node) return;

        queue<Node*>q;

        q.push(node);

        while (!q.empty()) {
            Node* u = q.front();
            q.pop();

            cout << u->data << " ";

            if (u->left) q.push(u->left);
            if (u->right) q.push(u->right);

        }

    }



 /////////////////////////////////////////////////////////////////////////////   
  // Encapsolation & Abstracion
 /////////////////////////////////////////////////////////////////////////////   

public:
    BST() :root(nullptr) {}

 /**
 * @brief Public method to insert a value into the BST.
 * @param value The integer value to insert.
 */
    void insert(int value) {
        root = insert(root, value);
    }

 
 /**
 * @brief Public method to check if a value exists in the BST.
 * @param value The target integer to search for.
 * @return true if found, false if not found.
 */
   bool search(int value)
   {
       return search(root, value);
   }


   

   /**
     * @brief Public method to delete a value from the Binary Search Tree.
     * @param value The integer value to delete.
     */

   void Delete(int value)
   {
       root =  Delete(root, value);
   }



   /**
     * @brief Public method to trigger Pre-Order traversal from the root.
     */
   void pre_Order() { pre_Order(root); cout << "\n"; }

   /**
    * @brief Public method to trigger In-Order traversal from the root.
    */
   void in_Order() { in_Order(root); cout << "\n"; }

   /**
    * @brief Public method to trigger Post-Order traversal from the root.
    */
   void post_Order() { post_Order(root); cout << "\n"; }


   void bfs() { bfs(root); cout << "\n"; }

   ~BST() {
         // Post-Order Deletion to free memory
         queue<Node*> q;
         if (root) q.push(root);
    
         while (!q.empty()) {
              Node* u = q.front();
              q.pop();
    
              if (u->left) q.push(u->left);
              if (u->right) q.push(u->right);
    
              delete u;
         }
   }

};

int main() 
{
    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    cout << "In-Order: ";
    tree.in_Order();

    cout << "Pre-Order: ";
    tree.pre_Order();

    cout << "Post-Order: ";
    tree.post_Order();

    cout << "BFS / Level-Order: ";
    tree.bfs();

    cout << "Search 40: " << (tree.search(40) ? "Found" : "Not Found") << "\n";
    cout << "Search 90: " << (tree.search(90) ? "Found" : "Not Found") << "\n";

    tree.Delete(20);
    tree.Delete(30);
    tree.Delete(50);

    cout << "In-Order after deletions: ";
    tree.in_Order();

    cout << "BFS after deletions: ";
    tree.bfs();


  return 0;
}
       