﻿#pragma once
#include <vector>
#include <ctime>
#include <math.h>
#include <algorithm>
#include <map>


namespace CppWinForm1 {

	std::vector<std::vector<double> > P;
	int R;
	int N;
	int k; // kol-vo intervalov
	double alpha; // yroven znachimosti
	int canPlotGraph = 0;
	double pi = 3.14159265358979323846;
	std::map<int, int> mapka;
	std::map<int, double> FteorRaspredelenie;
	std::map<int, double> ryadR;


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
			R = 5;
			N = 10;
			InitializePMatrix();
			FillTheDataGrid();
			
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
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBoxNumberOfShoots;
	private: System::Windows::Forms::Button^  buttonUpdatePMatrix;


	private: System::Windows::Forms::DataGridView^  dataGridView1;




	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBoxNumberOfExp;
	private: System::Windows::Forms::Button^  buttonGO;
	private: System::Windows::Forms::DataGridView^  dataGridView2;



	private: System::Windows::Forms::DataGridViewTextBoxColumn^  NumberOfShoot;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  FirstShooter;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  SecondShooter;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ThirdShooter;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  RyadRaspredelenia;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  textBoxMaxOtklonenie;



	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::TextBox^  textBoxMeraRashoj;

	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::DataGridView^  dataGridView3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column9;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column10;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column11;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column12;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::TextBox^  textBoxMaxOtklonenieWhere;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::Button^  buttonZadat;

	private: System::Windows::Forms::TextBox^  textBoxAlpha;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::TextBox^  textBoxNumOfIntervals;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::DataGridView^  dataGridView4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column13;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column14;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column15;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column16;
	private: System::Windows::Forms::TextBox^  textBoxResult;

	private: System::Windows::Forms::TextBox^  textBoxFR0;

	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::TextBox^  textboxR0;

