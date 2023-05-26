#pragma once

#include <iostream>

template<typename T>
void	swap(T &A, T &B) {
	T tmp = A;
	A = B;
	B = tmp;	
}

template<typename T>
T const &min(T const &A, T const &B) {
	if (A < B)
		return (A);
	return (B);
}

template<typename T>
T const &max(T const &A, T const &B) {
	if (A > B)
		return (A);
	return (B);
}
