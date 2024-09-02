#include<iostream>
using namespace std;
void merge(int data[], int left, int mid, int right)
{
	int lsize = (mid - left) + 1;
	int rsize = right - mid;
	int* ldata = new int[lsize];
	int* rdata = new int[rsize];
	
	for (int i = 0; i < lsize; i++)
	{
		ldata[i] = data[left + i];
	}
	for (int j = 0; j < rsize; j++)
	{
		rdata[j] = data[mid + 1 + j];
	}
	int i = 0;
	int j = 0;
	int k = left;
	while (i < lsize && j < rsize)
	{
		if (ldata[i] <= rdata[j])
		{
			data[k] = ldata[i];
			i++;
		}
		else
		{
			data[k] = rdata[j];
			j++;
		}
		k++;
	}
	while (i < lsize)
	{
		data[k] = ldata[i];
		i++;
		k++;
	}
	while (j < rsize)
	{
		data[k] = rdata[j];
		j++;
		k++;
	}
}
void merge_sort(int data[], int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		merge_sort(data, left, mid);
		merge_sort(data, mid + 1, right);
		merge(data, left, mid, right);
	}
}
int main()
{
	int val = 0;
	cout << "Input size of the array" << endl;
	cin >> val;
	int* data = new int[val];
	cout << "Input elements into the array" << endl;
	for (int i = 0; i < val; i++)
	{
		cin >>data[i];
	}
	cout << "Array elements before sorting" << endl;
	for (int u = 0; u < val; u++)
	{
		cout << data[u] << " ";
	}
	merge_sort(data, 0, val-1);
	cout << "Array elements after sorting:" << endl;
	for (int u = 0; u < val; u++)
	{
		cout << data[u] << " ";
	}
	return 0;
}