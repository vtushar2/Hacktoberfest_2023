#include <iostream>
#include <vector>

using namespace std;

vector<int> b;

void merge(vector<int>& v, int beg, int mid, int end) {
    int i = beg, k = beg, j = mid + 1;
    while (i <= mid && j <= end) {
        if (v[i] > v[j])
            b[k++] = v[j++];
        else
            b[k++] = v[i++];
    }
    while (i <= mid)
        b[k++] = v[i++];
    while (j <= end)
        b[k++] = v[j++];
    for (int l = beg; l <= end; l++)
        v[l] = b[l];
}

void merge_sort(vector<int>& v, int beg, int end) {
    if (beg < end) {
        int mid = (beg + end) / 2;
        merge_sort(v, beg, mid);
        merge_sort(v, mid + 1, end);
        merge(v, beg, mid, end);
    }
}

void display(vector<int>& v) {
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of elements : ";
    cin >> n;
    vector<int> v(n);
    b.resize(n);
    cout << "Enter " << n << " elements :" << endl;
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    merge_sort(v, 0, n - 1);
    display(v);
    return 0;
}
