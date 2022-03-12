#pragma once
#include <vector>
#include <\Users\Julian\Documents\Visual Studio 2015\Projects\DataStructPractice\DataStructPractice\KeyValue.h>

class HashTable {
public:
	void add(std::string key, std::string value);
	void remove(std::string key, std::string value);
	std::string get(std::string key);
	void print();
	std::string testHash(std::string key);
private:
	std::string hash(std::string key);
	std::vector<KeyValue> key_value_pairs;
};