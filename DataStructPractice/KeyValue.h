#pragma once
#include <string>
#include <vector>

class KeyValue {
public:
	KeyValue(std::string hashed_key, std::string value);
	KeyValue(const KeyValue &obj);
	void insertValue(std::string value);
	void removeValue(std::string value);
	std::vector<std::string> getValues() const;
	std::string valuesToString();
	std::string getKey() const;
private:
	std::string key;
	std::vector<std::string> values;
};

std::ostream& operator<<(std::ostream& os, KeyValue kv);