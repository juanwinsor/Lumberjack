#pragma once

#include "../../Controls/CFileBrowser.h"
#include "../../Source/ComponentInformation/ComponentInformation.h"
#include "../../Source/Util/EnumUtil.h"

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
	private: System::Windows::Forms::Panel^  pnlComponentInfo;
	private: System::Windows::Forms::Label^  lbComponentExtends;
	private: System::Windows::Forms::TextBox^  tbComponentName;
	private: System::Windows::Forms::Label^  lbComponentName;
	private: System::Windows::Forms::TextBox^  tbComponentExtends;
	private: System::Windows::Forms::TextBox^  tbComponentDiscription;

	private: System::Windows::Forms::Label^  lbComponentDiscription;





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
			this->dgvComponentParameters = (gcnew System::Windows::Forms::DataGridView());
			this->pnlComponentInfo = (gcnew System::Windows::Forms::Panel());
			this->tbComponentDiscription = (gcnew System::Windows::Forms::TextBox());
			this->lbComponentDiscription = (gcnew System::Windows::Forms::Label());
			this->tbComponentExtends = (gcnew System::Windows::Forms::TextBox());
			this->lbComponentExtends = (gcnew System::Windows::Forms::Label());
			this->tbComponentName = (gcnew System::Windows::Forms::TextBox());
			this->lbComponentName = (gcnew System::Windows::Forms::Label());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->tsBtnAdd = (gcnew System::Windows::Forms::ToolStripButton());
			this->tsBtnRemove = (gcnew System::Windows::Forms::ToolStripButton());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->scMain))->BeginInit();
			this->scMain->Panel1->SuspendLayout();
			this->scMain->Panel2->SuspendLayout();
			this->scMain->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvComponentParameters))->BeginInit();
			this->pnlComponentInfo->SuspendLayout();
			this->toolStrip1->SuspendLayout();
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
			this->scMain->Panel2->Controls->Add(this->dgvComponentParameters);
			this->scMain->Panel2->Controls->Add(this->pnlComponentInfo);
			this->scMain->Panel2->Controls->Add(this->toolStrip1);
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
			// dgvComponentParameters
			// 
			this->dgvComponentParameters->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvComponentParameters->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvComponentParameters->Location = System::Drawing::Point(0, 100);
			this->dgvComponentParameters->Name = L"dgvComponentParameters";
			this->dgvComponentParameters->Size = System::Drawing::Size(741, 414);
			this->dgvComponentParameters->TabIndex = 0;
			this->dgvComponentParameters->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ComponentTool::dgvComponentParameters_CellClick);
			this->dgvComponentParameters->CellValidating += gcnew System::Windows::Forms::DataGridViewCellValidatingEventHandler(this, &ComponentTool::dgvComponentParameters_CellValidating);
			this->dgvComponentParameters->Resize += gcnew System::EventHandler(this, &ComponentTool::dgvComponentParameters_Resize);
			// 
			// pnlComponentInfo
			// 
			this->pnlComponentInfo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pnlComponentInfo->Controls->Add(this->tbComponentDiscription);
			this->pnlComponentInfo->Controls->Add(this->lbComponentDiscription);
			this->pnlComponentInfo->Controls->Add(this->tbComponentExtends);
			this->pnlComponentInfo->Controls->Add(this->lbComponentExtends);
			this->pnlComponentInfo->Controls->Add(this->tbComponentName);
			this->pnlComponentInfo->Controls->Add(this->lbComponentName);
			this->pnlComponentInfo->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlComponentInfo->Location = System::Drawing::Point(0, 0);
			this->pnlComponentInfo->Name = L"pnlComponentInfo";
			this->pnlComponentInfo->Size = System::Drawing::Size(741, 100);
			this->pnlComponentInfo->TabIndex = 3;
			// 
			// tbComponentDiscription
			// 
			this->tbComponentDiscription->Location = System::Drawing::Point(69, 30);
			this->tbComponentDiscription->Multiline = true;
			this->tbComponentDiscription->Name = L"tbComponentDiscription";
			this->tbComponentDiscription->Size = System::Drawing::Size(361, 63);
			this->tbComponentDiscription->TabIndex = 5;
			// 
			// lbComponentDiscription
			// 
			this->lbComponentDiscription->AutoSize = true;
			this->lbComponentDiscription->Location = System::Drawing::Point(4, 29);
			this->lbComponentDiscription->Name = L"lbComponentDiscription";
			this->lbComponentDiscription->Size = System::Drawing::Size(59, 13);
			this->lbComponentDiscription->TabIndex = 4;
			this->lbComponentDiscription->Text = L"Discription:";
			// 
			// tbComponentExtends
			// 
			this->tbComponentExtends->Location = System::Drawing::Point(296, 4);
			this->tbComponentExtends->Name = L"tbComponentExtends";
			this->tbComponentExtends->Size = System::Drawing::Size(134, 20);
			this->tbComponentExtends->TabIndex = 3;
			// 
			// lbComponentExtends
			// 
			this->lbComponentExtends->AutoSize = true;
			this->lbComponentExtends->Location = System::Drawing::Point(245, 7);
			this->lbComponentExtends->Name = L"lbComponentExtends";
			this->lbComponentExtends->Size = System::Drawing::Size(48, 13);
			this->lbComponentExtends->TabIndex = 2;
			this->lbComponentExtends->Text = L"Extends:";
			// 
			// tbComponentName
			// 
			this->tbComponentName->Location = System::Drawing::Point(105, 4);
			this->tbComponentName->Name = L"tbComponentName";
			this->tbComponentName->Size = System::Drawing::Size(134, 20);
			this->tbComponentName->TabIndex = 1;
			// 
			// lbComponentName
			// 
			this->lbComponentName->AutoSize = true;
			this->lbComponentName->Location = System::Drawing::Point(4, 7);
			this->lbComponentName->Name = L"lbComponentName";
			this->lbComponentName->Size = System::Drawing::Size(95, 13);
			this->lbComponentName->TabIndex = 0;
			this->lbComponentName->Text = L"Component Name:";
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
			this->tsBtnAdd->ToolTipText = L"Add Component Parameter";
			this->tsBtnAdd->Click += gcnew System::EventHandler(this, &ComponentTool::tsBtnAdd_Click);
			// 
			// tsBtnRemove
			// 
			this->tsBtnRemove->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->tsBtnRemove->Name = L"tsBtnRemove";
			this->tsBtnRemove->Size = System::Drawing::Size(23, 22);
			this->tsBtnRemove->Text = L"tsBtnRemove";
			this->tsBtnRemove->ToolTipText = L"Remove Component Parameter";
			this->tsBtnRemove->Click += gcnew System::EventHandler(this, &ComponentTool::tsBtnRemove_Click);
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvComponentParameters))->EndInit();
			this->pnlComponentInfo->ResumeLayout(false);
			this->pnlComponentInfo->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: 
		System::Void ComponentTool_Load(System::Object^  sender, System::EventArgs^  e) 
		{
			Initialize();
		}

	public:

		void Initialize()
		{
			SetUpComponentBrowser();
			SetUpFileBrowser();
		}

		void SetUpFileBrowser()
		{
			CFileBrowser^ fileBrowser = gcnew CFileBrowser(tvFileBrowser, String::Concat( Application::StartupPath + "..\\..\\..\\..\\LJEditor" ), true );
		}

		void SetUpComponentBrowser()
		{
			m_ComponentInfo = gcnew ComponentInformation();
			m_ComponentInfo->Name = "TestName";
			m_ComponentInfo->BaseClassName = "TestBaseName";
			m_ComponentInfo->Discription = "This is a test discription and it will kill you while you sleep if you fuck with it....I mean it, don't fuck with a good thing. Or it will fuck you right back (testing wrapping).............................";
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

			this->tbComponentName->Text = m_ComponentInfo->Name;
			this->tbComponentExtends->Text = m_ComponentInfo->BaseClassName;
			this->tbComponentDiscription->Text = m_ComponentInfo->Discription;

			String^ textureLocation = Application::StartupPath;

			textureLocation = String::Concat( textureLocation + "\\..\\..\\..\\LJEditor\\Content\\Textures\\ToolStripTextures");
			
			this->tsBtnAdd->Image = Image::FromFile( String::Concat(textureLocation + "\\Add.png") );
			this->tsBtnRemove->Image = Image::FromFile( String::Concat(textureLocation + "\\Remove.png") );
		}

		//////////////////////////////////////////////////////////////////////////
		/// takes a components information and constructs a creates a row for 
		/// each param in the component
		//////////////////////////////////////////////////////////////////////////
		void CreateComponentTableEntries( ComponentInformation ^ componentInformation )
		{
			this->dgvComponentParameters->CellValidating -= gcnew System::Windows::Forms::DataGridViewCellValidatingEventHandler(this, &ComponentTool::dgvComponentParameters_CellValidating);
			while( this->dgvComponentParameters->Rows->Count > 1 )
			{
				this->dgvComponentParameters->Rows->Remove(this->dgvComponentParameters->Rows[1]);
			}

			for( int counter = 0; counter < componentInformation->ComponentParameters->Count; counter++ )
			{
				List<String^>^ variableTypes = Util::EnumUtils::getVariableTypes();
				List<String^>^ loadTypes = Util::EnumUtils::getLoadTypes();
				
				String^ variableType = "";
				String^ loadType = "";

				switch( componentInformation->ComponentParameters[counter]->VarType )
				{
				case 0:
					variableType = variableTypes[0];
					break;
				case 1:
					variableType = variableTypes[1];
					break;
				case 2:
					variableType = variableTypes[2];
					break;
				case 3:
					variableType = variableTypes[3];
					break;
				case 4:
					variableType = variableTypes[4];
					break;
				}

				switch( componentInformation->ComponentParameters[counter]->LoadType )
				{
				case 0:
					loadType = loadTypes[0];
					break;
				case 1:
					loadType = loadTypes[1];
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
			this->dgvComponentParameters->CellValidating += gcnew System::Windows::Forms::DataGridViewCellValidatingEventHandler(this, &ComponentTool::dgvComponentParameters_CellValidating);
		}

		//////////////////////////////////////////////////////////////////////////
		/// takes a components information and constructs a table from the values.
		/// This created the all the columns for the table
		//////////////////////////////////////////////////////////////////////////
		void CreateComponentTable ( ComponentInformation ^ componentInformation )
		{
			List<String^>^ variableTypes = Util::EnumUtils::getVariableTypes();
			List<String^>^ loadTypes = Util::EnumUtils::getLoadTypes();

			String^ baseClassVar = componentInformation->BaseClassName;//System::Convert::ToString( componentInformation->BaseClass );
			
			this->dgvComponentParameters->AllowUserToAddRows = false;
			//this->dgvComponentParameters->SelectionMode = DataGridViewSelectionMode::FullRowSelect;

			//creating a new column and setting them so they aren't sortable
			int index = 0;
			this->dgvComponentParameters->Columns->Add("Name", "Name");
			this->dgvComponentParameters->Columns[ index ]->SortMode = DataGridViewColumnSortMode::NotSortable;
			index++;

			DataGridViewComboBoxColumn^ dataGridViewComboBoxColumn1 = gcnew DataGridViewComboBoxColumn();
			this->dgvComponentParameters->Columns->Add( dataGridViewComboBoxColumn1 );
			dataGridViewComboBoxColumn1->SortMode = DataGridViewColumnSortMode::NotSortable;
			dataGridViewComboBoxColumn1->Name = "LoadType";
			dataGridViewComboBoxColumn1->DataSource = loadTypes;
			index++;

			DataGridViewComboBoxColumn^ dataGridViewComboBoxColumn = gcnew DataGridViewComboBoxColumn();
			this->dgvComponentParameters->Columns->Add( dataGridViewComboBoxColumn );
			dataGridViewComboBoxColumn->SortMode = DataGridViewColumnSortMode::NotSortable;
			dataGridViewComboBoxColumn->Name = "Type";
			dataGridViewComboBoxColumn->DataSource = variableTypes;
			index++;

			this->dgvComponentParameters->Columns->Add("Value", "Value");
			this->dgvComponentParameters->Columns[ index ]->SortMode = DataGridViewColumnSortMode::NotSortable;
			index++;

			this->dgvComponentParameters->Columns->Add("Discription", "Discription");
			this->dgvComponentParameters->Columns[ index ]->SortMode = DataGridViewColumnSortMode::NotSortable;
			index++;
			this->dgvComponentParameters->Rows->Add( componentInformation );

			CreateComponentTableEntries( componentInformation );

			//this->dgvComponentParameters->RowsAdded += gcnew System::Windows::Forms::DataGridViewRowsAddedEventHandler(this, &ComponentTool::dgvComponentParameters_RowsAdded);
		}

private: 
	System::Void tsBtnAdd_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		ComponentParameterInformation^ componentParamInfo = gcnew ComponentParameterInformation();
		m_ComponentInfo->ComponentParameters->Add( componentParamInfo );
		componentParamInfo->Name = "TestName" + m_ComponentInfo->ComponentParameters->Count;
		componentParamInfo->Discription = "TestDiscription" + m_ComponentInfo->ComponentParameters->Count;
		componentParamInfo->VarType = 0;
		componentParamInfo->LoadType = 0;
		componentParamInfo->Value = " TestValue" + m_ComponentInfo->ComponentParameters->Count ;

		CreateComponentTableEntries(m_ComponentInfo);
	}
private: 
	System::Void tsBtnRemove_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		DataGridViewSelectedRowCollection ^ rows = this->dgvComponentParameters->SelectedRows;
		if( rows->Count > 0 )
		{
			DataGridViewRow^ row = rows[0];

			m_ComponentInfo->ComponentParameters->RemoveAt( row->Index );

			CreateComponentTableEntries(m_ComponentInfo);
		}
	}
