#include "Vertex.h"

#include <iostream>


using namespace std;

#pragma region
Vertex::Vertex(int xCoordinate, int yCoordinate, float vertexWidth)
{
	this->xCoordinate = xCoordinate;
	this->yCoordinate = yCoordinate;
	this->vertexWidth = vertexWidth;
	this->Location = System::Drawing::Point(xCoordinate*	vertexWidth,yCoordinate*vertexWidth);
	this->BackColor = System::Drawing::Color::White;
	this->Size = System::Drawing::Size(vertexWidth, vertexWidth);
	this->Click += gcnew System::EventHandler(this, &Vertex::vertex_Click);
	this->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
	
	//Label^ tileLabel = gcnew Label();
	//tileLabel->Location = System::Drawing::Point(0,0);
	//tileLabel->Text = yCoordinate+" "+xCoordinate;
	//tileLabel->Font = gcnew System::Drawing::Font(L"Times new roman",6);
	
	//this->Controls->Add(tileLabel);
	
}
#pragma endregion
void Vertex::vertex_Click(System::Object^  sender, System::EventArgs^  e) {
	cout << "Vertex " << xCoordinate  <<" "<<yCoordinate << " click! vertex_Click\n";
	Panel^ vertex = (Panel^) sender;

	if(vertex->BackColor == System::Drawing::Color::White){
	
		vertex->BackColor = System::Drawing::Color::Black;
		cout << "Vertex " << xCoordinate  <<" "<<yCoordinate << "was white, now it's black\n";
	}else{
		
		vertex->BackColor = System::Drawing::Color::White;
		cout << "Vertex " << xCoordinate  <<" "<<yCoordinate << "as black, now it's white\n";
	}
}