#include <stdlib.h>
#include "list.h"
#include <iostream>

template <class T> class List;

int main() {

	List<int> integerList = List<int>();

	std::cout << integerList.count() << std::endl;

	integerList.insert(1);
	integerList.insert(3);
	integerList.insert(2);

	std::cout << integerList.count() << std::endl;
	std::cout << integerList.deleteItem() << std::endl;
	std::cout << integerList.deleteItem() << std::endl;
	std::cout << integerList.count() << std::endl;

	return 0;
}