private: 
	System::Void dgvComponentParameters_Resize(System::Object^  sender, System::EventArgs^  e) 
	{
		int headerwidth = this->dgvComponentParameters->RowHeadersWidth + 1;

		for( int counter = 0; counter < this->dgvComponentParameters->Columns->Count; counter++)
		{
			this->dgvComponentParameters->Columns[counter]->Resizable = DataGridViewTriState::False; 
			this->dgvComponentParameters->Columns[counter]->Width = ( this->dgvComponentParameters->Width - headerwidth )/ this->dgvComponentParameters->Columns->Count;
		}
	}
private: 
	System::Void dgvComponentParameters_CellValidating(System::Object^  sender, System::Windows::Forms::DataGridViewCellValidatingEventArgs^  e) 
	{
		int rowIndex = e->RowIndex;
		int columnIndex= e->ColumnIndex;
		
		ComponentParameterInformation^ compParam = m_ComponentInfo->ComponentParameters[rowIndex];

		switch( columnIndex )
		{
		case 0:
			//Name of the param
			compParam->Name = e->FormattedValue->ToString();
			break;
		case 1:
			{
				//Loadtype of the param
				String^ newValue = e->FormattedValue->ToString();
				int enumValue = Util::EnumUtils::getEnumValueFromString( newValue , Util::EnumUtils::getLoadTypes() );
				//if the value is greater then -1
				if( enumValue >= 0 )
				{
					//set the new param
					compParam->LoadType = enumValue;
				}
				else
				{
					//LOG msg about incorrect value
					e->Cancel = true;
				}
			}
			break;
		case 2:
			{
				//Type of the param
				String^ newValue = e->FormattedValue->ToString();
				int enumValue = Util::EnumUtils::getEnumValueFromString( newValue , Util::EnumUtils::getVariableTypes() );
				//if the value is greater then -1
				if( enumValue >= 0 )
				{
					//set the new param
					compParam->VarType = enumValue;
				}
				else
				{
					//LOG msg about incorrect value
					e->Cancel = true;
				}
			}
			break;
		case 3:
			//Value of the param
			compParam->Value = e->FormattedValue->ToString();
			break;
		case 4:
			//Discription of the param
			compParam->Discription = e->FormattedValue->ToString();
			break;
		}
	}
private: 
	System::Void dgvComponentParameters_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
	{
		if( e->RowIndex > -1 )
		{
			if ( ! this->dgvComponentParameters->Rows[ e->RowIndex]->Selected )
			{
				this->dgvComponentParameters->Rows[ e->RowIndex]->Selected = true;
			}
		}
	}
};
}
