#include "../include/PmergeMe.hpp"

static unsigned long long time_in_ms(struct timeval t) {
	return (static_cast<unsigned long long>(t.tv_sec) * 1000000 + t.tv_usec);
}

void PmergeMe::parseArgs(char **av, vector<int> &_vec, list<int> &_list) {
	while (*av) {
		int i;
		try {
			i = stoi(*av);
			if (i >= 0) {
					_vec.push_back(i);
					_list.push_back(i);
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
}

PmergeMe::PmergeMe (char **av) {
	timeval t0, t1;
	
	gettimeofday(&t0, NULL);
	parseArgs(av, _vectCont, _listCont);
	gettimeofday(&t1, NULL);

	cout << "Before: ";
	for (vector<int>::iterator it = _vectCont.begin(); it != _vectCont.end(); ++it){
		cout << *it << " ";
	}
	
	// cout << "\n[L] Before: ";
	// for (list<int>::iterator it = _listCont.begin(); it != _listCont.end(); ++it){
	// 	cout << *it << " ";
	// }

	timeval tVStart, tVEnd;
	gettimeofday(&tVStart, NULL);
	msortVector(0, _vectCont.size() - 1);
	gettimeofday(&tVEnd, NULL);

	timeval tLStart, tLEnd;
	gettimeofday(&tLStart, NULL);
	msortList(0, _listCont.size() - 1);
	gettimeofday(&tLEnd, NULL);

	cout << "\n\nAfter: ";
	for (vector<int>::iterator it = _vectCont.begin(); it != _vectCont.end(); ++it){
		cout << *it << " ";
	}
	// cout << "\n[L] After: ";
	// for (list<int>::iterator it = _listCont.begin(); it != _listCont.end(); ++it){
	// 	cout << *it << " ";
	// }
	cout << endl;

	unsigned long long tDataProcess = (time_in_ms(t1) - time_in_ms(t0)) / 2;
	unsigned long long tVProcess = (time_in_ms(tVEnd) - time_in_ms(tVStart)) + tDataProcess;
	unsigned long long tLProcess = (time_in_ms(tLEnd) - time_in_ms(tLStart)) + tDataProcess;

	cout << "\nTime to process a range of " << _vectCont.size() << " elements with std::vector:\t" << tVProcess << " us" << endl;
	cout << "Time to process a range of " << _listCont.size() << " elements with std::list:\t" << tLProcess << " us" << endl;
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

		msortVector(start, mid);
		msortVector((mid + 1), end);

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
    while (leftIdx <= mid) {
        tmp.push_back(*leftIt);
        leftIt++;
		leftIdx++;
    }
	//if there's something left in the second half, push it to tmp
    while (rightIdx <= end) {
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
		++start;
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

