#include "Array_PriorityQueue.h"
#include "Heap_Sort.h"
#include <cstdlib>
#include <ctime>

int main(int argc, char* argv[2]) {
	if (argc < 2) exit(-1);
	srand(time(NULL));
	Heap_MaxPriorityQueue<int> maxPQ(atoi(argv[1]));
	Heap_MinPriorityQueue<int> minPQ(atoi(argv[2]));
	int n;

	for (int i = 0; i < atoi(argv[1]); i++) {
		n = 1 + rand() % 50;
		cout << n << " ";
		maxPQ.insert(n);
	}
	cout << endl;
	for (int i = 0; i < atoi(argv[2]); i++) {
		n = 1 + rand() % 50;
		cout << n << " ";
		minPQ.insert(n);
	}
	cout << endl;

	cout << "maxPQ :" << endl;
	maxPQ.print();
	cout << "minPQ :" << endl;
	minPQ.print();

	//cout << "Max element of maxPQ = " << maxPQ.getMax_element() << endl;
	//cout << "Min element of minPQ = " << minPQ.getMin_element() << endl;

	cout << "maxPQ :" << endl;
	maxPQ.print();
	cout << "minPQ :" << endl;
	minPQ.print();

	int* arr = new int[atoi(argv[1])];
	cout << "Creating array of " << atoi(argv[1]) << " elements..." << endl;
	for (int i = 0; i < atoi(argv[1]); i++)
		arr[i] = rand() % 200;

	cout << "Heap Sort on maxPQ : " << endl;
	Heap_Sort(arr, 0, atoi(argv[1]) - 1);
	for (int i = 0; i < atoi(argv[1]); i++)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}