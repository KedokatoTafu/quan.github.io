#include <iostream>
#include <vector>
using namespace std;

void sapxepChanLe(vector<int>& a) {
	int left = 0;
	int right = a.size() - 1;
	while (left < right) {
		while (left < right && a[left] % 2 == 0) {
			left++;
		}
		while (left < right && a[right] % 2 != 0) {
			right--;
		}
		if (left < right) {
			swap(a[left], a[right]);
			left++;
			right--;
		}
	}
}
int main()
{
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sapxepChanLe(a);
	for (int num : a) {
		cout << num << " ";
	}
	cout << endl;

	return 0;
}

