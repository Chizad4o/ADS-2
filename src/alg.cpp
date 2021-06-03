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
  int count = 0;
  int pos = len-1;
  while (arr[0] + arr[pos] > value)
    pos--;
  for (int i = 0; i <= pos; i++)
    for (int j = i + 1; j <= pos; j++)
    if (arr[i] + arr[j] == value)
      count++;
  return count;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0, first, last, mid;
  for (int i = 0; i < len - 1; i++) {
    first = i+1;
    last = len - 1;
    mid = (first + last) / 2;
    while (last != first) {
      if (arr[i] + arr[mid] > value) {
        last = mid;
        mid = (first + last) / 2;
      } else if (arr[i] + arr[mid] < value) {
        first = mid + 1;
        mid = (first + last) / 2;
      } else {
        break;
      }
    }
    if (arr[i] + arr[mid] == value) {
      count++;
      int k = mid-1;
      while ((k > i/*-1*/) && (arr[k] + arr[i] == value)) {
        count++;
        k--;
      }
      k = mid + 1;
      while ((k < len) && (arr[k] + arr[i] == value)) {
        count++;
        k++;
      }
    }
  }
  return count;
}
