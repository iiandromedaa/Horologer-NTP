#pragma once


#include <Windows.h>
#include "wndstatus.h"
#include "AboutWindow.h"

namespace Horologer_NTP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
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
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ alarmsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ setAlarmsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ settingsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ nTPSettingsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ displaySettingsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ aboutToolStripMenuItem;
	private: System::Windows::Forms::Label^ NTPtime;
	private: System::Windows::Forms::Label^ CurrLocalLabel;
	private: System::Windows::Forms::Label^ SynchroLabel;
	private: System::Windows::Forms::Label^ SysAccuLabel;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ NTPping;


	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->alarmsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->setAlarmsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->nTPSettingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->displaySettingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->NTPtime = (gcnew System::Windows::Forms::Label());
			this->CurrLocalLabel = (gcnew System::Windows::Forms::Label());
			this->SynchroLabel = (gcnew System::Windows::Forms::Label());
			this->SysAccuLabel = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->NTPping = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->alarmsToolStripMenuItem,
					this->settingsToolStripMenuItem, this->helpToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(584, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// alarmsToolStripMenuItem
			// 
			this->alarmsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->setAlarmsToolStripMenuItem });
			this->alarmsToolStripMenuItem->Name = L"alarmsToolStripMenuItem";
			this->alarmsToolStripMenuItem->Size = System::Drawing::Size(56, 20);
			this->alarmsToolStripMenuItem->Text = L"Alarms";
			// 
			// setAlarmsToolStripMenuItem
			// 
			this->setAlarmsToolStripMenuItem->Name = L"setAlarmsToolStripMenuItem";
			this->setAlarmsToolStripMenuItem->Size = System::Drawing::Size(130, 22);
			this->setAlarmsToolStripMenuItem->Text = L"Set Alarms";
			// 
			// settingsToolStripMenuItem
			// 
			this->settingsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->nTPSettingsToolStripMenuItem,
					this->displaySettingsToolStripMenuItem
			});
			this->settingsToolStripMenuItem->Name = L"settingsToolStripMenuItem";
			this->settingsToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			this->settingsToolStripMenuItem->Text = L"Settings";
			// 
			// nTPSettingsToolStripMenuItem
			// 
			this->nTPSettingsToolStripMenuItem->Name = L"nTPSettingsToolStripMenuItem";
			this->nTPSettingsToolStripMenuItem->Size = System::Drawing::Size(157, 22);
			this->nTPSettingsToolStripMenuItem->Text = L"NTP Settings";
			// 
			// displaySettingsToolStripMenuItem
			// 
			this->displaySettingsToolStripMenuItem->Name = L"displaySettingsToolStripMenuItem";
			this->displaySettingsToolStripMenuItem->Size = System::Drawing::Size(157, 22);
			this->displaySettingsToolStripMenuItem->Text = L"Display Settings";
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->aboutToolStripMenuItem });
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			// 
			// NTPtime
			// 
			this->NTPtime->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->NTPtime->AutoSize = true;
			this->NTPtime->BackColor = System::Drawing::Color::Black;
			this->NTPtime->Font = (gcnew System::Drawing::Font(L"alarm clock", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NTPtime->ForeColor = System::Drawing::Color::LimeGreen;
			this->NTPtime->Location = System::Drawing::Point(133, 103);
			this->NTPtime->MaximumSize = System::Drawing::Size(320, 67);
			this->NTPtime->Name = L"NTPtime";
			this->NTPtime->Size = System::Drawing::Size(320, 67);
			this->NTPtime->TabIndex = 1;
			this->NTPtime->Text = L"12:00 AM";
			this->NTPtime->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->NTPtime->Click += gcnew System::EventHandler(this, &MainWindow::label1_Click);
			// 
			// CurrLocalLabel
			// 
			this->CurrLocalLabel->AutoSize = true;
			this->CurrLocalLabel->Location = System::Drawing::Point(238, 81);
			this->CurrLocalLabel->Name = L"CurrLocalLabel";
			this->CurrLocalLabel->Size = System::Drawing::Size(96, 13);
			this->CurrLocalLabel->TabIndex = 2;
			this->CurrLocalLabel->Text = L"Current Local Time";
			// 
			// SynchroLabel
			// 
			this->SynchroLabel->AutoSize = true;
			this->SynchroLabel->Location = System::Drawing::Point(345, 222);
			this->SynchroLabel->Name = L"SynchroLabel";
			this->SynchroLabel->Size = System::Drawing::Size(70, 13);
			this->SynchroLabel->TabIndex = 3;
			this->SynchroLabel->Text = L"NTP Latency";
			// 
			// SysAccuLabel
			// 
			this->SysAccuLabel->AutoSize = true;
			this->SysAccuLabel->Location = System::Drawing::Point(132, 222);
			this->SysAccuLabel->Name = L"SysAccuLabel";
			this->SysAccuLabel->Size = System::Drawing::Size(119, 13);
			this->SysAccuLabel->TabIndex = 4;
			this->SysAccuLabel->Text = L"System Clock Accuracy";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Black;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::LimeGreen;
			this->label4->Location = System::Drawing::Point(161, 246);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(58, 18);
			this->label4->TabIndex = 5;
			this->label4->Text = L"+0.0ms";
			// 
			// NTPping
			// 
			this->NTPping->AutoSize = true;
			this->NTPping->BackColor = System::Drawing::Color::Black;
			this->NTPping->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NTPping->ForeColor = System::Drawing::Color::LimeGreen;
			this->NTPping->Location = System::Drawing::Point(357, 246);
			this->NTPping->Name = L"NTPping";
			this->NTPping->Size = System::Drawing::Size(58, 18);
			this->NTPping->TabIndex = 6;
			this->NTPping->Text = L"+0.0ms";
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 357);
			this->Controls->Add(this->NTPping);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->SysAccuLabel);
			this->Controls->Add(this->SynchroLabel);
			this->Controls->Add(this->CurrLocalLabel);
			this->Controls->Add(this->NTPtime);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainWindow";
			this->Text = L"Horologer NTP";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void about_click(System::Object^ sender, System::EventArgs^ e) {
	//if (!aboutwndo) {
		//aboutwndo = true;
		AboutWindow^ aboutwnd = gcnew AboutWindow();
		aboutwnd->ShowDialog();
	//}
}
};
}
