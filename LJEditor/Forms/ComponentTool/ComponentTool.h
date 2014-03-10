#pragma once

#include "../../Controls/CFileBrowser.h"

namespace LJEditor {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::IO;

	/// <summary>
	/// Summary for ComponentTool
	/// </summary>
	public ref class ComponentTool : public System::Windows::Forms::Form
	{
	public:
		ComponentTool(void)
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
		~ComponentTool()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::SplitContainer^  scMain;
	protected: 
	private: System::Windows::Forms::TreeView^  tvFileBrowser;

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
			this->scMain = (gcnew System::Windows::Forms::SplitContainer());
			this->tvFileBrowser = (gcnew System::Windows::Forms::TreeView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->scMain))->BeginInit();
			this->scMain->Panel1->SuspendLayout();
			this->scMain->SuspendLayout();
			this->SuspendLayout();
			// 
			// scMain
			// 
			this->scMain->Dock = System::Windows::Forms::DockStyle::Fill;
			this->scMain->Location = System::Drawing::Point(0, 0);
			this->scMain->Name = L"scMain";
			// 
			// scMain.Panel1
			// 
			this->scMain->Panel1->Controls->Add(this->tvFileBrowser);
			this->scMain->Size = System::Drawing::Size(915, 539);
			this->scMain->SplitterDistance = 170;
			this->scMain->TabIndex = 0;
			// 
			// tvFileBrowser
			// 
			this->tvFileBrowser->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tvFileBrowser->Location = System::Drawing::Point(0, 0);
			this->tvFileBrowser->Name = L"tvFileBrowser";
			this->tvFileBrowser->Size = System::Drawing::Size(170, 539);
			this->tvFileBrowser->TabIndex = 0;
			// 
			// ComponentTool
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(915, 539);
			this->Controls->Add(this->scMain);
			this->Name = L"ComponentTool";
			this->Text = L"ComponentTool";
			this->Load += gcnew System::EventHandler(this, &ComponentTool::ComponentTool_Load);
			this->scMain->Panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->scMain))->EndInit();
			this->scMain->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: 
		System::Void ComponentTool_Load(System::Object^  sender, System::EventArgs^  e) 
		{
			SetUpFileBrowser();
		}
	public:
		void SetUpFileBrowser()
		{
			CFileBrowser^ fileBrowser = gcnew CFileBrowser(tvFileBrowser, String::Concat( Application::StartupPath + "..\\..\\..\\..\\" ));
		}
	};
}
