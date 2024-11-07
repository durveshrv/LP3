#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
using namespace std ;


struct Node{
    char data ; 
    int freq ; 
    Node* left ; 
    Node* right ; 

    Node (char data_ , int freq_){
        data = data_ ; 
        freq = freq_ ;
        left = nullptr ; // Initially set left child to null
        right = nullptr ; // Initially set right child to null
    }
};

struct compare{
    bool operator()(Node* Left, Node* Right){
        return Left->freq > Right->freq ; // Return true if the left node has greater frequency than the right node
    }
};

// Recursive function to generate the Huffman codes from the Huffman tree
void printCodes(Node* n , string code,unordered_map<char, string>& codes){
    if (!n)  // If the current node is null, just return
	{
        return ; 
    }
    if (!n->left && !n->right){ // If this node is a leaf node (both left and right children are null)
        codes[n->data] = code ;   // Save the code for the character at this leaf node
        cout  <<n->data << " : " << codes[n->data] <<endl ; // Print the character and its Huffman code
    }
    }
    else {  // If it's not a leaf node, recursively generate codes for its children
        printCodes(n->left , code + "0" , codes ); 
        printCodes(n->right , code + "1" , codes ); 
    }
}

// Function to build the Huffman tree and encode the given text
void buildHuffmanTree (string text){
    unordered_map <char , int > freqs ; // Create a map to store the frequency of each character
    for (auto ch : text){
        freqs[ch] ++ ; 
    }
  
   // Create a priority queue (min-heap) to store nodes, sorted by frequency
    priority_queue<Node* , vector<Node*> , compare> pq ; 

// Add all characters and their frequencies as nodes to the priority queue
    for (auto pair : freqs){
        pq.push(new Node(pair.first , pair.second)) ; 
    }

    while (pq.size()>1){
        Node* left = pq.top() ; pq.pop() ;  // Extract the node with the smallest frequency
        Node* right = pq.top() ; pq.pop() ; // Extract the next node with the smallest frequency

        Node* newNode = new Node ('\0' , left->freq + right->freq ); 

        newNode -> left = left ; // Set the left child of the new node to the left node
        newNode -> right = right; 

        pq.push(newNode) ; // Add the new internal node back to the priority queue
    }

    Node* root = pq.top() ; // The final node left in the queue is the root of the Huffman tree

    unordered_map<char, string> codes ; 
    printCodes(root,  "" , codes) ; 

    cout << "\nEncoded string: ";
    for (char ch : text) {
        cout << codes[ch];
    }
    cout << endl;
}
int main (){
    string text;
    cout << "Enter text to encode using Huffman Encoding: ";
    getline(cin, text);

    buildHuffmanTree(text);
}


/*


"hello world"

h: 1, e: 1, l: 3, o: 2, w: 1, r: 1, d: 1, (space): 1


           (*, 11)
          /        \
     (*, 5)         (*, 6)
     /      \       /     \
  (*, 2)  'l'(3)  'o'(2)  (*, 4)
   /    \               /     \
'h'(1) 'e'(1)       (*, 2)   (*, 2)
                   /     \   /     \
               'd'(1) ' '(1)'w'(1) 'r'(1)


h: 000
e: 001
l: 01
o: 10
w: 1110
r: 1111
d: 1000
space: 101


000 001 01 01 10 101 1110 10 1111 01 1000

*******************************************************************88

Why Huffman Encoding is Used
1)Efficient Compression: Huffman Encoding is a lossless compression technique, meaning no data is lost during the compression and decompression processes. It ensures that the original data can be perfectly reconstructed from the encoded data.
2)Variable-Length Coding: Huffman Encoding assigns variable-length binary codes to characters, with shorter codes for more frequent characters. This reduces the overall size of the data compared to fixed-length coding (like ASCII, where each character takes 8 bits).
3)Reduced Storage and Transmission Costs: By reducing the amount of data, Huffman Encoding can help lower storage costs and speed up data transmission over networks, 

APPLICATIONS
1)File Compression:
ZIP, GZIP: Huffman Encoding is a core component of file compression formats like ZIP and GZIP. These formats use Huffman Encoding in combination with other algorithms to reduce file sizes for efficient storage and transfer.
2)Image and Video Compression:
JPEG: In JPEG image compression, Huffman Encoding is used in the final steps after transforming and quantizing image data. It encodes the quantized values into a compressed form, reducing image file sizes without a significant loss of quality.
MP3, MPEG: Audio (MP3) and video (MPEG) compression formats also use Huffman Encoding to compress specific parts of the dat

*********************************************************************88
TIME COMPPLXITY
Combining all steps, the total time complexity is: 
In the worst case, when every character in the string is unique, =
k=n, so the complexity becomes: O(nlogn)


O(n) for counting character frequencies
O(k log k) for building the priority queue
O(k log k) for constructing the Huffman Tree
O(k) for generating Huffman codes
O(n) for encoding the string

SPACE COMPLEXITY
In the worst case, each code could be up to O(log k) bits long (height of the tree).
Therefore, the huffmanCodes map requires O(k log k) space.


*/
