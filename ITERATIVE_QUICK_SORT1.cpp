#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int partition(int a[],int low,int high){
	int pi = a[low];
	int count=0;
	for(int i=low+1;i<=high;i++){
		if(pi>=a[i]){
			count++;
		}
	}
	int pivot_index= low + count;
	swap(a[low],a[pivot_index]);
	int i = low;
	int j = high;
	while(i<pivot_index && j>pivot_index){
		while(a[i]<a[pivot_index]){
			i++;
		}
		while(a[j]>a[pivot_index]){
			j--;
		}
		if(i<pivot_index && j>pivot_index){
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}
	return pivot_index;
}

void iterative_quick(int a[], int low, int high) {
    stack<pair<int, int>> s;
    s.push({low, high});

    while (!s.empty()) {
        low = s.top().first;
        high = s.top().second;
        s.pop();

        if (low < high) {
            int j = partition(a, low, high);

            if ((j - low) > (high - j)) {
                s.push({j + 1, high});
                s.push({low, j - 1});
            } else {
                s.push({low, j - 1});
                s.push({j + 1, high});
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter size of array=";
    cin >> n;
    int a[n];
    cout << "Enter element in array\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    iterative_quick(a, 0, n - 1);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
