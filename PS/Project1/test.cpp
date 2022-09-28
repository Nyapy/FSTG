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

	//������ ���� ����
	//heap�� �ֻ�ܿ� �ִ´�.
	item = min_heap[1];
	cmp_value = min_heap[m_size--];
	parent = 1, child = 2;

	// �����ڽ��� ������ ���� �ݺ�
	while (child <= m_size)
	{
		//���� �ڽ� ����
		if (child < m_size &&
			(min_heap[child] > min_heap[child + 1]))
			child++;
		// �ڽ��� �� ũ�� ����
		if (min_heap[child] >= cmp_value)
			break;

		min_heap[parent] = min_heap[child];

		//���� �ε��� ����
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
	//�� Ǫ��,
	//Set Index
	//min_heap.push_back(num);
	min_heap[++m_size] = num;
	index = m_size;

	// �θ� ������ ������,
	// �θ� ���� ���翡 ������.
	while ((index != 1) && min_heap[index / 2] > num)
	{
		min_heap[index] = min_heap[index / 2];
		index /= 2;
	}

	min_heap[index] = num;
}
#endif