//
// Created by amana on 2023-06-26.
//

#ifndef HUFFMAN_HUFFMAN_H
#define HUFFMAN_HUFFMAN_H


#include <iostream>
#include <queue>
#include <unordered_map>
/*
    https://www.geeksforgeeks.org/huffman-decoding/
    Sources: https://stackoverflow.com/questions/75736302/issue-with-implementing-the-compare-function-in-a-priority-queue
    https://en.wikipedia.org/wiki/Huffman_coding
    https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/
*/

// Huffman tree node
struct Node {
    char data;
    unsigned frequency;
    Node* left;
    Node* right;

    Node(char data, unsigned frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};

// Comparison function for priority queue
struct Compare {
    bool operator()(const Node* left, const Node* right) {
        return left->frequency > right->frequency;
    }
};

// HuffmanTree class
class HuffmanTree {
private:
    Node* root;
    std::unordered_map<char, std::string> codes;

    // Generate Huffman codes and store them in the codes map
    void generateCodes(Node* node, const std::string& code) {
        if (node->left == nullptr && node->right == nullptr) {
            codes[node->data] = code;
            return;
        }

        generateCodes(node->left, code + "0");
        generateCodes(node->right, code + "1");
    }

    // Delete the Huffman tree nodes (used for memory cleanup)
    void deleteNodes(Node* node) {
        if (node == nullptr)
            return;

        deleteNodes(node->left);
        deleteNodes(node->right);

        delete node;
    }

public:
    // Constructor
    HuffmanTree(const std::string& text) : root(nullptr) {
        if (text.empty())
            return;

        // Calculate the frequency of each character
        std::unordered_map<char, unsigned> freq;
        for (char ch : text) {
            freq[ch]++;
        }

        // Create a priority queue to store nodes
        std::priority_queue<Node*, std::vector<Node*>, Compare> pq;

        // Create a leaf node for each character and add it to the priority queue
        for (const auto& pair : freq) {
            pq.push(new Node(pair.first, pair.second));
        }

        // Build the Huffman tree
        while (pq.size() > 1) {
            Node* left = pq.top();
            pq.pop();

            Node* right = pq.top();
            pq.pop();

            Node* newNode = new Node('$', left->frequency + right->frequency);
            newNode->left = left;
            newNode->right = right;

            pq.push(newNode);
        }

        if (!pq.empty())
            root = pq.top();

        // Generate Huffman codes
        if (root != nullptr)
            generateCodes(root, "");
    }

    // Destructor
    ~HuffmanTree() {
        std::cout<< "destructore is called\n";
        deleteNodes(root);
    }

    // Encode the input data using Huffman codes
    std::string encodeData(const std::string& data) const {
        std::string encodedData = "";
        for (char ch : data) {
            if (codes.find(ch) != codes.end())
                encodedData += codes.at(ch);
        }
        return encodedData;
    }

    // Decode the encoded data using Huffman codes
    std::string decodeData(const std::string& encodedData) const {
        std::string decodedData = "";

        Node* currNode = root;
        for (char bit : encodedData) {
            if (bit == '0') {
                currNode = currNode->left;
            } else if (bit == '1') {
                currNode = currNode->right;
            }

            if (currNode->left == nullptr && currNode->right == nullptr) {
                decodedData += currNode->data;
                currNode = root;
            }
        }

        return decodedData;
    }

    // Get the generated Huffman codes
    const std::unordered_map<char, std::string>& getCodes() const {
        return codes;
    }
};

#endif //HUFFMAN_HUFFMAN_H
