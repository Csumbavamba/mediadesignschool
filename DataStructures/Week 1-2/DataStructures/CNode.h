#ifndef _NODE_H__
#define _NODE_H__

class CNode{
private:
	int data;
	CNode *nextNode;
public:
	CNode();
	void SetData(int data);
	int GetData() const;
	void SetNextNode(CNode *nextNode);
	CNode* GetNextNode() const;
};

#endif