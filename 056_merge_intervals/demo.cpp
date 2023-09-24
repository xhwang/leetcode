
#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool intervalCompare(const Interval& lhs, const Interval& rhs) {
  return lhs.start < rhs.start;
}

class Solution {

  public:
    vector<Interval> merge(vector<Interval>& intervals) {

      vector<Interval> rel;

      if (intervals.size() == 0)
        return rel;

      sort(intervals.begin(), intervals.end(), intervalCompare);

      Interval last = intervals[0];

      for (size_t i=1; i<intervals.size(); i++) {
        Interval tmp = intervals[i];
        if (last.end >= tmp.start) {
          last.end = max(last.end, tmp.end);
        }
        else {
          rel.push_back(last);
          last = tmp;
        }
      }
      rel.push_back(last);

      return rel;
    }

};


int main() {

  Solution demo = Solution();

  vector<Interval> intervals;

  intervals.push_back(Interval(1, 3));
  intervals.push_back(Interval(2, 6));
  intervals.push_back(Interval(8, 10));
  intervals.push_back(Interval(15, 18));

  vector<Interval> rel = demo.merge(intervals);

  for (auto i:rel) {
    cout<<i.start<<" "<<i.end<<endl;
  }

}

