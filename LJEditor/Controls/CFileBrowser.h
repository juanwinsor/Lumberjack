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

	TreeView^ m_TreeView;

public:
	CFileBrowser( TreeView^  treeView , String^ directoryName )
	{
		m_TreeView = treeView;

		m_TreeView->BeforeCollapse += gcnew System::Windows::Forms::TreeViewCancelEventHandler(this, &CFileBrowser::m_TreeView_BeforeCollapse);
		m_TreeView->BeforeExpand += gcnew System::Windows::Forms::TreeViewCancelEventHandler(this, &CFileBrowser::m_TreeView_BeforeExpand);

		String^ textureLocation = Application::StartupPath;

		String^ textureFolderPath = String::Concat( textureLocation + "\\..\\..\\..\\LJEditor\\Content\\Textures\\TreeViewTextures");
		
		ImageList^ myImageList = gcnew ImageList;

		myImageList->Images->Add( Image::FromFile( String::Concat(textureFolderPath + "\\FolderClosed.png") ) );
		myImageList->Images->Add( Image::FromFile( String::Concat(textureFolderPath + "\\FolderOpen.png" ) ) );
		
		m_TreeView->ImageList = myImageList;

		TreeNode ^ node = CreateNodesFromDirectory( directoryName , true );//gcnew TreeNode("Testy");

		m_TreeView->Nodes->Add(node);

	}

	TreeNode^ CreateNodesFromDirectory(String^ directoryPath , bool removeParentPathNames )
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
	
private:

	System::Void m_TreeView_BeforeExpand(System::Object^  sender, System::Windows::Forms::TreeViewCancelEventArgs^  e) 
	{
		e->Node->ImageIndex = 1;
	}
	System::Void m_TreeView_BeforeCollapse(System::Object^  sender, System::Windows::Forms::TreeViewCancelEventArgs^  e) 
	{
		e->Node->ImageIndex = 0;
	}
};
