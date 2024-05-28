#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

// 이진 탐색을 이용해 삽입 위치를 찾는 함수
int binarySearchInsertPosition(const std::vector<int>& vec, int element) {
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

class PmergeMe {
public:
    void sortVector(std::vector<int>& vec);
};

void PmergeMe::sortVector(std::vector<int>& vec) {
    // Step 1
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < vec.size() - 1; i += 2) {
        if (vec[i] > vec[i + 1])
            pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
        else
            pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
    }
    int lastUnpaired = (vec.size() % 2 == 1) ? vec.back() : -1;

    // Step 2
    std::vector<int> S;
    for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
        S.push_back(it->first);
    }

    // Step 3
    if (S.size() > 1) {
        PmergeMe::sortVector(S);
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
    // 남은 요소들을 삽입
    for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
        int pos = binarySearchInsertPosition(S, it->second);
        S.insert(S.begin() + pos, it->second);
    }
    if (lastUnpaired != -1) {
        int pos = binarySearchInsertPosition(S, lastUnpaired);
        S.insert(S.begin() + pos, lastUnpaired);
    }

    // 결과를 원래 벡터에 복사
    vec = S;
}

int main() {
    std::vector<int> vec;
    vec.push_back(34);
    vec.push_back(7);
    vec.push_back(23);
    vec.push_back(32);
    vec.push_back(5);
    vec.push_back(62);

    PmergeMe sorter;
    sorter.sortVector(vec);

    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