	private: System::Windows::Forms::Label^  label20;
private: System::Windows::Forms::Label^  label21;








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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBoxNumberOfShoots = (gcnew System::Windows::Forms::TextBox());
			this->buttonUpdatePMatrix = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->NumberOfShoot = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->FirstShooter = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SecondShooter = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ThirdShooter = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBoxNumberOfExp = (gcnew System::Windows::Forms::TextBox());
			this->buttonGO = (gcnew System::Windows::Forms::Button());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->RyadRaspredelenia = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->textBoxMaxOtklonenieWhere = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBoxMaxOtklonenie = (gcnew System::Windows::Forms::TextBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->textBoxMeraRashoj = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column11 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column12 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->textBoxResult = (gcnew System::Windows::Forms::TextBox());
			this->textBoxFR0 = (gcnew System::Windows::Forms::TextBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->textboxR0 = (gcnew System::Windows::Forms::TextBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->dataGridView4 = (gcnew System::Windows::Forms::DataGridView());
			this->Column13 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column14 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column15 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column16 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->buttonZadat = (gcnew System::Windows::Forms::Button());
			this->textBoxAlpha = (gcnew System::Windows::Forms::TextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->textBoxNumOfIntervals = (gcnew System::Windows::Forms::TextBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(69, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Вариант №9";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(16, 42);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 13);
			this->label2->TabIndex = 1;
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(16, 110);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(130, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Количество выстрелов r";
			// 
			// textBoxNumberOfShoots
			// 
			this->textBoxNumberOfShoots->Location = System::Drawing::Point(19, 127);
			this->textBoxNumberOfShoots->Name = L"textBoxNumberOfShoots";
			this->textBoxNumberOfShoots->Size = System::Drawing::Size(100, 20);
			this->textBoxNumberOfShoots->TabIndex = 3;
			this->textBoxNumberOfShoots->Text = L"5";
			this->textBoxNumberOfShoots->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxNumberOfShoots_TextChanged);
			// 
			// buttonUpdatePMatrix
			// 
			this->buttonUpdatePMatrix->Location = System::Drawing::Point(125, 124);
			this->buttonUpdatePMatrix->Name = L"buttonUpdatePMatrix";
			this->buttonUpdatePMatrix->Size = System::Drawing::Size(253, 23);
			this->buttonUpdatePMatrix->TabIndex = 4;
			this->buttonUpdatePMatrix->Text = L"Обновить таблицу вероятностей попаданий";
			this->buttonUpdatePMatrix->UseVisualStyleBackColor = true;
			this->buttonUpdatePMatrix->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->NumberOfShoot,
					this->FirstShooter, this->SecondShooter, this->ThirdShooter
			});
			this->dataGridView1->EnableHeadersVisualStyles = false;
			this->dataGridView1->Location = System::Drawing::Point(537, 30);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(403, 431);
			this->dataGridView1->TabIndex = 5;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// NumberOfShoot
			// 
			this->NumberOfShoot->HeaderText = L"Номер выстрела";
			this->NumberOfShoot->Name = L"NumberOfShoot";
			// 
			// FirstShooter
			// 
			this->FirstShooter->HeaderText = L"Первый стрелок";
			this->FirstShooter->Name = L"FirstShooter";
			// 
			// SecondShooter
			// 
			this->SecondShooter->HeaderText = L"Второй стрелок";
			this->SecondShooter->Name = L"SecondShooter";
			// 
			// ThirdShooter
			// 
			this->ThirdShooter->HeaderText = L"Третий стрелок";
			this->ThirdShooter->Name = L"ThirdShooter";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(16, 30);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(395, 52);
			this->label4->TabIndex = 6;
			this->label4->Text = resources->GetString(L"label4.Text");
			this->label4->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(534, 9);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(180, 13);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Таблица вероятностей попаданий";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(16, 155);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(121, 13);
			this->label6->TabIndex = 8;
			this->label6->Text = L"Число экспериментов";
			// 
			// textBoxNumberOfExp
			// 
			this->textBoxNumberOfExp->Location = System::Drawing::Point(19, 171);
			this->textBoxNumberOfExp->Name = L"textBoxNumberOfExp";
			this->textBoxNumberOfExp->Size = System::Drawing::Size(100, 20);
			this->textBoxNumberOfExp->TabIndex = 9;
			this->textBoxNumberOfExp->Text = L"1000";
			// 
			// buttonGO
			// 
			this->buttonGO->Location = System::Drawing::Point(145, 167);
			this->buttonGO->Name = L"buttonGO";
			this->buttonGO->Size = System::Drawing::Size(75, 23);
			this->buttonGO->TabIndex = 10;
			this->buttonGO->Text = L"Рассчет";
			this->buttonGO->UseVisualStyleBackColor = true;
			this->buttonGO->Click += gcnew System::EventHandler(this, &MyForm::buttonGO_Click);
			// 
			// dataGridView2
			// 
			this->dataGridView2->BackgroundColor = System::Drawing::SystemColors::Control;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Column1,
					this->Column2, this->Column3, this->RyadRaspredelenia
			});
			this->dataGridView2->GridColor = System::Drawing::SystemColors::Control;
			this->dataGridView2->Location = System::Drawing::Point(3, 30);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersVisible = false;
			this->dataGridView2->Size = System::Drawing::Size(528, 600);
			this->dataGridView2->TabIndex = 11;
			this->dataGridView2->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView2_CellContentClick);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Значение случайной величины";
			this->Column1->Name = L"Column1";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Число повторений";
			this->Column2->Name = L"Column2";
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Частота";
			this->Column3->Name = L"Column3";
			// 
			// RyadRaspredelenia
			// 
			this->RyadRaspredelenia->HeaderText = L"Ряд распределения";
			this->RyadRaspredelenia->Name = L"RyadRaspredelenia";
			this->RyadRaspredelenia->Width = 225;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Location = System::Drawing::Point(16, 197);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(950, 663);
			this->tabControl1->TabIndex = 12;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label16);
			this->tabPage1->Controls->Add(this->textBoxMaxOtklonenieWhere);
			this->tabPage1->Controls->Add(this->label7);
			this->tabPage1->Controls->Add(this->textBoxMaxOtklonenie);
			this->tabPage1->Controls->Add(this->dataGridView2);
			this->tabPage1->Controls->Add(this->dataGridView1);
			this->tabPage1->Controls->Add(this->label5);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(942, 637);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Розыгрыш значений с.в.";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(345, 9);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(13, 13);
			this->label16->TabIndex = 15;
			this->label16->Text = L"в";
			// 
			// textBoxMaxOtklonenieWhere
			// 
			this->textBoxMaxOtklonenieWhere->Location = System::Drawing::Point(364, 6);
			this->textBoxMaxOtklonenieWhere->Name = L"textBoxMaxOtklonenieWhere";
			this->textBoxMaxOtklonenieWhere->Size = System::Drawing::Size(38, 20);
			this->textBoxMaxOtklonenieWhere->TabIndex = 14;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(0, 6);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(271, 13);
			this->label7->TabIndex = 13;
			this->label7->Text = L"Максимальное отклонение частоты от вероятности";
			// 
			// textBoxMaxOtklonenie
			// 
			this->textBoxMaxOtklonenie->Location = System::Drawing::Point(277, 6);
			this->textBoxMaxOtklonenie->Name = L"textBoxMaxOtklonenie";
			this->textBoxMaxOtklonenie->Size = System::Drawing::Size(58, 20);
			this->textBoxMaxOtklonenie->TabIndex = 12;
			this->textBoxMaxOtklonenie->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->label14);
			this->tabPage2->Controls->Add(this->textBoxMeraRashoj);
			this->tabPage2->Controls->Add(this->label13);
			this->tabPage2->Controls->Add(this->label12);
			this->tabPage2->Controls->Add(this->label11);
			this->tabPage2->Controls->Add(this->label10);
			this->tabPage2->Controls->Add(this->label9);
			this->tabPage2->Controls->Add(this->label8);
			this->tabPage2->Controls->Add(this->label15);
			this->tabPage2->Controls->Add(this->panel1);
			this->tabPage2->Controls->Add(this->dataGridView3);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(942, 637);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Характеристики";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(483, 6);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(104, 13);
			this->label14->TabIndex = 21;
			this->label14->Text = L"Мера расхождения";
			// 
			// textBoxMeraRashoj
			// 
			this->textBoxMeraRashoj->Location = System::Drawing::Point(486, 22);
			this->textBoxMeraRashoj->Name = L"textBoxMeraRashoj";
			this->textBoxMeraRashoj->Size = System::Drawing::Size(166, 20);
			this->textBoxMeraRashoj->TabIndex = 20;
			this->textBoxMeraRashoj->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxMeraRashoj_TextChanged);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(5, 202);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(28, 13);
			this->label13->TabIndex = 19;
			this->label13->Text = L"0,75";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(5, 321);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(28, 13);
			this->label12->TabIndex = 18;
			this->label12->Text = L"0,25";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(9, 263);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(22, 13);
			this->label11->TabIndex = 17;
			this->label11->Text = L"0,5";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(20, 144);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(13, 13);
			this->label10->TabIndex = 16;
			this->label10->Text = L"1";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(30, 393);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(694, 13);
			this->label9->TabIndex = 15;
			this->label9->Text = resources->GetString(L"label9.Text");
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(7, 109);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(26, 13);
			this->label8->TabIndex = 14;
			this->label8->Text = L"F(X)";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(727, 393);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(14, 13);
			this->label15->TabIndex = 13;
			this->label15->Text = L"Х";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel1->Location = System::Drawing::Point(33, 109);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(708, 281);
			this->panel1->TabIndex = 12;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			// 
			// dataGridView3
			// 
			this->dataGridView3->BackgroundColor = System::Drawing::SystemColors::Control;
			this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView3->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
				this->Column5,
					this->Column6, this->Column7, this->Column8, this->Column9, this->Column10, this->Column11, this->Column12
			});
			this->dataGridView3->Location = System::Drawing::Point(33, 6);
			this->dataGridView3->Name = L"dataGridView3";
			this->dataGridView3->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			this->dataGridView3->RowHeadersVisible = false;
			this->dataGridView3->Size = System::Drawing::Size(444, 84);
			this->dataGridView3->TabIndex = 11;
			this->dataGridView3->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView3_CellContentClick);
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Eη";
			this->Column5->Name = L"Column5";
			this->Column5->Width = 50;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L" x̅";
			this->Column6->Name = L"Column6";
			this->Column6->Width = 50;
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"|Eη- x̅|";
			this->Column7->Name = L"Column7";
			this->Column7->Width = 70;
			// 
			// Column8
			// 
			this->Column8->HeaderText = L"Dη";
			this->Column8->Name = L"Column8";
			this->Column8->Width = 50;
			// 
			// Column9
			// 
			this->Column9->HeaderText = L"S^2";
			this->Column9->Name = L"Column9";
			this->Column9->Width = 50;
			// 
			// Column10
			// 
			this->Column10->HeaderText = L"|Dη-S2|";
			this->Column10->Name = L"Column10";
			this->Column10->Width = 70;
			// 
			// Column11
			// 
			this->Column11->HeaderText = L"Me^";
			this->Column11->Name = L"Column11";
			this->Column11->Width = 50;
			// 
			// Column12
			// 
			this->Column12->HeaderText = L"R^";
			this->Column12->Name = L"Column12";
			this->Column12->Width = 50;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->label21);
			this->tabPage3->Controls->Add(this->textBoxResult);
			this->tabPage3->Controls->Add(this->textBoxFR0);
			this->tabPage3->Controls->Add(this->label19);
			this->tabPage3->Controls->Add(this->textboxR0);
			this->tabPage3->Controls->Add(this->label20);
			this->tabPage3->Controls->Add(this->dataGridView4);
			this->tabPage3->Controls->Add(this->buttonZadat);
			this->tabPage3->Controls->Add(this->textBoxAlpha);
			this->tabPage3->Controls->Add(this->label18);
			this->tabPage3->Controls->Add(this->textBoxNumOfIntervals);
			this->tabPage3->Controls->Add(this->label17);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(942, 637);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Проверка Гипотиз";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(458, 81);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(62, 13);
			this->label21->TabIndex = 17;
			this->label21->Text = L"Результат:";
			// 
			// textBoxResult
			// 
			this->textBoxResult->Location = System::Drawing::Point(526, 74);
			this->textBoxResult->Name = L"textBoxResult";
			this->textBoxResult->Size = System::Drawing::Size(100, 20);
			this->textBoxResult->TabIndex = 16;
			// 
			// textBoxFR0
			// 
			this->textBoxFR0->Location = System::Drawing::Point(526, 47);
			this->textBoxFR0->Name = L"textBoxFR0";
			this->textBoxFR0->Size = System::Drawing::Size(228, 20);
			this->textBoxFR0->TabIndex = 15;
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(458, 54);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(33, 13);
			this->label19->TabIndex = 14;
			this->label19->Text = L"F(R0)";
			// 
			// textboxR0
			// 
			this->textboxR0->Location = System::Drawing::Point(526, 15);
			this->textboxR0->Name = L"textboxR0";
			this->textboxR0->Size = System::Drawing::Size(228, 20);
			this->textboxR0->TabIndex = 13;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(458, 22);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(21, 13);
			this->label20->TabIndex = 12;
			this->label20->Text = L"R0";
			// 
			// dataGridView4
			// 
			this->dataGridView4->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView4->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Column13,
					this->Column14, this->Column15, this->Column16
			});
			this->dataGridView4->Location = System::Drawing::Point(9, 38);
			this->dataGridView4->Name = L"dataGridView4";
			this->dataGridView4->Size = System::Drawing::Size(438, 458);
			this->dataGridView4->TabIndex = 11;
			this->dataGridView4->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView4_CellContentClick);
			// 
			// Column13
			// 
			this->Column13->HeaderText = L" Интервал";
			this->Column13->Name = L"Column13";
			// 
			// Column14
			// 
			this->Column14->HeaderText = L"Значение";
			this->Column14->Name = L"Column14";
			// 
			// Column15
			// 
			this->Column15->HeaderText = L"Количество попаданий";
			this->Column15->Name = L"Column15";
			// 
			// Column16
			// 
			this->Column16->HeaderText = L"Теоритические вероятности(q)";
			this->Column16->Name = L"Column16";
			// 
			// buttonZadat
			// 
			this->buttonZadat->Location = System::Drawing::Point(356, 11);
			this->buttonZadat->Name = L"buttonZadat";
			this->buttonZadat->Size = System::Drawing::Size(75, 23);
			this->buttonZadat->TabIndex = 10;
			this->buttonZadat->Text = L"Задать";
			this->buttonZadat->UseVisualStyleBackColor = true;
			this->buttonZadat->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBoxAlpha
			// 
			this->textBoxAlpha->Location = System::Drawing::Point(299, 13);
			this->textBoxAlpha->Name = L"textBoxAlpha";
			this->textBoxAlpha->Size = System::Drawing::Size(51, 20);
			this->textBoxAlpha->TabIndex = 9;
			this->textBoxAlpha->Text = L"0,05";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(166, 15);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(127, 13);
			this->label18->TabIndex = 8;
			this->label18->Text = L"Уровень значимости(α)";
			// 
			// textBoxNumOfIntervals
			// 
			this->textBoxNumOfIntervals->Location = System::Drawing::Point(113, 12);
			this->textBoxNumOfIntervals->Name = L"textBoxNumOfIntervals";
			this->textBoxNumOfIntervals->Size = System::Drawing::Size(47, 20);
			this->textBoxNumOfIntervals->TabIndex = 3;
			this->textBoxNumOfIntervals->Text = L"4";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(6, 12);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(101, 13);
			this->label17->TabIndex = 2;
			this->label17->Text = L"Число интервалов";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(966, 862);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->buttonGO);
			this->Controls->Add(this->textBoxNumberOfExp);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->buttonUpdatePMatrix);
			this->Controls->Add(this->textBoxNumberOfShoots);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->EndInit();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

	private: void InitializePMatrix() {
		std::vector<double> first = { 0, 0, 1, 0, 0 };
		std::vector<double> second = { 0, 0, 0, 1, 0 };
		std::vector<double> third = { 0, 0, 0, 0, 1.0 };

		P.push_back(first);
		P.push_back(second);
		P.push_back(third);
	}

	private: void FillTheDataGrid() {
		dataGridView1->Rows->Clear();

		for (int i = 0; i < R; i++) {
			dataGridView1->Rows->Add();
			dataGridView1->Rows[i]->Cells[0]->Value = i + 1;
			dataGridView1->Rows[i]->Cells[1]->Value = P[0][i];
			dataGridView1->Rows[i]->Cells[2]->Value = P[1][i];
			dataGridView1->Rows[i]->Cells[3]->Value = P[2][i];
		}
	}

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {

	}

	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {

	}

	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {

	}

	private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	
	}
	private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {

	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		// Update R and update P matrix and refill the date grid 

		String^ Rstr = textBoxNumberOfShoots->Text;
		R = R.Parse(Rstr);

		RemakePMatrix();

		FillTheDataGrid();
	}

	private: void RemakePMatrix() {
		double step = 1.0 / R;
		double cur = step;
		
		for (int i = 0; i < 3; i++) {
			P[i].clear();
		}

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < 3; j++) {
				P[j].push_back(cur);
			}
			cur += step;
		}
	}

	private: System::Void textBoxNumberOfShoots_TextChanged(System::Object^  sender, System::EventArgs^  e) {

	}

	private: int searchSV() {
		int sv = 0;

		for (int j = 0; j < 3; j++) {
			for (int i = 0; i < R; i++) {
				double p = P[j][i];

				sv++;
				double u = double(rand()) / RAND_MAX; // RAND_MAX = 32767

				if (u <= p && p != 0) {
					break;
				}
			}
		}

		return sv;
	}

	private: double F(double x) {
		int index = x;
		return FteorRaspredelenie[index];
	}

			 /*
	private: double G(double x) {
		if (x == 1) return 1;
		if (x == 0.5) return sqrt(pi);
		return (x - 1) * G(x - 1);
	}

	private: double fhi2(double x) {
		//if (x <= 0) return 0;
		double e = 2.1718281828459045;
		return pow(2, -(k - 1) / 2) * (pow(G((k - 1) / 2), -1)) * pow(x, (k - 1) / 2 - 1) * pow(e, -x / 2);
	}
	*/

		private: double G(double a)
		{
			if (a == 0.5) return sqrt(pi);
			if (a == 1)
				return 1;
			else
				return (a - 1)*G(a - 1);
		}

		private: double g(double x)
		{
			if (x <= 0) return 0;
			double e = 2.7182818285;
			//return pow(2, -(k - 1) / 2)*(pow(G((k - 1) / 2), -1))*pow(x, (k - 1) / 2 - 1)*pow(e, -x / 2);
			return pow(2, -(double)k / 2.0) * (pow(G((double)k / 2.0), -1)) * pow(x, (double)k / 2.0 - 1) * pow(e, -x / 2);
		}

	private: void LoadPMatrix() {
		for (int i = 0; i < 3; i++) {
			P[i].clear();
			for (int j = 0; j < R; j++) {			
				String^ str = dataGridView1->Rows[j]->Cells[i + 1]->Value->ToString();

				double cur = cur.Parse(str);
				P[i].push_back(cur);
			}
		}
	}
	private: void CalcFteor() {
		for (int x = 1; x <= 10005; x++) {
			FteorRaspredelenie[x] = FteorRaspredelenie[x - 1] + ryadR[x];
		}
	}
	private: System::Void buttonGO_Click(System::Object^  sender, System::EventArgs^  e) {
		//RASSCHET
		LoadPMatrix();
		mapka.clear();
		ryadR = CalcRyadRaspredelenia();
		CalcFteor();
		

		String^ Nstr = textBoxNumberOfExp->Text;
		N = N.Parse(Nstr);


		String^ str7;
		str7 = textBoxAlpha->Text;
		alpha = alpha.Parse(str7);


		std::vector<int> viborka;
		double E = 0; //мат. ожидание
		double xs = 0; //выборочное среднее
		double D = 0; //дисперсия
		double S2 = 0; //выборочная дисперсия
		double Me = 0;
		double Razmah = 0; //размах выборки
		double max = 0; //максимальное отклонение частоты от вероятности 
		double maxWhere = -1; // номер максимальное отклонение частоты от вероятности 

		canPlotGraph = 1;


		std::vector<double> teorProbPopadaniaVInterval(N); //теорeтическая вероятность попадания в интервал 
		std::vector<int> numViborkaPopadaniaVInterval(N, 0); //число наблюдений, в j интервале
		std::vector<double> interval(N); //интервалы
		double R0 = 0; //мера расхождения 



		dataGridView2->Rows->Clear();
		dataGridView3->Rows->Clear();

		//E, D:
		for (auto o : ryadR) {
			int sv = o.first;
			double freq = o.second;

			E += sv * freq;
			D += sv * sv * freq;
		}
		D -= E * E;

		dataGridView3->Rows->Add();

		srand((unsigned int)time(0));
		for (int i = 0; i <= N - 1; i++) {
			int sv = searchSV();
			mapka[sv]++;
			viborka.push_back(sv);
		}

		std::sort(viborka.begin(), viborka.end());

		int i = 0;
		for (auto o : mapka) {
			int sv = o.first;
			int num = o.second;
			double freq = (double)num / N;
			double rasrpFreq = ryadR[sv];

			dataGridView2->Rows->Add();
			dataGridView2->Rows[i]->Cells[0]->Value = sv.ToString();
			dataGridView2->Rows[i]->Cells[1]->Value = num.ToString();
			dataGridView2->Rows[i]->Cells[2]->Value = freq.ToString();
			dataGridView2->Rows[i]->Cells[3]->Value = rasrpFreq.ToString();

			double tmp = abs(rasrpFreq - freq);
			if (tmp >= max) {
				max = tmp;
				maxWhere = sv;
			}

			xs += sv * freq;

			i++;
		}
		textBoxMaxOtklonenie->Text = max.ToString();
		textBoxMaxOtklonenieWhere->Text = maxWhere.ToString();

		dataGridView3->Rows[0]->Cells[0]->Value = E.ToString();
		dataGridView3->Rows[0]->Cells[1]->Value = xs.ToString();
		dataGridView3->Rows[0]->Cells[2]->Value = abs(E - xs).ToString();

		//S2:
		for (auto o : mapka) {
			int sv = o.first;
			double num = o.second;
			S2 += (sv - xs) * (sv - xs) * num;
		}
		S2 /= N;

		dataGridView3->Rows[0]->Cells[3]->Value = D.ToString();
		dataGridView3->Rows[0]->Cells[4]->Value = S2.ToString();
		dataGridView3->Rows[0]->Cells[5]->Value = abs(D - S2).ToString();
			
		if (N % 2)
			Me = viborka[N / 2];
		else 
			Me = (viborka[N / 2 - 1] + viborka[N / 2]) / 2;

		dataGridView3->Rows[0]->Cells[6]->Value = Me.ToString();

		Razmah = viborka[N - 1] - viborka[0];
		dataGridView3->Rows[0]->Cells[7]->Value = Razmah.ToString();
		panel1->Refresh();



		//------------------------------------ laba 3:
		
		interval[0] = 0;
		for (int i = 1; i <= k; i++) {
			interval[i] = Convert::ToDouble(dataGridView4->Rows[i - 1]->Cells[1]->Value);
		}

		for (int i = 0; i < N; i++) {
			int j = 1;
			while (j <= k) {
				if (viborka[i] <= interval[j]) {
					numViborkaPopadaniaVInterval[j]++;
					break;
				}
				else {
					j++;
				}
			}
		}

		int N1 = N;
		int j = 0;
		for (j = 1; j <= k; j++) {
			dataGridView4->Rows[j - 1]->Cells[2]->Value = (numViborkaPopadaniaVInterval[j]).ToString();
			N1 -= numViborkaPopadaniaVInterval[j];
		}

		numViborkaPopadaniaVInterval[j] = N1;
		dataGridView4->Rows[j - 1]->Cells[2]->Value = (numViborkaPopadaniaVInterval[j]).ToString();

		int j1 = 0;
		for (j1 = 1; j1 <= k; j1++) {
			teorProbPopadaniaVInterval[j1] = FteorRaspredelenie[interval[j1]] - FteorRaspredelenie[interval[j1 - 1]];
			dataGridView4->Rows[j1 - 1]->Cells[3]->Value = (teorProbPopadaniaVInterval[j1]).ToString();
		}

		teorProbPopadaniaVInterval[j1] = 1 - FteorRaspredelenie[interval[j1 - 1]];
		dataGridView4->Rows[j1 - 1]->Cells[3]->Value = (teorProbPopadaniaVInterval[j1]).ToString();

		for (int j = 1; j <= k + 1; j++) {
			double n1 = numViborkaPopadaniaVInterval[j];
			double n2 = teorProbPopadaniaVInterval[j];
			R0 += pow(n1 - N * n2, 2) / (N * n2);
			textboxR0->Text = R0.ToString();
		}



		double a = 0; double b = R0; double integral = 0; 
		int N = 1000;
		for (int i = 1; i < N; i++) {
			integral += (g(a + (b - a) * (i - 1) / N) + g(a + (b - a)*(i) / N)) * (b - a) / (2 * N);
		}
		
		textBoxFR0->Text = (1 - integral).ToString();

		if ((1 - integral) < alpha) textBoxResult->Text = "Отклоняем";
		else textBoxResult->Text = "Принимаем";
	}

	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		//GRAFIK

		Graphics^ g = e->Graphics;

		Pen^ penBlack = gcnew Pen(Color::Black);
		Pen^ penRed = gcnew Pen(Color::Red);
		Pen^ penGray = gcnew Pen(Color::LightGray);

		int sizeCageX = 40;
		int sizeCageY = 240;

		std::map<int, double> ryadR = CalcRyadRaspredelenia();
		double pt = 0;

		//Kletki:
		for (int i = 0; i <= panel1->Width; i += sizeCageX)
		{
			Point p1 = Point(i, 0);
			Point p2 = Point(i, panel1->Height);
			g->DrawLine(penGray, p1, p2);
		}
		for (int j = panel1->Height; j >= 0; j -= sizeCageY / 4)
		{
			Point p1 = Point(0, j);
			Point p2 = Point(panel1->Width, j);
			g->DrawLine(penGray, p1, p2);
		}

		if (canPlotGraph) {
			//Teoriya F(x):
			//Praktika F(x):
		
			double MeraRashoj = 0; //мера расхождения
			auto it1 = mapka.begin();
			auto it2 = mapka.begin();
			it2++;
			double Fprak = 0, Fteor = 0;

			Point p1 = Point(0, panel1->Height - 1);
			Point p2 = Point(3 * sizeCageX, panel1->Height - 1);
			g->DrawLine(penRed, p1, p2);
			g->DrawLine(penBlack, p1, p2);

			for (int x = 1; x < 20; x++) {
				Fprak += (double)mapka[x] / N;
				Fteor += ryadR[x];

				Point p1 = Point(x * sizeCageX, panel1->Height - Fteor*sizeCageY);
				Point p2 = Point((x + 1) * sizeCageX, panel1->Height - Fteor*sizeCageY);
				g->DrawLine(penBlack, p1, p2);

				Point p3 = Point(x * sizeCageX, panel1->Height - Fprak*sizeCageY);	
				Point p4 = Point((x + 1) * sizeCageX, panel1->Height - Fprak*sizeCageY);
				if (Fprak == 0) {
					p3 = Point(x * sizeCageX, panel1->Height - 1);
					p4 = Point((x + 1) * sizeCageX, panel1->Height - 1);
				}
				g->DrawLine(penRed, p3, p4);

				if (abs(Fprak - Fteor) > MeraRashoj) MeraRashoj = abs(Fprak - Fteor);
			}

			textBoxMeraRashoj->Text = MeraRashoj.ToString();
		}
	}

	private: double p(int x, int y) {
		if (y < R) return P[x][y];
		else return 1;
	}

	private: std::map<int, double> CalcRyadRaspredelenia() {
		std::map<int, double> mapka;
		// etta : 3, ... , 3 * r

		// (a,b,c) : a,b,c = 0...R-1 - nomer vystrela kogda popal

		for (int a = 0; a < R; a++) {
			for (int b = 0; b < R; b++) {
				for (int c = 0; c < R; c++) {
					int sum = a + b + c + 3; // kolvo vystrelov
					double cur = 1; // veroyatnost` etogo ishoda

					for (int i = 0; i < a; i++) {
						cur *= (1 - p(0, i));
					}
					if(a != R - 1) cur *= p(0, a);

					for (int i = 0; i < b; i++) {
						cur *= (1 - p(1, i));
					}
					if(b != R - 1) cur *= p(1, b);

					for (int i = 0; i < c; i++) {
						cur *= (1 - p(2, i));
					}
					if(c != R - 1) cur *= p(2, c);

					mapka[sum] += cur;
				}
			}
		}

		return mapka;
	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		while (dataGridView4->RowCount > 1) {
			int r = dataGridView4->RowCount;
			dataGridView4->Rows->RemoveAt(dataGridView4->RowCount - 2);
		}


		String^ str2;
		str2 = textBoxNumOfIntervals->Text;
		k = k.Parse(str2);
		for (int i = 0; i < k; i++)
		{
			dataGridView4->Rows->Add();
			dataGridView4->Rows[i]->Cells[0]->Value = "Z" + (i + 1).ToString();
		}
		dataGridView4->Rows->Add();
	}

private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void dataGridView2_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
}
private: System::Void dataGridView3_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
}
private: System::Void textBoxMeraRashoj_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void dataGridView4_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
}
};

}
