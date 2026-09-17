#pragma once

namespace Lz1Z1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
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
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				L"Лінія", L"Прямокутник", L"Зафарбований прямокутник",
					L"Еліпс", L"Зафарбований еліпс", L"Сектор", L"Зірка", L"Трикутник", L"Будиночок"
			});
			this->listBox1->Location = System::Drawing::Point(373, 24);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(206, 134);
			this->listBox1->TabIndex = 0;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox1_SelectedIndexChanged);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"Зелений", L"Фіолетовий", L"Рожевий", L"Синій",
					L"Оранжевий", L"Червоний"
			});
			this->comboBox1->Location = System::Drawing::Point(415, 180);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 1;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(591, 276);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->listBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ graf = CreateGraphics();
		graf->Clear(Color::White);
		Color selectedColor = Color::Green;
		switch (comboBox1->SelectedIndex)
		{
		case 0: selectedColor = Color::Green; break;
		case 1: selectedColor = Color::Purple; break;
		case 2: selectedColor = Color::DeepPink; break;
		case 3: selectedColor = Color::Blue; break;
		case 4: selectedColor = Color::Orange; break;
		case 5: selectedColor = Color::Red; break;
		}

		Pen^ pn = gcnew System::Drawing::Pen(selectedColor, 8);
		Brush^ br = gcnew System::Drawing::SolidBrush(selectedColor);

		switch (listBox1->SelectedIndex)
		{
		case 0:
			graf->DrawLine(pn, 50, 40, 250, 160);
			break;
		case 1:
			graf->DrawRectangle(pn, 40, 40, 150, 80);
			break;
		case 2:
			graf->FillRectangle(br, 40, 40, 150, 80);
			break;
		case 3:
			graf->DrawEllipse(pn, 40, 40, 200, 140);
			break;
		case 4:
			graf->FillEllipse(br, 40, 40, 200, 140);
			break;
		case 5:
			graf->FillPie(br, 40, 40, 200, 200, 180, 90);
			break;
		case 6: {
			cli::array<Point>^ starPoints = gcnew cli::array<Point>{
				Point(120, 30),
				Point(145, 100),
				Point(215, 100),
				Point(155, 150),
				Point(180, 230),
				Point(120, 180),
				Point(60, 230),
				Point(85, 150),
				Point(25, 100),
				Point(95, 100)
			};
			graf->FillPolygon(br, starPoints);
			graf->DrawPolygon(pn, starPoints);
			break;
		}
		case 7: {
			cli::array<Point>^ polygonPoints = gcnew cli::array<Point>{
				Point(50, 40),
				Point(150, 40),
				Point(250, 160)
			};
			graf->DrawPolygon(pn, polygonPoints);
			break;
		}
		case 8: { // Самостійне розширення — Будиночок
			// 1. Стіни (прямокутник)
			graf->DrawRectangle(pn, 80, 120, 160, 120);

			// 2. Дах (трикутник через DrawPolygon)
			cli::array<Point>^ roofPoints = gcnew cli::array<Point>{
				Point(160, 50),   // Вершина даху
				Point(60, 120),   // Лівий кут
				Point(260, 120)   // Правий кут
			};
			graf->DrawPolygon(pn, roofPoints);

			// 3. Двері (малий прямокутник)
			graf->DrawRectangle(pn, 140, 170, 40, 70);
			break;
		}
		}
	}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}