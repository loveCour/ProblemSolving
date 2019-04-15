#pragma once
#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;

template <typename T>
inline bool comp(const T a, const T b) {
	return a < b;
}

template <typename T>
void QS(int size, T* dstArray) {
	stack<int> SortRangeStack;
	SortRangeStack.push(size - 1);
	SortRangeStack.push(0);

	int pivotIdx;
	T pivot;
	while (SortRangeStack.size() > 0) {
		int start = SortRangeStack.top();
		SortRangeStack.pop();
		int end = SortRangeStack.top();
		SortRangeStack.pop();
		int i = start;
		int j = end;

		pivotIdx = ((end - start) >> 1) + start;
		pivot = dstArray[pivotIdx];
		swap(dstArray[pivotIdx], dstArray[i]);
		pivotIdx = i;
		i++;

		while (i < j)
		{
			while (comp(dstArray[i], pivot) && i < j) {
				++i;
			}
			while (!comp(dstArray[j], pivot) && i < j) {
				--j;
			}
			if (i < j)
			{
				swap(dstArray[i], dstArray[j]);
				++i;
				--j;
			}
		}
		if (comp(dstArray[j], pivot))
		{
			swap(dstArray[pivotIdx], dstArray[j]);
		}
		if (end - i > 0)
		{
			SortRangeStack.push(end);
			SortRangeStack.push(i);
		}
		if (j - 1 - start > 0)
		{
			SortRangeStack.push(j - 1);
			SortRangeStack.push(start);
		}
	}
}

int main()
{
	int n;
	cin >> n;
	
	pair<int, int> table[1000000];
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &table[i].first, &table[i].second);
	}
	QS(n, table);
	for (int i = 0; i < n; ++i) {
		printf("%d %d\n", table[i].first, table[i].second);
	}
	return 0;
}
