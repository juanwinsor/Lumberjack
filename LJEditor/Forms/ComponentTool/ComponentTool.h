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



	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->scMain))->BeginInit();
			this->scMain->Panel1->SuspendLayout();
			this->scMain->Panel2->SuspendLayout();
			this->scMain->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
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
			this->scMain->Panel2->Controls->Add(this->dataGridView1);
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
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(741, 539);
			this->dataGridView1->TabIndex = 0;
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
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
			CFileBrowser^ fileBrowser = gcnew CFileBrowser(tvFileBrowser, String::Concat( Application::StartupPath + "..\\..\\..\\..\\" ), true );

			m_ComponentInfo = gcnew ComponentInformation();
			m_ComponentInfo->Name = "TestName";
			//this->propertyGrid1->SelectedObject = m_ComponentInfo;

			CreateComponentTable( m_ComponentInfo );
		}

		//////////////////////////////////////////////////////////////////////////
		/// takes a components information and constructs a table from the values
		//////////////////////////////////////////////////////////////////////////
		void CreateComponentTable ( ComponentInformation ^ componentInformation )
		{
			
			String^ baseClassVar = System::Convert::ToString( componentInformation->BaseClass );
			
			//creating a new column and setting them so they aren't sortable
			this->dataGridView1->Columns->Add("Name", "Name");
			this->dataGridView1->Columns[ this->dataGridView1->Columns->GetColumnCount(DataGridViewElementStates::None) - 1]->SortMode = DataGridViewColumnSortMode::NotSortable;

			this->dataGridView1->Columns->Add("Type", "Type");
			this->dataGridView1->Columns[ this->dataGridView1->Columns->GetColumnCount(DataGridViewElementStates::None) - 1]->SortMode = DataGridViewColumnSortMode::NotSortable;

			this->dataGridView1->Columns->Add("Value", "Value");
			this->dataGridView1->Columns[ this->dataGridView1->Columns->GetColumnCount(DataGridViewElementStates::None) - 1]->SortMode = DataGridViewColumnSortMode::NotSortable;

			this->dataGridView1->Columns->Add("Discription", "Discription");
			this->dataGridView1->Columns[ this->dataGridView1->Columns->GetColumnCount(DataGridViewElementStates::None) - 1]->SortMode = DataGridViewColumnSortMode::NotSortable;
		}
	};
}
