#include <iostream>
#include "huffman_tree.h"
#include "min_heap.h"
using namespace std;

void HuffmanTree::construct(const string message) {
  this->message = message; 
  
  // Count the frequency of each letter in message
  // e.g. 
  //    message == "aaabbccccdd"
  //    frequencies == {a:3, b:2, c:4, d:2} 
  map<char, int> frequency_map;
  for (int i = 0; i < message.length(); ++i) {
    if (frequency_map.find(message[i]) != frequency_map.end())
      ++frequency_map[message[i]];
    else
      frequency_map[message[i]] = 1;
  }

  // Create HuffmanNode for each unique letter in message
  // and organize nodes into a min heap
  // e.g.
  //  heap == 
  //            {b:2}  
  //           /     \
  //        {d:2}   {a:3}
  //        /   \   /    \
  //      {c:4} 
  MinHeap<HuffmanNode*> heap;
  map<char, int>::iterator it = frequency_map.begin();
  for (; it != frequency_map.end(); ++it) {
    HuffmanNode* node = new HuffmanNode(
      it->first, it->second
    );
    heap.insert(node, it->second);
  }

  // Combine nodes with smallest frequency and insert
  // back into heap until heap size == 1. Along the way,
  // create binary tree out of combined nodes.
  // e.g.
  //  (1)
  //     {b:2} == heap.extract_min()
  //     {d:2} == heap.extract_min()
  //     parent ==
  //               {*:4}
  //              /     \
  //            {b:2}  {d:2}
  //
  //     heap == 
  //              {a:3}
  //             /     \
  //           {c:4}   {*:4}
  //
  //  (2)
  //     {a:3} == heap.extract_min()
  //     {c:4} == heap.extract_min()
  //     parent ==
  //              {*:7}
  //             /     \
  //          {a:3}   {*:4}
  //    
  //     heap ==
  //            {c:4}
  //           /
  //         {*:7}
  //
  //  (3)
  //     {*:4} == heap.extract_min()
  //     {*:7} == heap.extract_min()
  //     parent ==
  //            {*:11}
  //           /       \
  //      {c:4}        {*:7}
  //                  /     \
  //                {a:3}  {*:4}
  //                       /    \
  //                    {b:2}  {d:2}
  //
  //     heap == {*:11}
  while (heap.size() > 1) {
    HuffmanNode *left, *right;

    left = heap.extract_min();
    right = heap.extract_min();

    HuffmanNode *parent = new HuffmanNode(
      left->frequency + right->frequency
    );

    parent->left = left;
    parent->right = right;

    heap.insert(parent, parent->frequency);
  }

  // Get root of huffman tree. e.g. {*:11}
  this->root = heap.peek();
}

void HuffmanTree::generate_codes(HuffmanNode *node, string code, map<char, string>& huffman_codes) const {
  //will return if the node isnt set
  if (node == nullptr) return;

  //assigns a code for the charaters 
  if (node->character != '\0' && node->character != '*') {
      huffman_codes[node->character] = code;
  } else {
      //will go through the left and right nodes to assignment additional codes 
      generate_codes(node->left, code + "0", huffman_codes);
      generate_codes(node->right, code + "1", huffman_codes);
  }
}
void HuffmanTree::print() const {   // need to implement this function 
  //if the tree isnt created to return.
  if (root == nullptr) return;

    //creates a map of strings and characters
    map<char, string> huffman_codes;
    
    //assigns codes to the map that was created
    generate_codes(root, "", huffman_codes);

    //outputs the encodded message 
    std::cout << "Encoded Message: ";
    for (int i = 0; i < message.length(); i++) {
      std::cout << huffman_codes[message[i]] << " ";
    }
    std::cout << std::endl;
  }

  // Print the Huffman encoding of this->message.
  // Append 0 to a character's encoding if moving left in Huffman tree.
  // Append 1 to a character's encoding if moving right in Huffman tree.

  // Remember, your Huffman tree is pointed at by this->root, so start your
  // character searches from there.

  // Also, feel free to add a print helper function.



