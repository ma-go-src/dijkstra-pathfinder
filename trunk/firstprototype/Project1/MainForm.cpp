#include "MainForm.h"
#include <iostream>

//namespace DijkstraPathfinder{
	using namespace std;

	int main(){
		Application::EnableVisualStyles();
		MainForm^ form = gcnew MainForm();
		Application::Run(form);

	return 0;
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

	}//}



