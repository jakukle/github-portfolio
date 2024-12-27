#include "List.h"
#include <iostream>



List::Node * List::find(const size_t idx)
{
	Node * node = first;

	for (size_t i = 0; i < idx; i++)
	{
		node = node->next;
	}    
	
	return node;
}

void List::push(const Point & point, const size_t idx)
{
	if (idx == 0)
	{
		Node * tail = first;
		first = new Node(point);
		first->next = tail;
	}
	else
	{
		Node * prev = find(idx - 1);
		Node * tail = prev->next;
		prev->next = new Node(point);
		prev->next->next = tail;
	}
	size++;
}

void List::push(const List & list, const size_t idx)
{
	List copy(list);
	Node * it = copy.first;
	if (idx == 0)
	{
		Node * tail = first;
		Node * last = nullptr;
		if (it)
		{
			first = new Node(it->point);
			last = first;
			it = it->next;
		}
		while (it)
		{
			last->next = new Node(it->point);
			last = last->next;
			it = it->next;
		}
		if(last) last->next = tail;
	}
	else
	{
		Node * prev = find(idx - 1);
		Node * tail = prev->next;
		while (it)
		{
			prev->next = new Node(it->point);
			prev = prev->next;
			it = it->next;
		}
		prev->next = tail;
	}
	size += list.size;
}

void List::pop(const size_t idx)
{
	if (idx == 0)
	{
		Node * tail = first->next;
		delete first;
		first = tail;
	}
	else
	{
		Node * prev = find(idx - 1);
		Node * tail = prev->next->next;
		delete prev->next;
		prev->next = tail;
	}
	size--;
}

List::List() : size(0), first(nullptr){}

List::List(const List & list) : size(list.size), first(nullptr)
{
	Node * it = list.first;
	Node * last = first;
	if (it)
	{
		first = new Node(it->point);
		last = first;
		it = it->next;
	}
	while (it)
	{
		last->next = new Node(it->point);
		last = last->next;
		it = it->next;
	}
}

List::List(const vector<Point>& wektor)
{
	int j = 0;
	while (j<wektor.size())
	 {
		if (j == 0)
			first = new Node(wektor[j]);
		else {
			Node* poprzedni = find(j - 1);
			(*poprzedni).next = new Node(wektor[j]);
		}
	}
	size = wektor.size();
}
void List:: multiply(int mnoznik)
{
	if (mnoznik > 0)
	{
		for (int i = 1; i <= mnoznik; i++)
		{
			for (int j = 0; j < size; j++)
			{
				Point kopiaPunktu = find(j)->point;
				push_back(kopiaPunktu);
			}
			size += size;
		}	
	}
}

List::~List()
{
	while (size) pop(0);
}


List::Error List::pop_front()
{
	List::Error error = List::Error::SUCCESS;

	if (size == 0)
	{
		error = List::Error::LIST_EMPTY;
	}
	else
	{
		pop(0);
	}

	return error;
}

List::Error List::pop_back()
{
	List::Error error = List::Error::SUCCESS;

	if (size == 0)
	{
		error = List::Error::LIST_EMPTY;
	}
	else
	{
		pop(size-1);
	}

	return error;
}

List::Error List::push_back(const Point & punkt)
{
	List::Error error = List::Error::SUCCESS;
	push(punkt,size);
	return error;
}

List::Error List::find(Point& punkt, const size_t numer)
{
	List::Error error = List::Error::SUCCESS;

	if (size == 0)
	{
		error = List::Error::LIST_EMPTY;
	}
	else if (numer > size-1)
	{
		error = List::Error::OUT_OF_BOUNDS;
	}
	else
	{
		Node * wsk;
	    wsk = find(numer);
		punkt = wsk->point;
		//punkt = (*wsk).point;
    }
	return error;
}

List::Error List::insert(const Point& punkt,const size_t numer)
{
	List::Error error = List::Error::SUCCESS;

	if (size == 0)
	{
		error = List::Error::LIST_EMPTY;
	}
	else if (numer > size)
	{
		error = List::Error::OUT_OF_BOUNDS;
	}
	else
	{
		push(punkt, numer);
	}

	return error;
}


size_t List::getSize()
{
	return size;
}

List List::operator+(const List& list)
{
	List copy(*this);
	copy.push(list, copy.size);
	return copy;
}

List& List::operator+=(const List& list)
{
	push(list, size);
	return *this;
}

List & List::operator=(const List & list)
{
	List copy(list);
	this->~List(); 
	push(copy, 0);
	return *this;
}

List List::operator--(int)
{
	List copy(*this);
	pop_back();
	return copy;
}

List List::operator*(int mnoznik)
{
	List copy(*this);
	copy.multiply(mnoznik);
	return copy;
}

Point& List::operator[](int x)
{
	Point& point = find(x)->point;
	return point;
}

List List::operator++()
{
	List copy(*this);
	int  j;
	for (j = 0; j < size; j++) 
		copy.pop(j);
	return copy;
}
                                                                                                                              
ostream& operator<<(ostream& strumien, const List& lista)
{
	string napis;
	int j = 0;
	List copy(lista);
	while (j < copy.size) {
		napis = "x: " + to_string(copy.find(j)->point.x) + " y: " + to_string(copy.find(j)->point.y) + " z: " + to_string(copy.find(j)->point.z) + "\n";
		j++;
	}
	strumien << napis;
	return strumien;
}