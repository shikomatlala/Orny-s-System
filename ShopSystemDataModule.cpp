//---------------------------------------------------------------------------


#pragma hdrstop

#include "ShopSystemDataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "Vcl.Controls.TControl"
#pragma resource "*.dfm"
TDModule *DModule;
//---------------------------------------------------------------------------
__fastcall TDModule::TDModule(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------

