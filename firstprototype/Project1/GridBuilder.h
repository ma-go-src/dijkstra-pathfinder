#include "GridPanel.h"

#pragma once
ref class GridBuilder
{
public:
	GridBuilder(int gridPanelWidth);
	GridPanel^ CreateNewGrid(int n);
	System::Void ClearPanel();


private:
	int gridPanelWidth;
	GridPanel^ currentPanel;
	System::Void AddVertices(int n);
};

