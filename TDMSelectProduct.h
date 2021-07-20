//---------------------------------------------------------------------------

#ifndef TDMSelectProductH
#define TDMSelectProductH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
//---------------------------------------------------------------------------
class TDMSelectProduct : public TDataModule
{
__published:	// IDE-managed Components
	TADOConnection *ADOConnection1;
	TDataSource *ItemsQueryDatasource;
	TADOTable *ADOTable1;
	TADOQuery *ADOItemsQuery;
	TADOQuery *ADOItemsQueryExtractInfo;
	TDataSource *ItemsQueryDatasourceExtractInfo;
	TADOQuery *ADOItemTypeQuery;
	TDataSource *ADOItemsTypeDS;
	TADOQuery *CountItemsQuery;
	TDataSource *CountItemsDataSource;
private:	// User declarations
public:		// User declarations
	__fastcall TDMSelectProduct(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSelectProduct *DMSelectProduct;
//---------------------------------------------------------------------------
#endif
