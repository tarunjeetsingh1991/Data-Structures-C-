#include<iostream>
using namespace std;
class heap
{
public:
	int arr[100];
	int size = 0;
	heap()
	{
		arr[0] = -1;
		size = 0;
	}
	void insert(int val)
	{
		size = size + 1;
		int index = size;
		arr[index] = val;

		while (index > 1)
		{
			int parent = index / 2;
			if (arr[parent] < arr[index])
			{
				swap(arr[parent], arr[index]);
				index = parent;
			}
			else
				return;
		}
	}
	void print()
	{
		for (int i = 1;i <= size;i++)
		{
			cout << arr[i] << " ";
		}
	}

	void delete1()
	{
		if (size == 0)
		{
			cout << "Heap is empty. " << endl;
		}
		// put last element to first index
		arr[1] = arr[size];
		// remove last element
		size--;
		// take root node to its correct position
		int i = 1;
		while (i < size)
		{
			int left = 2 * i;
			int right = (2 * i) + 1;
			if (left < size && arr[i] < arr[left])
			{
				swap(arr[i], arr[left]);
				i = left;
			}
			else if (right < size && arr[i] < arr[right])
			{
				swap(arr[i], arr[right]);
				i = right;
			}
			else
			{
				return;
			}
		}
	}

};
void heapify(int arr[], int n, int i)
{
	int largest = i;
	int left = 2 * i;
	int right = (2 * i) + 1;

	if (left <= n && arr[largest] < arr[left])
	{
		largest = left;
	}
	if (right <= n && arr[largest] < arr[right])
	{
		largest = right;
	}

	if (largest != i)
	{
		swap(arr[largest], arr[i]);
		heapify(arr, n, largest);
	}

}

void heapsort(int arr[], int n)
{
	int size = n;
	while (size > 1)
	{
		swap(arr[size], arr[1]);
		size--;
		heapify(arr, size, 1);
	}
}

 void mergeHeaps(int a[], int b[], int n, int m)
 {

	int merged[100];

	for (int i = 0; i < n; i++) 
	{
		merged[i] = a[i];
	}

	for (int i = 0; i < m; i++) 
	{
		merged[i + n] = b[i];
	}

	int k = m + n;

	for (int i = (k / 2) - 1; i >= 0; i--) 
	{

		heapify(merged, k, i);
	}

	for (int i = 0; i < k; i++)
	{
		cout << merged[i] << " ";
	}

}

int main()
{
	int n, ch;
	heap h;
	while (1)
	{
		cout << "\n1:Insertion in the heap \n2:Display the heap\n3:Delete from the heap\n4:Heapify and Heap sort.\n5:Merge 2 heaps.\n";
		cout << "\nEnter Your Choice:";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "Enter values to be inserted : " << endl;
			cin >> n;
			h.insert(n);
			break;
		case 2:
			cout << "The Heap is : " << endl;
			h.print();
			break;
		case 3:
			cout << "Delete Operation : " << endl;
			h.delete1();
			h.print();
			break;
		case 4:
			cout << "Enter the array size : " << endl;
			int n;
			cin >> n;

			int arr[100];

			cout << "Enter the array values : " << endl;
			for (int i = 1;i <= n;i++)
			{
				cin >> arr[i];
			}

			cout << "The array is : " << endl;
			for (int i = 1;i <= n;i++)
			{
				cout << arr[i] << " ";
			}
			cout << endl;

			cout << "Heapify operation : " << endl;
			for (int i = n / 2;i > 0;i--)
			{
				heapify(arr, n, i);
			}

			cout << "After heapify, printing the heap : " << endl;
			for (int i = 1;i <= n;i++)
			{
				cout << arr[i] << " ";
			}
			cout << endl;

			cout << "Heap Sort : " << endl;
			heapsort(arr, n);
			cout << "Printing the sorted array : " << endl;
			for (int i = 1;i <= n;i++)
			{
				cout << arr[i] << " ";
			}
			cout << endl;

			break;
		case 5:
			cout << "Enter the first array size : " << endl;
			int m1;
			cin >> m1;

			int arr1[100];

			cout << "Enter the array values : " << endl;
			for (int i = 0;i < m1;i++)
			{
				cin >> arr1[i];
			}

			cout << "The array is : " << endl;
			for (int i = 0;i < m1;i++)
			{
				cout << arr1[i] << " ";
			}
			cout << endl;

			cout << "Enter the second array size : " << endl;
			int m2;
			cin >> m2;

			int arr2[100];

			cout << "Enter the array values : " << endl;
			for (int i = 0;i < m2;i++)
			{
				cin >> arr2[i];
			}

			cout << "The array is : " << endl;
			for (int i = 0;i < m2;i++)
			{
				cout << arr2[i] << " ";
			}
			cout << endl;
			mergeHeaps(arr1, arr2, m1, m2);

			break;

		default:
			cout << "Wrong choice : " << endl;
		}
	}
}
