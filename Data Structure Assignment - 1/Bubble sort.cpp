#include <iostream>

using namespace std;

void BSort (int arr[], int n)
{
	int i, j;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n-i-1; ++j)
		{
			if (arr[j] > arr[j+1])
			{
				arr[j] = arr[j]+arr[j+1];
				arr[j+1] = arr[j]-arr[j + 1];
				arr[j] = arr[j]-arr[j + 1];
			}
		}
	}
}

int main()
{
	int n, i;
	cout<<"Enter the numbers which you want to sort : ";
	cin>>n;

	int arr[n];
	for(i = 0; i < n; i++)
	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>arr[i];
	}

	BSort(arr, n);
	cout<<"\nSorted Data in Ascending Oreder :";
	for (i = 0; i < n; i++)
        cout<<arr[i] << " ";
        cout << endl;
}
