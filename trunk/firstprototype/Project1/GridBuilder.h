#include "GridPanel.h"
#include <cliext\vector>
#include "Vertex.h"

using namespace std;

#pragma once
ref class GridBuilder
{
public:
	GridBuilder(int gridPanelWidth);
	GridPanel^ GetGridPanel();
	//System::Void CreateVertices(int n);
	System::Void AddGridSizeSetter();
	System::Void ClearPanel();
	System::Void InitializeGridSizeSetter();
	 array<Vertex^, 2> ^  GetVertexArray();

private: System::Windows::Forms::Label^  gridSizeLabel;
private: System::Windows::Forms::Button^  okButton;
private: System::Windows::Forms::NumericUpDown^  gridValueSetter;

private:
	int gridPanelWidth;
	GridPanel^ currentPanel;
	System::Void AddVertices(int n);
	System::Windows::Forms::Panel^ gridSizeSetterPanel;

	//cliext::vector<cliext::vector<Vertex^> ^> vertexArray;
	    array<Vertex^, 2>^  vertexArray;



private: System::Void okButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->ClearPanel();
			 this->AddVertices((int)this->gridValueSetter->Value);

		 }
};

