#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end);

int main()
{
	vector<int> v = { 6, 4, 7, 6, 4, 4, 0, 1 };
	MergeSort(begin(v), end(v));
	for (int x : v) {
		cout << x << " ";
	}
	cout << endl;
	//system("pause");
	return 0;
}

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {

	if (range_end - range_begin < 3)
	{
		return;
	}

	vector<typename RandomIt::value_type> elements(range_begin, range_end);

	auto first_new_range = begin(elements) + elements.size() / 3;
	auto second_new_range = first_new_range + elements.size() / 3;

	MergeSort(begin(elements), first_new_range);
	MergeSort(first_new_range, second_new_range);
	MergeSort(second_new_range, end(elements));

	vector<typename RandomIt::value_type>temp;

	merge(begin(elements), first_new_range, first_new_range, second_new_range, back_inserter(temp));
	merge(begin(temp), end(temp), second_new_range, end(elements), range_begin);

}