#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Need to keep track of index after sort
typedef pair<double, int> myPair;

// Sort descending; if equal take earlier
bool mySort(const myPair &l, const myPair &r) {
  return l.first > r.first;
} 

int main() {
  cin.clear();

  // Read in first line
  int n, m;
  cin>>n;
  cin>>m;

  // Read in data
  double fi[n];
  string si[n];
  for (int i = 0; i < n; i++) {
    cin>>fi[i];
    cin>>si[i];
  }

  // Calculate quality score, keep a copy
  myPair qi[n];
  for (int i = 0; i < n; i++) {
    qi[i] = make_pair(fi[i]*(i+1), i);
  }

  // Sort quality
  stable_sort(qi, qi + n, mySort);

  // Print string by quality index
  for (int i = 0; i < m; i++) {
    cout<<si[qi[i].second]<<endl;
  }

  return 0;
}
