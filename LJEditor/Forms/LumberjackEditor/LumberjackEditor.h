#pragma once

#include "../../Controls/CGLWindow.h"
#include "../../Forms/Export/Export.h"
#include "../../Forms/ComponentTool/ComponentTool.h"
#include <Box2D/Box2D.h>
#include <LJEngine/LJEngineTestClass.h>

namespace LJEditor {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;

	/// <summary>
	/// Summary for LumberjackEditor
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class LumberjackEditor : public System::Windows::Forms::Form
	{
	public:
		LumberjackEditor(void)
		{
			InitializeComponent();
			//
			GLWindow = gcnew COpenGL(this, this->GLWindowPB);
			GLWindow2 = gcnew COpenGL(this, this->GLWindowPB2);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LumberjackEditor()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::Timer^  UpdateTimer;
	private: System::Windows::Forms::MenuStrip^  MainMS;
	protected: 




	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  editToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  toolsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  undoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  redoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  copyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  cutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  pasteToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  deleteToolStripMenuItem;
	private: System::DirectoryServices::DirectorySearcher^  directorySearcher1;

	private: System::Windows::Forms::SplitContainer^  LogSC;




	//-- propose naming standard of 2 or 3 letter control prefix (lower case), followed by the specific instance name
	//-- this will make intellisense more useful providing a naming hint from the control type
	//-- tcTools, tpGameWindow, pbGLWindow, tpExportTool, rtLogWindow
	//-- if all of the components have to be on this Form then maybe prefixing the instance name with the tool name would beneficial as well
	//-- ie. btnExportTool_ExportButton, btnExportTool_CleanButton
	private: System::Windows::Forms::TabControl^  ToolsTC;
	private: System::Windows::Forms::TabPage^  GameWindow;
	private: System::Windows::Forms::PictureBox^  GLWindowPB;
	private: System::Windows::Forms::TabPage^  ExportTool;
	private: System::Windows::Forms::RichTextBox^  LogWindow;
	private: System::Windows::Forms::PictureBox^  GLWindowPB2;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		OpenGLForm::COpenGL ^ GLWindow;
	private: System::Windows::Forms::TabPage^  Component_Tool;
			 OpenGLForm::COpenGL ^ GLWindow2;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->UpdateTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->MainMS = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->undoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->redoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->copyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pasteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->directorySearcher1 = (gcnew System::DirectoryServices::DirectorySearcher());
			this->LogSC = (gcnew System::Windows::Forms::SplitContainer());
			this->ToolsTC = (gcnew System::Windows::Forms::TabControl());
			this->GameWindow = (gcnew System::Windows::Forms::TabPage());
			this->GLWindowPB = (gcnew System::Windows::Forms::PictureBox());
			this->ExportTool = (gcnew System::Windows::Forms::TabPage());
			this->GLWindowPB2 = (gcnew System::Windows::Forms::PictureBox());
			this->LogWindow = (gcnew System::Windows::Forms::RichTextBox());
			this->Component_Tool = (gcnew System::Windows::Forms::TabPage());
			this->MainMS->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->LogSC))->BeginInit();
			this->LogSC->Panel1->SuspendLayout();
			this->LogSC->Panel2->SuspendLayout();
			this->LogSC->SuspendLayout();
			this->ToolsTC->SuspendLayout();
			this->GameWindow->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->GLWindowPB))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->GLWindowPB2))->BeginInit();
			this->SuspendLayout();
			// 
			// UpdateTimer
			// 
			this->UpdateTimer->Enabled = true;
			this->UpdateTimer->Interval = 10;
			this->UpdateTimer->Tick += gcnew System::EventHandler(this, &LumberjackEditor::timer1_Tick);
			// 
			// MainMS
			// 
			this->MainMS->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->fileToolStripMenuItem, 
				this->editToolStripMenuItem, this->toolsToolStripMenuItem});
			this->MainMS->Location = System::Drawing::Point(0, 0);
			this->MainMS->Name = L"MainMS";
			this->MainMS->Size = System::Drawing::Size(1008, 24);
			this->MainMS->TabIndex = 2;
			this->MainMS->Text = L"MainMS";
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
			this->undoToolStripMenuItem->ShortcutKeyDisplayString = L"ctrl-z";
			this->undoToolStripMenuItem->Size = System::Drawing::Size(163, 22);
			this->undoToolStripMenuItem->Text = L"Undo";
			this->undoToolStripMenuItem->ToolTipText = L"ctrl-z";
			// 
			// redoToolStripMenuItem
			// 
			this->redoToolStripMenuItem->Name = L"redoToolStripMenuItem";
			this->redoToolStripMenuItem->RightToLeftAutoMirrorImage = true;
			this->redoToolStripMenuItem->ShortcutKeyDisplayString = L"ctrl-shift-z";
			this->redoToolStripMenuItem->Size = System::Drawing::Size(163, 22);
			this->redoToolStripMenuItem->Text = L"Redo";
			this->redoToolStripMenuItem->ToolTipText = L"ctrl-shift-z";
			// 
			// copyToolStripMenuItem
			// 
			this->copyToolStripMenuItem->Name = L"copyToolStripMenuItem";
			this->copyToolStripMenuItem->ShortcutKeyDisplayString = L"ctrl-x";
			this->copyToolStripMenuItem->Size = System::Drawing::Size(163, 22);
			this->copyToolStripMenuItem->Text = L"Cut";
			this->copyToolStripMenuItem->ToolTipText = L"ctrl-x";
			// 
			// cutToolStripMenuItem
			// 
			this->cutToolStripMenuItem->Name = L"cutToolStripMenuItem";
			this->cutToolStripMenuItem->ShortcutKeyDisplayString = L"ctrl-c";
			this->cutToolStripMenuItem->Size = System::Drawing::Size(163, 22);
			this->cutToolStripMenuItem->Text = L"Copy";
			this->cutToolStripMenuItem->ToolTipText = L"ctrl-c";
			// 
			// pasteToolStripMenuItem
			// 
			this->pasteToolStripMenuItem->Name = L"pasteToolStripMenuItem";
			this->pasteToolStripMenuItem->ShortcutKeyDisplayString = L"ctrl-v";
			this->pasteToolStripMenuItem->Size = System::Drawing::Size(163, 22);
			this->pasteToolStripMenuItem->Text = L"Paste";
			this->pasteToolStripMenuItem->ToolTipText = L"ctrl-v";
			// 
			// deleteToolStripMenuItem
			// 
			this->deleteToolStripMenuItem->Name = L"deleteToolStripMenuItem";
			this->deleteToolStripMenuItem->ShortcutKeyDisplayString = L"delete";
			this->deleteToolStripMenuItem->Size = System::Drawing::Size(163, 22);
			this->deleteToolStripMenuItem->Text = L"Delete";
			this->deleteToolStripMenuItem->ToolTipText = L"delete";
			// 
			// toolsToolStripMenuItem
			// 
			this->toolsToolStripMenuItem->Name = L"toolsToolStripMenuItem";
			this->toolsToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->toolsToolStripMenuItem->Text = L"Tools";
			// 
			// directorySearcher1
			// 
			this->directorySearcher1->ClientTimeout = System::TimeSpan::Parse(L"-00:00:01");
			this->directorySearcher1->ServerPageTimeLimit = System::TimeSpan::Parse(L"-00:00:01");
			this->directorySearcher1->ServerTimeLimit = System::TimeSpan::Parse(L"-00:00:01");
			// 
			// LogSC
			// 
			this->LogSC->Dock = System::Windows::Forms::DockStyle::Fill;
			this->LogSC->Location = System::Drawing::Point(0, 24);
			this->LogSC->Name = L"LogSC";
			this->LogSC->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// LogSC.Panel1
			// 
			this->LogSC->Panel1->Controls->Add(this->ToolsTC);
			// 
			// LogSC.Panel2
			// 
			this->LogSC->Panel2->Controls->Add(this->GLWindowPB2);
			this->LogSC->Panel2->Controls->Add(this->LogWindow);
			this->LogSC->Panel2->Cursor = System::Windows::Forms::Cursors::Default;
			this->LogSC->Panel2->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->LogSC->Size = System::Drawing::Size(1008, 706);
			this->LogSC->SplitterDistance = 563;
			this->LogSC->TabIndex = 5;
			// 
			// ToolsTC
			// 
			this->ToolsTC->Controls->Add(this->GameWindow);
			this->ToolsTC->Controls->Add(this->ExportTool);
			this->ToolsTC->Controls->Add(this->Component_Tool);
			this->ToolsTC->Dock = System::Windows::Forms::DockStyle::Fill;
			this->ToolsTC->Location = System::Drawing::Point(0, 0);
			this->ToolsTC->Name = L"ToolsTC";
			this->ToolsTC->SelectedIndex = 0;
			this->ToolsTC->Size = System::Drawing::Size(1008, 563);
			this->ToolsTC->TabIndex = 6;
			// 
			// GameWindow
			// 
			this->GameWindow->Controls->Add(this->GLWindowPB);
			this->GameWindow->Location = System::Drawing::Point(4, 22);
			this->GameWindow->Name = L"GameWindow";
			this->GameWindow->Padding = System::Windows::Forms::Padding(3);
			this->GameWindow->Size = System::Drawing::Size(1000, 537);
			this->GameWindow->TabIndex = 0;
			this->GameWindow->Text = L"GameWindow";
			this->GameWindow->UseVisualStyleBackColor = true;
			// 
			// GLWindowPB
			// 
			this->GLWindowPB->Dock = System::Windows::Forms::DockStyle::Fill;
			this->GLWindowPB->Location = System::Drawing::Point(3, 3);
			this->GLWindowPB->Name = L"GLWindowPB";
			this->GLWindowPB->Size = System::Drawing::Size(994, 531);
			this->GLWindowPB->TabIndex = 0;
			this->GLWindowPB->TabStop = false;
			this->GLWindowPB->SizeChanged += gcnew System::EventHandler(this, &LumberjackEditor::GLWindowPB_SizeChanged);
			// 
			// ExportTool
			// 
			this->ExportTool->Location = System::Drawing::Point(4, 22);
			this->ExportTool->Name = L"ExportTool";
			this->ExportTool->Padding = System::Windows::Forms::Padding(3);
			this->ExportTool->Size = System::Drawing::Size(1000, 537);
			this->ExportTool->TabIndex = 1;
			this->ExportTool->Text = L"ExportTool";
			this->ExportTool->UseVisualStyleBackColor = true;
			// 
			// GLWindowPB2
			// 
			this->GLWindowPB2->Location = System::Drawing::Point(610, 14);
			this->GLWindowPB2->Name = L"GLWindowPB2";
			this->GLWindowPB2->Size = System::Drawing::Size(206, 96);
			this->GLWindowPB2->TabIndex = 7;
			this->GLWindowPB2->TabStop = false;
			// 
			// LogWindow
			// 
			this->LogWindow->Dock = System::Windows::Forms::DockStyle::Fill;
			this->LogWindow->Enabled = false;
			this->LogWindow->Location = System::Drawing::Point(0, 0);
			this->LogWindow->Name = L"LogWindow";
			this->LogWindow->ReadOnly = true;
			this->LogWindow->Size = System::Drawing::Size(1008, 139);
			this->LogWindow->TabIndex = 6;
			this->LogWindow->TabStop = false;
			this->LogWindow->Text = L"LogWindow";
			// 
			// Component_Tool
			// 
			this->Component_Tool->Location = System::Drawing::Point(4, 22);
			this->Component_Tool->Name = L"ComponentTool";
			this->Component_Tool->Padding = System::Windows::Forms::Padding(3);
			this->Component_Tool->Size = System::Drawing::Size(1000, 537);
			this->Component_Tool->TabIndex = 2;
			this->Component_Tool->Text = L"ComponentTool";
			this->Component_Tool->UseVisualStyleBackColor = true;
			// 
			// LumberjackEditor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1008, 730);
			this->Controls->Add(this->LogSC);
			this->Controls->Add(this->MainMS);
			this->MainMenuStrip = this->MainMS;
			this->Name = L"LumberjackEditor";
			this->Text = L"LumberjackEditor";
			this->Load += gcnew System::EventHandler(this, &LumberjackEditor::LumberjackEditor_Load);
			this->MainMS->ResumeLayout(false);
			this->MainMS->PerformLayout();
			this->LogSC->Panel1->ResumeLayout(false);
			this->LogSC->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->LogSC))->EndInit();
			this->LogSC->ResumeLayout(false);
			this->ToolsTC->ResumeLayout(false);
			this->GameWindow->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->GLWindowPB))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->GLWindowPB2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
			 {				 

				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);

				 wglMakeCurrent( GLWindow->getWindowHandle(), GLWindow->getGLContextHandler() );

				 GLWindow->Render();
				 GLWindow->SwapOpenGLBuffers();

				 wglMakeCurrent( GLWindow2->getWindowHandle(), GLWindow2->getGLContextHandler() );

				 GLWindow2->Render();
				 GLWindow2->SwapOpenGLBuffers();
			 }
	private: 
		System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			//GLFWTest::clearToCornflowerBlue();
		}
