int Solution::books(vector<int> &A, int B) {
  // binary search on the max pages allocated to student
  int lo = 0;
  int hi = 1e9;
  int n = A.size();
  if (B > n) {
    return -1;
  }
  while (hi - lo > 5) {
    int mid = lo + (hi - lo) / 2;
    // now do allocation such that no student gets more than "mid" pages
    // get as close to "mid" as possible
    long long int sum = 0;
    int stud = 0;
    for (int i = 0; i < n; i++) {
      if (sum + A[i] > (long long int)mid) {
        if (A[i] > mid) { // this is less, we want max pages to be more
          lo = mid + 1;
          break;
        } else {
          stud++;
          sum = A[i];
        }
      } else {
        sum += A[i];
      }
    }
    if (lo == mid + 1) {
      continue;
    }
    stud++;
    if (stud > B) {
      lo = mid + 1;
      continue;
    }
    hi = mid;
  }
  int i;
  for (i = lo; i <= hi; i++) {
    bool check = false;
    int sum = 0;
    int stud = 0;
    for (int j = 0; j < n; j++) {
      if (sum + A[j] > (long long int)i) {
        if (A[j] > i) {
          check = true;
          break;
        } else {
          sum = A[j];
          stud++;
        }
      } else {
        sum += A[j];
      }
    }
    if (check) {
      continue;
    }
    stud++;
    if (stud <= B)
      break;
  }
  return i;
}
