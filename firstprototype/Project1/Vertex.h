#ifndef _V_H_
#define _V_H_

#include "GridBuilder.h"
#include <vector>

#pragma once

ref class GridBuilder;

using namespace std;

public ref class Vertex :	public System::Windows::Forms::Panel
{
	public:
		Vertex(int xCoordinate, int yCoordinate, float vertexWidth, GridBuilder ^builder, int id);
		System::Void SetWorking();
		System::Void SetDone(int costFromStart);
		System::Void Reset();
		System::Void SetStart(bool isStart);
		System::Void SetEnd(bool isEnd);
		System::Void SetPath(bool isPath);
		System::Void AddNeighbors(array<Vertex^,1>^ neighbors);
		array<Vertex^,1>^ neighborList;
		array<Vertex^,1>^ GetNeighborsArray();
	
		int GetID();
		int GetCost();
		bool IsVisited();
		bool IsStart();
		bool IsEnd();
		int GetXCoordinate();
		int GetYCoordinate();
		bool IsWall();

	public: GridBuilder^ builder;
	private:
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^  startFieldToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  endFieldToolStripMenuItem;
	private: System::ComponentModel::IContainer^  components;
	private: System::Void startFieldItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void endFieldItem_Click(System::Object^  sender, System::EventArgs^  e);

	System::Windows::Forms::Label^ costLabel;
	int xCoordinate;
	int yCoordinate;
	int id;
	int cost;
	int neighborCount;
	float vertexWidth;
	bool visited;
	bool working;
	bool done;
	bool wall;
	bool end;
	bool start;
	bool path;
	System::Void vertex_Click(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
};

#endif