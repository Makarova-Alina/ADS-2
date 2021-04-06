// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int cout = 0;
  for (int i = 0; i < len - 1; i++){
    for (int j = i + 1; j < len; j++){
      if ((arr[i] + arr[j]) == value) cout++;
    }
  }
  return cout;
}
int countPairs2(int *arr, int len, int value) {
  int cout = 0, left = 0, right = len, mid;
  while (left < right - 1) {
    mid = (left + right) / 2;
    if (arr[mid] <= value)
      left = mid;
    else
      right = mid;
  }
  len = right;
  for (int i = 0; i < len-1; i++) {
    for (int j = len; j > i; j--) {
      if (arr[i] + arr[j] == value)
        cout++;
    }
  }
  return cout;
}
int countPairs3(int *arr, int len, int value) {
  int left = 0, right = len, mid;
  while (left < right - 1) {
    mid = (left + right) / 2;
    if (arr[mid] <= value)
      left = mid + 1;
    else
      right = mid;
  }
  len = right;
  int cout = 0;
  for (int i = 0; i < len - 1; i++) {
    int left = i, right = len;
    while (left < right - 1) {
      int mid = (left + right) / 2;
      if (arr[i] + arr[mid] == value) {
        cout++;
        int j = mid + 1;
        while (arr[i] + arr[j] == value && j < right) {
          cout++;
          j++;
        }
        j = mid - 1;
        while (arr[i] + arr[j] == value && j > left) {
          cout++;
          j--;
        }
        break;
      }
      if (arr[i] + arr[mid] > value)
        right = mid;
      else
        left = mid;
    }
  }
  return cout;
}
