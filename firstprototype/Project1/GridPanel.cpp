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
	this->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;

}

void GridPanel::AddGridSizeSetter(Panel^ gridSizeSetter){


	this->Controls->Add(gridSizeSetter);
}

void GridPanel::ClearPanel(){
	this->Controls->Clear();
}
