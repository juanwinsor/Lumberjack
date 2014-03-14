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
	private: System::Windows::Forms::DataGridView^  dgvComponentParameters;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  tsBtnAdd;
	private: System::Windows::Forms::ToolStripButton^  tsBtnRemove;



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
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->tsBtnAdd = (gcnew System::Windows::Forms::ToolStripButton());
			this->tsBtnRemove = (gcnew System::Windows::Forms::ToolStripButton());
			this->dgvComponentParameters = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->scMain))->BeginInit();
			this->scMain->Panel1->SuspendLayout();
			this->scMain->Panel2->SuspendLayout();
			this->scMain->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvComponentParameters))->BeginInit();
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
			this->scMain->Panel2->Controls->Add(this->toolStrip1);
			this->scMain->Panel2->Controls->Add(this->dgvComponentParameters);
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
			// toolStrip1
			// 
			this->toolStrip1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->tsBtnAdd, this->tsBtnRemove});
			this->toolStrip1->Location = System::Drawing::Point(0, 514);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(741, 25);
			this->toolStrip1->TabIndex = 1;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// tsBtnAdd
			// 
			this->tsBtnAdd->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->tsBtnAdd->Name = L"tsBtnAdd";
			this->tsBtnAdd->Size = System::Drawing::Size(23, 22);
			this->tsBtnAdd->Text = L"tsBtnAdd";
			this->tsBtnAdd->Click += gcnew System::EventHandler(this, &ComponentTool::tsBtnAdd_Click);
			// 
			// tsBtnRemove
			// 
			this->tsBtnRemove->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->tsBtnRemove->Name = L"tsBtnRemove";
			this->tsBtnRemove->Size = System::Drawing::Size(23, 22);
			this->tsBtnRemove->Text = L"tsBtnRemove";
			this->tsBtnRemove->ToolTipText = L"Remove Element";
			this->tsBtnRemove->Click += gcnew System::EventHandler(this, &ComponentTool::tsBtnRemove_Click);
			// 
			// dgvComponentParameters
			// 
			this->dgvComponentParameters->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvComponentParameters->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvComponentParameters->Location = System::Drawing::Point(0, 0);
			this->dgvComponentParameters->Name = L"dgvComponentParameters";
			this->dgvComponentParameters->Size = System::Drawing::Size(741, 539);
			this->dgvComponentParameters->TabIndex = 0;
			this->dgvComponentParameters->Resize += gcnew System::EventHandler(this, &ComponentTool::dgvComponentParameters_Resize);
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
			this->scMain->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->scMain))->EndInit();
			this->scMain->ResumeLayout(false);
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvComponentParameters))->EndInit();
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

			SetUpComponentBrowser();
		}

		void SetUpComponentBrowser()
		{
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

			String^ textureLocation = Application::StartupPath;

			textureLocation = String::Concat( textureLocation + "\\..\\..\\..\\LJEditor\\Content\\Textures\\ToolStripTextures");
			
			this->tsBtnAdd->Image = Image::FromFile( String::Concat(textureLocation + "\\Add.png") );
			this->tsBtnRemove->Image = Image::FromFile( String::Concat(textureLocation + "\\Remove.png") );
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

			while( this->dgvComponentParameters->Rows->Count > 1 )
			{
				this->dgvComponentParameters->Rows->Remove(this->dgvComponentParameters->Rows[1]);
			}

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
				this->dgvComponentParameters->Rows[counter]->Cells[0]->Value = componentInformation->ComponentParameters[counter]->Name;
				this->dgvComponentParameters->Rows[counter]->Cells[1]->Value = loadType;
				this->dgvComponentParameters->Rows[counter]->Cells[2]->Value = variableType;
				this->dgvComponentParameters->Rows[counter]->Cells[3]->Value = System::Convert::ToString( componentInformation->ComponentParameters[counter]->Value );
				this->dgvComponentParameters->Rows[counter]->Cells[4]->Value = componentInformation->ComponentParameters[counter]->Discription;
				this->dgvComponentParameters->Rows[counter]->Resizable = DataGridViewTriState::False;
				if( counter < componentInformation->ComponentParameters->Count  - 1)
				{
					this->dgvComponentParameters->Rows->Insert(counter + 1,1);
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
			
			this->dgvComponentParameters->AllowUserToAddRows = false;

			//creating a new column and setting them so they aren't sortable
			int index = 0;
			this->dgvComponentParameters->Columns->Add("Name", "Name");
			this->dgvComponentParameters->Columns[ index ]->SortMode = DataGridViewColumnSortMode::NotSortable;
			index++;

			DataGridViewComboBoxColumn^ dataGridViewComboBoxColumn1 = gcnew DataGridViewComboBoxColumn();
			this->dgvComponentParameters->Columns->Add( dataGridViewComboBoxColumn1 );
			dataGridViewComboBoxColumn1->SortMode = DataGridViewColumnSortMode::NotSortable;
			dataGridViewComboBoxColumn1->Name = "LoadType";
			dataGridViewComboBoxColumn1->DataSource = LoadTypes;
			index++;

			DataGridViewComboBoxColumn^ dataGridViewComboBoxColumn = gcnew DataGridViewComboBoxColumn();
			this->dgvComponentParameters->Columns->Add( dataGridViewComboBoxColumn );
			dataGridViewComboBoxColumn->SortMode = DataGridViewColumnSortMode::NotSortable;
			dataGridViewComboBoxColumn->Name = "Type";
			dataGridViewComboBoxColumn->DataSource = VariableTypes;
			index++;

			this->dgvComponentParameters->Columns->Add("Value", "Value");
			this->dgvComponentParameters->Columns[ index ]->SortMode = DataGridViewColumnSortMode::NotSortable;
			index++;

			this->dgvComponentParameters->Columns->Add("Discription", "Discription");
			this->dgvComponentParameters->Columns[ index ]->SortMode = DataGridViewColumnSortMode::NotSortable;
			index++;
			this->dgvComponentParameters->Rows->Add( componentInformation );

			CreateTableEntries( componentInformation );

			//this->dgvComponentParameters->RowsAdded += gcnew System::Windows::Forms::DataGridViewRowsAddedEventHandler(this, &ComponentTool::dgvComponentParameters_RowsAdded);
		}
	private: 
		//System::Void dgvComponentParameters_RowsAdded(System::Object^  sender, System::Windows::Forms::DataGridViewRowsAddedEventArgs^  e) 
		//{
		//	int bp = 0;
		//}
private: 
	System::Void tsBtnAdd_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		ComponentParameterInformation^ componentParamInfo = gcnew ComponentParameterInformation();
		m_ComponentInfo->ComponentParameters->Add( componentParamInfo );
		componentParamInfo->Name = "TestName" + m_ComponentInfo->ComponentParameters->Count;
		componentParamInfo->Discription = "TestDiscription" + m_ComponentInfo->ComponentParameters->Count;
		componentParamInfo->VarType = 1;
		componentParamInfo->LoadType = 1;
		componentParamInfo->Value = " TestValue" + m_ComponentInfo->ComponentParameters->Count ;

		CreateTableEntries(m_ComponentInfo);
	}
private: 
	System::Void tsBtnRemove_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		DataGridViewSelectedRowCollection ^ rows = this->dgvComponentParameters->SelectedRows;
		if( rows->Count > 0 )
		{
			DataGridViewRow^ row = rows[0];

			m_ComponentInfo->ComponentParameters->RemoveAt( row->Index );

			CreateTableEntries(m_ComponentInfo);
		}
	}
private: 
	System::Void dgvComponentParameters_Resize(System::Object^  sender, System::EventArgs^  e) 
	{
		for( int counter = 0; counter < this->dgvComponentParameters->Columns->Count; counter++)
		{
			this->dgvComponentParameters->Columns[counter]->Resizable = DataGridViewTriState::False; 
			this->dgvComponentParameters->Columns[counter]->Width = this->dgvComponentParameters->Width / this->dgvComponentParameters->Columns->Count;
		}
	}
};
}
