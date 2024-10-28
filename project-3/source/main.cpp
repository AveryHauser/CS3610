#include <iostream>
#include "huffman_tree.h"
using namespace std;

int main(int argc, char** argv) {

  HuffmanTree tree;

  int T;
  cout << "Enter how many test cases you have: ";
  cin >> T;
  cin.ignore();
  for (int t = 1; t <= T; ++t) {
    cout << "Test Case: " << t << endl;
    cout << "Enter message: ";
    string message;
    getline(cin, message);

    // Create a HuffmanTree object and read the input messages into the
    // HuffmanTree construct function. Next, print the encoded message.
    // Finally, destruct the huffman tree and move on to the next test case.
				     
    tree.construct(message);
    tree.print();
    tree.destruct();
  }

}
