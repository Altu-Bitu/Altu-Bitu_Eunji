#include <iostream>
#include <vector>

using namespace std;
vector<int> post_order; //후위 순회 결과
vector<int> pre_order; //전위 순회 결과

//전위 순회 결과: 루트>왼>오 순서. 루트보다 큰 노드가 등장한 지점이 오른쪽 서브트리의 시작점.
//전위 순회 결과에서 트리를 왼쪽, 오른쪽 서브트리로 나누어 각각 후위 순회 진행
void postOrder(int left, int right) { //left 입력받은 트리의 시작점, right: 트리의 끝 + 1 지점
	if (left == right) //원소가 없는 트리이므로 리턴
		return;

	if (left + 1 == right) { //원소 1개
		post_order.push_back(pre_order[left]); //후위 순회 결과에 저장
		return;
	}

	//왼쪽, 오른쪽 서브트리 사이의 경계 찾기
	int temp = left + 1;
	while (temp < right && pre_order[temp] < pre_order[left])
		temp++;

	postOrder(left + 1, temp); //왼쪽 서브트리에서 후위 순회
	postOrder(temp, right); //오른쪽 서브트리에서 후위 순회
	post_order.push_back(pre_order[left]); //후위 순회 결과에 루트 저장
}

int main() {
	//입력
	int input;
	while (cin >> input) 
		pre_order.push_back(input);

	//연산
	postOrder(0, pre_order.size());

	//출력
	for (int i = 0; i < post_order.size(); i++)
		cout << post_order[i] << '\n';
}