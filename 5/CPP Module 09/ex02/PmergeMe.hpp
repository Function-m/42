#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <stdexcept>

class PmergeMe {
public:
    PmergeMe(int argc = 0, char* argv[] = NULL);
    void sortAndCountTime();
    void displayAll();

    // For Orthodox Canonical Form, not used in this exercise.
    PmergeMe(const PmergeMe& other);
    ~PmergeMe();
    PmergeMe& operator=(const PmergeMe& other);

private:
    int mainArgc;
    char **mainArgv;
	std::vector<int> vec;
	std::list<int> lst;
	double vecTime;
	double lstTime;

    void sortVector(std::vector<int>& vec);
    int binarySearchForVector(const std::vector<int>& vec, int element);
    
    void sortList(std::list<int>& lst);
    std::list<int>::iterator binarySearchForList(std::list<int>& lst, int element);
};

#endif
