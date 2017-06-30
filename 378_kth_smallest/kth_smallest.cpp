#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVectors(vector<vector<int>> vectors);

class Solution {
  
public:

  struct Node {
    int row;
    int col;
    int value;
    Node(int r, int c, int v): row(r), col(c), value(v) {}
  };

  struct Comp {

    bool operator()(Node& one, Node& two) {
      return one.value > two.value;
    }
  
  };


  int kthSmallest(vector<vector<int>>& matrix, int k) {

    int n = matrix.size();

    vector<Node> elements;

    for(int i=0; i<n; i++) {
      Node t = Node(0, i, matrix[0][i]);
      elements.push_back(t);
    }

    make_heap(elements.begin(), elements.end(), Comp());

    Node t(0,0,0);

    for(int i=0; i<k; i++) {

      // log(n)
      pop_heap(elements.begin(), elements.end(), Comp());

      t = elements.back();
      elements.pop_back();
      cout<<t.value<<endl;

      if(t.row + 1 < n) {
        Node t_next = Node(t.row+1, t.col, matrix[t.row+1][t.col]);
        elements.push_back(t_next);
        // log(n)
        push_heap(elements.begin(), elements.end(), Comp());
      }
    
    }

    return t.value;
  }

};

void print1DVector(vector<int> v) {

  for(int n: v) {
    cout<<n<<" ";
  }
  cout<<endl;

}

void printVectors(vector<vector<int>> vectors) {

  for(vector<int> v: vectors) {
    for(int n: v) {
      cout<<n<<" ";
    }
    cout<<endl;
  }

}

void test() {

  vector<int> test = {7, 6, 5, 4, 3, 2, 1};

  make_heap(test.begin(), test.end());
  print1DVector(test);

  int end;
  pop_heap(test.begin(), test.end());
  end = test.back();
  cout<<"1 "<<end<<endl;
  print1DVector(test);

  int t = test[6];
  test[6] = test[5];
  test[5] = t;

  // pop_heap 只做 shiftdown, 不做合法性检查
  // 要保证 pop_heap 之前是合法堆, 即 pop_heap 之后 vector pop_back
  // 不然 vector 最大的元素又会回到堆顶
  pop_heap(test.begin(), test.end());
  end = test.back();
  cout<<"2 "<<end<<endl;
  print1DVector(test);

}

int main() {

  test();
  return 0;

  Solution demo = Solution();

  vector<vector<int>> nums = {
          {1, 5, 9},
          {10, 11, 13},
          {12, 13, 15}
  };
  int k = 8;

  int rel = demo.kthSmallest(nums, k);

  cout<<rel<<endl;


}


