#pragma once

#include "../../Controls/CFileBrowser.h"
#include "../../Source/ComponentInformation/ComponentInformation.h"

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
	private: System::Windows::Forms::PropertyGrid^  propertyGrid1;


	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		ComponentInformation^ m_ComponentInfo;
		
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->scMain = (gcnew System::Windows::Forms::SplitContainer());
			this->tvFileBrowser = (gcnew System::Windows::Forms::TreeView());
			this->propertyGrid1 = (gcnew System::Windows::Forms::PropertyGrid());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->scMain))->BeginInit();
			this->scMain->Panel1->SuspendLayout();
			this->scMain->Panel2->SuspendLayout();
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
			// 
			// scMain.Panel2
			// 
			this->scMain->Panel2->Controls->Add(this->propertyGrid1);
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
			// propertyGrid1
			// 
			this->propertyGrid1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->propertyGrid1->Location = System::Drawing::Point(0, 0);
			this->propertyGrid1->Name = L"propertyGrid1";
			this->propertyGrid1->Size = System::Drawing::Size(741, 539);
			this->propertyGrid1->TabIndex = 0;
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
			this->scMain->Panel2->ResumeLayout(false);
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

			m_ComponentInfo = gcnew ComponentInformation();

			this->propertyGrid1->SelectedObject = m_ComponentInfo;
		}
	};
}
