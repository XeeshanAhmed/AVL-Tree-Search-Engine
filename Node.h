#pragma once
using namespace std;
class Node {
private:
	string data;
	Node* next;
public:
	Node()
	{
		data = "";
		next = nullptr;
	}
	Node(const string data)
	{
		this->data = data;
		this->next = nullptr;
	}
	Node(const string data, Node* next)
	{
		this->data = data;
		this->next = next;
	}
	void setnext(Node* next)
	{
		this->next = next;
	}
	void setdata(const string data)
	{
		this->data = data;
	}
	const string getdata()
	{
		return this->data;
	}
	Node* getnext()
	{
		return this->next;
	}
};