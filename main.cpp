#include "HuffmanTree.h"
/*
 * Created By Aman Arabzadeh 2023-06-26
    https://www.geeksforgeeks.org/huffman-decoding/
    Sources: https://stackoverflow.com/questions/75736302/issue-with-implementing-the-compare-function-in-a-priority-queue
    https://en.wikipedia.org/wiki/Huffman_coding
    https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/
*/


int main() {
    std::string text = "\'Veni, vidi, vici\'";

    HuffmanTree huffmanTree(text);

    const std::unordered_map<char, std::string>& codes = huffmanTree.getCodes();

    // Print Huffman codes
    std::cout << "Huffman Codes:\n";
    for (const auto& pair : codes) {
        std::cout << pair.first << " : " << pair.second << "\n";
    }

    // Encode the original data using Huffman codes
    std::string encodedData = huffmanTree.encodeData(text);

    // Decode the encoded data using Huffman codes
    std::string decodedData = huffmanTree.decodeData(encodedData);

    std::cout << "Encoded Data: " << encodedData << std::endl;
    std::cout << "Decoded Data: " << decodedData << std::endl;

    return 0;
}
