void countingSort(vector<int>& a, int maxVal) {
    vector<int> count(maxVal + 1, 0);

    for (int x : a)
        count[x]++;

    int index = 0;
    for (int i = 0; i <= maxVal; i++) {
        while (count[i]--) {
            a[index++] = i;
        }
    }
}
