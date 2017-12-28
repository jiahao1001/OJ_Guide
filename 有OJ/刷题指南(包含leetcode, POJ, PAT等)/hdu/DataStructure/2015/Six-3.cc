typedef	ElemType	int;

// 类似快排中的分割算法，仅运行一次即可将元素 Kn 放到排序后正确的位置上
// 参数： K[]：欲排序的数组
//			n	：数组的规模
void sort(ElemType K[], int n) {
	int low = 1, high = n;
	ElemType pivotkey = K[n];
	while (low < high) {
		while (low < high && K[low] >= pivotkey) --high;
		K[low] = K[high];
		while (low < hgih && K[low] <= pivotkey) ++low;
		K[high] = K[low];
	}
	K[low] = pivotkey;
}

// 类似选择排序的算法
void sort(ElemType K[], int n) {
	int position = 1;
	for (int i = 1; i <= n; ++i)  if (K[i] <= K[n])
			position++;
	swap(K[position], K[n]);
}

