#include "GridBuilder.h"
#include <iostream>

using namespace std;

GridBuilder::GridBuilder(int gridPanelWidth)
{
	this->gridPanelWidth = gridPanelWidth;
	currentPanel = gcnew GridPanel(gridPanelWidth);
	this->InitializeGridSizeSetter();
	currentPanel->AddGridSizeSetter(this->gridSizeSetterPanel);
}

GridPanel^ GridBuilder::GetGridPanel() {
	return currentPanel;
}
void GridBuilder::AddGridSizeSetter() {
	if(currentPanel && gridSizeSetterPanel) {
		ClearPanel();
		currentPanel->AddGridSizeSetter(this->gridSizeSetterPanel);
	}
}

void GridBuilder::ClearPanel() {
	currentPanel->ClearPanel();
}

int GridBuilder::GetNumberOfVertices() {
	return this->vertexArray->Length; 
}

void  GridBuilder::AddVertices(int n) {
	vertexArray = gcnew array<Vertex^, 2>(n, n);

	//vertexArray.resize(n);
	float vertexWidth = this->gridPanelWidth / n;
	cout << "Vertex width! \n";
	cout << vertexWidth << "\n";
	int counter = 0;
	for(int i = 0; i < n; i++) {
		//vertexArray[i].resize(n);
		for(int j = 0; j < n; j++) {
			counter++;
			Vertex^ tilePanel = gcnew Vertex(j, i, vertexWidth, this, counter);
			vertexArray[i, j] = tilePanel;
			this->currentPanel->Controls->Add(tilePanel);
		}
	}
	for(int i = 0; i < n; i++) {
		array<Vertex^,1>^ neighbors;
		for(int j = 0; j < n; j++){
			Vertex^ tilePanel = vertexArray[i, j];
			if(i == 0 && j == 0) {
				neighbors = gcnew array<Vertex^, 1>(2);
				neighbors[0] = vertexArray[i+1,j];
				neighbors[1] = vertexArray[i,j+1];
			} else
				if(i == 0 && j == n-1) {
					neighbors = gcnew array<Vertex^, 1>(2);
					neighbors[0] = vertexArray[i+1,j];
					neighbors[1] = vertexArray[i,j-1];
				} else
					if(i == n-1 && j == n-1) {
						neighbors = gcnew array<Vertex^, 1>(2);
						neighbors[0] = vertexArray[i-1,j];
						neighbors[1] = vertexArray[i,j-1];
					} else
						if(i == n-1 && j == 0) {
							neighbors = gcnew array<Vertex^, 1>(2);
							neighbors[0] = vertexArray[i-1,j];
							neighbors[1] = vertexArray[i,j+1];
						} else
							if(i == 0) {
								neighbors = gcnew array<Vertex^, 1>(3);
								neighbors[0] = vertexArray[i,j-1];
								neighbors[1] = vertexArray[i,j+1];
								neighbors[2] = vertexArray[i+1,j];
							} else
								if(j == 0) {
									neighbors = gcnew array<Vertex^, 1>(3);
									neighbors[0] = vertexArray[i-1,j];
									neighbors[1] = vertexArray[i+1,j];
									neighbors[2] = vertexArray[i,j+1];
								} else
									if(j == n-1) {
										neighbors = gcnew array<Vertex^, 1>(3);
										neighbors[0] = vertexArray[i-1,j];
										neighbors[1] = vertexArray[i+1,j];
										neighbors[2] = vertexArray[i,j-1];
									} else 
										if(i == n-1) {
											neighbors = gcnew array<Vertex^, 1>(3);
											neighbors[0] = vertexArray[i,j-1];
											neighbors[1] = vertexArray[i,j+1];
											neighbors[2] = vertexArray[i-1,j];
										} else {
											neighbors = gcnew array<Vertex^, 1>(4);
											neighbors[0] = vertexArray[i,j-1];
											neighbors[1] = vertexArray[i,j+1];
											neighbors[2] = vertexArray[i-1,j];
											neighbors[3] = vertexArray[i+1,j];
										}
		
										tilePanel->AddNeighbors(neighbors);
		}
	}
}

void GridBuilder::SetStartVertex(Vertex^ vertex) {
	if(startVertex) {
		startVertex->SetStart(false);
	}
	startVertex = vertex;
	startVertex->SetStart(true);
}

void GridBuilder::SetEndVertex(Vertex^ vertex) {
	if(endVertex) {
		endVertex->SetEnd(false);
	}
	endVertex = vertex;
	endVertex->SetEnd(true);
}

array<Vertex^, 2> ^  GridBuilder::GetVertexArray() {
	return vertexArray;
}

void GridBuilder::InitializeGridSizeSetter() {
	this->gridSizeLabel = (gcnew System::Windows::Forms::Label());
	this->gridSizeSetterPanel = (gcnew System::Windows::Forms::Panel());
	this->gridValueSetter = (gcnew System::Windows::Forms::NumericUpDown());
	this->gridSizeSetterPanel->SuspendLayout();
	this->okButton = (gcnew System::Windows::Forms::Button());
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->gridValueSetter))->BeginInit();
	gridSizeSetterPanel->SuspendLayout();

	// 
	// gridSizeLabel
	// 
	this->gridSizeLabel->AutoSize = true;
	this->gridSizeLabel->Location = System::Drawing::Point(31, 8);
	this->gridSizeLabel->Name = L"gridSizeLabel";
	this->gridSizeLabel->Size = System::Drawing::Size(106, 13);
	this->gridSizeLabel->TabIndex = 0;
	this->gridSizeLabel->Text = L"Enter grid size (2-30):";
	// 
	// gridSizeSetterPanel
	// 
	this->gridSizeSetterPanel->Controls->Add(this->gridValueSetter);
	this->gridSizeSetterPanel->Controls->Add(this->gridSizeLabel);
	this->gridSizeSetterPanel->Controls->Add(this->okButton);
	this->gridSizeSetterPanel->Location = System::Drawing::Point(210, 230);
	this->gridSizeSetterPanel->Name = L"gridSizeSetterPanel";
	this->gridSizeSetterPanel->Size = System::Drawing::Size(180, 140);
	this->gridSizeSetterPanel->TabIndex = 1;
	this->gridSizeSetterPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;

	// 
	// okButton
	// 
	this->okButton->Location = System::Drawing::Point(47, 72);
	this->okButton->Name = L"okButton";
	this->okButton->Size = System::Drawing::Size(75, 40);
	this->okButton->TabIndex = 2;
	this->okButton->Text = L"Ok";
	this->okButton->UseVisualStyleBackColor = true;
	this->okButton->Click += gcnew System::EventHandler(this, &GridBuilder::okButton_Click);
	// 
	// gridValueSetter
	// 
	this->gridValueSetter->Location = System::Drawing::Point(34, 37);
	this->gridValueSetter->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
	this->gridValueSetter->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {30, 0, 0, 0});
	this->gridValueSetter->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
	this->gridValueSetter->Name = L"gridValueSetter";
	this->gridValueSetter->Size = System::Drawing::Size(103, 25);
	this->gridValueSetter->TabIndex = 2;
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->gridValueSetter))->EndInit();

}
