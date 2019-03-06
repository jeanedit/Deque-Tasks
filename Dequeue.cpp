#include<stdio.h>
template<class T>
class Node
{
public:
	T val;
	Node*next;
	Node(T value)
	{
		val = value;
		next = NULL;
	}
	~Node()
	{
		delete next;
	}
};

template<class T>
class List
{
public:
	Node<T>*head;
	Node<T>*tail;
	List()
	{
		head = NULL;
		tail = NULL;
	}
	~List()
	{
		delete head;
		delete tail;
	}
};

template<class T>
class Deque
{
public:
	List<T> * list;
	int deqsize;
	Deque()
	{
		list = new List<T>();
		deqsize = 0;
	}

	void add_front(T item)
	{
		Node<T>*node = new Node<T>(item);
		if (list->head == NULL)
		{
			list->head = node;
			list->tail = node;
		}
		node->next = list->head;
		list->head = node;
		list->tail->next = NULL;
		deqsize++;
	}

	void add_tail(int item)
	{
		Node<T>*node = new Node<T>(item);
		if (list->tail == NULL)
		{
			list->head = node;
			list->tail = node;
		}
		list->tail->next = node;
		list->tail = node;
		deqsize++;
	}

	T remove_front()
	{
		Node<T>*node = new Node<T>(0);
		if (list->head == NULL) return -1;
		if (list->head == list->tail)
		{
			node = list->head;
			list->head = NULL;
			list->tail = NULL;
			deqsize--;
			return node->val;
		}
		node = list->head;
		list->head = list->head->next;
		deqsize--;
		return node->val;
	}

	T remove_tail()
	{
		Node<T>*node = new Node<T>(0);
		Node<T>*node1 = new Node<T>(0);
		if (list->tail == NULL) return -1;
		node = list->head;
		if (list->head == list->tail)
		{
			node = list->tail;
			list->head = NULL;
			list->tail = NULL;
			deqsize--;
			return node->val;
		}
		while (node->next != list->tail)
		{
			node = node->next;
		}
		node1 = list->tail;
		list->tail = node;
		deqsize--;
		return node1->val;
	}

	int size()
	{
		return deqsize;
	}
	~Deque()
	{
		delete list;
	}
};


// checking words 
bool is_palindrome(const char*word)
{
	Deque<char>*deq = new Deque<char>();
	int i = 0;

	while (word[i] != '\0')
	{
		if (word[i] == ' ') i++;
		deq->add_tail(word[i]);
		i++;
	}

	if (deq->size() % 2 == 0)
	{
		while (deq->size() != 2)
		{
			if (deq->remove_front()!= deq->remove_tail())
				return false;
		}
	}
	else
	{
		while (deq->size() != 1)
		{
			if (deq->remove_front() != deq->remove_tail())
				return false;
		}
	}

	return true;
}


