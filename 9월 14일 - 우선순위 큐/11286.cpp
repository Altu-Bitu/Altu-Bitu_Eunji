#include<iostream>
#include<queue>
using namespace std;

struct comp{
	bool operator()(long long a, long long b) {
		if (abs(a) != abs(b))
			return abs(a) > abs(b);
		else
			return a > b;
	}
};

//Àý´ñ°ª Èü
priority_queue<long long, vector<long long>, comp> arr;


long long arrPop() {
	long long result;
	if (!arr.empty()) {
		result = arr.top();
		arr.pop();
		return result;
	}
	else {
		result = 0;
		return result;
	}
}

void arrAdd(long long x) {
	arr.push(x);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	long long x, result;

	//ÀÔ·Â
	cin >> n;
	while (n--) {
		cin >> x;
		if (x == 0) {
			result = arrPop();
			cout << result << '\n';
		}
		else 
			arrAdd(x);
	}
}