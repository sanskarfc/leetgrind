class TimeMap {
public:
  map<string, vector<pair<int, string>>> m2;
  TimeMap() {}

  void set(string key, string value, int timestamp) {
    m2[key].push_back(make_pair(timestamp, value));
  }

  string get(string key, int timestamp) {
    if (m2.find(key) == m2.end()) {
      return "";
    }

    auto &vec = m2[key];
    auto it =
        lower_bound(vec.begin(), vec.end(), make_pair(timestamp, ""),
                    [](const pair<int, string> &a, const pair<int, string> &b) {
                      return a.first < b.first;
                    });

    if (it == vec.end() || it->first > timestamp) {
      if (it == vec.begin()) {
        return "";
      }
      --it;
    }

    return it->second;
  }
};
