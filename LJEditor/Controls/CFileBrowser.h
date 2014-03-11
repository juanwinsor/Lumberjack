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

	bool m_RemoveParentPathNames;
	bool m_RemoveEmptyPaths;
	bool m_RemoveFileExtentions;

	System::Windows::Forms::ToolStripButton^ m_ToggleEmptyFolderButton;
	System::Windows::Forms::ToolStripButton^ m_ToggleFileExtensionsButton;
	
public:
	CFileBrowser( TreeView^  treeView , String^ directoryName , bool createTaskBar)
	{
		//Init our tree view
		m_RemoveParentPathNames = true;
		m_RemoveEmptyPaths = false;
		m_RemoveFileExtentions = true;

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

		TreeNode ^ node = CreateNodesFromDirectory( directoryName );//gcnew TreeNode("Testy");
		node->Expand();
		m_TreeView->Nodes->Add(node);

		if ( createTaskBar )
		{
			CreateTaskBar();
		}
	}

	TreeNode^ CreateNodesFromDirectory(String^ directoryPath )
	{
		bool removeEmptyPaths = m_RemoveEmptyPaths;
		bool removeFileExtentions = m_RemoveFileExtentions;

		TreeNode ^ node;
		if( m_RemoveParentPathNames )
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

			TreeNode^ subDirectory = CreateNodesFromDirectory( directoryName);// gcnew TreeNode(subDirectories[counter]);

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
				if( m_RemoveParentPathNames )
				{
					if ( removeFileExtentions )
					{
						fileName = Path::GetFileNameWithoutExtension(fileName);
					}
					else
					{
						fileName = Path::GetFileName(fileName);
					}
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

		m_ToggleFileExtensionsButton = gcnew ToolStripButton(FileImage);
		m_ToggleFileExtensionsButton->Click += gcnew EventHandler(this, &CFileBrowser::ToggleFileExtensionsCheckedChanged);
		m_ToggleFileExtensionsButton->ToolTipText = "ToggleEmptyExtensions";
		m_ToolStrip->Items->Add( m_ToggleFileExtensionsButton );
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
		m_RemoveEmptyPaths = m_ToggleEmptyFolderButton->Checked;

		m_TreeView->Nodes->Clear();
		TreeNode ^ node;
		node = CreateNodesFromDirectory( m_DirectoryName );
		node->Expand();
		m_TreeView->Nodes->Add(node);
	}

	void ToggleFileExtensionsCheckedChanged(Object^ sender, EventArgs^ e)
	{
		m_ToggleFileExtensionsButton->Checked = !m_ToggleFileExtensionsButton->Checked;
		m_RemoveFileExtentions = !m_ToggleFileExtensionsButton->Checked;

		m_TreeView->Nodes->Clear();
		TreeNode ^ node;
		node = CreateNodesFromDirectory( m_DirectoryName );
		node->Expand();
		m_TreeView->Nodes->Add(node);
	}
};