#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#include <cstdlib>
#include <utility>      // std::pair, std::make_pair

struct node {
  int val;
  node *left, *right, *parent;
};

class SplayTree {
  public:
    SplayTree();
    void rotate(node* node1, node* node2);
    void printTree(node* root);

    node* access(int key);
    void splay(node* node);
    std::pair<SplayTree,SplayTree> split(int key);
    bool insert(int key);
    node* createNode(int key);
    bool find(int key);

    node* getRoot();
    void setRoot(node* newRoot);

  private:
    node* root;
};

#endif
