#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int n, const int Low, const int High, int i, int j)
{
	a[i][j] = Low + rand() % (High - Low + 1);
	if (j < n - 1)
		Create(a, n, Low, High, i, j + 1);
	if (i < n - 1)
		Create(a, n, Low, High, i + 1, 0);
	else
		return;

}
void Print(int** a, const int n, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (j < n - 1)
		Print(a, n, i, j + 1);
	else
	{
		cout << endl;
		if (i < n - 1)
		{
			Print(a, n, i + 1, 0);
		}
		else
			cout << endl;
	}
}


int Search(int** a, const int n, int* iArrOfCountOfZeroValues, int& p, int iCount, int j, int i, bool& umova)
{
	if (j < n)
	{
		if (umova)
		{
			iArrOfCountOfZeroValues[j] = iCount;
			iCount = 0;
			umova = false;
		}
		if (i < n)
		{
			if (a[i][j] == 0)
			{
				iCount++;
				p++;
			}
			Search(a, n, iArrOfCountOfZeroValues, p, iCount, j, i + 1, umova);
		}
		else
		{
			umova = true;
			Search(a, n, iArrOfCountOfZeroValues, p, iCount, j + 1, 0, umova);
		}

	}
	else 
		return iCount;
}

int result(int** a, int* iArrOfCountOfZeroValues, const int n, int iMaxValue, int i, int& index)
{

	if (i < n)
	{

		if (iMaxValue <= iArrOfCountOfZeroValues[i])
		{
			iMaxValue = iArrOfCountOfZeroValues[i];
			index = i;
		}
		result(a, iArrOfCountOfZeroValues, n, iMaxValue, i + 1, index);
	}
	else
		return index - 1;

}

int main()
{
	srand((unsigned)time(NULL));
	int Low = -1;
	int High = 1;
	int n;

	cout << "n = "; cin >> n;
	int* iArrOfCountOfZeroValues = new int[n];
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];

	Create(a, n, Low, High, 0, 0);
	Print(a, n, 0, 0);
	int max1Col = 0;
	int p = 0;
	int i = 0;
	bool umova = true;
	Search(a, n, iArrOfCountOfZeroValues, p, 0, 0, 0, umova);
	int iMaxValue = iArrOfCountOfZeroValues[0];
	//int resultt = 0;
	int index = 0;
	if (p > 0)
		cout << "k = " << result(a, iArrOfCountOfZeroValues, n, iMaxValue, 0, index) << endl;
	else
		cout << "Not 0s elements " << endl;
	

	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}