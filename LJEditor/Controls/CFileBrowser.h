#pragma once

#include <windows.h>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;



public ref class CFileBrowser
{
private:
	//This is the tree view that we will be effecting
	TreeView^ m_TreeView;
	String^ m_TextureLocation;
	ImageList^ m_ImageList;
	ToolStrip^ m_ToolStrip;
	String^ m_DirectoryName;

	System::Windows::Forms::ToolStripButton^ m_ToggleEmptyFolderButton;
	System::Windows::Forms::ToolStripButton^ m_ToggleFileExtensions;
	

public:
	CFileBrowser( TreeView^  treeView , String^ directoryName , bool createTaskBar)
	{
		//Init our tree view
		m_TreeView = treeView;
		m_DirectoryName = directoryName;
		
		m_TreeView->BeforeCollapse += gcnew System::Windows::Forms::TreeViewCancelEventHandler(this, &CFileBrowser::m_TreeView_BeforeCollapse);
		m_TreeView->BeforeExpand += gcnew System::Windows::Forms::TreeViewCancelEventHandler(this, &CFileBrowser::m_TreeView_BeforeExpand);

		m_TextureLocation = Application::StartupPath;

		m_TextureLocation = String::Concat( m_TextureLocation + "\\..\\..\\..\\LJEditor\\Content\\Textures\\TreeViewTextures");
		//Create a new ImageList for our objects
		m_ImageList = gcnew ImageList;
		//Find the location of our images
		m_ImageList->Images->Add( Image::FromFile( String::Concat(m_TextureLocation + "\\FolderClosed.png") ) );
		m_ImageList->Images->Add( Image::FromFile( String::Concat(m_TextureLocation + "\\FolderOpen.png" ) ) );
		m_ImageList->Images->Add( Image::FromFile( String::Concat(m_TextureLocation + "\\File.png" ) ) );
		m_ImageList->Images->Add( Image::FromFile( String::Concat(m_TextureLocation + "\\FolderEmpty.png" ) ) );

		m_TreeView->ImageList = m_ImageList;

		TreeNode ^ node = CreateNodesFromDirectory( directoryName , true , false );//gcnew TreeNode("Testy");
		node->Expand();
		m_TreeView->Nodes->Add(node);

		if ( createTaskBar )
		{
			CreateTaskBar();
		}

	}

	TreeNode^ CreateNodesFromDirectory(String^ directoryPath , bool removeParentPathNames , bool removeEmptyPaths)
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

			TreeNode^ subDirectory = CreateNodesFromDirectory( directoryName , removeParentPathNames , removeEmptyPaths);// gcnew TreeNode(subDirectories[counter]);

			subDirectory->ImageIndex = 0;

			

			array<String^>^ nextSubDirectories = Directory::GetDirectories( directoryName );

			array<String^>^ filesInDirectory = Directory::GetFiles(subDirectories[counter]);

			if( filesInDirectory->Length <= 0 && nextSubDirectories->Length <= 0 )
			{
				subDirectory->ImageIndex = 3;
				subDirectory->SelectedImageIndex = 3;

				if ( !removeEmptyPaths )
				{
					node->Nodes->Add(subDirectory);
				}
			}
			else
			{
				node->Nodes->Add(subDirectory);
			}

			for( int counter2 = 0; counter2 < filesInDirectory->Length; counter2++ )
			{
				String^ fileName = filesInDirectory[counter2];
				if( removeParentPathNames )
				{
					fileName = Path::GetFileNameWithoutExtension(fileName);
				}
				TreeNode^ fileInDirectory = gcnew TreeNode(fileName);
				subDirectory->Nodes->Add( fileInDirectory );

				fileInDirectory->ImageIndex = 2;
				fileInDirectory->SelectedImageIndex = 2;
			}

		}
		return node;
	}

	void CreateTaskBar()
	{

		array<ToolStripItem^>^ newTooStripItems = gcnew array<ToolStripItem^>(3);
		
		newTooStripItems[0] = gcnew ToolStripDropDownButton("Test");//newTooStripItems);

		m_ToolStrip = gcnew ToolStrip();
		m_ToolStrip->Dock = DockStyle::Bottom;

		this->m_TreeView->Parent->Controls->Add( m_ToolStrip );
		
		Image^ EmptyFolderImage = Image::FromFile( String::Concat(m_TextureLocation + "\\FolderEmpty.png" ) );
		Image^ FileImage = Image::FromFile( String::Concat(m_TextureLocation + "\\File.png" ) );
		
		m_ToggleEmptyFolderButton = gcnew ToolStripButton(EmptyFolderImage);
		m_ToggleEmptyFolderButton->Click += gcnew EventHandler(this, &CFileBrowser::ToggleEmptyFoldersButtonCheckedChanged);
		m_ToggleEmptyFolderButton->ToolTipText = "ToggleEmptyFolders";
		m_ToolStrip->Items->Add( m_ToggleEmptyFolderButton );

		m_ToggleFileExtensions = gcnew ToolStripButton(FileImage);
		m_ToggleFileExtensions->Click += gcnew EventHandler(this, &CFileBrowser::ToggleFileExtensionsCheckedChanged);
		m_ToggleFileExtensions->ToolTipText = "ToggleEmptyFolders";
		m_ToolStrip->Items->Add( m_ToggleFileExtensions );
		//"ToggleEmptyFolders"
		//newToolStrip->
	}
	
