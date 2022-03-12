#include <\Users\Julian\Documents\Visual Studio 2015\Projects\DataStructPractice\DataStructPractice\HashTable.h>

void HashTable::add(std::string key, std::string value)
{
	if (get(key) == "") {
		//RELOOK AT APPROACH TO KEY VALUE
	}
	else {
		key_value_pairs.push_back(KeyValue(hash(key), value));
	}
}

void HashTable::remove(std::string key, std::string value)
{
}

std::string HashTable::get(std::string key)
{
	for (KeyValue pair : key_value_pairs) {
		if (pair.getKey() == hash(key)) {
			return key;
		}
	}
	return "";
}

void HashTable::print()
{
}

std::string HashTable::testHash(std::string key)
{
	return hash(key);
}

std::string HashTable::hash(std::string key)
{
	return std::string();
}

int main() {
	HashTable ht;
}
