// Copyright 2021 NNTU-CS
int sizeEdge (int* arr, int size, int value) {
  for (int i = 0; i < size; ++i) {
    if (arr[i] > value) {
      return i;
      break;
    }
  }
  return 0;
}
int cbinsearch (int* arr, int size, int value) {
  int count = 0;
  int first = 0;
  int last = size - 1;
  int mid = 0;
  while (first <= last) {
    mid = (first + last) / 2;
    if (arr[mid] == value) {
      ++count;
      int index = mid - 1;
      while (index >= first && arr[index] == value) {
        ++count;
        --index;
      }
      index = mid + 1;
      while (index <= last && arr[index] == value) {
        ++count;
        --index;
      }
      return count;
    } else if (arr[mid] < value) {
      first = mid + 1;
    } else {
      last = mid - 1;
    }
  }
  return 0;
}
int countPairs1 (int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (value == arr[i] + arr[j]) {
        count++;
      }
    }
  }
  return count;
}
int countPairs2 (int *arr, int len, int value) {
  int count = 0;
  len = sizeEdge(arr, len, value);
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      ++count;
    }
  }
  return count;
}
int countPairs3 (int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    int n = value - arr[i];
    count += cbinsearch(arr + i + 1, len - i - 1, n);
  }
  return count;
}
