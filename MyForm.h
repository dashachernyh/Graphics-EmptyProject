#pragma once
#include<msclr\marshal_cppstd.h>
#include"calcul.h"
#include"stack.h"
#include<string>
namespace CppWinForm1 {

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
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(23, 90);
			this->textBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(76, 20);
			this->textBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::DarkMagenta;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->button1->ForeColor = System::Drawing::Color::HotPink;
			this->button1->Location = System::Drawing::Point(120, 88);
			this->button1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(50, 21);
			this->button1->TabIndex = 1;
			this->button1->Text = L"=";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 13, System::Drawing::FontStyle::Italic));
			this->label1->ForeColor = System::Drawing::Color::LightCyan;
			this->label1->Location = System::Drawing::Point(187, 88);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(84, 21);
			this->label1->TabIndex = 2;
			this->label1->Text = L"результат";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 13, System::Drawing::FontStyle::Italic));
			this->label2->ForeColor = System::Drawing::Color::LavenderBlush;
			this->label2->Location = System::Drawing::Point(284, 88);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(100, 21);
			this->label2->TabIndex = 3;
			this->label2->Text = L"постфиксная";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 15.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::Color::Indigo;
			this->label3->Location = System::Drawing::Point(139, 23);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(119, 25);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Калькулятор";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Plum;
			this->ClientSize = System::Drawing::Size(411, 307);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		std::string infix,postfix;
		infix = msclr::interop::marshal_as<std::string>(textBox1->Text);
		TCalculator<double> calc;
		try {
			calc.SetExpr(infix);
			//calc.CheckBrackets();
			calc.ToPosfix();
			postfix = calc.GetPostfix();
			double rez = calc.Calc();
			label1->Text = Convert::ToString(rez);
			label2->Text = gcnew String(postfix.c_str());
		    }
		catch (char str)
		{
			label1->Text = Convert::ToString(str);
		}
	}

};
}
