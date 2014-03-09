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
	private: System::Windows::Forms::TreeView^  treeView1;
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
			this->treeView1 = (gcnew System::Windows::Forms::TreeView());
			this->SuspendLayout();
			// 
			// treeView1
			// 
			this->treeView1->Dock = System::Windows::Forms::DockStyle::Left;
			this->treeView1->Location = System::Drawing::Point(0, 0);
			this->treeView1->Name = L"treeView1";
			this->treeView1->Size = System::Drawing::Size(467, 539);
			this->treeView1->TabIndex = 0;
			// 
			// ComponentTool
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(915, 539);
			this->Controls->Add(this->treeView1);
			this->Name = L"ComponentTool";
			this->Text = L"ComponentTool";
			this->Load += gcnew System::EventHandler(this, &ComponentTool::ComponentTool_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: 
		System::Void ComponentTool_Load(System::Object^  sender, System::EventArgs^  e) 
		{
			CFileBrowser^ fileBrowser = gcnew CFileBrowser(treeView1,"c:\\TEST");
		}
	};
}
