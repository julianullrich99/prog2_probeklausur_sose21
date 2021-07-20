#include <stdlib.h>
#include "list.h"
#include <iostream>

template <class T> class List;

int main() {

	List<int> integerList;

	std::cout << integerList.count() << std::endl;

	integerList.insert(1);
	integerList.insert(3);
	integerList.insert(2);

	integerList.printList();

	List<int> intList2 = integerList;

	std::cout << integerList.count() << std::endl;
	std::cout << integerList.deleteItem() << std::endl;
	std::cout << integerList.deleteItem() << std::endl;
	std::cout << integerList.count() << std::endl;

	intList2.printList();

	intList2 = &integerList;

	intList2.printList();

	return 0;
}