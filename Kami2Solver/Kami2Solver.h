#pragma once
#include <unordered_set>
#include <unordered_map>
#include <opencv2/core.hpp>

using namespace std;

class Graph_Node {
private: 
	int Node_Color;
	int Node_Number;
	unordered_set<Graph_Node*> Adjacent_Nodes;
	static vector<Graph_Node>* All_Nodes;
	
	static unordered_map<int, unordered_set<Graph_Node*>*> Color2Nodes;

public:
	void Node_Recolor(int new_color);
	//merge current node into target node
	void Merge_Into(Graph_Node* target);
	int Try_Reduce();

};
