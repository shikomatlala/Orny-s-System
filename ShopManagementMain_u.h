//---------------------------------------------------------------------------

#ifndef ShopManagementMain_uH
#define ShopManagementMain_uH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.DBCGrids.hpp>
#include <Vcl.ButtonGroup.hpp>
#include <Vcl.WinXCtrls.hpp>
#include <Vcl.ToolWin.hpp>
//---------------------------------------------------------------------------
class TshopName : public TForm
{
__published:	// IDE-managed Components
	TPageControl *pcntrlMenuBar;
	TTabSheet *tbsCustomer;
	TLabel *lblCID;
	TLabel *lblName;
	TLabel *lblSurname;
	TLabel *lblID;
	TLabel *lblGender;
	TLabel *lblDOB;
	TBevel *Bevel1;
	TLabel *lblRegReport;
	TLabel *lblSubReport;
	TLabel *lblInfoName;
	TLabel *lblInfoSurn;
	TLabel *lblInfoID;
	TLabel *lblInfoGen;
	TLabel *lblInfoDOB;
	TLabel *Label1;
	TEdit *edtCID;
	TEdit *edtName;
	TEdit *edtSurn;
	TEdit *edtID;
	TComboBox *cmbGender;
	TDateTimePicker *dtpDOB;
	TButton *btnGetCID;
	TButton *btnEnterRegistration;
	TButton *btnSubmitRegistration;
	TMemo *mmCustDetails;
	TButton *btnRegCust;
	TTabSheet *tbsProduct;
	TLabel *lblGetIDHelp;
	TLabel *lblRegProdID;
	TLabel *lblRegProdName;
	TLabel *lblProdPrice;
	TLabel *lblEntrRegWarning;
	TBevel *Bevel2;
	TLabel *lblWarningName;
	TEdit *edtRegProdID;
	TTabSheet *Customer;
	TDBGrid *dbCustGrid;
	TTimer *Timer1;
	TTimer *cmpUpdater;
	TEdit *edtProdName;
	TEdit *edtProdPrice;
	TEdit *edtPStockPrice;
	TDateTimePicker *dtpPOrderDate;
	TEdit *edtPReorderLevel;
	TDateTimePicker *dtpPExpiaryDate;
	TEdit *edtPFoodName;
	TEdit *edtPFoodID;
	TEdit *edtPSupplierName;
	TEdit *edtPSupplierID;
	TLabel *lblProdStockPrice;
	TLabel *lblProdStockDate;
	TLabel *lblProdReorderLevel;
	TLabel *lblProdExpiryDate;
	TLabel *lblFoodName;
	TLabel *lblFoodID;
	TLabel *lblSupplierCompanyName;
	TLabel *lblItemSupplierID;
	TPanel *Panel1;
	TMemo *Memo1;
	TPanel *Panel2;
	TLabel *lblSelectFoodType;
	TLabel *lblFoodType;
	TLabel *lblFoodGroup;
	TLabel *lblFood;
	TDBComboBox *dbcmbFoodType;
	TDBComboBox *dbcmbFoodGroup;
	TDBComboBox *dbcmbFood;
	TButton *btnEnterProdReg;
	TTimer *timerProdReport;
	TButton *btnPRegistration;
	TDBListBox *dblPItemList;
	TLabel *lblProdList;
	TButton *edtRegisterProduct;
	TButton *btnRefreshList;
	TButton *btnGetProdID;
	TBevel *Bevel3;
	TBevel *Bevel4;
	TTabSheet *tbsIPurchase;
	TPanel *pnlDecoPurchaseColor;
	TPageControl *PageControl1;
	TTabSheet *tbsItemsCart;
	TStringGrid *StringGrid1;
	TPanel *pnlItmSlctOnLstDtls;
	TPanel *Panel3;
	TPanel *Panel5;
	TPanel *Panel7;
	TPanel *pnlCheckOut;
	TEdit *edtCIDEntry;
	TPanel *pnlDltItmFrmList;
	TPanel *pnlItemPriceSum;
	TPanel *pnlItmListCount;
	TPanel *pnlCIDEnter;
	TPanel *pnlAddItemsToCart;
	TTabSheet *TabSheet2;
	TDBGrid *dbgItems2Select;
	TPanel *pnlAllItemsShow;
	TPanel *pnlNvgItemListCategory;
	TPanel *Panel4;
	TPanel *Panel8;
	TPanel *pnlAddCustFinishRegister;
	TPanel *Panel6;
	TPanel *pnlSlctdItemPriceOnItems;
	TPanel *pnlSlctdItemNameOnItems;
	TPanel *Panel9;
	TListBox *ListBox1;
	TButtonGroup *ButtonGroup1;
	TPanel *pnlPicture;
	TImage *imgCategory;
	TImage *Image1;
	TPanel *Panel10;
	TPanel *pnlDate;
	TImage *Image2;
	TSearchBox *SearchBox1;
	TComboBox *cmbSearchInclude;
	TPanel *pnlCountItems;
	TPanel *pnlNvgItemListRight;
	TComboBox *cmbSearchCriteria;
	TComboBox *cmbSortItems;
	TPanel *pnlItemCatTable;
	TUpDown *AscDesc;
	void __fastcall btnSubmitRegistrationClick(TObject *Sender);
	void __fastcall btnEnterRegistrationClick(TObject *Sender);
	void __fastcall btnGetCIDClick(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall cmbGenderChange(TObject *Sender);
	void __fastcall cmpUpdaterTimer(TObject *Sender);
	void __fastcall btnRegCustClick(TObject *Sender);
	void __fastcall edtIDExit(TObject *Sender);
	void __fastcall tbsCustomerShow(TObject *Sender);
	void __fastcall tbsProductShow(TObject *Sender);
	void __fastcall edtNameChange(TObject *Sender);
	void __fastcall edtSurnChange(TObject *Sender);
	void __fastcall edtIDChange(TObject *Sender);
	void __fastcall dbcmbFoodTypeChange(TObject *Sender);
	void __fastcall dbcmbFoodGroupChange(TObject *Sender);
	void __fastcall dbcmbFoodChange(TObject *Sender);
	void __fastcall btnEnterProdRegClick(TObject *Sender);
	void __fastcall btnGetProdIDClick(TObject *Sender);
	void __fastcall edtProdNameChange(TObject *Sender);
	void __fastcall edtProdPriceChange(TObject *Sender);
	void __fastcall edtPStockPriceChange(TObject *Sender);
	void __fastcall dtpPOrderDateChange(TObject *Sender);
	void __fastcall edtPReorderLevelChange(TObject *Sender);
	void __fastcall dtpPExpiaryDateChange(TObject *Sender);
	void __fastcall edtPFoodNameChange(TObject *Sender);
	void __fastcall edtPFoodIDChange(TObject *Sender);
	void __fastcall edtPSupplierNameChange(TObject *Sender);
	void __fastcall edtPSupplierIDChange(TObject *Sender);
	void __fastcall btnPRegistrationClick(TObject *Sender);
	void __fastcall btnRefreshListClick(TObject *Sender);
	void __fastcall edtRegisterProductClick(TObject *Sender);
	void __fastcall pnlAllItemsShowClick(TObject *Sender);
	void __fastcall dbgItems2SelectCellClick(TColumn *Column);
	void __fastcall pnlAddItemsToCartClick(TObject *Sender);
	void __fastcall dbgItems2SelectKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall dbgItems2SelectKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall dbgItems2SelectDblClick(TObject *Sender);
	void __fastcall pnlCheckOutClick(TObject *Sender);
	void __fastcall Panel4Click(TObject *Sender);
	void __fastcall pnlAddCustFinishRegisterClick(TObject *Sender);
	void __fastcall Panel8Click(TObject *Sender);
	void __fastcall Panel7Click(TObject *Sender);
	void __fastcall Panel6Click(TObject *Sender);
	void __fastcall StringGrid1Click(TObject *Sender);
	void __fastcall Panel9Click(TObject *Sender);
	void __fastcall pnlDltItmFrmListClick(TObject *Sender);
	void __fastcall tbsItemsCartShow(TObject *Sender);
	void __fastcall pnlCIDEnterClick(TObject *Sender);
	void __fastcall ButtonGroup1Items0Click(TObject *Sender);
	void __fastcall ButtonGroup1Items1Click(TObject *Sender);
	void __fastcall ButtonGroup1Items2Click(TObject *Sender);
	void __fastcall ButtonGroup1Items3Click(TObject *Sender);
	void __fastcall ButtonGroup1Items4Click(TObject *Sender);
	void __fastcall ButtonGroup1Items5Click(TObject *Sender);
	void __fastcall ButtonGroup1Items7Click(TObject *Sender);
	void __fastcall ButtonGroup1Items8Click(TObject *Sender);
	void __fastcall ButtonGroup1Items9Click(TObject *Sender);
	void __fastcall ButtonGroup1Items10Click(TObject *Sender);
	void __fastcall ButtonGroup1Items11Click(TObject *Sender);
	void __fastcall ButtonGroup1Items12Click(TObject *Sender);
	void __fastcall ButtonGroup1Items13Click(TObject *Sender);
	void __fastcall ButtonGroup1Items14Click(TObject *Sender);
	void __fastcall ButtonGroup1Items6Click(TObject *Sender);
	void __fastcall pnlAddItemsToCartDblClick(TObject *Sender);
	void __fastcall pnlNvgItemListRightClick(TObject *Sender);
	void __fastcall pnlNvgItemListRightDblClick(TObject *Sender);
	void __fastcall pnlItemCatTableClick(TObject *Sender);
	void __fastcall SearchBox1Change(TObject *Sender);
	void __fastcall cmbSortItemsChange(TObject *Sender);
	void __fastcall AscDescChanging(TObject *Sender, bool &AllowChange);
	void __fastcall AscDescClick(TObject *Sender, TUDBtnType Button);

private:	// User declarations
	//TGrpButtonItem * newButton  = new TGrpButtonItem(this);
public:		// User declarations
	__fastcall TshopName(TComponent* Owner);
	void componentsEnabler(bool);
	void componentsClearer();
	void checkDoubleConversionError(String &edit, bool &report);
	void checkIntConversionError(String &edit, bool &report, int &value);
	void chooseImage(TImage *imgCategory, String);
	String queryFoodID(String id);
	void queryFoodType(String id);
	String getFoodTypeName(String id);
	int countItems();
	int countItemsInTypes(String foodID);
	void switchPictureGrid(bool status);
	void UpdateQuery(String query);
	void scrollList();
    void emptyQuery(String query);
	void resetInfoLables()
	{
		lblInfoID->Caption = "Enter ID";
		lblInfoSurn->Caption  = "Enter Surname" ;
		lblInfoName->Caption  =  "Enter Name";
		lblInfoGen->Caption = "Select Gender";
	 	lblInfoDOB->Caption = "Select Date\nof Birth";
	}

};
//---------------------------------------------------------------------------
extern PACKAGE TshopName *shopName;
//---------------------------------------------------------------------------
#endif
