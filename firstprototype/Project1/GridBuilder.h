#ifndef _G_H_
#define _G_H_

#include "GridPanel.h"

#include "Vertex.h"
ref class Vertex;
	using namespace std;
#pragma once
	public ref  class GridBuilder
	{
	public:
		GridBuilder(int gridPanelWidth);
		GridPanel^ GetGridPanel();
		//System::Void CreateVertices(int n);
		System::Void AddGridSizeSetter();
		System::Void ClearPanel();
		System::Void InitializeGridSizeSetter();
		array<Vertex^, 2> ^  GetVertexArray();
		System::Void SetStartVertex(Vertex^ vertex);
		System::Void SetEndVertex(Vertex^ vertex);

	private: System::Windows::Forms::Label^  gridSizeLabel;
	private: System::Windows::Forms::Button^  okButton;
	private: System::Windows::Forms::NumericUpDown^  gridValueSetter;

	private:
		int gridPanelWidth;
		GridPanel^ currentPanel;
		System::Void AddVertices(int n);
		System::Windows::Forms::Panel^ gridSizeSetterPanel;
		Vertex^ endVertex;
		Vertex^ startVertex;
		//cliext::vector<cliext::vector<Vertex^> ^> vertexArray;
		array<Vertex^, 2>^  vertexArray;



	private: System::Void okButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->ClearPanel();
				 this->AddVertices((int)this->gridValueSetter->Value);

			 }
	};
#endif
