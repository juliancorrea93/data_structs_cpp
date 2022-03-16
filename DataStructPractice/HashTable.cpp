#include <\Users\Julian\Documents\Visual Studio 2015\Projects\DataStructPractice\DataStructPractice\HashTable.h>

/*template<typename T>
std::string HashTable<T>::testHash(std::string key)
{
	std::cout << hash(key) << std::endl << std::flush;
}

template<typename T>
std::string HashTable<T>::hash(std::string key)
{
	std::vector<bitset<8>> bit_vector;
	for (char const &c : key) {
		bit_vector.push_back(hash(c));
	}

	//append the 1 to the binary
	//append 0's until binary value % 512 == 0
	return std::string();
}

template<typename T>
std::bitset<8> HashTable<T>::to_binary(char const & c)
{
	return std::bitset<8>();
}
*/

template<typename T>
std::string HashTable<T>::hash(std::string key)
{
	CryptoPP::SHA256 _hash;
	unsigned char digest[CryptoPP::SHA256::DIGESTSIZE];
	_hash.CalculateDigest(digest, (unsigned char*)key.c_str(), key.length());
	CryptoPP::HexEncoder encoder;
	std::string output;
	encoder.Attach(new CryptoPP::StringSink(output));
	encoder.Put(digest, sizeof(digest));
	encoder.MessageEnd();
	return output;
}

template<typename T>
std::string HashTable<T>::testHash(std::string key)
{
	return hash(key);
}


template<typename T>
void HashTable<T>::add(std::string key, std::string value)
{
	std::string hashed_key = hash(key);
	
	
}

template<typename T>
bool HashTable<T>::is_full()
{
	int items = 0;
	for (int i = 0; i < (sizeof(table) / sizeof(*table)); i++) {
		if (table[i] == nullptr) {
			items += 1;
		}
	}

	return items > ((sizeof(table) / sizeof(*table)) / 2)
	return 0;
}

template<typename T>
void HashTable<T>::double_size()
{
	T doubled = new T[(sizeof(table) / sizeof(*table)) * 2];
	for (int i = 0; i < (sizeof(table) / sizeof(*table)); i++) {
		doubled[i] = table[i];
	}
	delete[] table;

	table = doubled;
}

int main() {
	HashTable<int> ht;
	std::cout << ht.testHash("Fuck");
}
