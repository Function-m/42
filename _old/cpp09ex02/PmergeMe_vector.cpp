#include "PmergeMe.hpp"

int PmergeMe::binarySearchForVector(const std::vector<int>& vec, int element) {
  int left = 0;
  int right = vec.size();
  while (left < right) {
    int mid = (left + right) / 2;
    if (vec[mid] < element)
      left = mid + 1;
    else
      right = mid;
  }
  return left;
}

void PmergeMe::sortVector(std::vector<int>& vec) {
  // Step 1 - 2
  /*
    1. Group the elements of X into [n/2] pairs of elements, arbitrarily, leaving one element unpaired if there is an odd number of elements.
    1. X의 요소들을 [n/2] 쌍으로 임의로 그룹화합니다. 요소의 수가 홀수일 경우 하나의 요소는 쌍을 이루지 않습니다.

    2. Perform [n/2] comparisons, one per pair, to determine the larger of the two elements in each pair.
    2. 각 쌍마다 한 번씩 [n/2] 비교를 수행하여 각 쌍에서 더 큰 요소를 결정합니다.
  */
  std::vector<std::pair<int, int> > pairs;
  for (size_t i = 0; i < vec.size() - 1; i += 2) {
    if (vec[i] > vec[i + 1])
      pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
    else
      pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
  }
  int lastUnpaired = (vec.size() % 2 == 1) ? vec.back() : -1;

  // Step 3
  /*
    3. Recursively sort the [n/2] larger elements from each pair, creating a sorted sequence S of [n/2] of the input elements, in ascending order.
    3. 각 쌍에서 더 큰 요소들로 이루어진 [n/2]개의 요소를 재귀적으로 정렬하여 입력 요소의 [n/2]개의 요소로 이루어진 오름차순의 정렬된 시퀀스 S를 만듭니다.
  */
  std::vector<int> S;
  for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
    S.push_back(it->first);
  }
  if (S.size() > 1) {
	  sortVector(S);
  }

  // Step 4
  /*
    4. Insert at the start of S the element that was paired with the first and smallest element of S.
    4. S의 첫 번째이자 가장 작은 요소와 쌍을 이루었던 요소를 S의 시작에 삽입합니다.
  */
  for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
    if (it->first == S.front()) {
      S.insert(S.begin(), it->second);
      pairs.erase(it);
      break;
    }
  }

  // Step 5
  /*
    5. Insert the remaining [n/2] - 1 elements of X \ S into S, one at a time, with a specially chosen insertion ordering described below. Use binary search in subsequences of S (as described below) to determine the position at which each element should be inserted.
    5. X \ S의 나머지 [n/2] - 1 요소를 특별히 선택된 삽입 순서에 따라 S에 하나씩 삽입합니다. 각 요소가 삽입될 위치를 결정하기 위해 S의 부분 시퀀스에서 이진 검색을 사용합니다.
  */
  for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
    int pos = binarySearchForVector(S, it->second);
    S.insert(S.begin() + pos, it->second);
  }
  if (lastUnpaired != -1) {
    int pos = binarySearchForVector(S, lastUnpaired);
    S.insert(S.begin() + pos, lastUnpaired);
  }

  if (S.size() == vec.size())
    vec = S;
}
