#pragma once
#include <vector>
#include <bitset>
#include <\Users\Julian\Documents\Visual Studio 2015\Projects\DataStructPractice\DataStructPractice\KeyValue.h>
#include <iostream>


template <typename T> 
class HashTable {
public:
	HashTable() :
		table(new T[4])
	{}
	void add(std::string key, std::string value);
	void remove(std::string key, std::string value);
	std::string get(std::string key);
	void print();
	//std::hash<std::string> testHash(std::string key);
	
private:
	//std::hash<std::string> hash(std::string key);
	//std::bitset<8> to_binary(char const &c);
	bool is_full();
	void double_size();
	//std::vector<KeyValue> key_value_pairs;
	T *table;
};