private: System::Void GLWindowPB_SizeChanged(System::Object^  sender, System::EventArgs^  e) 
{
	GLWindow->UpdateGLSceneSize(GLWindowPB->Width,GLWindowPB->Height);

	//-- fix for window resize
	UINT flags = SWP_NOZORDER | SWP_NOACTIVATE;
	SetWindowPos((HWND)GLWindow->Handle.ToPointer(), 0, 0, 0, GLWindowPB->Width, GLWindowPB->Height, flags);
}
private: 
	System::Void LumberjackEditor_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		ComponentTool ^ newComponentTool = gcnew ComponentTool();
		newComponentTool->Initialize();

		array<Control^> ^ ControlsForComponentTool = gcnew array<Control^>(99);
		newComponentTool->Controls->CopyTo( ControlsForComponentTool , 0 );
		int numOfControls = newComponentTool->Controls->Count;
		for(int counter =0; counter < numOfControls ; counter ++ )
		{
			this->Component_Tool->Controls->Add( ControlsForComponentTool[counter] );
		}

		Export ^ newExport = gcnew Export();
		newExport->Visible = false;		

		array<Control^> ^ ControlsForExport = gcnew array<Control^>(99);
		newExport->Controls->CopyTo( ControlsForExport , 0 );
		numOfControls = newExport->Controls->Count;
		for(int counter =0; counter < numOfControls ; counter ++ )
		{
			this->ExportTool->Controls->Add( ControlsForExport[counter] );
		}

		EngineTestClass::InitEngine();
	}
};
}

