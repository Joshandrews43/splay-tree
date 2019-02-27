#include "SplayTree.h"
#include <iostream>
#include <queue>

using namespace std;

SplayTree::SplayTree() {
  this->root = nullptr;
}

node* SplayTree::getRoot() {
  return this->root;
}

void SplayTree::setRoot(node* newRoot) {
  this->root = newRoot;
}


node* SplayTree::access(int key) {
  node* node = this->root;

  while(node) {
    if (node->val == key) {
      cout << "calling splay in access" << endl;
      splay(node);
      return node;
    } else if (node->val < key) { // go down right subtree.
      node = node->right;
    } else if (node->val > key) { // go down left subtree.
      node = node-> left;
    }
  }
  return nullptr;
}

// returns a vector with leftTree in position 0, and rightTree in position 1.
pair<SplayTree,SplayTree> SplayTree::split(int key) {
  node* node = access(key);
  SplayTree rightTree, leftTree;

  if (this->root->val > key) {
    leftTree.setRoot(this->root->left);
    this->root->left = nullptr;
    rightTree.setRoot(this->root);
  } else {
    rightTree.setRoot(this->root->right);
    this->root->right = nullptr;
    leftTree.setRoot(this->root);
  }


  return make_pair(leftTree, rightTree);

}

bool SplayTree::insert(int key) {

  if (!this->root) {
    this->root = createNode(key);
    return true;
  }

  if (find(key)) {
    return false;
  } else {
    pair<SplayTree, SplayTree> treePair = split(key);

    node* newRoot = createNode(key);
    newRoot->left = treePair.first.getRoot();
    newRoot->left->parent = newRoot;
    newRoot->right = treePair.second.getRoot();
    newRoot->right->parent = newRoot;
    this->root = newRoot;
    return true;
  }
}

bool SplayTree::find(int key) {
  printTree(this->root);
  node* found = access(key);
  cout << "find after access" << endl;

  if (found == nullptr) {
    return false;
  } else {
    return true;
  }
}


void SplayTree::splay(node* node) {

  if (this->root == node) {
    return;
  }

  if (node->parent == this->root) {
    rotate(node->parent, node);
    return;
  }

  cout << "right before error part with key: " << node->val << endl;
  cout << "parent " << node->parent << endl;
  cout << "grandparent " << node->parent->parent << endl;
  cout << "grandparent left" << node->parent->parent->left << endl;


  if ((node->parent->parent->left && node->parent->parent->left->left) || (node->parent->parent->right && node->parent->parent->right->right)) {
    rotate(node->parent->parent, node->parent);
    rotate(node->parent->parent, node);
  } else {
    rotate(node->parent, node);
    rotate(node->parent->parent, node);
  }

  cout << "right after error part" << endl;


  if(this->root != node) {
    splay(node);
  }
}


void SplayTree::rotate(node* node1, node* node2) {
  node* node1Parent = node1->parent;

  if (node1->left == node2) {
    node1->left = node2->right;
    node2->right = node1;
  } else {
    node1->right = node2->left;
    node2->left = node1;
  }

  if(!node1Parent) {
    this->root = node2;
    node2->parent = nullptr;
  } else if (node1Parent->left == node1) {
    node1Parent->left = node2;
  } else {
    node1Parent->right = node2;
  }
}

node* SplayTree::createNode(int key) {
  node* temp = new node;
  temp->val = key;
  temp->left = nullptr;
  temp->right = nullptr;
  temp->parent = nullptr;
  return temp;
}


/* Print nodes at a given level */
void printGivenLevel(struct node* root, int level)
{
    if (root == nullptr)
        return;
    if (level == 1)
        printf("%d ", root->val);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

int height(struct node* node)
{
    if (node==nullptr)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);

        /* use the larger one */
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
  }

void printLevelOrder(struct node* root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
    {
        printGivenLevel(root, i);
        printf("\n");
    }
}



  void SplayTree::printTree(node* root) {
    printLevelOrder(root);
  }
