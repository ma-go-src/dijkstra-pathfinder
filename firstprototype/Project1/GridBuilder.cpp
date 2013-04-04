#include "GridBuilder.h"
#include "Vertex.h"
#include <iostream>
using namespace std;


GridBuilder::GridBuilder(int gridPanelWidth)
{
	this->gridPanelWidth = gridPanelWidth;
}

GridPanel^ GridBuilder::CreateNewGrid(int n){

	currentPanel = gcnew GridPanel(gridPanelWidth);
	AddVertices(n);
	return currentPanel;
}

void GridBuilder::ClearPanel(){

	currentPanel->Controls->Clear();

}

void  GridBuilder::AddVertices(int n){


	float vertexWidth = this->gridPanelWidth / n;
	cout << "Vertex width! \n";
	cout << vertexWidth << "\n";
	for(int i =0; i<n;i++){
		for(int j =0; j<n;j++){

			Vertex^ tilePanel = gcnew Vertex(j,i, vertexWidth);
			this->currentPanel->Controls->Add(tilePanel);
		}
	}

}
