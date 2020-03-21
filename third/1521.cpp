#include <iostream>

int find_mth_max(int tree[], int m, int n_max) {
    int x = 1;

    while (2 * x < n_max) {
        if (tree[x * 2] >= m) {
            x *= 2;
        }
        else {
            m -= tree[x * 2];
            x = x * 2 + 1;
        }
    }
    if (tree[x] == 2)
        return tree[2 * x + m - 1];
    else
    if (tree[2 * x + 1] != 0)
        return tree[2 * x + 1];
    else
        return tree[2 * x];
}

int main() {
    int n, k;
    std::cin >> n;
    std::cin >> k;

    if (n == 1) {
        std::cout << 1;
        return 0;
    }

    int n_max = 1;
    while (n_max < n)
        n_max <<= 1;
    int* tree_data = new int[2 * n_max];


    for (int i = 0; i < n; i++)
        tree_data[n_max + i] = i + 1;
    for (int i = n_max - 1; i > 0; i--) {
        if (2 * i >= n_max) {
            tree_data[i] = 0;
            if (tree_data[2 * i] != 0)
                tree_data[i]++;
            if (tree_data[2 * i + 1] != 0)
                tree_data[i]++;
        }
        else
            tree_data[i] = tree_data[2 * i] + tree_data[2 * i + 1];
    }

    int prev = 0;
    while (n > 0) {
        prev = (prev + k - 1) % n;
        n--;
        int index = find_mth_max(tree_data, prev + 1, n_max);
        std::cout << index << " ";
        tree_data[n_max + index - 1] = 0;

        int j = n_max + index - 1;
        while (j > 1) {
            j /= 2;
            tree_data[j]--;
        }
    }

    return 0;
}