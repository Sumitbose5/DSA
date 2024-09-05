#include <iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* left;
  Node* right;

  Node(int val){
    this->data = val;
    this->left = NULL;
    this->right = NULL;
  }
};

Node* createTree(){
  cout << "Enter the value : " << endl;
  int data;
  cin >> data;

  if(data == -1){
    return NULL;
  }

  Node* root = new Node(data);
  cout << "Left of Node : " << root->data << endl;
  root->left = createTree();
  cout << "Right of Node : " << root->data << endl;
  root->right = createTree();
  return root;
}

int main(){
  Node* root = createTree();
  cout << root->data << endl;
  return 0;
}
