#include <iostream>
#include "SplayTree.h"
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

void executeCommand(string command, SplayTree &tree);


int main() {
    SplayTree st;

    string line;
    getline(cin, line);

    while (cin) {
      executeCommand(line, st);
      getline(cin, line);
  }

  return 0;
}

void executeCommand(string command, SplayTree &tree) {
  int separator = command.find(" ");
  string func = command.substr(0, separator);

  if (func == "print") {
    cout << "print" << endl;
    tree.printTree(tree.getRoot());
  } else {
    int key = stoi(command.substr(separator + 1));

    if (func == "insert") {
      bool inserted = tree.insert(key);
      if (inserted) {
        cout << "item " << key << " inserted" << endl;
      } else {
        cout << "item " << key << " not inserted; already present" << endl;
      }
    } else if (func == "find") {
      bool found = tree.find(key);
      if (found) {
        cout << "item " << key << " found" << endl;
      } else {
        cout << "item " << key << " not found" << endl;
      }
    } else if (func == "delete") {
      //tree.remove(key, tree.getRoot());
      tree.printTree(tree.getRoot());
    }
  }

}
