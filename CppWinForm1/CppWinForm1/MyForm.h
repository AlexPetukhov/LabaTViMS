#pragma once
#include <vector>
#include <ctime>
#include <math.h>
#include <map>


namespace CppWinForm1 {

	std::vector<std::vector<double> > P;
	int R;
	int N;


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
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  NumberOfShoot;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  FirstShooter;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  SecondShooter;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ThirdShooter;




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
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBoxNumberOfExp = (gcnew System::Windows::Forms::TextBox());
			this->buttonGO = (gcnew System::Windows::Forms::Button());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->NumberOfShoot = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->FirstShooter = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SecondShooter = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ThirdShooter = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
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
			this->dataGridView1->Location = System::Drawing::Point(420, 29);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(403, 431);
			this->dataGridView1->TabIndex = 5;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
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
			this->label5->Location = System::Drawing::Point(417, 13);
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
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Column1,
					this->Column2, this->Column3
			});
			this->dataGridView2->GridColor = System::Drawing::SystemColors::Control;
			this->dataGridView2->Location = System::Drawing::Point(19, 196);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersVisible = false;
			this->dataGridView2->Size = System::Drawing::Size(304, 600);
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
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(832, 807);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->buttonGO);
			this->Controls->Add(this->textBoxNumberOfExp);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->buttonUpdatePMatrix);
			this->Controls->Add(this->textBoxNumberOfShoots);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"Лабораторная работа по ТВиМС";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
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

	private: System::Void buttonGO_Click(System::Object^  sender, System::EventArgs^  e) {
		LoadPMatrix();

		std::map<int, int> mapka;

		String^ Nstr = textBoxNumberOfExp->Text;
		N = N.Parse(Nstr);


		dataGridView2->Rows->Clear();

		srand((unsigned int)time(0));

		for (int i = 0; i <= N - 1; i++) {
			int sv = searchSV();
			mapka[sv]++;
		}

		int i = 0;
		for (auto o : mapka) {
			int sv = o.first;
			int num = o.second;
			double freq = (double)num / (double)N;

			dataGridView2->Rows->Add();
			dataGridView2->Rows[i]->Cells[0]->Value = sv.ToString();
			dataGridView2->Rows[i]->Cells[1]->Value = num.ToString();
			dataGridView2->Rows[i]->Cells[2]->Value = freq.ToString();

			i++;
		}

	}

	private: System::Void dataGridView2_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {

	}
};

}
