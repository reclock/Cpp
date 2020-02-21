#include "ZList.h"


ZList::ZList(void)
{
	head = new Node(0);
	length = 0;
}


ZList::~ZList(void)
{
}

void ZList::addNode(int n)
{
	Node *tmp = head;
	while(tmp->next != NULL)
	{
		tmp=tmp->next;
	}
	tmp->next = new Node(n);
	length++;
}

int ZList::getLen()
{
	return length;
}

Node *invertLinkList(Node *node)
{
	if(node->next == nullptr)
		return node;
	Node *newHead = invertLinkList(node->next);
	node->next->next = node;
	node->next = NULL;
	return newHead;
}