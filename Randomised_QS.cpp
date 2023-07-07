#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int Comparisons = 0;
int RandomComparisons = 0;

int partition(vector <int> &arr, int low, int high, bool randomQS)
{
	int pivot = arr[high];
	int i = (low - 1);

	for(int j = low; j <= high - 1; j++) 
	{
		randomQS ? RandomComparisons++ : Comparisons++;
		if (arr[j] < pivot)
		{
		    i++;
		    swap(arr[i], arr[j]);
		}
	}
	
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

int randomPartition(vector <int> &v, int low, int high)
{
	
	int pivot = rand();
	swap(v[pivot], v[high]);	
	
	return partition(v, low, high, true);
}

void QuickSort(vector <int> &arr, int low, int high, bool isRandomQS)
{
    if (low < high) {
  
       int pi = isRandomQS ? randomPartition(arr, low, high) : partition(arr, low, high, isRandomQS);
  
        QuickSort(arr, low, pi - 1, isRandomQS);
        QuickSort(arr, pi + 1, high, isRandomQS);
    }
}

void LearnQuickSort()
{
	const int N = 1001, n = N - 1;
	vector <int> v1(N), v2(N);
	
	for(int i=0;i<N;i++)
	{
		v1[i] = v2[i] = rand();
		//cout << v[i] << ' ';
	}
	
	cout << '\n';
	
	const bool randomQS = true, notRandomQS = false;

	cout << "Starting RandomisedQS" << endl;
	QuickSort(v1, 0, n, randomQS);
	cout << "Starting NormalQS" << endl;
	QuickSort(v2, 0, n, notRandomQS);
	
	cout << "RandomComparisons=" << RandomComparisons << " Comparisons=" << Comparisons << endl;

	Comparisons = RandomComparisons = 0;
}


int main()
{
	cout << "radhe radhe ram ram" << endl;
	int t, i=0;
	cin >> t;
	
	srand(17);	
	while(i++ < t) {
		cout << "TestCase #" << i << ": ";
		LearnQuickSort();
	}
	
}