private:

	System::Void m_TreeView_BeforeExpand(System::Object^  sender, System::Windows::Forms::TreeViewCancelEventArgs^  e) 
	{
		e->Node->ImageIndex = 1;
		e->Node->SelectedImageIndex = 1;
	}
	System::Void m_TreeView_BeforeCollapse(System::Object^  sender, System::Windows::Forms::TreeViewCancelEventArgs^  e) 
	{
		e->Node->ImageIndex = 0;
		e->Node->SelectedImageIndex = 0;
	}

	void ToggleEmptyFoldersButtonCheckedChanged(Object^ sender, EventArgs^ e)
	{
		m_ToggleEmptyFolderButton->Checked = !m_ToggleEmptyFolderButton->Checked;

		if (m_ToggleEmptyFolderButton->Checked)
		{ 
			m_TreeView->Nodes->Clear();
			TreeNode ^ node;
			if( m_ToggleEmptyFolderButton->Checked )
			{
				node = CreateNodesFromDirectory( m_DirectoryName , true , true );
			}
			else
			{
				node = CreateNodesFromDirectory( m_DirectoryName , false , true );
			}
			node->Expand();
			m_TreeView->Nodes->Add(node);
		}
		else
		{ 
			m_TreeView->Nodes->Clear();
			TreeNode ^ node;
			if( m_ToggleEmptyFolderButton->Checked )
			{
				node = CreateNodesFromDirectory( m_DirectoryName , true , false );
			}
			else
			{
				node = CreateNodesFromDirectory( m_DirectoryName , false , false );
			}
			node->Expand();
			m_TreeView->Nodes->Add(node);
		}
	}

	void ToggleFileExtensionsCheckedChanged(Object^ sender, EventArgs^ e)
	{
		m_ToggleFileExtensions->Checked = !m_ToggleFileExtensions->Checked;

		if (m_ToggleFileExtensions->Checked)
		{ 
			m_TreeView->Nodes->Clear();
			TreeNode ^ node;
			if( m_ToggleEmptyFolderButton->Checked )
			{
				node = CreateNodesFromDirectory( m_DirectoryName , true , true );
			}
			else
			{
				node = CreateNodesFromDirectory( m_DirectoryName , true , false );
			}
			node->Expand();
			m_TreeView->Nodes->Add(node);
		}
		else
		{ 
			m_TreeView->Nodes->Clear();
			TreeNode ^ node;
			if( m_ToggleEmptyFolderButton->Checked )
			{
				node = CreateNodesFromDirectory( m_DirectoryName , false , true );
			}
			else
			{
				node = CreateNodesFromDirectory( m_DirectoryName , false , false );
			}
			node->Expand();
			m_TreeView->Nodes->Add(node);
		}
	}
};
