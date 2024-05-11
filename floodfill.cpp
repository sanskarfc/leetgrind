class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int color) {
    vector<int> x = {1, -1, 0, 0};
    vector<int> y = {0, 0, 1, -1};
    int m = image.size();
    int n = image[0].size();
    stack<pair<int, int>> s1;
    int ori = image[sr][sc];
    if (ori == color)
      return image;
    s1.push(make_pair(sr, sc));
    while (!s1.empty()) {
      image[sr][sc] = color;
      pair<int, int> p = s1.top();
      s1.pop();
      int row = p.first;
      int col = p.second;
      for (int k = 0; k < 4; k++) {
        int rowNew = row + y[k];
        int colNew = col + x[k];
        if (rowNew < 0 || rowNew >= m || colNew < 0 || colNew >= n) {
          continue;
        }
        if (image[rowNew][colNew] == ori) {
          image[rowNew][colNew] = color;
          s1.push(make_pair(rowNew, colNew));
        }
      }
    }
    return image;
  }
};
