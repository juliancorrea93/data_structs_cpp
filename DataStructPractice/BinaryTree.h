#include <string>
#include <iostream>

struct TreeNode {
	TreeNode* left;
	TreeNode* right;
	int data;
};

class BinaryTree {
public:
	BinaryTree() :
		root(nullptr) {}
	bool insert(int data);
	bool deleteNode(int data);
	std::string toString(TreeNode* root_node);
	TreeNode* getRoot();
private:
	bool isPresent(int data);
	TreeNode* getNode(int data);
	TreeNode *root;
};