#include "MutantStack.hpp"
#include <iostream>

// * stack에 대해서
//  1. LIFO 구조: std::stack은 후입선출(Last-In, First-Out) 구조로, 가장 나중에 삽입된 요소가 가장 먼저 제거됩니다.
//  2. 시퀀스 컨테이너 어댑터: std::stack은 기본적으로 다른 시퀀스 컨테이너를 사용하여 구현됩니다. 기본 컨테이너는 std::deque입니다.
//  3. 제한된 인터페이스: std::stack은 표준 시퀀스 컨테이너와 비교했을 때 제한된 인터페이스를 제공합니다. 이터레이터를 제공하지 않으며, 순회(traversal)가 불가능합니다.

int main() {
    MutantStack<int> mstack;
    std::cout << "* Basic Operations Test *\n";
    mstack.push(5);
    mstack.push(17);
    
    std::cout << "Top element: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size after one pop: " << mstack.size() << std::endl;
    
    std::cout << "\n* Pushing Multiple Elements Test *\n";
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    std::cout << "\n* Iterator Output Test *\n";
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    for (; it != ite; ++it) {
        std::cout << *it << std::endl;
    }

    std::cout << "\n* Iterator Manipulation Test *\n";
    it = mstack.begin();
    ite = mstack.end();
    ++it;
    --it;
    
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "\n* Copy to std::stack Test *\n";
    std::stack<int> s(mstack);
    while (!s.empty()) {
        std::cout << s.top() << std::endl;
        s.pop();
    }

    return 0;
}
