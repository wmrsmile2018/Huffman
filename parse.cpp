#include "Header.h"

char ** SORT(char* str, int &m)
{
	int i, n = strlen(str);
	char ** mas = new char *[2];
	for (int i = 0; i < 2; i++)
		mas[i] = new char[n];
	for (int i = 0; i < n; i++)
		mas[1][i] = 49;
	for (; *str != 0; str++)
	{
		for (i = 0; i < n && mas[0][i] != *str; i++);
		if (i == n)
		{
			mas[0][m] = *str;
			m++;
		}
		else
			mas[1][i]++;
	}

	return mas;
}

char ** reverse(char** mas, int m)
{
	int t = 0;
	for (int i = 0; i < m; i++)
	{
		int save, max = 0;
		t = i;
		for (; t < m; t++)
		{
			if (mas[1][t] > max)
			{
				max = mas[1][t];
				save = t;
			}
		}
		max = mas[0][i]; mas[0][i] = mas[0][save]; mas[0][save] = max;
		max = mas[1][i]; mas[1][i] = mas[1][save]; mas[1][save] = max;
	}

	mas[0][m] = '\0';
	mas[1][m] = '\0';
	return mas;

}


