#pragma once

#include <string.h>
#include <iostream>

class Node
{
public:
	Node(int val)
	{
		data = val;
		next = NULL;
	}

public:
	int data;
	Node *next;
};

class ZList
{
public:
	ZList(void);
	~ZList(void);

	Node *invertLinkList(Node *node);
	int getLen();
	void addNode(int n);

public:
	Node *head;
	int length;
};

