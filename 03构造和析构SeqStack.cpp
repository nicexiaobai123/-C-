#include <iostream>
using namespace std;

//	 ˳��ջ
class SeqStack {
public:
	//	����
	SeqStack(int size = 5) {
		_pdata = new int[size];
		_top = -1;
		_size = size;
	}
	//	����
	~SeqStack() {
		if (_pdata != nullptr) {
			delete[] _pdata;
			_pdata = nullptr;
		}
	}
	void push(int x) {
		if (isFull()) {
			resize();
		}
		_pdata[++_top] = x;
	}
	void pop() {
		--_top;
	}
	int top() {
		return _pdata[_top];
	}
	bool isEmpty() {
		return _top == -1;
	}
private:
	bool isFull() {
		return _top == _size - 1;
	}
	void resize() {
		int* ptemp = new int[_size * 2];
		for (int i = 0; i < _size; i++) {
			ptemp[i] = _pdata[i];
		}
		delete[] _pdata;
		_pdata = ptemp;
		_size = _size * 2;
	}
private:
	int* _pdata;
	int _top;
	int _size;
};

#if 0
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//	new �������ڴ�malloc���ٵ��ù���
	SeqStack* seq1 = new SeqStack(5);

	srand(time(NULL));
	for (int i = 0; i < 15; i++) {
		seq1->push(rand() % 100);
	}

	while (!seq1->isEmpty())
	{
		cout << seq1->top() << " ";
		seq1->pop();
	}
	cout << endl;

	//	delete �ȵ������������ͷ��ڴ�free
	delete seq1;
	return 0;
}
#endif