 ref class Vertex :	public System::Windows::Forms::Panel
	{
	public:
		Vertex(int xCoordinate, int yCoordinate, float vertexWidth);


	private:
		int xCoordinate;
		int yCoordinate;
		float vertexWidth;
		System::Void vertex_Click(System::Object^  sender, System::EventArgs^  e);
	};
