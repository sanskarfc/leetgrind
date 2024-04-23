#include <map>
#include <set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  double maxProbability(int n, vector<vector<int>> &edges,
                        vector<double> &succProb, int start_node,
                        int end_node) {
    vector<vector<int>> adj(n);
    map<pair<int, int>, double> prob;
    for (int i = 0; i < edges.size(); i++) {
      adj[edges[i][0]].push_back(edges[i][1]);
      adj[edges[i][1]].push_back(edges[i][0]);
      prob[make_pair(min(edges[i][0], edges[i][1]),
                     max(edges[i][0], edges[i][1]))] = succProb[i];
    }

    set<pair<double, int>> s1;
    map<int, double> ans;

    s1.insert(make_pair(-1, start_node));

    while (!s1.empty()) {
      int cur_node = (*s1.begin()).second;
      double cur_prob = -(*s1.begin()).first;
      s1.erase(make_pair(-cur_prob, cur_node));
      for (auto adjNode : adj[cur_node]) {
        double edgeProb =
            prob[make_pair(min(adjNode, cur_node), max(adjNode, cur_node))];
        if (edgeProb * cur_prob > ans[adjNode]) {
          if (ans[adjNode] != 0) {
            s1.erase(s1.find(make_pair(-ans[adjNode], adjNode)));
          }
          ans[adjNode] = edgeProb * cur_prob;
          s1.insert(make_pair(-ans[adjNode], adjNode));
        }
      }
    }

    return ans[end_node];
  }
};
