#pragma once
#include <time.h>
#include <iostream>
#include <string.h>
using namespace std;
class Element
{
	int data;
	char symb;
	Element * straight;
	Element * previous;
	Element * down;
public:
	Element(int a, char b) { symb = b; data = a; straight = 0; down = 0; }
	friend class List;
	friend ostream & operator << (ostream&s, List &a);
};
class List
{
	Element *Ver;
public:
	List() { Ver = 0; }
	void push(char**,int);
	void Dekor(char*,List,char*,int len);
	void Kodir(List a, char * mas, char *,int&);
	friend  ostream & operator << (ostream&s, List &a);
};
char ** SORT(char* str, int &m);
char ** reverse(char** mas, int m);