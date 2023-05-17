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

	void print1()
	{
		for (int i = 1;i <= size;i++)
		{
			if (i <= size / 2)
			{

				cout << "The parent is : " << arr[i] << endl;
				cout << "The left child is : " << arr[2 * i] << endl;
				cout << "The Right child is : " << arr[(2 * i) + 1] << endl;
			}
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

int main()
{
	int n, ch;
	heap h;
	while (1)
	{
		cout << "\n1:Insertion in the heap \n2:Display the heap\n3:Delete from the heap \n4:Display the parents and children\n";
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
			cout << "The Heap is : " << endl;
			h.print1();
			break;
		default:
			cout << "Wrong choice : " << endl;
		}
	}
}
