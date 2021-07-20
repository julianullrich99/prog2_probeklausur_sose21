#ifndef LIST_H
#define LIST_H

template <typename T> class List {
	public:
		List();
		List(List& list);
		~List() {};
		int count();
		void insert(T value);
		void printList();
		T deleteItem();
		void operator=(List *list);

		typedef struct el
		{
			T val;
			struct el* next;
		} elem;

		elem* head;
		
};



#endif