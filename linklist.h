#pragma once
using namespace std;
class linklist {
private:
	Node* head;
	Node* tail;
public:
	linklist()
	{
		head = new Node();
		tail = head;
	}
	Node* gethead()
	{
		return this->head;
	}
	bool insert(const string data)
	{
		if (head->getnext() == nullptr)
		{
			Node* newNode = new Node(data);
			head->setnext(newNode);
			tail = newNode;
		}
		else
		{
			bool exists = false;
			Node* temp = head->getnext();
			while (temp != nullptr)
			{
				if (temp->getdata() == data)
				{
					exists = true;
					return false;
				}
				temp = temp->getnext();
			}
			if (!exists)
			{
				Node* newNode = new Node(data);
				tail->setnext(newNode);
				tail = newNode;
			}
		}
		return true;
	}
	void print()
	{
		Node* temp = head->getnext();
		int i = 1;
		while (temp != nullptr)
		{
			Sleep(500);
			cout << i++ << "." << temp->getdata() << endl;
			temp = temp->getnext();
		}
	}
	~linklist()
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			Node* next = temp->getnext();
			if (temp != head)
			{
				cout << temp->getdata() << " deleted" << endl;
			}
			delete temp;
			temp = next;
		}
		head = nullptr;
	}
};