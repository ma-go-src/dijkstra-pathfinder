#include <iostream>
#include "GridBuilder.h"
#include "GridSizeSetter.h"

#pragma once

namespace Project1 {

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

	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  startFieldToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  endFieldToolStripMenuItem;


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



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		GridBuilder^ gridBuilder;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->startFieldToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->endFieldToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mainPanel = (gcnew System::Windows::Forms::Panel());
			this->controlsPanel = (gcnew System::Windows::Forms::Panel());
			this->speedLabel = (gcnew System::Windows::Forms::Label());
			this->speedSetter = (gcnew System::Windows::Forms::NumericUpDown());
			this->resetButton = (gcnew System::Windows::Forms::Button());
			this->startButton = (gcnew System::Windows::Forms::Button());
			this->contextMenuStrip1->SuspendLayout();
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
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->startFieldToolStripMenuItem, 
				this->endFieldToolStripMenuItem});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(127, 48);
			// 
			// startFieldToolStripMenuItem
			// 
			this->startFieldToolStripMenuItem->Name = L"startFieldToolStripMenuItem";
			this->startFieldToolStripMenuItem->Size = System::Drawing::Size(126, 22);
			this->startFieldToolStripMenuItem->Text = L"Start Field";
			// 
			// endFieldToolStripMenuItem
			// 
			this->endFieldToolStripMenuItem->Name = L"endFieldToolStripMenuItem";
			this->endFieldToolStripMenuItem->Size = System::Drawing::Size(126, 22);
			this->endFieldToolStripMenuItem->Text = L"End Field";
			// 
			// mainPanel
			// 
			this->mainPanel->Location = System::Drawing::Point(0, 0);
			this->mainPanel->Name = L"mainPanel";
			this->mainPanel->Size = System::Drawing::Size(600, 600);
			this->mainPanel->TabIndex = 1;
			// 
			// controlsPanel
			// 
			this->controlsPanel->Controls->Add(this->speedLabel);
			this->controlsPanel->Controls->Add(this->speedSetter);
			this->controlsPanel->Controls->Add(this->resetButton);
			this->controlsPanel->Controls->Add(this->startButton);
			this->controlsPanel->Location = System::Drawing::Point(0, 601);
			this->controlsPanel->Name = L"controlsPanel";
			this->controlsPanel->Size = System::Drawing::Size(600, 100);
			this->controlsPanel->TabIndex = 2;
			// 
			// speedLabel
			// 
			this->speedLabel->AutoSize = true;
			this->speedLabel->Location = System::Drawing::Point(170, 25);
			this->speedLabel->Name = L"speedLabel";
			this->speedLabel->Size = System::Drawing::Size(87, 13);
			this->speedLabel->TabIndex = 3;
			this->speedLabel->Text = L"Animation Speed";
			// 
			// speedSetter
			// 
			this->speedSetter->Location = System::Drawing::Point(200, 50);
			this->speedSetter->Name = L"speedSetter";
			this->speedSetter->Size = System::Drawing::Size(35, 20);
			this->speedSetter->TabIndex = 2;
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
			this->contextMenuStrip1->ResumeLayout(false);
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
			 }
	private: System::Void resetButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->gridBuilder->ClearPanel();
				 int newGrid = 0;
				 GridSizeSetter^ form = gcnew GridSizeSetter(newGrid);

				 Application::Run(form);
				 this->gridBuilder->CreateNewGrid(newGrid);
				
			 }
	};

}