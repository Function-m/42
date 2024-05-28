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
  std::vector<std::pair<int, int> > pairs;
  for (size_t i = 0; i < vec.size() - 1; i += 2) {
    if (vec[i] > vec[i + 1])
      pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
    else
      pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
  }
  int lastUnpaired = (vec.size() % 2 == 1) ? vec.back() : -1;

  // Step 3
  std::vector<int> S;
  for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
    S.push_back(it->first);
  }
  if (S.size() > 1) {
	sortVector(S);
  }

  // Step 4
  for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
    if (it->first == S.front()) {
      S.insert(S.begin(), it->second);
      pairs.erase(it);
      break;
    }
  }

  // Step 5
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
