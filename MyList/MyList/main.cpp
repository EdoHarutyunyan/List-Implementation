#include <iostream>
#include "List.h"
#include <string>

int main()
try 
{
	list::List<int> l;

	std::cout << "empty(): " << std::boolalpha << l.empty() << std::endl;
	l.insert(1, 1);
	l.insert(2, 2);
	l.insert(2, 2);
	std::cout << "empty(): " << std::boolalpha << l.empty() << std::endl;
	l.insert(2, 2);
	l.insert(2, 2);
	l.insert(2, 2);
	std::cout << "size(): " << l.size() << std::endl;
	l.insert(2, 2);
	l.clear();
	std::cout << "empty(): " << std::boolalpha << l.empty() << std::endl;

	system("pause");
	return 0;
}
catch (const std::string& ex)
{
	std::cerr << ex << std::endl;
	return -1;
}