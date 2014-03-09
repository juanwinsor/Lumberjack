#pragma once

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
			//Parse the components folder for all sub folders and .comp.xml files
			int tmep = 0;
			treeView1->Nodes->Add("1","Test");

			ImageList^ myImageList = gcnew ImageList;

			String^ textureLocation = Application::StartupPath;

			String^ textureFolderPath = String::Concat( textureLocation + "\\..\\..\\..\\LJEditor\\Content\\Textures\\TreeViewTextures");//../../../LJEditor/Content/Textures/TreeViewTextures/FolderClosed.png");

			//folderClosedPath = "C:\\Users\\Brendan\\Downloads\\Desktop\\LumberJack\\Lumberjack\\build\\Debug\\LJEditor\\FolderClosed.png";

			myImageList->Images->Add( Image::FromFile( String::Concat(textureFolderPath + "\\FolderClosed.png") ) );
			myImageList->Images->Add( Image::FromFile( String::Concat(textureFolderPath + "\\FolderOpen.png" ) ) );

			treeView1->ImageList = myImageList;

			TreeNode ^ node = CreateNodesFromDirectory("C:/TEST" , true );//gcnew TreeNode("Testy");

			treeView1->Nodes->Add(node);

			//treeView1->Nodes->Add();
			//String^ temp = "words";
		}

		static TreeNode^ CreateNodesFromDirectory(String^ directoryPath , bool removeParentPathNames )
		{
			TreeNode ^ node;
			if( removeParentPathNames )
			{
				node = gcnew TreeNode( Path::GetFileNameWithoutExtension( directoryPath ));
			}
			else
			{
				node = gcnew TreeNode( directoryPath );
			}

			array<String^>^ subDirectories = Directory::GetDirectories( directoryPath );
			 
			for( int counter = 0; counter < subDirectories->Length; counter++ )
			{
				String ^ directoryName = subDirectories[counter];

				TreeNode^ subDirectory = CreateNodesFromDirectory( directoryName , removeParentPathNames );// gcnew TreeNode(subDirectories[counter]);
				
				subDirectory->ImageIndex = 0;

				node->Nodes->Add(subDirectory);

				array<String^>^ filesInDirectory = Directory::GetFiles(subDirectories[counter]);

				for( int counter2 = 0; counter2 < filesInDirectory->Length; counter2++ )
				{
					String^ fileName = filesInDirectory[counter2];
					if( removeParentPathNames )
					{
						fileName = Path::GetFileNameWithoutExtension(fileName);
					}
					TreeNode^ fileInDirectory = gcnew TreeNode(fileName);
					subDirectory->Nodes->Add( fileInDirectory );
				}
			}
			return node;
		}
	};
}
