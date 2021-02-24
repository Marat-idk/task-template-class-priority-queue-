#ifndef QUEUE_PRIORITY_H
#define QUEUE_PRIORITY_H

#include <iostream>

template<class T>
class QueueP {
private:
	T* data;
	int size;
	int head;
	int tail;

public:
	QueueP(int n = 5);
	~QueueP() { delete[] data; }
	bool queueIsFull();
	bool queueIsEmpty();
	void push(T x);							// вставка элемента в очередь
	T pop();								// извлечение элемента из начала очереди
	void printQueueP();						// печать очереди
};

template<class T>
QueueP<T>::QueueP(int n) {
	size = n;
	data = new T[size];
	head = -1;
	tail = -1;
}

template<class T>
inline bool QueueP<T>::queueIsFull()
{
	return head == 0 && tail == size - 1;
}

template<class T>
inline bool QueueP<T>::queueIsEmpty()
{
	return head == -1;
}

template<class T>
void QueueP<T>::push(T x) {
	if (queueIsFull())
		throw "Queue is full";
	else {
		if (queueIsEmpty()) {
			head = tail = 0;
			data[tail] = x;
		}
		else if(tail == size - 1){								// если в очереди уже есть какие-то элементы
			data[--head] = x;
			for (int i = head+1; i <= tail; ++i) {
				if (x > data[i]) {
					T temp = data[i - 1];
					data[i - 1] = data[i];
					data[i] = temp;
				}
			}
		}
		else {
			data[++tail] = x;
			for (int i = tail; i > head; --i) {
				if (x <= data[i-1]) {
					T temp = data[i];
					data[i] = data[i-1];
					data[i-1] = temp;
				}
			}
		}
	}
}

template<class T>
T QueueP<T>::pop() {
	if (queueIsEmpty())
		throw "Queue is empty";
	T temp = data[head];
	if (head == tail)
		head = tail = -1;
	else
		++head;
	return temp;
}

template<class T>
void QueueP<T>::printQueueP() {
	if (queueIsEmpty())
		throw "Queue is empty";
	for (int i = head; i <= tail; ++i) {
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}

#endif // !QUEUE_PRIORITY_H
