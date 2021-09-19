#include<iostream>
#include<queue>
using namespace std;

struct comp{
	bool operator()(int a, int b) {
		if (abs(a) != abs(b))
			return abs(a) > abs(b);
		else
			return a > b;
	}
};

//Àý´ñ°ª Èü
priority_queue<int, vector<int>, comp> arr;


int arrPop() {
	int result;
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


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int x, result;

	//ÀÔ·Â
	cin >> n;
	while (n--) {
		cin >> x;
		if (x == 0) {
			result = arrPop();
			cout << result << '\n';
		}
		else
			arr.push(x);
	}
}