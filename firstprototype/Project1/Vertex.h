#ifndef _V_H_
#define _V_H_

#include "GridBuilder.h"
#pragma once

ref class GridBuilder;

public ref class Vertex :	public System::Windows::Forms::Panel
{
public:
	Vertex(int xCoordinate, int yCoordinate, float vertexWidth, GridBuilder ^builder);
	System::Void SetWorking();
	System::Void SetDone(int costFromStart);
	System::Void Reset();
	System::Void SetStart(bool isStart);
	System::Void SetEnd(bool isEnd);

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
		 int cost;
		 float vertexWidth;
		 bool working;
		 bool done;
		 bool wall;
		 bool end;
		 bool start;
		 System::Void vertex_Click(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
};

#endif