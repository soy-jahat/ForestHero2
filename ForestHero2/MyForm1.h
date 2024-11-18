#pragma once
#include "File.h"
#include "Guardian.h"
#include <string>
using namespace System;
using namespace System::Drawing;
using namespace System::Collections::Generic;

	public ref class jugadorPuntaje
	{
	public:
		String^ nombre;  // Ahora usando String^
		String^ puntaje; // Ahora usando String^
	};

namespace ForestHero2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();
			bmpRanking = gcnew Bitmap("Resources/Images/menuRanking.png");
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);
			file = new File();
			guardian = new Guardian(200, 200, 64, 64);
			jugadores = gcnew List<jugadorPuntaje^>();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		Bitmap^ bmpRanking;
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
		File* file;
		Guardian* guardian;
		System::String^ nombre;
		int puntos;
		bool labelsCreados = false;
		List<jugadorPuntaje^>^ jugadores;

	private: System::Windows::Forms::Panel^ panel1;
		   
	private: System::Collections::Generic::List<System::Windows::Forms::Label^>^ listaLabels;
		  
	
#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm1::timer1_Tick);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::Control;
			this->panel1->Location = System::Drawing::Point(0, -1);
			this->panel1->Margin = System::Windows::Forms::Padding(4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1821, 945);
			this->panel1->TabIndex = 0;
			// 
			// MyForm1
			// 
			this->AccessibleRole = System::Windows::Forms::AccessibleRole::TitleBar;
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->AutoValidate = System::Windows::Forms::AutoValidate::Disable;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(1366, 768);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Ranking";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		int numJugadores = 1000;
		
		ifstream fileRead;
		string texto;
		String^ nombre;
		String^ puntaje;
		fileRead.open("JugadorPuntaje.txt", ios::in | ios::out);

		if (fileRead.fail()) {
			exit(1);
		}

		int k = 0;
		while (!fileRead.eof()) {
			// Crear un nuevo objeto jugadorPuntaje para cada jugador
			jugadorPuntaje^ nuevoJugador = gcnew jugadorPuntaje();

			// Leer el nombre y asignarlo al objeto
			getline(fileRead, texto);
			if (fileRead.eof()) break; // Prevenir errores si el archivo termina aqu�
			nuevoJugador->nombre = gcnew String(texto.c_str());

			// Leer el puntaje y convertirlo a entero
			getline(fileRead, texto);
			if (fileRead.eof()) break; // Prevenir errores si el archivo termina aqu�
			nuevoJugador->puntaje = gcnew String(texto.c_str());

			// Agregar el jugador a la lista
			jugadores->Add(nuevoJugador);
			k++;
		}
		fileRead.close();
		/*for (int i = 0; i < jugadores->Count - 1; i++) {
			for (int j = 0; j < jugadores->Count - i - 1; j++) {
				int puntaje1 = Convert::ToInt32(jugadores[j]->puntaje);
				int puntaje2 = Convert::ToInt32(jugadores[j + 1]->puntaje);

				if (puntaje1 < puntaje2) {
					jugadorPuntaje^ temp = jugadores[j];
					jugadores[j] = jugadores[j + 1];
					jugadores[j + 1] = temp;
				}
			}
		}*/
		buffer->Graphics->DrawImage(bmpRanking, 0, 0, bmpRanking->Width, bmpRanking->Height);
		buffer->Render(g);

		if (!labelsCreados) {
			listaLabels = gcnew System::Collections::Generic::List<System::Windows::Forms::Label^>();

			for (int i = 0; i < k; i++) {
				System::Windows::Forms::Label^ nuevoLabel = gcnew System::Windows::Forms::Label();

				nuevoLabel->Visible = true;
				nuevoLabel->Text = "Texto inicial del Label #" + i.ToString();
				nuevoLabel->Location = System::Drawing::Point(400, 200 + (i * 40)); // Posici�n din�mica
				nuevoLabel->Size = System::Drawing::Size(200, 30);
				nuevoLabel->Font = gcnew System::Drawing::Font("Arial", 12);
				panel1->Controls->Add(nuevoLabel);
				listaLabels->Add(nuevoLabel);
			}

			labelsCreados = true;
		}
		//ordemar la lista desendente por puntaje con algo ordenaminento
		for (int i = 0; i < listaLabels->Count; i++) {
			listaLabels[i]->Text = (i + 1).ToString() + ". " + jugadores[i]->nombre + " " + jugadores[i]->puntaje;
			listaLabels[i]->ForeColor = System::Drawing::Color::Brown;
		}
	}
	};
}
