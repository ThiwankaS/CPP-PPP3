#include <iostream>
#include <unordered_map>
#include <string>

int main(void)
{
	std::unordered_map<int, std::string> m;
	m.insert({1, "apple"});
	m.insert({2, "orange"});
	m.insert({3, "pears"});
	m.insert({4, "grapes"});
	m.insert({5, "blackberry"});

	/**
	 *Looking up for the key and value pair with using of ieterator
	*/
	int key1 = 6;
	std::unordered_map<int, std::string>::iterator look_up1;
	look_up1 = m.find(key1);
	if(look_up1 != m.end())
		std::cout << "Found the key1 !" << std::endl;
	else
		std::cout << "Not Found the key1 !" << std::endl;

	/**
	 *Looking up for the key and value pair with using of iterator type auto
	*/
	int key2 = 6;
	auto look_up2 = m.find(key2);
	if(look_up2 != m.end())
		std::cout << "Found the key2 !" << std::endl;
	else
		std::cout << "Not Found the key2 !" << std::endl;

	/**
	 *Print the entire unordered map using an iterator
	*/
	std::cout << "solution 01" << std::endl;
	std::unordered_map<int, std::string> :: iterator it;
	for(it = m.begin(); it != m.end(); it++)
		std::cout << "item {" << it->first << "} : " << it->second << std::endl;

	/**
	 *Print the entire unordered map using an iterator
	*/
	std::cout << "solution 02" << std::endl;
	for(std::pair<const int, std::string> & key_val : m)
		std::cout << "item {" << key_val.first << "} : " << key_val.second << std::endl;

	/**
	 *Print the entire unordered map using an iterator type auto
	*/
	std::cout << "solution 03" << std::endl;
	for(auto &item : m)
		std::cout << "item {" << item.first << "} : " << item.second << std::endl;
	return (0);
}
