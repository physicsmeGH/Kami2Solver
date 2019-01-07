// Kami2Solver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Kami2Solver.h"

#include "pch.h"
#include <iostream>


void Graph_Node::Merge_Into(Graph_Node* target) {
	for (Graph_Node* second_node : this->Adjacent_Nodes) {

		Color2Nodes.at(second_node->Node_Color)->erase(this);
		second_node->Adjacent_Nodes.erase(this);
		second_node->Adjacent_Nodes.insert(target);
		target->Adjacent_Nodes.insert(second_node);
	}
	
}

void Graph_Node::Node_Recolor(int new_color) {
	//if this node is the last one of the same color
	if (Color2Nodes.at(this->Node_Color)->size() == 1) {
		Color2Nodes.erase(this->Node_Color);
	}
	this->Node_Color = new_color;
	for (Graph_Node* node : this->Adjacent_Nodes) {
		
		if (node->Node_Color == new_color) {
			node->Merge_Into(this);
		}
	}
}

int Graph_Node::Try_Reduce() {
	for (Graph_Node* adj_node : this->Adjacent_Nodes) {

	}
}


int main()
{
    std::cout << "Hello World!\n"; 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
