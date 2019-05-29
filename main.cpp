#include "Header.h"

void main()
{
	const int n = 100000;
	int m = 0;
	char mas[n];
	cin >> mas;
	char ** mas1 = SORT(mas, m);
	mas1 = reverse(mas1, m);
	cout << endl << endl;
	for (int i = 0; i < m; i++)
	{
		cout <<"["<< mas1[0][i]<<"]" << " frequence " << "[" << mas1[1][i] << "]";
		cout << endl;
	}
	cout << endl << endl;
	float begin = clock();
	List r;
	r.push(mas1, m);
	cout << r;
	cout << endl << endl;

	int len;
	char mas2[n];
	r.Kodir(r, mas2, mas, len);
	for (int i = 0; i < len; i++)
		cout << mas2[i];
	cout << endl << endl;

	char result[n];

	char test[100];
	cin >> test;
	r.Dekor(test, r, result, strlen(test));
	cout << result << endl << endl;
	float end = clock();
	cout << endl << "Time: " << (end - begin)/(float)CLOCKS_PER_SEC<<endl;
	system("pause");
}