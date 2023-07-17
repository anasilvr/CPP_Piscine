#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe (char **av) {
	int i = 0;

	while (*av) {
		try {
			i = stoi(*av);
			if (i >= 0) {
					_vectCont.push_back(i);
					_listCont.push_back(i);
			}
			else {
				cerr << "Error: invalid input [negative number]" << endl;
				exit(EXIT_FAILURE);
			}
		}
		catch (std::exception e) {
			cerr << "Error: invalid input [" << e.what() << "]" << endl;
			exit(EXIT_FAILURE);
		}
	av++;
	}
	// cout << "\nBefore (vector): ";
	// for (vector<int>::iterator it = _vectCont.begin(); it != _vectCont.end(); ++it){
	// 	cout << *it << " ";
	// }

	cout << "\nBefore (list): ";
	for (list<int>::iterator it = _listCont.begin(); it != _listCont.end(); ++it){
		cout << *it << " ";
	}

	msortVector(0, _vectCont.size() - 1);
	msortList(0, _listCont.size() - 1);

	// cout << "\n\nAfter (vector): ";
	// for (vector<int>::iterator it = _vectCont.begin(); it != _vectCont.end(); ++it){
	// 	cout << *it << " ";
	// }

	cout << "\nAfter (list): ";
	for (list<int>::iterator it = _listCont.begin(); it != _listCont.end(); ++it){
		cout << *it << " ";
	}


	cout << endl;
}

void PmergeMe::mergeVectors(int start, int mid, int end) {
	vector<int> tmp;

	int leftIdx = start;
	int rightIdx = mid + 1;

	//finds the smaller between indexes and push it back into tmp
	while (leftIdx <= mid && rightIdx <= end) {
		if(_vectCont[leftIdx] <= _vectCont[rightIdx]) {
			tmp.push_back(_vectCont[leftIdx]);
			leftIdx++;
		}
		else {
			tmp.push_back(_vectCont[rightIdx]);
			rightIdx++;
		}
	}
	//if there's something left in the first half, push it to tmp
	while (leftIdx <= mid) {
		tmp.push_back(_vectCont[leftIdx]);
		leftIdx++;
	}
	//if there's something left in the second half, push it to tmp
	while (rightIdx <= end) {
		tmp.push_back(_vectCont[rightIdx]);
		rightIdx++;
	}
	// updates values inside _vectCont by sorted ones
	for (int i = start; i <= end; i++) {
		_vectCont[i] = tmp[i - start];
	}
}

void PmergeMe::msortVector(int start, int end) {
	if (start < end) {
		int mid = ((start + end) / 2);

		//sort each half
		msortVector(start, mid);
		msortVector((mid + 1), end);

		//merge sorted halves
		mergeVectors(start, mid, end);
	}
}

void PmergeMe::mergeLists(int start, int mid) {
	list<int> tmp;

	list<int>::iterator leftIt = _listCont.begin();
	std::advance(leftIt, start);

	list<int>::iterator rightIt = _listCont.begin();
	std::advance(rightIt, mid + 1);

	//finds the smaller between indexes and push it back into tmp
	while (leftIt != _listCont.end() && rightIt != _listCont.end()) {
        if (*leftIt <= *rightIt) {
            tmp.push_back(*leftIt);
            leftIt++;
        } else {
            tmp.push_back(*rightIt);
            rightIt++;
        }
    }
	//if there's something left in the first half, push it to tmp
    while (leftIt != _listCont.end()) {
        tmp.push_back(*leftIt);
        leftIt++;
    }
	//if there's something left in the second half, push it to tmp
    while (rightIt != _listCont.end()) {
        tmp.push_back(*rightIt);
        rightIt++;
    }

    list<int>::iterator tmpIt = tmp.begin();
    std::advance(tmpIt, start);

    list<int>::iterator listIt = _listCont.begin();
    std::advance(listIt, start);

    while (tmpIt != tmp.end() && listIt != _listCont.end()) {
        *listIt = *tmpIt;
        tmpIt++;
        listIt++;
	}
}

void PmergeMe::msortList(int start, int end) {
	int mid = (start + end) / 2;

	if (start >= end)
		return;
	msortList(start, mid);
	msortList(mid + 1, end);

	mergeLists(start, mid);
}

PmergeMe::~PmergeMe() {}

