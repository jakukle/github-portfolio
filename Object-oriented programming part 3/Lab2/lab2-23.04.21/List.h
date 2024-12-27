#pragma once
#include <vector>
#include "Point.h"
#include <string>
#include <string.h>
using namespace std;

class List
{
	size_t size;
	struct Node
	{
	public:
		Point point;
		Node * next;
		Node(const Point & p) : point(p.x, p.y, p.z), next(nullptr){}
	};
	Node * first;

	Node * find(const size_t);
	void push(const Point &, const size_t);
	void push(const List &, const size_t);
	void pop(const size_t);
	void multiply(int mnoznik);

public:
	List();
	List(const List&);
	List(const vector<Point>&);
	~List();
	enum Error
	{
		SUCCESS,
		LIST_EMPTY,
		OUT_OF_BOUNDS
	};
	Error pop_front();
	Error pop_back();
	Error push_back(const Point &);
	Error find(Point &, const size_t);
	Error insert(const Point &, const size_t);
	size_t getSize();
	List operator+(const List&);
	List& operator+=(const List&);
	List& operator=(const List&);
	List operator--(int);
	List operator*(int);
	Point& operator[](int);
	List operator++();
	friend ostream& operator<<(ostream& strumien, const List&);
};

