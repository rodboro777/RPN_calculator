#pragma once
#include <iostream>
#include <stack>
#include <fstream>

using namespace std;

template<class T> class RPNCalculator
{
private:
	stack<T> st;
	/* NOTE:
	* 1. You MUST use an instance of a Stack
	* 2. The following functions are to be implemented as defined for RP
	*/
public:
	// pushes a new operand onto the stack

	void push(T operand);
	// binary operators:
	void add();
	void subtract();
	void multiply();
	void divide();
	// squares the current value
	void square();
	// negates, i.e. 3 becomes -3
	void negate();
	// tests to see if there are elements on the stack
	bool isEmpty();
	// clears out the stack
	void clear();
	// returns the topmost value
	T value();
	// returns the topmost value and pops it off the top
	T pop();
};


template<class T>
void RPNCalculator<T>::push(T operand)
{
	st.push(operand);
}

template<class T>
void RPNCalculator<T>::add()
{

	//check if stack size is less than 2 elements
	if (st.size() < 2) {
		clear();
	}
	//if stack has two values, get first value, then second, pop both, add and push result to the top
	else {
		T top = st.top();
		st.pop();
		T pretop = st.top();
		st.pop();
		st.push(top + pretop);
	}
}

template<class T>
void RPNCalculator<T>::subtract()
{
	//check if stack size is less than 2 elements
	if (st.size() < 2) {
		clear();
	}
	//if stack has to values, get first value, then second, pop both values, subtract and push result to the top
	else {
		T top = st.top();
		st.pop();
		T pretop = st.top();
		st.pop();
		st.push(pretop - top);
	}
}

template<class T>
void RPNCalculator<T>::multiply()
{
	//check if stack size is less than 2 elements
	if (st.size() < 2) {
		clear();
	}
	//if stack has to values, get first value, then second, pop both values, multiply and push result to the top

	else {
		T top = st.top();
		st.pop();
		T pretop = st.top();
		st.pop();
		st.push(top * pretop);
	}
}

template<class T>
void RPNCalculator<T>::divide()
{
	//check if stack size is less than 2 elements

	if (st.size() < 2) {
		clear();
	}
	//if stack has to values, get first value, then second, pop both values, divide and push result to the top

	else {
		T top = st.top();
		st.pop();
		T pretop = st.top();
		st.pop();
		st.push(pretop / top);
	}
}

template<class T>
void RPNCalculator<T>::square()
{
	//check if stack has at least one element and multiply it by itself and push to the stack
	if (!st.empty()) {
		T top = st.top();
		st.pop();
		st.push(top * top);
	}
}

template<class T>
void RPNCalculator<T>::negate()
{
	//check if stack has at least one element, get the value and negate it
	if (!st.empty()) {
		T top = st.top();
		st.pop();
		st.push(-top);
	}
}

template<class T>
bool RPNCalculator<T>::isEmpty()
{
	return st.empty();
}


//clears the whole stack
template<class T>
void RPNCalculator<T>::clear()
{
	while (!st.empty()) {
		st.pop();
	}
}

//returns top value of the stack
template<class T>
T RPNCalculator<T>::value()
{
	if (!st.empty()) {
		return st.top();
	}
	else {
		return 0;
	}
}

// pops the top value of the stack if it's not empty
template<class T>
T RPNCalculator<T>::pop()
{
	if (!st.empty()) {
		T top = st.top();
		st.pop();
		return top;
	}
	else {
		return 0;
	}
}
