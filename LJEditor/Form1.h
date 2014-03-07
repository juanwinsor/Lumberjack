#pragma once

#include "OpenGL.h"
#include "GLFWTest.h"

namespace LJEditor {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;

	

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			GLWindow = gcnew COpenGL(this, this->pictureBox1);
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
	private: System::ComponentModel::IContainer^  components;
	protected: 
	private: System::Windows::Forms::Timer^  timer1;


	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  editToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  toolsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  undoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  redoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  copyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  cutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  pasteToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  deleteToolStripMenuItem;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton1;
	private: System::Windows::Forms::ToolStripComboBox^  toolStripComboBox1;
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		OpenGLForm::COpenGL ^ GLWindow;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->undoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->redoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->copyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pasteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripComboBox1 = (gcnew System::Windows::Forms::ToolStripComboBox());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->menuStrip1->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->fileToolStripMenuItem, 
				this->editToolStripMenuItem, this->toolsToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1008, 24);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// editToolStripMenuItem
			// 
			this->editToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {this->undoToolStripMenuItem, 
				this->redoToolStripMenuItem, this->copyToolStripMenuItem, this->cutToolStripMenuItem, this->pasteToolStripMenuItem, this->deleteToolStripMenuItem});
			this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
			this->editToolStripMenuItem->Size = System::Drawing::Size(39, 20);
			this->editToolStripMenuItem->Text = L"Edit";
			// 
			// undoToolStripMenuItem
			// 
			this->undoToolStripMenuItem->Name = L"undoToolStripMenuItem";
			this->undoToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->undoToolStripMenuItem->Text = L"Undo";
			// 
			// redoToolStripMenuItem
			// 
			this->redoToolStripMenuItem->Name = L"redoToolStripMenuItem";
			this->redoToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->redoToolStripMenuItem->Text = L"Redo";
			// 
			// copyToolStripMenuItem
			// 
			this->copyToolStripMenuItem->Name = L"copyToolStripMenuItem";
			this->copyToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->copyToolStripMenuItem->Text = L"Cut";
			// 
			// cutToolStripMenuItem
			// 
			this->cutToolStripMenuItem->Name = L"cutToolStripMenuItem";
			this->cutToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->cutToolStripMenuItem->Text = L"Copy";
			// 
			// pasteToolStripMenuItem
			// 
			this->pasteToolStripMenuItem->Name = L"pasteToolStripMenuItem";
			this->pasteToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->pasteToolStripMenuItem->Text = L"Paste";
			// 
			// toolsToolStripMenuItem
			// 
			this->toolsToolStripMenuItem->Name = L"toolsToolStripMenuItem";
			this->toolsToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->toolsToolStripMenuItem->Text = L"Tools";
			// 
			// deleteToolStripMenuItem
			// 
			this->deleteToolStripMenuItem->Name = L"deleteToolStripMenuItem";
			this->deleteToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->deleteToolStripMenuItem->Text = L"Delete";
			// 
			// toolStrip1
			// 
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripButton1, 
				this->toolStripComboBox1});
			this->toolStrip1->Location = System::Drawing::Point(0, 24);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(1008, 25);
			this->toolStrip1->TabIndex = 3;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(23, 22);
			this->toolStripButton1->Text = L"toolStripButton1";
			// 
			// toolStripComboBox1
			// 
			this->toolStripComboBox1->Name = L"toolStripComboBox1";
			this->toolStripComboBox1->Size = System::Drawing::Size(121, 25);
			// 
			// splitContainer1
			// 
			this->splitContainer1->Location = System::Drawing::Point(12, 52);
			this->splitContainer1->Name = L"splitContainer1";
			this->splitContainer1->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->pictureBox1);
			this->splitContainer1->Panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::splitContainer1_Panel1_Paint);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->tabControl1);
			this->splitContainer1->Panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::splitContainer1_Panel2_Paint);
			this->splitContainer1->Size = System::Drawing::Size(984, 666);
			this->splitContainer1->SplitterDistance = 421;
			this->splitContainer1->TabIndex = 4;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(3, 3);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(978, 415);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(4, 4);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(977, 234);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(969, 208);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"tabPage1";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(192, 74);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"tabPage2";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1008, 730);
			this->Controls->Add(this->splitContainer1);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"OpenGL on a Windows Form using Managed C++";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
			 {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 GLWindow->Render();
				 GLWindow->SwapOpenGLBuffers();
			 }
	private: 
		System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			//GLFWTest::clearToCornflowerBlue();
		}
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void splitContainer1_Panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		 }
private: System::Void splitContainer1_Panel2_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		 }
};
}

