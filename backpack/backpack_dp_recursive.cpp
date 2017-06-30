#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

public:

    void printVectors(vector<vector<int>> vectors) {
    
      for(vector<int> v: vectors) {
        for(int n: v) {
          cout<<setw(2)<<n<<" ";
        }
        cout<<endl;
      }
    
    }

    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {

    int rel = 0;
    size_t nums = A.size();

    sort(A.begin(), A.end());

    vector<vector<int>> marks(nums, vector<int>(m+1, -1));

    for(int j=1; j<=m; j++)
      recursive(A, marks, nums-1, j);

    //printVectors(marks);

    for(int j=m;j>0;j--) {
      if(marks[nums-1][j] == 1) {
        rel = j;
        break;
      }
    }

    return rel;

  }

  int recursive(vector<int> A, vector<vector<int>>& marks, int i, int j) {
  
    if(j < 0)
      return 0;
    if(j == 0)
      return 1;

    if(i == 0)
      return 0;

    if(marks[i][j] != -1)
      return marks[i][j];

    if( 1 == recursive(A, marks, i-1, j-A[i]) || 1 == recursive(A, marks, i-1, j) )
      marks[i][j] = 1;
    else
      marks[i][j] = 0;
  
    return marks[i][j];
  }


    
};


int main() {

Solution demo = Solution();

vector<int> nums;
int value;

nums.push_back(2);
nums.push_back(3);
nums.push_back(7);
nums.push_back(5);

value = demo.backPack(11, nums);
cout<<value<<endl;

// corner case: many zero
int narray2[] = {
828,125,740,724,983,321,773,
678,841,842,875,377,674,144,
340,467,625,916,463,922,255,
662,692,123,778,766,254,559,
480,483,904,60,305,966,872,
935,626,691,832,998,508,657,
215,162,858,179,869,674,452,
158,520,138,847,452,764,995,
600,568,92,496,533,404,186,
345,304,420,181,73,547,281,
374,376,454,438,553,929,140,
298,451,674,91,531,685,862,
446,262,477,573,627,624,814,
103,294,388};

vector<int> nums2(narray2, narray2 + sizeof narray2 / sizeof narray2[0]);

value = demo.backPack(5000, nums2);
cout<<value<<endl;


// corner case: smaller than m
int narray3[] = {
81,112,609,341,164,601,97,709,
944,828,627,730,460,523,643,901,
602,508,401,442,738,443,555,
471,97,644,184,964,418,492,920,
897,99,711,916,178,189,202,72,
692,86,716,588,297,512,605,209,
100,107,938,246,251,921,767,825,
133,465,224,807,455,179,436,201,
842,325,694,132,891,973,107,284,
203,272,538,137,248,329,234,175,
108,745,708,453,101,823,937,639,
485,524,660,873,367,153,191,756,
162,50,267,166,996,552,675,383,
615,985,339,868,393,178,932
};


vector<int> nums3(narray3, narray3 + sizeof narray3 / sizeof narray3[0]);

value = demo.backPack(52740, nums3);
cout<<value<<endl;

}
