template<typename T>
struct Node {
	Node<T> *next;
	//std::unique_ptr<Node<T>> next;
	~Node();
	T data;
};