#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe (char **av) {
	int i;

	// timeval t0, t1;
	// gettimeofday(&t0, NULL);

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
	// gettimeofday(&t0, NULL);

	cout << "Before: ";
	for (vector<int>::iterator it = _vectCont.begin(); it != _vectCont.end(); ++it){
		cout << *it << " ";
	}
	
	timeval tVStart, tVEnd;
	gettimeofday(&tVStart, NULL);
	msortVector(0, _vectCont.size() - 1);
	gettimeofday(&tVEnd, NULL);

	timeval tLStart, tLEnd;
	gettimeofday(&tLStart, NULL);
	msortList(0, _listCont.size() - 1);
	gettimeofday(&tLEnd, NULL);

	cout << "\nAfter: ";
	for (list<int>::iterator it = _listCont.begin(); it != _listCont.end(); ++it){
		cout << *it << " ";
	}

	// unsigned long long t0_us = static_cast<unsigned long long>(t0.tv_sec) * 1000000 + t0.tv_usec;
	// unsigned long long t1_us = static_cast<unsigned long long>(t1.tv_sec) * 1000000 + t1.tv_usec;
	// unsigned long long tDataProcess = static_cast<unsigned long long>(t1_us + t0_us) / 2;

	unsigned long long tVStart_us = static_cast<unsigned long long>(tVStart.tv_sec) * 1000000 + tVStart.tv_usec;
	unsigned long long tVEnd_us = static_cast<unsigned long long>(tVEnd.tv_sec) * 1000000 + tVEnd.tv_usec;
	unsigned long long tVProcess = (tVEnd_us - tVStart_us);
	unsigned long long tLStart_us = static_cast<unsigned long long>(tLStart.tv_sec) * 1000000 + tLStart.tv_usec;
	unsigned long long tLEnd_us = static_cast<unsigned long long>(tLEnd.tv_sec) * 1000000 + tLEnd.tv_usec;
	unsigned long long tLProcess = (tLEnd_us - tLStart_us);

	cout << "\nTime to process a range of " << _vectCont.size() << " elements with std::vector:\t" << tVProcess << " us" << endl;
	cout << "Time to process a range of " << _listCont.size() << " elements with std::list:\t" << tLProcess << " us" << endl;
	cout << endl;
}

/*------------------------------ VECTOR SORT ------------------------------*/

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

/*------------------------------ LIST SORT ------------------------------*/

void PmergeMe::mergeLists(int start, int mid, int end) {
	list<int> tmp;

	int leftIdx = start;
	int rightIdx = mid + 1;

	list<int>::iterator leftIt = _listCont.begin();
	std::advance(leftIt, leftIdx);

	list<int>::iterator rightIt = _listCont.begin();
	std::advance(rightIt, rightIdx);

	//finds the smaller between indexes and push it back into tmp
	while (leftIdx <= mid && rightIdx <= end) {
        if (*leftIt <= *rightIt) {
            tmp.push_back(*leftIt);
            leftIt++;
			leftIdx++;
        }
		else {
            tmp.push_back(*rightIt);
            rightIt++;
			rightIdx++;
        }
    }
	//if there's something left in the first half, push it to tmp
    while (leftIt != _listCont.end()) {
        tmp.push_back(*leftIt);
        leftIt++;
		leftIdx++;
    }
	//if there's something left in the second half, push it to tmp
    while (rightIt != _listCont.end()) {
        tmp.push_back(*rightIt);
        rightIt++;
		rightIdx++;
    }

    list<int>::iterator tmpIt = tmp.begin();
    list<int>::iterator listIt = _listCont.begin();
    std::advance(listIt, start);

    while (start <= end) {
        *listIt = *tmpIt;
        tmpIt++;
        listIt++;
		start++;
	}
}

void PmergeMe::msortList(int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;

	msortList(start, mid);
	msortList(mid + 1, end);

	mergeLists(start, mid, end);
	}
}

PmergeMe::~PmergeMe() {} 

