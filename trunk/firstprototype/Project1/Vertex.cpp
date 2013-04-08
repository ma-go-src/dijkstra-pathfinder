#include "Vertex.h"

#include <iostream>


using namespace std;

#pragma region
Vertex::Vertex(int xCoordinate, int yCoordinate, float vertexWidth)
{
	this->cost = 1;
	this->xCoordinate = xCoordinate;
	this->yCoordinate = yCoordinate;
	this->vertexWidth = vertexWidth;
	this->Location = System::Drawing::Point(xCoordinate*	vertexWidth,yCoordinate*vertexWidth);
	this->BackColor = System::Drawing::Color::White;
	this->Size = System::Drawing::Size(vertexWidth, vertexWidth);
	this->Click += gcnew System::EventHandler(this, &Vertex::vertex_Click);
	this->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
	this->working = false;
	this->done = false;


	costLabel = gcnew 	System::Windows::Forms::Label();
	costLabel->Font = gcnew System::Drawing::Font(L"Times new roman",vertexWidth/10);
	costLabel->Height = (vertexWidth/10)+10;
	costLabel->BackColor = System::Drawing::Color::Yellow;
	costLabel->Visible= false;
	//this->Controls->Add(tileLabel);

}

void Vertex::SetWorking(){
	if(!wall){

		this->working = true;
		this->BackColor = System::Drawing::Color::Orange;}
	this->Refresh();

}
void Vertex::SetDone(int costFromStart){
	if(!wall){

		this->working = false;
		this->done = true;
		this->BackColor = System::Drawing::Color::Yellow;
		costLabel->Text = yCoordinate+" "+xCoordinate;
		costLabel->Location = System::Drawing::Point(20,20);
		costLabel->Visible = true;

		this->Controls->Add(costLabel);}
	this->Refresh();




}

void Vertex::Reset(){
	cout << wall;
	if(!wall){
		this->done = false;
		this->Controls->Remove(costLabel);
		costLabel->Visible= false;

		this ->BackColor =  System::Drawing::Color::White;}
}


#pragma endregion
void Vertex::vertex_Click(System::Object^  sender, System::EventArgs^  e) {
	cout << "Vertex " << xCoordinate  <<" "<<yCoordinate << " click! vertex_Click\n";
	Vertex^ source =(Vertex^) sender;

	if(!end && !start){
		if(source->BackColor == System::Drawing::Color::White){
			source->wall = true;
			source->BackColor = System::Drawing::Color::Black;
			cout << "Vertex " << xCoordinate  <<" "<<yCoordinate << "was white, now it's black\n";
		}else{
			source->wall = false;
			source->BackColor = System::Drawing::Color::White;
			cout << "Vertex " << xCoordinate  <<" "<<yCoordinate << "as black, now it's white\n";
		}}
}