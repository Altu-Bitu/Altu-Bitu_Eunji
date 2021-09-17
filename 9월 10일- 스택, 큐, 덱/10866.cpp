#include<iostream>
#include<deque>
#include<vector>

using namespace std;
const int SIZE = 10001;

int front_pointer = 0, rear_pointer = 0;
vector<int> queue_vec(SIZE);

void push_front(int k) {
	queue_vec[front_pointer] = k;
	if (front_pointer - 1 < 0)
		front_pointer = front_pointer - 1 + SIZE;
	else
		front_pointer = front_pointer - 1;
}

void push_back(int k) {
	rear_pointer = (rear_pointer + 1) % SIZE;
	queue_vec[rear_pointer] = k;
}

int pop_front() {
	front_pointer = (front_pointer + 1) % SIZE;
	return queue_vec[front_pointer];
}

int pop_back() {
	int temp = queue_vec[rear_pointer];
	if (rear_pointer - 1 < 0)
		rear_pointer = rear_pointer - 1 + SIZE;
	else
		rear_pointer = rear_pointer - 1;
	return temp;
}

int size() {
	int temp = (rear_pointer - front_pointer);
	if (temp < 0)
		temp += SIZE;
	return temp;
}

bool empty() {
	return rear_pointer == front_pointer;
}

bool full() {
	return (rear_pointer + 1) % SIZE == front_pointer;
}

int front() {
	int temp = (front_pointer + 1) % SIZE;
	return queue_vec[temp];
}

int back() {
	return queue_vec[rear_pointer];
}

int main() {
	deque<int> d;
	int n, k;
	string cmd;

	cin >> n;
	while (n--) {
		cin >> cmd;
		if (cmd == "push_front") {
			cin >> k;
			//if (!full())
			//	push_front(k);
			d.push_front(k);
			continue;
		}
		if (cmd == "push_back") {
			cin >> k;
			//if (!full())
			//	push_back(k);
			d.push_back(k);
			continue;
		}
		if (cmd == "pop_front") {
			//if (empty())
			//	cout << -1 << '\n';
			//else {
			//	cout << pop_front() << '\n';
			//}
			if (d.empty())
				cout << -1 << '\n';
			else {
				cout << d.front() << '\n';
				d.pop_front();
			}
			continue;
		}
		if (cmd == "pop_back") {
			//if (empty())
			//	cout << -1 << '\n';
			//else {
			//	cout << pop_back() << '\n';
			//}
			if (d.empty())
				cout << -1 << '\n';
			else {
				cout << d.back() << '\n';
				d.pop_back();
			}
			continue;
		}
		if (cmd == "size") {
			//cout << size() << '\n';
			cout << d.size() << '\n';
			continue;
		}
		if (cmd == "empty") {
			//cout << empty() << '\n';
			cout << d.empty() << '\n';
			continue;
		}
		if (cmd == "front") {
			//if (empty())
			//	cout << -1 << '\n';
			//else
			//	cout << front() << '\n';
			if (d.empty())
				cout << -1 << '\n';
			else
				cout << d.front() << '\n';
			continue;
		}
		if (cmd == "back") {
			//if (empty())
			//	cout << -1 << '\n';
			//else
			//	cout << back() << '\n';
			if (d.empty())
				cout << -1 << '\n';
			else
				cout << d.back() << '\n';
			continue;
		}
	}
}