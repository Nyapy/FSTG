#if 0
#include<iostream>
#include<vector>

using namespace std;

void min_push(int num);
int min_pop(void);

//vector<int> min_heap;
int min_heap[100000 + 10] = { 0, };
int m_size = 0;
int item;
int cmp_value;
int parent, child;
int index;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int input, n;
	cin >> n;

	while (n--)
	{
		cin >> input;
		if (input == 0)
			cout << min_pop() << "\n";
		else
			min_push(input);
	}
}

int min_pop(void)
{
	if (m_size == 0)
		return 0;

	//마지막 인자 뺴서
	//heap의 최상단에 넣는다.
	item = min_heap[1];
	cmp_value = min_heap[m_size--];
	parent = 1, child = 2;

	// 왼쪽자식이 없을때 까지 반복
	while (child <= m_size)
	{
		//작은 자식 구함
		if (child < m_size &&
			(min_heap[child] > min_heap[child + 1]))
			child++;
		// 자식이 더 크면 종료
		if (min_heap[child] >= cmp_value)
			break;

		min_heap[parent] = min_heap[child];

		//다음 인덱스 설정
		parent = child;
		child *= 2;
	}

	if (m_size != 0)
		min_heap[parent] = cmp_value;
	return item;
}

void min_push(int num)
{
	if (m_size == 0)
	{
		min_heap[++m_size] = num;
		return;
	}
	//힙 푸쉬,
	//Set Index
	//min_heap.push_back(num);
	min_heap[++m_size] = num;
	index = m_size;

	// 부모 값보다 작으면,
	// 부모 값을 현재에 덮어씌운다.
	while ((index != 1) && min_heap[index / 2] > num)
	{
		min_heap[index] = min_heap[index / 2];
		index /= 2;
	}

	min_heap[index] = num;
}
#endif