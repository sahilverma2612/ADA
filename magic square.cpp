#include <bits/stdc++.h>
#include<vector>
using namespace std;

void magics(vector<vector<int>>& a, int n) {
    int count = 1; // Start with 1
    int i = 0, j = n / 2;
    while (count <= n * n) {
        a[i][j] = count++; 
        int newi = (n+i-1) % n;
        int newj = (j + 1) % n;

        if (a[newi][newj] != 0) { 
            i = (i + 1) % n;       
        } else {
            i = newi;
            j = newj;
        }
    }
}
int main() {
    int n;
    cin >> n;

    if (n % 2 == 0) {
        cout << "Magic square is not possible for even-sized matrices.\n";
        return 0;
    }
    vector<vector<int>> a(n, vector<int>(n, 0));
    magics(a, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

