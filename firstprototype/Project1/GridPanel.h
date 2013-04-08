#pragma once
ref class GridPanel :
public System::Windows::Forms::Panel
{
public:
	GridPanel(int width);
	System::Void AddGridSizeSetter(Panel^ gridSizeSetter);
	System::Void ClearPanel();
};

