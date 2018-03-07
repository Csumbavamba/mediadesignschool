#include "CNode.h"
#include <Windows.h>

CNode::CNode()
{
}

void CNode::SetData(int data)
{
	this->data = data;
}

int CNode::GetData() const
{
	return data;
}

void CNode::SetNextNode(CNode * nextNode)
{
	this->nextNode = nextNode;
}

CNode * CNode::GetNextNode() const
{
	return nextNode;
}



