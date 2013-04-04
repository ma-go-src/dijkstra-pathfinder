#include "GridPanel.h"
#include "Vertex.h"
#include <iostream>

using namespace std;

GridPanel::GridPanel(int width)
{
	this->CausesValidation = false;
	this->Location = System::Drawing::Point(0, 0);
	this->Name = L"gridPanel";
	this->Size = System::Drawing::Size(width,width);
}
