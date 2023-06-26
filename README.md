# Huffman-Algorithm

<img src="https://t.bkit.co/w_6499780fbd5f6.gif" />
This repository contains an implementation of Huffman coding, a popular algorithm for data compression.

## Introduction

Huffman coding is a lossless data compression algorithm that assigns variable-length codes to different characters based on their frequency of occurrence in the input data.
It uses a binary tree structure to encode characters efficiently, with more frequently occurring characters assigned shorter codes.

## Usage

To use the Huffman coding implementation, follow these steps:

1. Clone the repository:
git clone <https://github.com/AMAN-ARABZADEH/Huffman-Algorithm/new/main?readme=1>


2.  Enter the input text when prompted.

3. The program will generate the Huffman codes for each character and display the encoded and decoded data.

## Code Description

- The code defines a `Node` struct representing a node in the Huffman tree. Each node contains character data, frequency, and pointers to its left and right child nodes.
- It also defines a `Compare` struct to compare two nodes based on their frequencies, which is used in the priority queue for building the Huffman tree.
- The `HuffmanTree` class encapsulates the Huffman tree and provides methods for generating Huffman codes, encoding and decoding data, and cleaning up memory.
- The `HuffmanTree` constructor takes an input text and builds the Huffman tree based on the frequency of each character in the text.
- The `encodeData` method encodes the input data using the generated Huffman codes.
- The `decodeData` method decodes the encoded data using the Huffman codes.
- The `getCodes` method returns the generated Huffman codes for each character.


Feel free to use this code as a reference or incorporate it into your own projects. 
For more information on the Huffman algorithm and its implementation, please refer to the provided sources:

## References

- [Wikipedia: Huffman coding](https://en.wikipedia.org/wiki/Huffman_coding)
- [GeeksforGeeks: Huffman Coding](https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/)
- [GeeksforGeeks: Huffman Decoding](https://www.geeksforgeeks.org/huffman-decoding/)

