#pragma once
ref class Vertex :	public System::Windows::Forms::Panel
{
public:
	Vertex(int xCoordinate, int yCoordinate, float vertexWidth);
	System::Void SetWorking();
	System::Void SetDone(int costFromStart);
	System::Void Reset();
	

private:
	System::Windows::Forms::Label^ costLabel;
	int xCoordinate;
	int yCoordinate;
	int cost;
	float vertexWidth;
	bool working;
	bool done;
	bool wall;
	bool end;
	bool start;
	System::Void vertex_Click(System::Object^  sender, System::EventArgs^  e);
};
