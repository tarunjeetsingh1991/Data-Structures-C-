#include <iostream>
using namespace std;

void Insert(int A[], int n)
{
	int i = n, temp;
	temp = A[i];
	while (i > 1 && temp > A[i / 2])
	{
		A[i] = A[i / 2];
		i = i / 2;
	}
	A[i] = temp;
}

int Delete(int A[], int n)
{
	int i, j, x, temp, val;
	val = A[1];
	x = A[n];
	A[1] = A[n];
	A[n] = val;
	i = 1;j = i * 2;
	while (j <= n - 1)
	{
		if (j<n - 1 && A[j + 1]>A[j])
			j = j + 1;
		if (A[i] < A[j])
		{
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
			i = j;
			j = 2 * j;
		}
		else
			break;
	}
	return val;
}
int main() 
{
	int H[100000];
	int n;
	cout << "Enter the array size : " << endl;
	cin >> n;
	int i;
	cout << "Enter the array values : " << endl;
	for(i = 1;i <= n;i++)
	{
		H[i] = rand() % 100;
	}
	for (i = 1;i <= n;i++)
		Insert(H, i);

	for (i = n;i > 1;i--)
	{
		Delete(H, i);
	}
	for (i = 1;i <= n;i++)
		cout << H[i] << " ";
	cout << endl;

	return 0;
}