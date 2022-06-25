#include <iostream>
using namespace std;

int rodCutting (int length[], int price[], int N, int size) {
    int maxProfit[size + 1][N + 1];

    for (int i = 0; i < size + 1; i++) {
        for (int j = 0; j < N + 1; j++) {
            if (i == 0 || j == 0) {
                maxProfit[i][j] = 0;
            } else if (length[i - 1] <= j) {
                maxProfit[i][j] = max (price[i - 1] + maxProfit[i][j - length[i - 1]], maxProfit[i - 1][j]);
            } else {
                maxProfit[i][j] = maxProfit[i - 1][j];
            }
        }
    }
    return maxProfit[size][N];
}

int main() {
    int N = 8;
    int length[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    cout << endl << rodCutting (length, price, N, N) << endl;
    return 0;
}