#include "Header.h" 
void List::push(char** b, int m)
{
	Element *pver;
	Element *pdown;
	int a = b[1][m - 1] - 48;
	for (int i = m - 1; i >= 0; i--)
	{
		if (Ver != 0)
		{
			a += b[1][i] - 48;
			pver = new Element(1, a);
			pdown = new Element(0, b[0][i]);
			Ver->previous = pver;
			pver->straight = Ver;
			pdown->previous = pver;
			pver->down = pdown;
			Ver = pver;
		}
		else
		{
			pver = new Element(1, b[0][i]);
			Ver = pver;
			Ver->straight = 0;
			Ver->down = 0;
		}
	}
}

void List::Kodir(List a, char * mas, char *mas1, int &t)
{
	Element * ptr = a.Ver;
	int data1;
	t = 0;
	for (int i = 0; i < strlen(mas1); i++)
	{
		ptr = a.Ver;
		while (ptr->straight != 0)
		{
			if (ptr->down->symb != mas1[i] && ptr->straight->symb != mas1[i])
				ptr = ptr->straight;
			else
			{
				if (ptr->down->symb == mas1[i])
					data1 = ptr->down->data;
				else
					data1 = ptr->straight->data;

				ptr = ptr->down;
				while (ptr->previous->previous != 0)
				{
					mas[t] = ptr->previous->data + 48;
					t++;
					ptr = ptr->previous;
				}
				mas[t] = data1 + 48;
				t++;
				break;
			}
		}
	}
}

void List::Dekor(char* mas, List a, char*str, int len)
{
	Element*ptr = a.Ver;
	int t = 0;
	for (int i = 0; i < len; i++)
	{
		if (0 == mas[i] - 48)
			ptr = ptr->down;
		else
			ptr = ptr->straight;
		if (ptr->straight == 0)
		{
			str[t] = ptr->symb;
			t++;
			ptr = a.Ver;
		}
	}
	str[t] = '\0';
}

ostream & operator << (ostream&s, List &a)
{
	Element *ptr = a.Ver, *ptrsave = ptr;
	int data;
	char symb;
	while (ptrsave->straight != 0)
	{
		ptr = ptrsave->down;
		data = ptr->data;
		symb = ptr->symb;
		while (ptr->previous->previous != 0)
		{
			ptr = ptr->previous;
			s << ptr->data;
		}
		s << data << " - " << symb << endl;
		ptrsave = ptrsave->straight;
	}
	ptr = ptrsave;
	while (ptr->previous != 0)
	{
		s << ptr->data;
		ptr = ptr->previous;
	}
	s << " - " << ptrsave->symb << endl;
	return s;
}
