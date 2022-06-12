// ContainerList v0.1
#include <iostream>

using namespace std;

struct List
{
	int Value;
	List* Back;
};

void AddObject(List* _Next, const int& _Value);
void Insert(List* head, int idx, const int& _Value);
void Output(List* _Next);

int main(void)
{
	List* NumberList = new List;
	NumberList->Value = 0;
	NumberList->Back = nullptr;

	for (int i = 0; i < 10; ++i)
	{
		AddObject(NumberList, i * 10 + 10);
	}

	Insert(NumberList, 3, 15);

	Output(NumberList->Back);

	return 0;
}

void AddObject(List* _Next, const int& _Value)
{
	if (_Next->Back == nullptr)
	{
		List* Temp = new List;
		Temp->Value = _Value;
		Temp->Back = nullptr;

		_Next->Back = Temp;
	}
	else
		AddObject(_Next->Back, _Value);
}

void Insert(List* head, int idx, const int& _Value)
{
	List* ptr = head;
	List* temp = ptr;

	List* node = new List;
	node->Value = _Value;
	node->Back = nullptr;

	for (int i = 0; i < idx; i++)
	{
		temp = ptr;
		ptr = ptr->Back;
	}
	temp->Back = node;
	node->Back = ptr;
}

void Output(List* _Next)
{
	cout << _Next->Value << endl;
	//cout << _Next->Back << endl << endl;

	if (_Next->Back != nullptr)
		Output(_Next->Back);
}