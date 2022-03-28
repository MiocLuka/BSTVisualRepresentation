#include <iostream>
#include <vector>
#include <iomanip>

class TreeNode {
public:
    TreeNode();
    TreeNode(int value);
    ~TreeNode(); 
    int key;
    TreeNode* leftNode;
    TreeNode* rightNode;
    int xPos, yPos;
};

TreeNode::TreeNode() {
    leftNode = nullptr;
    rightNode = nullptr;
}

TreeNode::TreeNode(int data) {
    leftNode = nullptr;
    rightNode = nullptr;
    key = data;
}

TreeNode::~TreeNode() {
    delete leftNode;
    delete rightNode;
}


class BST {
public:
    BST();
    ~BST();
    void insertKey(int newKey);
    bool searchKey(int data);
    std::vector< int > inOrder();
    int getHeight();
    void prettyPrint();
    
    
private:
    TreeNode* rootNode;
    bool findKey(TreeNode* rootNode, int data);
    TreeNode* insert(TreeNode* rootNode, int newKey);
    std::vector< int > keysInOrder(TreeNode* rootNode, std::vector< int > &sorted);
    int calculateHeight(TreeNode* rootNode);

    void assignDepth(TreeNode* rootNode, int currDepth);
    void assignColumn(TreeNode* rootNode, int &currColumn);

    std::vector< std::vector< std::string > > createEmptyMatrix(int rows, int columns);
    void populateMatrix(TreeNode* rootNode, std::vector< std::vector< std::string > > &treeMatrix);
    void createPrettyPrint(std::vector< std::vector< std::string > > treeMatrix);
};

BST::BST() {
    rootNode = nullptr; 
}

BST::~BST() {
    delete rootNode;
}

void BST::insertKey(int newKey) {
    rootNode = insert(rootNode, newKey);
}

TreeNode* BST::insert(TreeNode* rootNode, int newKey) {
    if (rootNode == nullptr) {
        rootNode = new TreeNode(newKey);
    }
    else if (newKey <= rootNode->key) {
        rootNode->leftNode = insert(rootNode->leftNode, newKey);
    }
    else if (newKey > rootNode->key) {
        rootNode->rightNode = insert(rootNode->rightNode, newKey);
    }
    return rootNode;
}

int BST::getHeight() {
    return calculateHeight(rootNode);    
}

int BST::calculateHeight(TreeNode* rootNode) {
    int leftHeight, rightHeight;
    if (rootNode == nullptr) {
        return 0;
    }
    leftHeight = calculateHeight(rootNode->leftNode);
    rightHeight = calculateHeight(rootNode->rightNode);

    if (leftHeight > rightHeight) return (leftHeight+1);
    else return (rightHeight+1);
}

std::vector< int > BST::inOrder() {
    std::vector< int > sorted;
    sorted = keysInOrder(rootNode, sorted);

    return sorted;
}

std::vector< int > BST::keysInOrder(TreeNode* rootNode, std::vector< int > &sorted) {
    if (rootNode == nullptr) {
        return sorted;
    }
    keysInOrder(rootNode->leftNode, sorted);
    sorted.push_back(rootNode->key);
    keysInOrder(rootNode->rightNode, sorted);
    
    return sorted;
}

void BST::prettyPrint() {
    if (rootNode == nullptr) {
        return;
    }

    int currColumn = 0;
    assignColumn(rootNode, currColumn);
    assignDepth(rootNode, 0);

    int height = getHeight();
    std::vector< int > ordered = inOrder();
    
    std::vector< std::vector< std::string > > treeMatrix = createEmptyMatrix(height, ordered.size());
    populateMatrix(rootNode, treeMatrix);
    createPrettyPrint(treeMatrix);
}

void BST::assignColumn(TreeNode* rootNode, int &currColumn) {
    if (rootNode == nullptr) {
        return;
    }
    assignColumn(rootNode->leftNode, currColumn);

    rootNode->xPos = currColumn;
    currColumn++;

    assignColumn(rootNode->rightNode,currColumn);
}

void BST::assignDepth(TreeNode* rootNode, int currDepth) {
    if (rootNode == nullptr) {
        return;
    }
    rootNode->yPos = currDepth;
    assignDepth(rootNode->leftNode, currDepth + 1);
    assignDepth(rootNode->rightNode, currDepth + 1); 
}

std::vector< std::vector< std::string > > BST::createEmptyMatrix(int rows, int columns) {
    std::vector< std::vector< std::string > > emptyMatrix;
    for (int currRow = 0; currRow < rows; currRow++) {
        std::vector< std::string > emptyRow;
        for (int currColumn = 0; currColumn < columns; currColumn++) {
            emptyRow.push_back("");
        }
        emptyMatrix.push_back(emptyRow);
    }
    return emptyMatrix;
}

void BST::populateMatrix(TreeNode* rootNode, std::vector< std::vector< std::string > > &treeMatrix) {
    if (rootNode == nullptr) {
        return;
    }
    treeMatrix.at(rootNode->yPos).at(rootNode->xPos) = std::to_string(rootNode->key);
    populateMatrix(rootNode->leftNode, treeMatrix);
    populateMatrix(rootNode->rightNode, treeMatrix); 
}

void BST::createPrettyPrint(std::vector< std::vector< std::string > > treeMatrix) {
    for (int row = 0; row < treeMatrix.size(); row++) {
        std::cout << std::setfill('-') << std::setw((treeMatrix.at(0).size())* 5 + 1) << "" << std::endl;

        for (int column = 0; column < treeMatrix.at(0).size(); column++) {
            std::cout << std::setfill(' ');
            std::cout << "|";
            std::cout << std::setw(4) << std::right <<  treeMatrix.at(row).at(column);
        } 
        std::cout << "|";
        std::cout << std::endl;
    }
    std::cout << std::setfill('-') << std::setw((treeMatrix.at(0).size()) * 5 + 1) << "" << std::endl;
}


int main() {
    BST tree;
    int addNum;
    std::cout << "Enter the numbers to be stored: ";
    
    while (std::cin >> addNum) {
        tree.insertKey(addNum);     
    }
    std::cout<<std::endl;

    std::vector< int > contents = tree.inOrder();
    std::cout << "The numbers in sorted order: ";
    for (int i = 0; i < contents.size(); i++) {
        std::cout << contents.at(i) << " ";
    }
    std::cout << std::endl;
    tree.prettyPrint();
}
