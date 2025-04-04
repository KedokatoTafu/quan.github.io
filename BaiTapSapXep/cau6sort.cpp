#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// câu 6 phần ứng dụng
void heapify(vector<int>& a, int n, int i, bool mangTang) {
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int largest = i;
	if (mangTang) {
		if (l<n && a[l]>a[largest]) {
			largest = l;
		}
		if (r<n && a[r]>a[largest]) {
			largest = r;
		}
	}
	else {
		if (l<n && a[l]<a[largest]) {
			largest = l;
		}
		if (r<n && a[r]<a[largest]) {
			largest = r;
		}
	}
	if (largest != i ) {
		swap(a[i], a[largest]);
		heapify(a, n, largest, mangTang);
	}
}

void heapSort(vector<int>& a, bool mangtang) {
	int n = a.size();
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(a, n, i,mangtang);
	}
	for (int i = n - 1; i >= 0; i--) {
		swap(a[i], a[0]);
		heapify(a, i, 0, mangtang);
	}
}

void sapxepChanLe(vector<int>& a) {
	vector<int> chan, le, vitri0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == 0) {
			vitri0.push_back(i);
		}
		else if (a[i] % 2 == 0) {
			chan.push_back(a[i]);
		}
		else {
			le.push_back(a[i]);
		}
	}
	heapSort(chan, true);
	heapSort(le, false);

	int chisochan = 0, chisole = 0;
	for (int i = 0; i < a.size(); i++) {
		if (find(vitri0.begin(), vitri0.end(), i) != vitri0.end()) {
			continue;
		}
		if (a[i] % 2 == 0) {
			a[i] = chan[chisochan++];
		}
		else {
			a[i] = le[chisole++];
		}
	}
}
int main() {
	int n; cout << "Nhap kich thuoc: ";
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sapxepChanLe(a);
	for (int x : a) {
		cout << x << " ";
	}
	return 0;
}