#include "Vertex.h"

#include <iostream>


using namespace std;

#pragma region
Vertex::Vertex(int xCoordinate, int yCoordinate, float vertexWidth, GridBuilder ^builder, int id)
{
	this->builder = builder;
	this->cost = 1;
	this->neighborCount =0;
	this->xCoordinate = xCoordinate;
	this->yCoordinate = yCoordinate;
	this->id = id;
	this->vertexWidth = vertexWidth;
	this->Location = System::Drawing::Point(xCoordinate*	vertexWidth,yCoordinate*vertexWidth);
	this->BackColor = System::Drawing::Color::White;
	this->Size = System::Drawing::Size(vertexWidth, vertexWidth);
	this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Vertex::vertex_Click);
	this->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
	this->working = false;
	this->done = false;
	this->builder = builder;
	this->components = (gcnew System::ComponentModel::Container());

	costLabel = gcnew 	System::Windows::Forms::Label();
	costLabel->Font = gcnew System::Drawing::Font(L"Times new roman",vertexWidth/10);
	costLabel->Height = (vertexWidth/10)+10;
	costLabel->BackColor = System::Drawing::Color::Yellow;
	costLabel->Visible= false;
	//this->Controls->Add(tileLabel);
	// 
	// contextMenuStrip
	// 
	this->contextMenuStrip = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
	this->startFieldToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->endFieldToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());

	//this->contextMenuStrip1->SuspendLayout();
	this->contextMenuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->startFieldToolStripMenuItem, 
		this->endFieldToolStripMenuItem});
	this->contextMenuStrip->Name = L"contextMenuStrip";
	this->contextMenuStrip->Size = System::Drawing::Size(127, 48);
	// 
	// startFieldToolStripMenuItem
	// 

	this->startFieldToolStripMenuItem->Name = L"startFieldToolStripMenuItem";
	this->startFieldToolStripMenuItem->Size = System::Drawing::Size(126, 22);
	this->startFieldToolStripMenuItem->Text = L"Start Field";
	this->startFieldToolStripMenuItem->Click += gcnew System::EventHandler(this, &Vertex::startFieldItem_Click);
	// 
	// endFieldToolStripMenuItem
	// 
	this->endFieldToolStripMenuItem->Name = L"endFieldToolStripMenuItem";
	this->endFieldToolStripMenuItem->Size = System::Drawing::Size(126, 22);
	this->endFieldToolStripMenuItem->Text = L"End Field";
	this->endFieldToolStripMenuItem->Click += gcnew System::EventHandler(this, &Vertex::endFieldItem_Click);
	this->ContextMenuStrip = contextMenuStrip;
}

void Vertex::SetWorking(){
	if(!wall&& !start&&!end){
		this->visited = true;
		this->working = true;
		this->BackColor = System::Drawing::Color::Orange;}
	this->Refresh();

}
void Vertex::SetDone(int costFromStart){
	if(!wall&& !start&&!end){

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
	if(!wall&& !start&&!end){
		this->visited = false;
		this->done = false;
		this->Controls->Remove(costLabel);
		costLabel->Visible= false;

		this ->BackColor =  System::Drawing::Color::White;}
}


void Vertex::SetStart(bool isStart){
	if(isStart){
		if(wall)
			wall = false;
		if(end)
			end = false;
		start = true;
		this ->BackColor =  System::Drawing::Color::Green;
		this->cost =0;}
	else{
		start = false;
		this ->BackColor =  System::Drawing::Color::White;
		this->cost = 1;
	}
}

void Vertex::SetEnd(bool isEnd){
	if(isEnd){
		if(wall)
			wall = false;
		if(start)
			start = false;
		end = true;
		this ->BackColor =  System::Drawing::Color::Red;}
	else{
		end = false;
		this ->BackColor =  System::Drawing::Color::White;
	}
}

int Vertex::GetID()
{
	return id;
}

int Vertex::GetCost(){
	return cost;
}
void Vertex::AddNeighbors(array<Vertex^,1>^ neighbors){
	neighborList = neighbors;
}

array<Vertex^,1>^ Vertex::GetNeighborsArray(){
	return neighborList;
}

bool Vertex::IsVisited(){
	return visited;
}

bool Vertex::IsStart()
{
	return start;
}

bool Vertex::IsEnd()
{
	return end;
}

#pragma endregion
void Vertex::vertex_Click(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if(e->Button == System::Windows::Forms::MouseButtons::Left){
		cout << "Vertex " << xCoordinate  <<" "<<yCoordinate << " click! vertex_Click\n";
		Vertex^ source =(Vertex^) sender;

		if(!end && !start){
			if(source->BackColor == System::Drawing::Color::White){
				source->wall = true;
				source->BackColor = System::Drawing::Color::Black;
				this->cost = -1;
				cout<< "neighbors: "<<neighborList->GetLength(0);
				cout << "Vertex " << xCoordinate  <<" "<<yCoordinate << "was white, now it's black\n";
			}else{
				source->wall = false;
				source->BackColor = System::Drawing::Color::White;
				this->cost = 1;
				cout << "Vertex " << xCoordinate  <<" "<<yCoordinate << "as black, now it's white\n";
			}
		}
	}
	else{
		if(e->Button == System::Windows::Forms::MouseButtons::Right){
			//contextMenuStrip->Show();
			cout<< "Right click";

		}
	}
}

void  Vertex::startFieldItem_Click(System::Object^  sender, System::EventArgs^  e) {
	this->builder->SetStartVertex(this);
}

void Vertex::endFieldItem_Click(System::Object^  sender, System::EventArgs^  e) {
	this->builder->SetEndVertex(this);
}