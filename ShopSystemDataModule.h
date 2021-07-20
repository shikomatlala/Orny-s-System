//---------------------------------------------------------------------------

#ifndef ShopSystemDataModuleH
#define ShopSystemDataModuleH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
//---------------------------------------------------------------------------
class TDModule : public TDataModule
{
__published:	// IDE-managed Components
	TADOConnection *ADOConnection1;
	TADOTable *TCustomer;
	TDataSource *DCustomer;
	TADOTable *TFood;
	TDataSource *DSFood;
	TADOTable *TFoodType;
	TADOTable *TFoodGroup;
	TDataSource *DSFoodType;
	TDataSource *DSFoodGroup;
	TADOQuery *QueryFood;
	TDataSource *QFoodDataAccess;
	TADOQuery *QueryFood2;
	TADOTable *TItems;
	TDataSource *DSItems;
	TDataSource *DataSource1;
	TADOQuery *QuerySearchItems;
	TDataSource *DSSearchItems;
	TADOQuery *ItemsList;
	TDataSource *DSItemsList;
	TADOQuery *GeneralQuery;
	TDataSource *GeneralDS;
	TADODataSet *ADODataSet1;
	TDataSource *DataSource2;
private:	// User declarations
public:		// User declarations
	__fastcall TDModule(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDModule *DModule;
//---------------------------------------------------------------------------
#endif
