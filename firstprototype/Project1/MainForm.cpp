#include "MainForm.h"
#include "Vertex.h"
#include <iostream>

using namespace Project1;
using namespace std;

int main(){
	Application::EnableVisualStyles();
	MainForm^ form = gcnew MainForm();
	Application::Run(form);


}

MainForm::MainForm(void) 	{

	gridBuilder = gcnew GridBuilder(GRIDPANEL_WIDTH);
	InitializeComponent();
	CreateFirstPanel();
	//
	//TODO: Add the constructor code here
	//
}

MainForm::~MainForm(void) {
	if (components)
	{
		delete components;
	}
}

void MainForm::CreateFirstPanel(){
 int newGrid = 0;
			 
				 this->mainPanel->Controls->Add( this->gridBuilder->GetGridPanel());
				 cout << "first grid size: "<< newGrid;		
}



