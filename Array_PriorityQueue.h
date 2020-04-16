#ifndef ARRAY_PQ_H
#define ARRAY_PQ_H

#include <iostream>
#include <string>
using namespace std;

inline void Assert(bool exp, string s);

template <typename E> class Array_MaxPriorityQueue {
private:
	E* V;
	int S;
	int maxSize;

public:
	Array_MaxPriorityQueue(int max) {
		V = new E[max];
		S = -1;
		maxSize = max;
	}
	~Array_MaxPriorityQueue() { delete[] V; }

	bool empty() { return (S == -1 ? true : false); }

	void insert(const E& it) {
		Assert(S < maxSize - 1, "Capacity exceeded...!");
		V[S++] = it;
	}

	E getMax_element() {
		Assert(S != -1, "Priority Queue is empty...!");
		int max = 0;
		for (int i = 1; i <= S; i++)
			if (V[max] < V[i])
				max = i;
		swap(V[max], V[S]);
		return V[S--];
	}
};

template <typename E> class Array_MinPriorityQueue {
private:
	E* V;
	int S;
	int maxSize;

public:
	Array_MinPriorityQueue(int max) {
		V = new E[max];
		S = -1;
		maxSize = max;
	}

	~Array_MinPriorityQueue() { delete[] V; }

	bool empty() { return (S == -1 ? true : false); }

	void insert(const E& it) {
		Assert(S < maxSize - 1, "Capacity exceeded...!");
		V[S++] = it;
	}

	E getMin_element() {
		int min = 0;
		for (int i = 0; i <= S; i++)
			if (V[min] > V[i])
				min = i;
		swap(V[min], V[S]);
		return V[S--];
	}

};


#endif // !ARRAY_PQ_H