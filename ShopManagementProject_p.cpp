//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("ShopSystemDataModule.cpp", DModule); /* TDataModule: File Type */
USEFORM("TDMSelectProduct.cpp", DMSelectProduct); /* TDataModule: File Type */
USEFORM("ShopManagementMain_u.cpp", shopName);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TshopName), &shopName);
		Application->CreateForm(__classid(TDModule), &DModule);
		Application->CreateForm(__classid(TDMSelectProduct), &DMSelectProduct);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