int main()
{
	printf("Tesing palindrome function\n\n");
	if (is_palindrome("no lemon no melon")) printf("Palindrome\n\n");

	//test for add_tail and remove_tail functions
	Deque<int>*deq = new Deque<int>();
	for (int i = 0; i < 5; ++i)
	{
		deq->add_tail(1+i*i*i);
	}

	printf("Testing add_tail and remove_tail\n\nHead:%i\tTail:%i\n", deq->list->head->val, deq->list->tail->val);
	
	printf("Delete:%i\tSize:%i\tHead:%i\tTail:%i\n", deq->remove_tail(),deq->size(),deq->list->head->val,deq->list->tail->val);
	printf("Delete:%i\tSize:%i\tHead:%i\tTail:%i\n", deq->remove_tail(), deq->size(), deq->list->head->val, deq->list->tail->val);
	printf("Delete:%i\tSize:%i\tHead:%i\tTail:%i\n", deq->remove_tail(), deq->size(), deq->list->head->val, deq->list->tail->val);
	printf("Delete:%i\tSize:%i\tHead:%i\tTail:%i\n", deq->remove_tail(), deq->size(), deq->list->head->val, deq->list->tail->val);
	printf("Delete:%i\tSize:%i\tHead:%i\tTail:%i\n", deq->remove_tail(), deq->size(), deq->list->head->val, deq->list->tail->val);
	printf("Delete:%i\tSize:%i\tHead:%i\tTail:%i\n\n", deq->remove_tail(), deq->size(), deq->list->head, deq->list->tail);

	//test for add_front and remove_front operations
	Deque<int>*deq_v1 = new Deque<int>();
	for (int i = 0; i < 5; ++i)
	{
		deq->add_front(1 + i * i*i);
	}

	printf("Testing add_front and remove_front\n\nHead:%i\tTail:%i\n", deq->list->head->val, deq->list->tail->val);

	printf("Delete:%i\tSize:%i\tHead:%i\tTail:%i\n", deq->remove_front(), deq->size(), deq->list->head->val, deq->list->tail->val);
	printf("Delete:%i\tSize:%i\tHead:%i\tTail:%i\n", deq->remove_front(), deq->size(), deq->list->head->val, deq->list->tail->val);
	printf("Delete:%i\tSize:%i\tHead:%i\tTail:%i\n", deq->remove_front(), deq->size(), deq->list->head->val, deq->list->tail->val);
	printf("Delete:%i\tSize:%i\tHead:%i\tTail:%i\n", deq->remove_front(), deq->size(), deq->list->head->val, deq->list->tail->val);
	printf("Delete:%i\tSize:%i\tHead:%i\tTail:%i\n", deq->remove_front(), deq->size(), deq->list->head->val, deq->list->tail->val);
	printf("Delete:%i\tSize:%i\tHead:%i\tTail:%i\n\n", deq->remove_front(), deq->size(), deq->list->head, deq->list->tail);



	//test for add_front and remove_tail functions
	Deque<int>*deq_v2 = new Deque<int>();
	for (int i = 0; i < 5; ++i)
	{
		deq->add_front(1 + i * i*i);
	}

	printf("Testing add_front and remove_tail\n\nHead:%i\tTail:%i\n", deq->list->head->val, deq->list->tail->val);

	printf("Delete:%i\tSize:%i\tHead:%i\tTail:%i\n", deq->remove_tail(), deq->size(), deq->list->head->val, deq->list->tail->val);
	printf("Delete:%i\tSize:%i\tHead:%i\tTail:%i\n", deq->remove_tail(), deq->size(), deq->list->head->val, deq->list->tail->val);
	printf("Delete:%i\tSize:%i\tHead:%i\tTail:%i\n", deq->remove_tail(), deq->size(), deq->list->head->val, deq->list->tail->val);
	printf("Delete:%i\tSize:%i\tHead:%i\tTail:%i\n", deq->remove_tail(), deq->size(), deq->list->head->val, deq->list->tail->val);
	printf("Delete:%i\tSize:%i\tHead:%i\tTail:%i\n", deq->remove_tail(), deq->size(), deq->list->head->val, deq->list->tail->val);
	printf("Delete:%i\tSize:%i\tHead:%i\tTail:%i\n\n", deq->remove_tail(), deq->size(), deq->list->head, deq->list->tail);

	//test for add_front and remove_tail operations
	Deque<int>*deq_v3 = new Deque<int>();
	for (int i = 0; i < 5; ++i)
	{
		deq->add_tail(1 + i * i*i);
	}

	printf("Testing add_tail and remove_front\n\nHead:%i\tTail:%i\n", deq->list->head->val, deq->list->tail->val);

	printf("Delete:%i\tSize:%i\tHead:%i\tTail:%i\n", deq->remove_front(), deq->size(), deq->list->head->val, deq->list->tail->val);
	printf("Delete:%i\tSize:%i\tHead:%i\tTail:%i\n", deq->remove_front(), deq->size(), deq->list->head->val, deq->list->tail->val);
	printf("Delete:%i\tSize:%i\tHead:%i\tTail:%i\n", deq->remove_front(), deq->size(), deq->list->head->val, deq->list->tail->val);
	printf("Delete:%i\tSize:%i\tHead:%i\tTail:%i\n", deq->remove_front(), deq->size(), deq->list->head->val, deq->list->tail->val);
	printf("Delete:%i\tSize:%i\tHead:%i\tTail:%i\n", deq->remove_front(), deq->size(), deq->list->head->val, deq->list->tail->val);
	printf("Delete:%i\tSize:%i\tHead:%i\tTail:%i\n\n", deq->remove_front(), deq->size(), deq->list->head, deq->list->tail);
}
