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
			CFileBrowser^ fileBrowser = gcnew CFileBrowser(tvFileBrowser, String::Concat( Application::StartupPath + "..\\..\\..\\..\\LJEditor" ), true );

			m_ComponentInfo = gcnew ComponentInformation();
			m_ComponentInfo->Name = "TestName";
			m_ComponentInfo->ComponentParameters->Add( gcnew ComponentParameterInformation() );
			m_ComponentInfo->ComponentParameters[0]->Name = "TestName0";
			m_ComponentInfo->ComponentParameters[0]->Discription = "TestDiscription0";
			m_ComponentInfo->ComponentParameters[0]->VarType = 3;
			m_ComponentInfo->ComponentParameters[0]->LoadType = 0;
			m_ComponentInfo->ComponentParameters[0]->Value = " TestValue0" ;

			m_ComponentInfo->ComponentParameters->Add( gcnew ComponentParameterInformation() );
			m_ComponentInfo->ComponentParameters[1]->Name = "TestName1";
			m_ComponentInfo->ComponentParameters[1]->Discription = "TestDiscription1";
			m_ComponentInfo->ComponentParameters[1]->VarType = 1;
			m_ComponentInfo->ComponentParameters[1]->LoadType = 0;
			m_ComponentInfo->ComponentParameters[1]->Value = " TestValue1" ;

			m_ComponentInfo->ComponentParameters->Add( gcnew ComponentParameterInformation() );
			m_ComponentInfo->ComponentParameters[2]->Name = "TestName2";
			m_ComponentInfo->ComponentParameters[2]->Discription = "TestDiscription2";
			m_ComponentInfo->ComponentParameters[2]->VarType = 2;
			m_ComponentInfo->ComponentParameters[2]->LoadType = 1;
			m_ComponentInfo->ComponentParameters[2]->Value = " TestValue2" ;

			CreateComponentTable( m_ComponentInfo );
		}


		void CreateTableEntries( ComponentInformation ^ componentInformation )
		{
			List<String^>^ VariableTypes = gcnew List<String^>();
			VariableTypes->Add(" f32 ");
			VariableTypes->Add(" f64 ");
			VariableTypes->Add(" s32 ");
			VariableTypes->Add(" str ");
			VariableTypes->Add(" bool ");

			List<String^>^ LoadTypes = gcnew List<String^>();
			LoadTypes->Add(" static ");
			LoadTypes->Add(" state ");


			for( int counter = 0; counter < componentInformation->ComponentParameters->Count; counter++ )
			{
				String^ variableType = "";
				String^ loadType = "";

				switch( componentInformation->ComponentParameters[counter]->VarType )
				{
				case 0:
					variableType = VariableTypes[0];
					break;
				case 1:
					variableType = VariableTypes[1];
					break;
				case 2:
					variableType = VariableTypes[2];
					break;
				case 3:
					variableType = VariableTypes[3];
					break;
				case 4:
					variableType = VariableTypes[4];
					break;
				}

				switch( componentInformation->ComponentParameters[counter]->LoadType )
				{
				case 0:
					loadType = LoadTypes[0];
					break;
				case 1:
					loadType = LoadTypes[1];
					break;
				}
				this->dataGridView1->Rows[counter]->Cells[0]->Value = componentInformation->ComponentParameters[counter]->Name;
				this->dataGridView1->Rows[counter]->Cells[1]->Value = loadType;
				this->dataGridView1->Rows[counter]->Cells[2]->Value = variableType;
				this->dataGridView1->Rows[counter]->Cells[3]->Value = System::Convert::ToString( componentInformation->ComponentParameters[counter]->Value );
				this->dataGridView1->Rows[counter]->Cells[4]->Value = componentInformation->ComponentParameters[counter]->Discription;

				if( counter < componentInformation->ComponentParameters->Count  - 1)
				{
					this->dataGridView1->Rows->Insert(counter + 1,1);
				}
			}
		}
		//////////////////////////////////////////////////////////////////////////
		/// takes a components information and constructs a table from the values
		//////////////////////////////////////////////////////////////////////////
		void CreateComponentTable ( ComponentInformation ^ componentInformation )
		{
			List<String^>^ VariableTypes = gcnew List<String^>();
			VariableTypes->Add(" f32 ");
			VariableTypes->Add(" f64 ");
			VariableTypes->Add(" s32 ");
			VariableTypes->Add(" str ");
			VariableTypes->Add(" bool ");

			List<String^>^ LoadTypes = gcnew List<String^>();
			LoadTypes->Add(" static ");
			LoadTypes->Add(" state ");

			String^ baseClassVar = System::Convert::ToString( componentInformation->BaseClass );
			
			//creating a new column and setting them so they aren't sortable
			int index = 0;
			this->dataGridView1->Columns->Add("Name", "Name");
			this->dataGridView1->Columns[ index ]->SortMode = DataGridViewColumnSortMode::NotSortable;
			index++;

			DataGridViewComboBoxColumn^ dataGridViewComboBoxColumn1 = gcnew DataGridViewComboBoxColumn();
			this->dataGridView1->Columns->Add( dataGridViewComboBoxColumn1 );
			dataGridViewComboBoxColumn1->SortMode = DataGridViewColumnSortMode::NotSortable;
			dataGridViewComboBoxColumn1->Name = "LoadType";
			dataGridViewComboBoxColumn1->DataSource = LoadTypes;
			index++;

			DataGridViewComboBoxColumn^ dataGridViewComboBoxColumn = gcnew DataGridViewComboBoxColumn();
			this->dataGridView1->Columns->Add( dataGridViewComboBoxColumn );
			dataGridViewComboBoxColumn->SortMode = DataGridViewColumnSortMode::NotSortable;
			dataGridViewComboBoxColumn->Name = "Type";
			dataGridViewComboBoxColumn->DataSource = VariableTypes;
			index++;

			this->dataGridView1->Columns->Add("Value", "Value");
			this->dataGridView1->Columns[ index ]->SortMode = DataGridViewColumnSortMode::NotSortable;
			index++;

			this->dataGridView1->Columns->Add("Discription", "Discription");
			this->dataGridView1->Columns[ index ]->SortMode = DataGridViewColumnSortMode::NotSortable;
			index++;
			this->dataGridView1->Rows->Add( componentInformation );

			CreateTableEntries( componentInformation );

			this->dataGridView1->RowsAdded += gcnew System::Windows::Forms::DataGridViewRowsAddedEventHandler(this, &ComponentTool::dataGridView1_RowsAdded);
		}
	private: 
		System::Void dataGridView1_RowsAdded(System::Object^  sender, System::Windows::Forms::DataGridViewRowsAddedEventArgs^  e) 
		{
			int bp = 0;
		}
};
}
