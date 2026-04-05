// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int c = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                c++;
            }
        }
    }
    return c;
}
int countPairs2(int *arr, int len, int value) {
int c = 0;
    for (int i = 0; i < len - 1; i++) {
        int t = value - arr[i];
        int l = i + 1;
        int r = len;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (arr[m] < t) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        int first = l;
        if (first >= len || arr[first] != t) {
            continue;
        }
        l = first;
        r = len;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (arr[m] <= t) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        int firste = l;
        int num = firste - first;
        c += num;
    }
    return c;
}

int countPairs3(int *arr, int len, int value) {
    int c = 0;
    int l = 0;
    int r = len - 1;
    while (l < r) {
        int sum = arr[l] + arr[r];
        if (sum > value) {
            r--;
        }
        else if (sum < value) {
            l++;
        }
        else {
            if (arr[l] == arr[r]) {
                int k = r - l + 1;
                c += k * (k - 1) / 2;
                break;
            }
            else {
                int val = arr[l];
                int cnl = 0;
                while (l < r && arr[l] == val) {
                    cnl++;
                    l++;
                }
                int var = arr[r];
                int cnr = 0;
                while (l <= r && arr[r] == var) {
                    cnr++;
                    r--;
                }
                c += (cnl * cnr);
            }
        }
    }
    return c;
}
