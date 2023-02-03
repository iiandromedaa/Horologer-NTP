#pragma once
#include <Windows.h>
#include "MainWindow.h"
#include "wndstatus.h"


namespace Horologer_NTP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AboutWindow
	/// </summary>
	public ref class AboutWindow : public System::Windows::Forms::Form
	{
	public:
		AboutWindow(void)
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
		~AboutWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Button^ okbutton;
	private: System::Windows::Forms::PictureBox^ Logo;

	private: System::Windows::Forms::Label^ versionLabel;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::LinkLabel^ profileLink;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::LinkLabel^ linkLabel1;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AboutWindow::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->okbutton = (gcnew System::Windows::Forms::Button());
			this->Logo = (gcnew System::Windows::Forms::PictureBox());
			this->versionLabel = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->profileLink = (gcnew System::Windows::Forms::LinkLabel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Logo))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(153, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(78, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Horologer NTP";
			this->label1->Click += gcnew System::EventHandler(this, &AboutWindow::label1_Click);
			// 
			// okbutton
			// 
			this->okbutton->Location = System::Drawing::Point(156, 138);
			this->okbutton->Name = L"okbutton";
			this->okbutton->Size = System::Drawing::Size(75, 23);
			this->okbutton->TabIndex = 1;
			this->okbutton->Text = L"Ok";
			this->okbutton->UseVisualStyleBackColor = true;
			this->okbutton->Click += gcnew System::EventHandler(this, &AboutWindow::button1_click);
			// 
			// Logo
			// 
			this->Logo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Logo.Image")));
			this->Logo->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Logo.InitialImage")));
			this->Logo->Location = System::Drawing::Point(24, 23);
			this->Logo->Name = L"Logo";
			this->Logo->Size = System::Drawing::Size(94, 99);
			this->Logo->TabIndex = 2;
			this->Logo->TabStop = false;
			// 
			// versionLabel
			// 
			this->versionLabel->AutoSize = true;
			this->versionLabel->Location = System::Drawing::Point(153, 36);
			this->versionLabel->Name = L"versionLabel";
			this->versionLabel->Size = System::Drawing::Size(86, 13);
			this->versionLabel->TabIndex = 4;
			this->versionLabel->Text = L"VERSION_NUM";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(153, 49);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(147, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Copyright (c) 2023 AndroBohij";
			this->label3->Click += gcnew System::EventHandler(this, &AboutWindow::label3_Click);
			// 
			// profileLink
			// 
			this->profileLink->AutoSize = true;
			this->profileLink->Location = System::Drawing::Point(153, 62);
			this->profileLink->Name = L"profileLink";
			this->profileLink->Size = System::Drawing::Size(163, 13);
			this->profileLink->TabIndex = 6;
			this->profileLink->TabStop = true;
			this->profileLink->Text = L"https://github.com/iiandromedaa";
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(153, 84);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(163, 26);
			this->label2->TabIndex = 7;
			this->label2->Text = L"simpleini Copyright (c) 2006-2023, Brodie Thiesfield";
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Location = System::Drawing::Point(153, 110);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(178, 13);
			this->linkLabel1->TabIndex = 8;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"https://github.com/brofield/simpleini";
			// 
			// AboutWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(387, 173);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->profileLink);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->versionLabel);
			this->Controls->Add(this->Logo);
			this->Controls->Add(this->okbutton);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"AboutWindow";
			this->Text = L"About";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Logo))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_click(System::Object^ sender, System::EventArgs^ e) {
		aboutwndo = false;
		this->Close();
	}
};
}
