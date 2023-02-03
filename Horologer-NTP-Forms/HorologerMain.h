#pragma once

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ changeNTPServerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ aboutToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ alarmsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ setAlarmsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ clockLayoutToolStripMenuItem;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->alarmsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->setAlarmsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->changeNTPServerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clockLayoutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->alarmsToolStripMenuItem,
					this->aboutToolStripMenuItem, this->helpToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(695, 24);
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
			this->setAlarmsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::setAlarmsToolStripMenuItem_Click);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->changeNTPServerToolStripMenuItem,
					this->clockLayoutToolStripMenuItem
			});
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			this->aboutToolStripMenuItem->Text = L"Settings";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::aboutToolStripMenuItem_Click);
			// 
			// changeNTPServerToolStripMenuItem
			// 
			this->changeNTPServerToolStripMenuItem->Name = L"changeNTPServerToolStripMenuItem";
			this->changeNTPServerToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->changeNTPServerToolStripMenuItem->Text = L"NTP Server";
			this->changeNTPServerToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::changeNTPServerToolStripMenuItem_Click);
			// 
			// clockLayoutToolStripMenuItem
			// 
			this->clockLayoutToolStripMenuItem->Name = L"clockLayoutToolStripMenuItem";
			this->clockLayoutToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->clockLayoutToolStripMenuItem->Text = L"Clock Layout";
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->aboutToolStripMenuItem1 });
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// aboutToolStripMenuItem1
			// 
			this->aboutToolStripMenuItem1->Name = L"aboutToolStripMenuItem1";
			this->aboutToolStripMenuItem1->Size = System::Drawing::Size(107, 22);
			this->aboutToolStripMenuItem1->Text = L"About";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(695, 448);
			this->Controls->Add(this->menuStrip1);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Form1";
			this->Text = L"Horologer NTP";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void aboutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void changeNTPServerToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void setAlarmsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
