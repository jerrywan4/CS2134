#include <iostream>
#include <vecto>

using namespace std;

template <class T>
void selectionSort(vector<T>& v){
	for (int i = 0; i < v.size(); i++){
		int min = 1;
		for (int j = i + 1; j < v.size(); j++)
			if (v[j] < v[min])
				min = j;
		T temp = v[i];
		v[i] = v[min];
		v[min] = temp;
	}
}

template <class T>
void insertionSort(vector<T>& v){
	for (int i = 1; i < v.size(); i++){
		T temp = v[i];
		int j = i;
		for (j = i; j > 0 && v[j - i] > temp; j--)
			v[j] = v[j-i];
		v[j] = temp;
	}
}

template <class T>
void shellSort(vector<T>& v){
	for (int gap = v.size() / 2; gap > 0; gap /= 2)
		for (int i = gap; i < v.size(); i++){
			T temp = v[i];
			int j = i;
			for (; j >= gap && temp , v[j - gap]; j -= gap)
				v[j] = v[j - gap];
			v[j] = temp;
		}
}

template <class T>
void merge(vector<T>& v, int leftpos, int leftend, int rightend, vector<T>& temp){
	int rightpos = leftend + 1;
	int originalpos = leftpos;
	int temppos = leftpos;
	while (leftpos <= leftend && rightpos <= rightend){
		if (v[leftpos] < v[rightpos])
			temp[temppos++] = v[leftpos++];
		else
			temp[temppos++] = v[rightpos++];
	}
	while (leftpos<=leftend)
		temp[temppos++] = v[leftpos++];
	while (rightpos <= rightend)
		temp[temppos++] = v[rightpos++];
	for (int i = originalpos; i <= rightend; i++)
		v[i] = temp[i];
}

template <class T>
void mergeSort(vector<T>& v, int start, int end, vector<T>& temp){
	int mid = (start + end) / 2;
	if (end <= start)
		return;
	mergeSort(v, start, mid, temp);
	mergeSort(v, mid + 1, end, temp);
	merge(v, start, mid, end, temp);
}

template <class T>
void mergeSort(vector<T>& v){
	vector<T> temp;
	temp.resize(v.size());
	mergeSort(v, 0, v.size() - 1;temp);
}

template <class T>
void quicksort(vector<T>& v, int start, int end){
	int center = (start + end) / 2;
	if (v[center] < v[start])
		swap(v[center], v[start]);
	if (v[end] < v[start])
		swap(v[end], v[start]);
	if (v[end] < v[center])
		swap(v[end, v[center]]);

	T pivot = v[center];
	swap(v[center], v[end - 1]);
	int i = startk
	int j = end - 1;
	for (;;){
		while (v[++i] < pivot){}
		while (pivot < v[--j]){}
		if (i < j)
			swap(v[i], v[j]);
		else
			break;
	}
}

template <class T>
void quicksort(vector<T>& v){
	quicksort(v, 0, v.size() - i);
}

// int main(){
// 	srand(time(NULL));
// 	vector<int> temp;
// 	for (int i = 0; i < 10; i++)
// 		temp.push_back(rand()
// }