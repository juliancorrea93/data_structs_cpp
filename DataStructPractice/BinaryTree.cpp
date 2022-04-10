#include <\Users\Julian\Documents\Visual Studio 2015\Projects\DataStructPractice\DataStructPractice\BinaryTree.h>

bool BinaryTree::insert(int data)
{
	if (isPresent(data)) {
		return false;
	}
	else {
		TreeNode* new_node = getNode(std::move(data));
		TreeNode* temp = root;
		while (temp != nullptr) {
			if (temp->data < data) {
				temp = temp->left;
			}
			if (temp->data > data) {
				temp = temp->right;
			}
		}
		temp = new_node;
		return true;
	}
}

bool BinaryTree::deleteNode(int data)
{
	return false;
}

std::string BinaryTree::toString(TreeNode* root_node)
{
	std::string result = "";
	std::string delimiter = " -> ";

	if (root_node == nullptr) {
		result += "" + root->data + delimiter;

		result += toString(root_node->right) + delimiter;
		result += toString(root_node->left) + delimiter;
	}

	return result;
}

TreeNode * BinaryTree::getRoot()
{
	return root;
}

bool BinaryTree::isPresent(int data)
{
	TreeNode* temp = root;
	while (temp != nullptr) {
		if (temp->data < data) {
			temp = temp->left;
		}
		else if (temp->data > data) {
			temp = temp->right;
		}
		else {
			return true;
		}
	}
	return false;
}

TreeNode* BinaryTree::getNode(int data)
{
	TreeNode new_node;
	new_node.left = nullptr;
	new_node.right = nullptr;
	new_node.data = data;

	return &new_node;
}

int main() {
	BinaryTree tree;
	tree.insert(5);
	tree.insert(2);
	tree.insert(20);
	tree.insert(30);
	tree.insert(22);
	tree.insert(25);
	tree.insert(4);
	tree.insert(3);
	std::cout << tree.toString(tree.getRoot()) << std::endl << std::flush;
}