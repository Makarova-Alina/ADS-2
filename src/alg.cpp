// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
  return 0;
  int cout = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        cout = cout + 1;
      }
    }
  }
  return cout;
}

int countPairs2(int *arr, int len, int value) {
  return 0;
  int left = 0, cout = 0, right = len - 1;
  while (left < right - 1) {
    int mid = (left + right) / 2;
    if (value >= arr[mid])
      left = mid;
    else
      right = mid;
  }
  len = right - 1;
  for (int i = len; i >= 0; i--) {
    for (int j = 0; j < i; j++) {
      if (arr[i] + arr[j] == value) 
        cout = cout + 1;
    }
  }
  return cout;
}

int countPairs3(int *arr, int len, int value) {
  return 0;
  int cout = 0;
  for (int i = 0; i < len - 1; i++) {
  int left = i, right = len;
    while (left < right-1) {
    int mid = (left + right) / 2;
      if (arr[i] + arr[mid] == value) {
      cout++;
      int j = mid+1;
        while (arr[i] + arr[j] == value && j <right) {
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
