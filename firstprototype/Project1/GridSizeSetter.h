

#pragma once

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class GridSizeSetter : public System::Windows::Forms::Form
	{
	public:
		GridSizeSetter() 
		{
			
			InitializeComponent();
		
			//
			//TODO: Add the constructor code here
			//
		}
		
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GridSizeSetter()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  gridSizeLabel;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  cancelButton;

	private: System::Windows::Forms::Button^  okButton;

	private: System::Windows::Forms::NumericUpDown^  gridValueSetter;
	protected: 

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->gridSizeLabel = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->okButton = (gcnew System::Windows::Forms::Button());
			this->gridValueSetter = (gcnew System::Windows::Forms::NumericUpDown());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->gridValueSetter))->BeginInit();
			this->SuspendLayout();
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
			// panel1
			// 
			this->panel1->Controls->Add(this->cancelButton);
			this->panel1->Controls->Add(this->okButton);
			this->panel1->Controls->Add(this->gridValueSetter);
			this->panel1->Controls->Add(this->gridSizeLabel);
			this->panel1->Location = System::Drawing::Point(-1, 1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(173, 140);
			this->panel1->TabIndex = 1;
			// 
			// cancelButton
			// 
			this->cancelButton->Location = System::Drawing::Point(47, 101);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(75, 23);
			this->cancelButton->TabIndex = 3;
			this->cancelButton->Text = L"Cancel";
			this->cancelButton->UseVisualStyleBackColor = true;
			this->cancelButton->Click += gcnew System::EventHandler(this, &GridSizeSetter::cancelButton_Click);
			// 
			// okButton
			// 
			this->okButton->Location = System::Drawing::Point(47, 72);
			this->okButton->Name = L"okButton";
			this->okButton->Size = System::Drawing::Size(75, 23);
			this->okButton->TabIndex = 2;
			this->okButton->Text = L"Ok";
			this->okButton->UseVisualStyleBackColor = true;
			this->okButton->Click += gcnew System::EventHandler(this, &GridSizeSetter::okButton_Click);
			// 
			// gridValueSetter
			// 
			this->gridValueSetter->Location = System::Drawing::Point(34, 37);
			this->gridValueSetter->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {30, 0, 0, 0});
			this->gridValueSetter->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
			this->gridValueSetter->Name = L"gridValueSetter";
			this->gridValueSetter->Size = System::Drawing::Size(103, 20);
			this->gridValueSetter->TabIndex = 1;
			this->gridValueSetter->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
			// 
			// GridSizeSetter
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(172, 140);
			this->Controls->Add(this->panel1);
			this->Name = L"GridSizeSetter";
			this->Text = L"MyForm";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->gridValueSetter))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void cancelButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->~GridSizeSetter();
			 }
private: System::Void okButton_Click(System::Object^  sender, System::EventArgs^  e) {
			
			  this->~GridSizeSetter();
		 }
};
}
