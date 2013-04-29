#include <iostream>
#include "GridBuilder.h"
#include <windows.h>
#include "PathCalculator.h"

#pragma once


//namespace DijkstraPathfinder{

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

#define GRIDPANEL_WIDTH 600

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{

	public:
		MainForm(void);



	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm();

	private: System::Void CreateFirstPanel();
	private: System::Windows::Forms::Panel^  panel1;


	private: System::ComponentModel::IContainer^  components;
	protected:
		int panelWidth ;
	private: System::Windows::Forms::Panel^  mainPanel;
	private: System::Windows::Forms::Panel^  controlsPanel;
	protected: 

	private: System::Windows::Forms::Label^  speedLabel;


	private: System::Windows::Forms::NumericUpDown^  speedSetter;

	private: System::Windows::Forms::Button^  resetButton;
	private: System::Windows::Forms::Button^  startButton;
	private: System::Windows::Forms::Button^  editButton;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		GridBuilder^ gridBuilder;
		PathCalculator pathCalculator;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->mainPanel = (gcnew System::Windows::Forms::Panel());
			this->controlsPanel = (gcnew System::Windows::Forms::Panel());
			this->editButton = (gcnew System::Windows::Forms::Button());
			this->speedLabel = (gcnew System::Windows::Forms::Label());
			this->speedSetter = (gcnew System::Windows::Forms::NumericUpDown());
			this->resetButton = (gcnew System::Windows::Forms::Button());
			this->startButton = (gcnew System::Windows::Forms::Button());

			this->controlsPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->speedSetter))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Azure;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(800, 600);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::panel1_Paint);

			// 
			// mainPanel
			// 
			this->mainPanel->Location = System::Drawing::Point(0, 0);
			this->mainPanel->Name = L"mainPanel";
			this->mainPanel->Size = System::Drawing::Size(600, 600);
			this->mainPanel->TabIndex = 1;
			this->mainPanel->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::mainPanel_MouseClick);
			// 
			// controlsPanel
			// 
			this->controlsPanel->Controls->Add(this->editButton);
			this->controlsPanel->Controls->Add(this->speedLabel);
			this->controlsPanel->Controls->Add(this->speedSetter);
			this->controlsPanel->Controls->Add(this->resetButton);
			this->controlsPanel->Controls->Add(this->startButton);
			this->controlsPanel->Location = System::Drawing::Point(0, 601);
			this->controlsPanel->Name = L"controlsPanel";
			this->controlsPanel->Size = System::Drawing::Size(600, 100);
			this->controlsPanel->TabIndex = 2;
			// 
			// editButton
			// 
			this->editButton->Location = System::Drawing::Point(173, 60);
			this->editButton->Name = L"editButton";
			this->editButton->Size = System::Drawing::Size(84, 30);
			this->editButton->TabIndex = 4;
			this->editButton->Text = L"Edit";
			this->editButton->UseVisualStyleBackColor = true;
			this->editButton->Click += gcnew System::EventHandler(this, &MainForm::editButton_Click);
			// 
			// speedLabel
			// 
			this->speedLabel->AutoSize = true;
			this->speedLabel->Location = System::Drawing::Point(170, 5);
			this->speedLabel->Name = L"speedLabel";
			this->speedLabel->Size = System::Drawing::Size(87, 13);
			this->speedLabel->TabIndex = 3;
			this->speedLabel->Text = L"Animation Speed";
			// 
			// speedSetter
			// 
			this->speedSetter->Location = System::Drawing::Point(200, 22);
			this->speedSetter->Name = L"speedSetter";
			this->speedSetter->Size = System::Drawing::Size(50, 20);
			this->speedSetter->TabIndex = 2;
			this->speedSetter->Maximum = 1000;
			// 
			// resetButton
			// 
			this->resetButton->Location = System::Drawing::Point(5, 60);
			this->resetButton->Name = L"resetButton";
			this->resetButton->Size = System::Drawing::Size(150, 30);
			this->resetButton->TabIndex = 1;
			this->resetButton->Text = L"Reset";
			this->resetButton->UseVisualStyleBackColor = true;
			this->resetButton->Click += gcnew System::EventHandler(this, &MainForm::resetButton_Click);
			// 
			// startButton
			// 
			this->startButton->Location = System::Drawing::Point(5, 5);
			this->startButton->Name = L"startButton";
			this->startButton->Size = System::Drawing::Size(150, 50);
			this->startButton->TabIndex = 0;
			this->startButton->Text = L"Start";
			this->startButton->UseVisualStyleBackColor = true;
			this->startButton->Click += gcnew System::EventHandler(this, &MainForm::startButton_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(601, 702);
			this->Controls->Add(this->controlsPanel);
			this->Controls->Add(this->mainPanel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"MainForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MyForm_Load);
			//			this->contextMenuStrip1->ResumeLayout(false);
			this->controlsPanel->ResumeLayout(false);
			this->controlsPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->speedSetter))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void panel2_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 }
	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 }


	private: System::Void startButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 array<Vertex^,2>^ vertexes2D = gridBuilder->GetVertexArray();
				 array<Vertex^,1>^ vertexes = gcnew array<Vertex^, 1>(vertexes2D->GetLength(0)*vertexes2D->GetLength(0));
				 
				 int count = 0;
				 cout <<"array length: "<< vertexes2D->GetLength(0);
				 for(int i = 0; i < vertexes2D->GetLength(0);i++){
					 for(int j = 0; j < vertexes2D->GetLength(0);j++){
						 Vertex^ vertex = vertexes2D[i,j];
						 vertexes[count] = vertex;
						 count++;
						 
					 }
				 }
				 
				 int source;
				 int target;
				 for (int q = 0; q < vertexes->Length; q++)
				 {
					 if (vertexes[q]->IsStart())
						 source = q;
					 if (vertexes[q]->IsEnd())
						 target = q;
				 }
				 int timeInterval = (int)this->speedSetter->Value;
				 pathCalculator.calculatePath(vertexes, source, target, timeInterval);
				 
			 }
	private: System::Void resetButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->gridBuilder->ClearPanel();
				 this->gridBuilder->AddGridSizeSetter();

			 }

	private: System::Void editButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 array<Vertex^,2>^ vertexes = gridBuilder->GetVertexArray();

				 for(int i = 0; i < vertexes->GetLength(0);i++){
					 for(int j = 0; j < vertexes->GetLength(0);j++){
						 Vertex^ vertex = vertexes[i,j];
						 vertex->Reset();
					 }
				 }
			 }

	private: System::Void mainPanel_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 }

	};

//}
