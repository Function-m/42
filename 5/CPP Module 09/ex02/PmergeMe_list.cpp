#include "PmergeMe.hpp"

std::list<int>::iterator PmergeMe::binarySearchForList(std::list<int>& lst, int element) {
  std::list<int>::iterator left = lst.begin();
  std::list<int>::iterator right = lst.end();

  while (left != right) {
    std::list<int>::iterator mid = left;
    std::advance(mid, std::distance(left, right) / 2);

    if (*mid < element) {
      left = ++mid;
    } else {
      right = mid;
    }
  }

  return left;
}

void PmergeMe::sortList(std::list<int>& lst) {
  // Step 1 - 2
  std::list<std::pair<int, int> > pairs;
  std::list<int>::iterator it = lst.begin();
  while (it != lst.end()) {
    int first = *it;
    ++it;
    if (it != lst.end()) {
      int second = *it;
      if (first > second)
        pairs.push_back(std::make_pair(first, second));
      else
        pairs.push_back(std::make_pair(second, first));
      ++it;
    }
  }
  int lastUnpaired = (lst.size() % 2 == 1) ? lst.back() : -1;

  // Step 3
  std::list<int> S;
  for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
    S.push_back(it->first);
  }
  if (S.size() > 1) {
    sortList(S);
  }

  // Step 4
  for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
    if (it->first == S.front()) {
      S.insert(S.begin(), it->second);
      pairs.erase(it);
      break;
    }
  }

  // Step 5
  for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
    std::list<int>::iterator pos = binarySearchForList(S, it->second);
    S.insert(pos, it->second);
  }
  if (lastUnpaired != -1) {
    std::list<int>::iterator pos = binarySearchForList(S, lastUnpaired);
    S.insert(pos, lastUnpaired);
  }

  if (S.size() == lst.size())
  	lst = S;
}