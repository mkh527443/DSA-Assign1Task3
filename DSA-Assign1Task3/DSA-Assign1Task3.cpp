#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

class List {
private:
	Node* head;

public:
	List()
	{
		head = NULL;
	}

	bool IsListEmpty()
	{
		if (head == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void insert_begin(int value)
	{
		Node* temp;
		temp = new Node;
		temp->data = value;
		temp->next = NULL;
		if (head == NULL)
		{
			head = temp;
		}
		else
		{
			temp->next = head;
			head = temp;
		}
	}

	void insert_end(int Value)
	{
		Node* temp, * p;
		temp = new Node;
		temp->data = Value;
		temp->next = NULL;

		if (IsListEmpty())
		{
			head = temp;
		}
		else
		{
			p = head;
			while (p->next != NULL)
			{
				p = p->next;
			}
			p->next = temp;
		}
	}

	void insert_after(int OldV, int NewV)
	{
		Node* temp = new Node;
		temp->data = NewV;

		if (IsListEmpty())
		{
			head = temp;
		}

		Node* p = head;
		while (p->next)
		{
			if (p->data == OldV)
			{
				temp->next = p->next;
				p->next = temp;
			}
			p = p->next;
		}
	}

	void delete_node(int Value)
	{
		if (head == NULL)
		{
			cout << "List is empty!" << endl;
		}

		Node* p = head;
		Node* q = NULL;

		while (p != NULL && p->data != Value)
		{
			q = p;
			p = p->next;
		}

		if (p == NULL)
		{
			cout << "Element not found!" << endl;
			return;
		}

		if (q)
		{
			q->next = p->next;
		}
		else
		{
			head = p->next;
		}
		delete p;
	}

	void display()
	{
		Node* p;
		p = head;

		if (head == NULL)
		{
			cout << "List is empty";
		}
		else
		{
			cout << "List is: " << endl;
			while (p != NULL)
			{
				cout << p->data << " ";
				p = p->next;
			}
			cout << endl;
		}
	}
};


int main()
{
	List li;
	li.insert_begin(10);
	li.insert_begin(20);
	li.insert_begin(30);
	li.insert_end(40);
	li.insert_after(20, 50);
	li.insert_end(60);
	li.insert_end(70);
	li.insert_end(80);
	li.insert_end(90);
	li.display();
}