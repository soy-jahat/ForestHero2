#pragma once

namespace ForestHero2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm3
	/// </summary>
	public ref class MyForm3 : public System::Windows::Forms::Form
	{
	public:
		MyForm3(void)
		{
			InitializeComponent();
			bmpWin = gcnew Bitmap("Resources/Images/menuVictoria.png");
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~MyForm3()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Timer^ timerWin;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		Bitmap^ bmpWin;
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->timerWin = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(-2, -2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1366, 768);
			this->panel1->TabIndex = 0;
			// 
			// timerWin
			// 
			this->timerWin->Enabled = true;
			this->timerWin->Tick += gcnew System::EventHandler(this, &MyForm3::timerWin_Tick);
			// 
			// MyForm3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1366, 768);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm3";
			this->Text = L"MyForm3";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timerWin_Tick(System::Object^ sender, System::EventArgs^ e) {
		//winner
		buffer->Graphics->DrawImage(bmpWin, 0, 0, bmpWin->Width, bmpWin->Height);
		buffer->Render(g);
	}
	};
}
