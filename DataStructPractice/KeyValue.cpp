#include <\Users\Julian\Documents\Visual Studio 2015\Projects\DataStructPractice\DataStructPractice\KeyValue.h>

KeyValue::KeyValue(std::string hashed_key, std::string value)
{
	key = hashed_key;
	values.push_back(value);
}

KeyValue::KeyValue(const KeyValue & obj)
{
	key = obj.getKey();
	values = obj.getValues();
}

void KeyValue::insertValue(std::string value)
{
	values.push_back(value);
}

void KeyValue::removeValue(std::string value)
{
	values.erase(std::find(values.begin(), values.end(), value));
}

std::vector<std::string> KeyValue::getValues() const
{
	return values;
}

std::string KeyValue::valuesToString()
{
	std::string value_string = "";
	for (std::string s : values) {
		value_string.append(s + ", ");
	}
	value_string = value_string.substr(0, value_string.size() - 2);
	return value_string;
}

std::string KeyValue::getKey() const
{
	return key;
}

std::ostream & operator<<(std::ostream & os, KeyValue kv)
{
	std::vector<std::string> vals;
	std::string values_string = kv.valuesToString();
	os << kv.getKey() << " : " << values_string << std::endl << std::flush;
	return os;
}
