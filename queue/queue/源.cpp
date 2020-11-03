#include<iostream>
using namespace std;

//1.定义
template<class T,int size>
class Queue
{
	public:
		Queue() { first = last = -1; }
		void AddQueue(T num);
		T DeleteQueue();
		bool IsFull();
		bool IsEmpty();
		int first, last;
		T data[size];

};

//2.入队
template<class T,int size>
void Queue<T, size>::AddQueue(T num)
{
	if (!IsFull()) {
		if (last == size - 1 || last == -1) {
			data[0] = num;
			last = 0;
			if (first == -1) {
				first = 0;
			}
		}
		else {
			data[++last] = num;
		}
	}
	else {
		cout << "队列满！" << endl;
	}
}

//3.出队
template<class T,int size>
T Queue<T, size>::DeleteQueue()
{
	T num;
	num = data[first];
	if (first == last) {
		last = first = -1;
	}
	else if (first == size - 1) {
		first = 0;
	}
	else
		first++;
	return num;
}

//4.判断队列是否为满
template<class T, int size>
bool Queue<T, size>::IsFull()
{
	return first == 0 && last == size - 1 || first == last + 1;
}

//5.判断队列是否为空
template<class T, int size>
bool Queue<T, size>::IsEmpty()
{
	return first == -1;
}

int main()
{
	Queue<double, 100> Q;
	int i;
	double num;
	for (i = 0; i < 10; i++) {
		Q.AddQueue(i);
	}
	for (i = 0; i < 5; i++) {
		num = Q.DeleteQueue();
		cout << num << endl;
	}
	cout << Q.first << "  " << Q.last << endl;
}