// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
 int count = 0;
	for (int i = 0; i < len - 1; ++i) {
      for (int j = i + 1; j < len; ++j) {
	        if (arr[i] + arr[j] == value) {
	            ++count;
	        }
	    }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int Pres = 0;
    int count = 0;
    while (arr[len - 1] > value && len > 0) {
        --len;
    }
    if (!len) {
        return 0;
    }
    for (int j = len - 1; j >= 0; --j) {
        Pres = 0;
        for (int Pres = 0; Pres < j; ++Pres) {
            if (arr[Pres] + arr[j] == value)
                ++count;
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        int leftBorder = i + 1, rightBorder = len;
        while (leftBorder < rightBorder) {
            int center = (leftBorder + rightBorder) / 2;
            if (arr[center] == (value - arr[i])) {
                while (arr[center - 1] == (value - arr[i]) && (center > leftBorder)) {
                    --center;
                }
                while (arr[center] == (value - arr[i])) {
                    ++center;
                    ++count;
                }
                break;
            } else if (arr[center] > (value - arr[i])) {
                rightBorder = center;
            } else {
                leftBorder = center + 1;
            }
        }
    }
}
