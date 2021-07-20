//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "TDMSelectProduct.h"
#include "ShopManagementMain_u.h"
#include "ShopSystemDataModule.h"
#include "User_u.h"
#include "OrderProd.h"
#include "ProdSelect.h"
#include "Invoice.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TshopName *shopName;
User custClass;
Product product;
String xFoodName = "";
String xFoodGroup = "";
Invoice inV;
ProdSelected itemSelect;
CONST int EDTCOUNT = 6;
String report[EDTCOUNT] = {"Bad"};   //0-Name, 1-Surname, 2-, 3-UserID  4-cmbGender, 5-dptDOB
CONST int LSPACE = 5;
bool reportStatus = 0;
CONST int PRODCOMPS = 11;
String searchQuery = "SELECT productName,productPrice, FoodName FROM Items ";
String allItems =   "SELECT productName,productPrice, FoodName FROM Items ";
bool prodReport[PRODCOMPS] = {0};
//bool opened[3] = {0};
float totalSum = 0;
String idX  = "";//idX is used on the nvgItemsPanel to allow us to see which Item is being selected so that the navigation panel can display selected category
//---------------------------------------------------------------------------
__fastcall TshopName::TshopName(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TshopName::btnSubmitRegistrationClick(TObject *Sender)
{
	String disPerson;
	DModule->TCustomer->Insert();
	DModule->TCustomer->FieldByName("CID")->AsString = edtCID->Text;
	DModule->TCustomer->FieldByName("custName")->AsString = edtName->Text;
	DModule->TCustomer->FieldByName("custSurn")->AsString = edtSurn->Text;
	DModule->TCustomer->FieldByName("custID")->AsString = edtID->Text;
	DModule->TCustomer->FieldByName("sex")->AsString = cmbGender->Text;
	DModule->TCustomer->FieldByName("dob")->AsString = dtpDOB->Date;
	DModule->TCustomer->Post();
	componentsEnabler(false);
	btnSubmitRegistration->Enabled = 0;
	btnRegCust->Enabled = true;
	disPerson = custClass.getUserID() + "#";
	disPerson += custClass.getPerson();
	String temp;
	int pos;
	for(int x = 0; x < 6; x++){
	   pos = disPerson.Pos("#");
	   temp = disPerson.SubString(0,pos-1);
	   mmCustDetails->Lines->Add(temp);
	   disPerson.Delete(1,pos);
	}
	lblRegReport->Font->Color = clGreen;
	lblRegReport->Caption = "Registration Submitted";
	pnlAddCustFinishRegister->Enabled = 1;
	pnlAddCustFinishRegister->Color = clSkyBlue;

}
//---------------------------------------------------------------------------

void __fastcall TshopName::btnEnterRegistrationClick(TObject *Sender)
{
	if(reportStatus){
		btnSubmitRegistration->Enabled = reportStatus;
		btnEnterRegistration->Enabled = 0;
	}
	componentsEnabler(false);
	reportStatus = 0;

	lblRegReport->Font->Color = clGreen;
	lblRegReport->Caption = "Entered\nSubmit Registration";
	//Turn of Timers
	Timer1->Enabled = 0;
	cmpUpdater->Enabled = 0;
}
//---------------------------------------------------------------------------

void __fastcall TshopName::btnGetCIDClick(TObject *Sender)
{
	edtCID->Font->Color = clBlack;
	custClass.setUserID();
	edtCID->Text = custClass.getUserID();
	report[3] = "Good";
	btnGetCID->Enabled = false;

}
//---------------------------------------------------------------------------
void __fastcall TshopName::Timer1Timer(TObject *Sender)
{

	for(int x = 0; x<EDTCOUNT; x++){
		if(report[x] != "Good"){
			reportStatus = 0;
			x = EDTCOUNT + 1;
		}
		else
			reportStatus = 1;
	}
	btnEnterRegistration->Enabled = reportStatus;
	if(reportStatus){
        lblRegReport->Color = clRed;
		lblRegReport->Caption = "Ensure that all details \nare correct before you submit";
	}
}
//---------------------------------------------------------------------------

void __fastcall TshopName::cmbGenderChange(TObject *Sender)
{
	lblInfoGen->Left = cmbGender->Left + cmbGender->Width + LSPACE;
	cmbGender->Text = cmbGender->Items->Strings[0];
}
//---------------------------------------------------------------------------


void TshopName::componentsEnabler(bool comPEnable)
{
	edtCID->Enabled = comPEnable;
	edtName->Enabled = comPEnable;
	edtSurn->Enabled = comPEnable;
	edtID->Enabled = comPEnable;
	cmbGender->Enabled = comPEnable;
	dtpDOB->Enabled = comPEnable;
	btnGetCID->Enabled = comPEnable;
	btnEnterRegistration->Enabled = comPEnable;
}

void TshopName::componentsClearer()
{
	edtCID->Clear();
	edtName->Clear();
	edtSurn->Clear();
	edtID->Clear();
	cmbGender->Text = "";
	dtpDOB->Date = Date();
	btnGetCID->Enabled = 0;
	btnEnterRegistration->Enabled = 1;
}
void __fastcall TshopName::cmpUpdaterTimer(TObject *Sender)
{
	//COMPARE GENDER WITH ID
	String genCompare, xGender;
	int genInt;
	genCompare = custClass.getID();   //Get ID --
	genCompare.Delete(1,6); //By default the ID is 	id = "0000009999081" Thus the person is male and
	genCompare.Delete(5,3);
	genInt = StrToInt(genCompare);

	if(genInt >= 0000 && genInt <= 4999)
		xGender = "Female";

	if(genInt >= 5000 && genInt <= 9999)
			xGender = "Male";

	if(cmbGender->Text != ""){
		if(cmbGender->Text != "Other"){
			if(cmbGender->Text != xGender){
				lblInfoGen->Caption = "Gender does\nnot Match ID";
				report[4] = "Bad";
			}
			else{
				report[4] = "Good";
				lblInfoGen->Caption = "Good";
			}
		}
		else{
			lblInfoGen->Caption = "Good";
            report[4] = "Good";
		}
	}

	//COMPARE THE DATE
	custClass.setDOB(dtpDOB->Date, report[5]);
	lblInfoDOB->Left = dtpDOB->Left + dtpDOB->Width + 5;
	String comprReport;
	comprReport = custClass.CompareID_Date(custClass.getID(),custClass.getDOB());
	lblInfoDOB->Caption = comprReport;
	if(comprReport == "Good Match")
		report[5] = "Good";
	else
		report[5] = "Bad";
}
//---------------------------------------------------------------------------

void __fastcall TshopName::btnRegCustClick(TObject *Sender)
{
	componentsEnabler(0);
	componentsClearer();
	componentsEnabler(1);
	resetInfoLables();
	mmCustDetails->Lines->Clear();
	lblRegReport->Caption = "";
	lblRegReport->Font->Color = clRed;
	//Turn on Timers
	Timer1->Enabled = 1;
	cmpUpdater->Enabled = 1;
}
//---------------------------------------------------------------------------

void __fastcall TshopName::edtIDExit(TObject *Sender)
{
	//ENTER ID
	lblInfoID->Left = edtID->Left + edtID->Width + LSPACE;
}
//---------------------------------------------------------------------------


void __fastcall TshopName::tbsCustomerShow(TObject *Sender)
{
	 resetInfoLables();
}
//---------------------------------------------------------------------------

void __fastcall TshopName::tbsProductShow(TObject *Sender)
{
	for(int x = 0; x < DModule->TFoodType->RecordCount; x++){
	   dbcmbFoodType->Items->Add(DModule->TFoodType->FieldByName("foodType")->AsString);
	   DModule->TFoodType->Next();
	}
	DModule->TFoodType->First();
}
//---------------------------------------------------------------------------
void __fastcall TshopName::edtNameChange(TObject *Sender)
{
	//ENTER NAME
	lblInfoName->Left =  edtName->Left + edtName->Width + LSPACE;
	custClass.setName(edtName->Text, report[0]);
	lblInfoName->Caption = report[0];
}
//---------------------------------------------------------------------------

void __fastcall TshopName::edtSurnChange(TObject *Sender)
{
	//ENTER SURNAME
	lblInfoSurn->Left =  edtSurn->Left + edtSurn->Width + LSPACE;
	custClass.setSurname(edtSurn->Text, report[1]);
	lblInfoSurn->Caption = report[1];
}
//---------------------------------------------------------------------------

void __fastcall TshopName::edtIDChange(TObject *Sender)
{
	//VALIDATE THE ID
	bool matchFound = 0;
	String result = "";
	if(edtID->Text !=""){
		custClass.setID(edtID->Text,result);
		if(result == "Good"){
			//Check for a match
			DModule->TCustomer->First();
			for(int x = 0; x < DModule->TCustomer->RecordCount; x++){
				if(edtID->Text == DModule->TCustomer->FieldByName("custID")->AsString){
					matchFound = 1;
					x =  DModule->TCustomer->RecordCount + 2;
				}
				else{
					DModule->TCustomer->Next();
				}
			}
			if(matchFound)
				lblInfoID->Caption = "ID number is \nalready Registered";
			else{
				lblInfoID->Caption = "Good";
				report[2] = "Good";
			}
           DModule->TCustomer->First();
		}
		else  {
		  lblInfoID->Caption = result;
		  report[2]= "Bad";
		}
	}
	else {
		lblInfoID->Caption = "Enter ID";
		report[2]= "Bad";
	}
}
//---------------------------------------------------------------------------
void __fastcall TshopName::dbcmbFoodTypeChange(TObject *Sender)
{
	//Build Query
	dbcmbFoodGroup->Enabled = true;
	dbcmbFood->Items->Clear();
	dbcmbFood->Text = "";
	dbcmbFoodGroup->Text = "";
	dbcmbFoodGroup->Items->Clear(); //Clear the Items so that they are not added again and again.
	String fTypeName = "";
	int ind = dbcmbFoodType->ItemIndex;
	fTypeName = dbcmbFoodType->Items->Strings[ind];
	String queryBuilder = "SELECT * FROM TFoodGroup FG, TFoodType FT WHERE FT.FoodTypeID = FG.FoodTypeID AND FT.FoodType = \"" + fTypeName + "\"";
	DModule->QueryFood->Close();
	DModule->QueryFood->SQL->Clear();
	DModule->QueryFood->SQL->Add(queryBuilder);
	DModule->QueryFood->Open();
	for(int x =0; x< DModule->QueryFood->RecordCount;x++){
		dbcmbFoodGroup->Items->Add(DModule->QueryFood->FieldByName("FoodGroup")->AsString);
		DModule->QueryFood->Next();
	}
	DModule->QueryFood->First();
}
//---------------------------------------------------------------------------

void __fastcall TshopName::dbcmbFoodGroupChange(TObject *Sender)
{
	//Build Query
	dbcmbFood->Items->Clear();
	String fName = "";
	dbcmbFood->Text = "";
	int ind = dbcmbFoodGroup->ItemIndex;
	fName = dbcmbFoodGroup->Items->Strings[ind];
	String queryBuilder = "SELECT * FROM TFoodGroup FG, TFood FD WHERE FG.FoodGroupID = FD.FoodGroupID AND FG.FoodGroup = \"" + fName + "\"";
	DModule->QueryFood2->Close();
	DModule->QueryFood2->SQL->Clear();
	DModule->QueryFood2->SQL->Add(queryBuilder);
	DModule->QueryFood2->Open();
	for(int x =0; x< DModule->QueryFood2->RecordCount;x++){
		dbcmbFood->Items->Add(DModule->QueryFood2->FieldByName("FoodName")->AsString);
		DModule->QueryFood2->Next();
	}
	DModule->QueryFood2->First();
}
//---------------------------------------------------------------------------


void __fastcall TshopName::dbcmbFoodChange(TObject *Sender)
{
	String fTypeName = "";
	int ind = dbcmbFood->ItemIndex;
	fTypeName = dbcmbFood->Items->Strings[ind];
	edtPFoodName->Text = fTypeName;

	//CREATE A QUERY
	String queryBuilder = "SELECT FoodID FROM  TFood WHERE  FoodName = \"" + fTypeName + "\"";
	DModule->QueryFood2->Close();
	DModule->QueryFood2->SQL->Clear();
	DModule->QueryFood2->SQL->Add(queryBuilder);
	DModule->QueryFood2->Open();
	edtPFoodID->Text = DModule->QueryFood2->FieldByName("FoodID")->AsString;

}
//---------------------------------------------------------------------------


void __fastcall TshopName::btnEnterProdRegClick(TObject *Sender)
{
	Memo1->Lines->Add(product.getProductDetails());
	btnPRegistration->Enabled = true;
	btnEnterProdReg->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TshopName::btnGetProdIDClick(TObject *Sender)
{
	product.setProdID();
	edtRegProdID->Text = product.getProdID();
	btnGetProdID->Enabled = 0;
	prodReport[0] = 1;
}
//---------------------------------------------------------------------------

void __fastcall TshopName::edtProdNameChange(TObject *Sender)
{
	product.setProdName(edtProdName->Text,prodReport[1]);
}
//---------------------------------------------------------------------------


void __fastcall TshopName::edtProdPriceChange(TObject *Sender)
{
	String edit = edtProdPrice->Text;
	double productPrice = StrToFloat(edit);
	product.setProdPrice(productPrice, prodReport[2]);
}
//---------------------------------------------------------------------------

void TshopName::checkDoubleConversionError(String &edit, bool &report){
	try{
		String temp = edit;
		temp.ToDouble();
		report = 1;
	}
	catch(...){
		edit = "1.00";
		MessageBeep(MB_OK);
		report = 0;
	}
}

void TshopName::checkIntConversionError(String &edit, bool &report, int &value){
	try{
		String temp = edit;
		temp.ToInt();
		value = temp.ToInt();
		report = 1;
	}
	catch(...){
		edit = "1";
        value = 1;
		MessageBeep(MB_OK);
		report = 0;
	}
}

//---------------------------------------------------------------------------

void __fastcall TshopName::edtPReorderLevelChange(TObject *Sender)
{
	String editStr;
	int editInt;
	editStr = edtPReorderLevel->Text;
	editInt = StrToInt(editStr);
	product.setProdStockLevel(editInt, prodReport[5]);
}
//---------------------------------------------------------------------------
void __fastcall TshopName::edtPStockPriceChange(TObject *Sender)
{
	String edtStr;
	double edtFloat;
	edtStr = edtPStockPrice->Text;
	edtFloat = StrToFloat(edtStr);
	product.setProdStockPrice(edtFloat, prodReport[3]);
}

void __fastcall TshopName::dtpPOrderDateChange(TObject *Sender)
{
	product.setProdStockDate(dtpPOrderDate->Date, prodReport[4]);
}
//---------------------------------------------------------------------------

void __fastcall TshopName::dtpPExpiaryDateChange(TObject *Sender)
{
	product.setProdExpiaryDate(dtpPExpiaryDate->Date, prodReport[6]);
}
//---------------------------------------------------------------------------

void __fastcall TshopName::edtPFoodNameChange(TObject *Sender)
{
	product.setFoodName(edtPFoodName->Text, prodReport[7]);
}
//---------------------------------------------------------------------------

void __fastcall TshopName::edtPFoodIDChange(TObject *Sender)
{
	product.setFoodID(edtPFoodID->Text, prodReport[8]);
}
//---------------------------------------------------------------------------

void __fastcall TshopName::edtPSupplierNameChange(TObject *Sender)
{
	product.setSupCompanyName(edtPSupplierName->Text, prodReport[9]);
}
//---------------------------------------------------------------------------

void __fastcall TshopName::edtPSupplierIDChange(TObject *Sender)
{
	product.setItemSupplierID(edtPSupplierID->Text, prodReport[10]);
}
//---------------------------------------------------------------------------
void __fastcall TshopName::btnPRegistrationClick(TObject *Sender)
{
	DModule->TItems->Insert();
	DModule->TItems->FieldByName("productID")->AsString = product.getProdID();
	DModule->TItems->FieldByName("productName")->AsString = product.getProdName();
	DModule->TItems->FieldByName("productPrice")->AsFloat = product.getProdPrice();
	DModule->TItems->FieldByName("productStockPrice")->AsFloat = product.getProdStockPrice();
	DModule->TItems->FieldByName("productStockDate")->AsString = product.getProdStockDate();
	DModule->TItems->FieldByName("productStockLevel")->AsInteger  = product.getProdStockLevel();
	DModule->TItems->FieldByName("productReorderLevel")->AsInteger = product.getProdReorderLevel();
	DModule->TItems->FieldByName("productExpiaryDate")->AsString = product.getProdExpiaryDate();
	DModule->TItems->FieldByName("FoodName")->AsString = product.getFoodName();
	DModule->TItems->FieldByName("FoodID")->AsString = product.getFoodID();
	DModule->TItems->FieldByName("supplierCompanyName")->AsString = product.getSupCompanyName();
	DModule->TItems->FieldByName("itemSupplierID")->AsString = product.getItemSupplierID();
	DModule->TItems->Post();
	btnPRegistration->Enabled = false;
	edtRegisterProduct->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TshopName::btnRefreshListClick(TObject *Sender)
{
	dblPItemList->Items->Clear();
	for(int x =0; x< DModule->TItems->RecordCount;x++){
		dblPItemList->Items->Add(DModule->TItems->FieldByName("productName")->AsString);
		DModule->TItems->Next();
	}
	DModule->TItems->First();
}
//---------------------------------------------------------------------------


void __fastcall TshopName::edtRegisterProductClick(TObject *Sender)
{
	btnPRegistration->Enabled = true;
	edtRegisterProduct->Enabled =false;
	btnGetProdID->Enabled = true;
	btnEnterProdReg->Enabled = true;

}
//---------------------------------------------------------------------------

void __fastcall TshopName::pnlAllItemsShowClick(TObject *Sender)
{

	itemSelect.AllItemsShow();


	pnlNvgItemListCategory->Caption = "All Items";
	//dbgItems2Select->DataSource = DModule->DSItemsList;
	//String test = DMSelectProduct->ADOItemsQuery->FieldByName("foodType")->AsString;
	dbgItems2Select->Enabled = true;
	dbgItems2Select->Visible = true;
	ButtonGroup1->Visible = false;
	ButtonGroup1->Enabled = false;
	imgCategory->Visible = false;
	imgCategory->Enabled = false;
	pnlPicture->Visible = false;
	pnlPicture->Enabled = false;
	pnlCountItems->Caption = IntToStr(countItems());
	emptyQuery(allItems);

}
//---------------------------------------------------------------------------

String test = "";
String prodPriceQuery = "";
String test2 = "";
float itemPrice =0.00;
void __fastcall TshopName::dbgItems2SelectCellClick(TColumn *Column)
{
	inV.setProdName(DModule->ItemsList->FieldByName("productName")->AsString);
	searchQuery = "SELECT productPrice FROM Items WHERE productName = \""+ inV.getProdName()+ "\"";
	DModule->GeneralQuery->Close();
	DModule->GeneralQuery->SQL->Clear();
	DModule->GeneralQuery->SQL->Add(searchQuery);
	DModule->GeneralQuery->Open();
	//float itemPrice = 0.00;

	//EXTRACT THE PRICE AND THE PRODUCT NAME
	inV.setProdPrice(DModule->GeneralQuery->FieldByName("productPrice")->AsFloat);
	pnlSlctdItemNameOnItems->Caption = inV.getProdName();
	pnlSlctdItemPriceOnItems->Caption = "R" + FormatFloat("00.00",inV.getProdPrices());

	//opened[1] = 1;
	int rows2 = StringGrid1->RowCount -1;
	pnlItmListCount->Caption = IntToStr(rows2);
}
int itemClicked = 0;


//---------------------------------------------------------------------------
void __fastcall TshopName::pnlAddItemsToCartClick(TObject *Sender)
{

	inV.setProdName(DMSelectProduct->ADOItemsQuery->FieldByName("productName")->AsString);

	ListBox1->Items->Add(inV.getProdName()+ "#" + inV.getProdPrices());

	//Make sure that you StringGrid1 gets items from the listBox1
	//Create a colcount First
	StringGrid1->ColCount = 3;
	inV.NoItems(ListBox1->Items->Count);
	StringGrid1->RowCount = inV.getSumItems();


	int x = inV.getSumItems();
	x -=1;
	StringGrid1->Cells[0][0] = "#";
	StringGrid1->Cells[1][0] = "Item Name";
	StringGrid1->Cells[2][0] = "Item Price";
	//Set the size of the columns created
	StringGrid1->ColWidths[0] = 30;
	StringGrid1->ColWidths[1] = 610;
	StringGrid1->ColWidths[2] = 120;

	//Where does our row Count start?
	StringGrid1->Cells[0][x] =  x;
	StringGrid1->Cells[1][x] = inV.getProdName();
	StringGrid1->Cells[2][x] = "R"+FormatFloat("00.00",inV.getProdPrices());
	pnlItmListCount->Caption = "ITEMS " + IntToStr(x);
	inV.sumPrice(inV.getProdPrices());
	pnlItemPriceSum->Caption =  "R" + FormatFloat("00.00",inV.getSumPrice());
	pnlDltItmFrmList->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TshopName::dbgItems2SelectKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	scrollList();
}
//---------------------------------------------------------------------------

void __fastcall TshopName::dbgItems2SelectKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)
{
	scrollList();
}
//---------------------------------------------------------------------------
void TshopName::scrollList()
{
	inV.setProdName(DModule->ItemsList->FieldByName("productName")->AsString);
	float itemPrice =0.00;
	inV.setProdPrice(DModule->ItemsList->FieldByName("productPrice")->AsFloat);
	pnlSlctdItemNameOnItems->Caption = inV.getProdName();
	pnlSlctdItemPriceOnItems->Caption ="R" + FormatFloat("00.00",inV.getProdPrices());
}

void __fastcall TshopName::dbgItems2SelectDblClick(TObject *Sender)
{
	//itemClicked += 1;
	inV.setProdName(DModule->ItemsList->FieldByName("productName")->AsString);
	inV.setProdPrice(DModule->ItemsList->FieldByName("productPrice")->AsFloat);
	//ADD THE ITEM SELECTED

	ListBox1->Items->Add(inV.getProdName()+ "#" + inV.getProdPrices());

	//Make sure that your StringGrid1 gets items from the listBox1
	//Create a colcount First
	StringGrid1->ColCount = 3;
	inV.NoItems(ListBox1->Items->Count);
	StringGrid1->RowCount = inV.getSumItems();
	//StringGrid1->FixedRows = 1;
	//Create columns for  item Number, itemname, item price
	//StringGrid1->
	int x = inV.getSumItems();
	x -=1;
	StringGrid1->Cells[0][0] = "#";
	StringGrid1->Cells[1][0] = "Item Name";
	StringGrid1->Cells[2][0] = "Item Price";
	//Set the size of the columns created
	StringGrid1->ColWidths[0] = 30;
	StringGrid1->ColWidths[1] = 610;
	StringGrid1->ColWidths[2] = 120;

	//Where does our row Count start?
	StringGrid1->Cells[0][x] =  x;
	StringGrid1->Cells[1][x] = inV.getProdName();
	StringGrid1->Cells[2][x] = "R"+FormatFloat("00.00",inV.getProdPrices());
	pnlItmListCount->Caption = "ITEMS " + IntToStr(x);
	inV.sumPrice(inV.getProdPrices());
	pnlItemPriceSum->Caption =  "R" + FormatFloat("00.00",inV.getSumPrice());
	pnlDltItmFrmList->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TshopName::pnlCheckOutClick(TObject *Sender)
{
	TabSheet2->Show();
	//Get today date.
	pnlDate->Caption = inV.getInvDate();
}
//---------------------------------------------------------------------------

void __fastcall TshopName::Panel4Click(TObject *Sender)
{
	tbsCustomer->Show();
}
//---------------------------------------------------------------------------


void __fastcall TshopName::pnlAddCustFinishRegisterClick(TObject *Sender)
{

	pnlAddCustFinishRegister->Color = clBtnFace;
	//TAKE THE CID AND PUT IT ON THE ITEMS LIST.
	edtCIDEntry->Text = custClass.getUserID();
	pnlAddCustFinishRegister->Enabled = 0;
	tbsItemsCart->Show();

}
//---------------------------------------------------------------------------


void __fastcall TshopName::Panel8Click(TObject *Sender)
{
	//CREATE A TEMPORARY CID
	edtCIDEntry->Text = custClass.custXID();
}
//---------------------------------------------------------------------------
 int counteX = 0;
void __fastcall TshopName::Panel7Click(TObject *Sender)
{
	if(counteX <StringGrid1->RowCount){
		counteX++;
		Panel3->Caption = StringGrid1->Cells[1][counteX];
		Panel5->Caption = StringGrid1->Cells[2][counteX];

	}
}
//---------------------------------------------------------------------------

void __fastcall TshopName::Panel6Click(TObject *Sender)
{
	if(counteX >= 1){
		counteX--;
		Panel3->Caption = StringGrid1->Cells[1][counteX];
		Panel5->Caption = StringGrid1->Cells[2][counteX];
		if(counteX <=1){
			counteX = 1;
		}
	}

}
//---------------------------------------------------------------------------

int itmSelected = 1;
void __fastcall TshopName::StringGrid1Click(TObject *Sender)
{
	//
		itmSelected = StringGrid1->Row;
		//int y = StringGrid1->Col;
		counteX = itmSelected;
		Panel3->Caption = StringGrid1->Cells[1][counteX];
		Panel5->Caption = StringGrid1->Cells[2][counteX];
		//Find the string list index using the row.
		ListBox1->Items->IndexOf(itmSelected);
}
//---------------------------------------------------------------------------

void __fastcall TshopName::Panel9Click(TObject *Sender)
{
	//.Show
	tbsItemsCart->Show();
}
//---------------------------------------------------------------------------

void __fastcall TshopName::pnlDltItmFrmListClick(TObject *Sender)
{
	//DELETE THE ITEM THAT IS BEING DELETED

	String itmPrice = "0";
	if(ListBox1->Items->Count >= 1){
		itmPrice = ListBox1->Items->Strings[itmSelected];
	}
	int pos = 0;
	pos = itmPrice.Pos("#");
	itmPrice = itmPrice.Delete(1, pos);



	//SUBTRACT THE ITEM COUNT
	inV.subItems();
	pnlItmListCount->Caption = "ITEMS " + IntToStr(inV.getSumItems()-1);
	if(itmSelected >= 1)
	{	ListBox1->Items->Delete(itmSelected);
		itmSelected-=1;
		//Subtract the price that is being delete from the main sum price
		inV.subPrice(StrToFloat(itmPrice));
		pnlItemPriceSum->Caption = "R" + FormatFloat("00.00", inV.getSumPrice());
	}


	//Create a for loop -- and then you should be good to
	for(int x= 1; x <StringGrid1->RowCount; x++)
	{
		StringGrid1->Rows[x]->Clear();
	}
	StringGrid1->FixedRows = 1;
	StringGrid1->FixedCols = 1;
	StringGrid1->ColCount = 3;
	inV.NoItems(ListBox1->Items->Count);
	StringGrid1->RowCount = inV.getSumItems();

//	int y= inV.getSumItems();
//	y-=1;

	StringGrid1->Cells[0][0] = "#";
	StringGrid1->Cells[1][0] = "Item Name";
	StringGrid1->Cells[2][0] = "Item Price";
	if(ListBox1->Items->Count >= 1){
		for(int x =1; x < ListBox1->Items->Count;x++)
		{
			StringGrid1->Cells[0][x] = x;
			//Get the String Items
			String items, temp;
			items = ListBox1->Items->Strings[x];
			int pos = 0;
			pos = items.Pos("#");
			temp = items.SubString(1,pos -1);
			//temp = items
			//items.Delete(0,pos);
			items = items.Delete(1, pos);

			 StringGrid1->Cells[0][x] =  x;
			 StringGrid1->Cells[1][x] = temp;
			StringGrid1->Cells[2][x] = items;
		}
	}
	//Supract the price from the sumPrice
	if(inV.getSumItems()-1 < 1)
		pnlDltItmFrmList->Enabled = false;

}
//---------------------------------------------------------------------------

void __fastcall TshopName::tbsItemsCartShow(TObject *Sender)
{
	StringGrid1->ColCount = 3;
	//Create columns for  item Number, itemname, item price
	StringGrid1->Cells[0][0] = "No.";
	StringGrid1->Cells[1][0] = "Item Name";
	StringGrid1->Cells[2][0] = "Item Price";
	//Set the size of the columns created
	StringGrid1->ColWidths[0] = 30;
	StringGrid1->ColWidths[1] = 610;
	StringGrid1->ColWidths[2] = 120;
	ListBox1->Items->Add("#,Item Name, Item Price");
    chooseImage(imgCategory, "1.bmp");

}
//---------------------------------------------------------------------------


void __fastcall TshopName::pnlCIDEnterClick(TObject *Sender)
{
	 //Clear the edit box
	 edtCIDEntry->Clear();
	 //Check if the CID is good or not
     //Open the cid list
}
//---------------------------------------------------------------------------


void __fastcall TshopName::ButtonGroup1Items0Click(TObject *Sender)
{
	chooseImage(imgCategory, "1.bmp");
	idX = "1";
	queryFoodType(queryFoodID(idX));
	pnlNvgItemListCategory->Caption = getFoodTypeName(idX);
	//pnlCountItems->Caption = IntToStr(countItemsInTypes(1));
}
//---------------------------------------------------------------------------

void __fastcall TshopName::ButtonGroup1Items1Click(TObject *Sender)
{
	chooseImage(imgCategory, "2.bmp");
	idX = "2";
	queryFoodType(queryFoodID(idX));
	pnlNvgItemListCategory->Caption = getFoodTypeName(idX);
}
//---------------------------------------------------------------------------

void __fastcall TshopName::ButtonGroup1Items2Click(TObject *Sender)
{
	chooseImage(imgCategory, "3.bmp");
	idX = "3";
	queryFoodType(queryFoodID(idX));
	pnlNvgItemListCategory->Caption = getFoodTypeName(idX);
}
//---------------------------------------------------------------------------

void __fastcall TshopName::ButtonGroup1Items3Click(TObject *Sender)
{
	chooseImage(imgCategory, "4.bmp");
	idX = "4";
	queryFoodType(queryFoodID(idX));
	pnlNvgItemListCategory->Caption = getFoodTypeName(idX);
}
//---------------------------------------------------------------------------

void __fastcall TshopName::ButtonGroup1Items4Click(TObject *Sender)
{
	chooseImage(imgCategory, "5.bmp");
	idX = "5";
	queryFoodType(queryFoodID(idX));
	pnlNvgItemListCategory->Caption = getFoodTypeName(idX);
}
//---------------------------------------------------------------------------

void __fastcall TshopName::ButtonGroup1Items5Click(TObject *Sender)
{
	chooseImage(imgCategory, "6.bmp");
	idX = "6";
	queryFoodType(queryFoodID(idX));
	pnlNvgItemListCategory->Caption = getFoodTypeName(idX);
}
//---------------------------------------------------------------------------

void TshopName::chooseImage(TImage *imgCategory, String img)
{
	ChDir("catImages");
	imgCategory->Stretch = true;
	imgCategory->Picture->LoadFromFile(img);
	ChDir("../");
}
void __fastcall TshopName::ButtonGroup1Items7Click(TObject *Sender)
{
   chooseImage(imgCategory, "8.bmp");
   idX= "8";
   queryFoodType(queryFoodID(idX));
   pnlNvgItemListCategory->Caption = getFoodTypeName(idX);
}
//---------------------------------------------------------------------------

void __fastcall TshopName::ButtonGroup1Items8Click(TObject *Sender)
{
	chooseImage(imgCategory, "9.bmp");
	idX = "7";
	queryFoodType(queryFoodID(idX));
	pnlNvgItemListCategory->Caption = getFoodTypeName(idX);
}
//---------------------------------------------------------------------------

void __fastcall TshopName::ButtonGroup1Items9Click(TObject *Sender)
{
	chooseImage(imgCategory, "10.bmp");
	idX = "10";
	queryFoodType(queryFoodID(idX));
	pnlNvgItemListCategory->Caption = getFoodTypeName(idX);
}
//---------------------------------------------------------------------------

void __fastcall TshopName::ButtonGroup1Items10Click(TObject *Sender)
{
	chooseImage(imgCategory, "11.bmp");
	idX = "11";
	queryFoodType(queryFoodID(idX));
	pnlNvgItemListCategory->Caption = getFoodTypeName(idX);
}
//---------------------------------------------------------------------------

void __fastcall TshopName::ButtonGroup1Items11Click(TObject *Sender)
{
	chooseImage(imgCategory, "12.bmp");
	idX = "12";
	queryFoodType(queryFoodID(idX));
	pnlNvgItemListCategory->Caption = getFoodTypeName(idX);
}
//---------------------------------------------------------------------------

void __fastcall TshopName::ButtonGroup1Items12Click(TObject *Sender)
{
	chooseImage(imgCategory, "13.bmp");
	idX = "13";
	queryFoodType(queryFoodID(idX));
	pnlNvgItemListCategory->Caption = getFoodTypeName(idX);
}
//---------------------------------------------------------------------------

void __fastcall TshopName::ButtonGroup1Items13Click(TObject *Sender)
{
	chooseImage(imgCategory, "14.bmp");
	idX = "14";
	queryFoodType(queryFoodID(idX));
	pnlNvgItemListCategory->Caption = getFoodTypeName(idX);
}
//---------------------------------------------------------------------------

void __fastcall TshopName::ButtonGroup1Items14Click(TObject *Sender)
{
	chooseImage(imgCategory, "15.bmp");
	idX  = "15";
	queryFoodType(queryFoodID(idX));
	pnlNvgItemListCategory->Caption = getFoodTypeName(idX);
}
//---------------------------------------------------------------------------

void __fastcall TshopName::ButtonGroup1Items6Click(TObject *Sender)
{
	chooseImage(imgCategory, "7.bmp");
	idX = "7";
	queryFoodType(queryFoodID(idX));
	//pnlNvgItemListCategory->Caption = getFoodTypeName(idX);
}
//---------------------------------------------------------------------------

void __fastcall TshopName::pnlAddItemsToCartDblClick(TObject *Sender)
{
	//

}
//---------------------------------------------------------------------------
String TshopName::queryFoodID(String idX)
{
   //int id = StrToInt(idX);

	searchQuery ="SELECT productname AS Name, productPrice AS Price, FD.FoodName AS FoodName FROM TFoodType AS FT, TFoodGroup AS FG, TFood AS FD, Items AS ITM WHERE FT.FoodTypeID = FG.FoodTypeID AND FG.FoodGroupID = FD.FoodGroupID AND  FD.FoodID = ITM.FoodID AND FT.FoodTypeID = " + idX ;//\"" + idX + "\";";
   return searchQuery ;
}

String TshopName::getFoodTypeName(String id)
{
	String query = "SELECT foodType FROM TFoodType WHERE FoodTypeID = " + id;
	DModule->GeneralQuery->Close();
	DModule->GeneralQuery->SQL->Clear();
	DModule->GeneralQuery->SQL->Add(query);
	DModule->GeneralQuery->Open();
	pnlCountItems->Caption = IntToStr(countItemsInTypes(id));
//	ShowMessage(DModule->GeneralQuery->FieldByName("foodType")->AsString);
//	return DModule->GeneralQuery->FieldByName("foodType")->AsString;

}

void TshopName::queryFoodType(String id)
{
	DModule->ItemsList->Close();
	DModule->ItemsList->SQL->Clear();
	DModule->ItemsList->SQL->Add(id);
	DModule->ItemsList->Open();
}

void __fastcall TshopName::pnlNvgItemListRightClick(TObject *Sender)
{
	switchPictureGrid(false);
}
//---------------------------------------------------------------------------

void __fastcall TshopName::pnlNvgItemListRightDblClick(TObject *Sender)
{
	switchPictureGrid(true);
}
//---------------------------------------------------------------------------

 int TshopName::countItems()
 {
	String query =  "SELECT COUNT(productID) AS ItemCount FROM Items";
	DModule->ItemsList->Close();
	DModule->ItemsList->SQL->Clear();
	DModule->ItemsList->SQL->Add(query);
	DModule->ItemsList->Open();
	return DModule->ItemsList->FieldByName("ItemCount")->AsInteger;
 }
 int TshopName::countItemsInTypes(String foodID)
 {
	String query = "SELECT COUNT(TMS.FoodID) AS ItemCount FROM Items TMS, TFoodType FT, TFoodGroup FG, TFood FD WHERE TMS.FoodID = FD.FoodID AND FD.FoodGroupID = FG.FoodGroupID AND FG.FoodTypeID = FT.FoodTypeID AND FT.FoodTypeID = " + foodID;
	DModule->GeneralQuery->Close();
	DModule->GeneralQuery->SQL->Clear();
	DModule->GeneralQuery->SQL->Add(query);
	DModule->GeneralQuery->Open();
	return DModule->GeneralQuery->FieldByName("ItemCount")->AsInteger;
 }

void __fastcall TshopName::pnlItemCatTableClick(TObject *Sender)
{
	itemSelect.ItemCatShow();
	//opened[0] = 1;
	pnlNvgItemListCategory->Caption = "Food Type";
	String foodType = "";
	String FoodGroup = "";

	//CREATE A BUTTON GROUP AND THEN POPULATE IT
	switchPictureGrid(true);
}
//---------------------------------------------------------------------------
String foodname;

void __fastcall TshopName::SearchBox1Change(TObject *Sender)
{
	switchPictureGrid(false);
	foodname = SearchBox1->Text;
	 if(cmbSearchInclude->ItemIndex == 0){

		if(cmbSearchCriteria->ItemIndex == 0)
		{
			searchQuery = "SELECT productName,productPrice, FoodName FROM Items WHERE productName LIKE \"" + foodname + "%\"";
			DModule->ItemsList->Close();
			DModule->ItemsList->SQL->Clear();
			DModule->ItemsList->SQL->Add(searchQuery);
			DModule->ItemsList->Open();
		}
		if(cmbSearchCriteria->ItemIndex == 1)
		{
			searchQuery =  "SELECT productName,productPrice, FoodName FROM Items WHERE FoodName LIKE \"" + foodname + "%\"";
			DModule->ItemsList->Close();
			DModule->ItemsList->SQL->Clear();
			DModule->ItemsList->SQL->Add(searchQuery);
			DModule->ItemsList->Open();
		}
		if(cmbSearchCriteria->ItemIndex == 2)
		{
			searchQuery = "SELECT productName,productPrice, FG.FoodGroup FROM Items IT, TFood FD, TFoodGroup FG WHERE  IT.FoodName = FD.FoodName AND FD.FoodGroupID = FG.FoodGroupID AND FoodGroup LIKE  \"" + foodname + "%\"";
			DModule->ItemsList->Close();
			DModule->ItemsList->SQL->Clear();
			DModule->ItemsList->SQL->Add(searchQuery);
			DModule->ItemsList->Open();
		}
	 }
	 if(cmbSearchInclude->ItemIndex == 1){
		if(cmbSearchCriteria->ItemIndex == 0)
		{
			searchQuery = "SELECT productName,productPrice, FoodName FROM Items WHERE productName = \"" + foodname + "\"";
			DModule->ItemsList->Close();
			DModule->ItemsList->SQL->Clear();
			DModule->ItemsList->SQL->Add(searchQuery);
			DModule->ItemsList->Open();
		}
		if(cmbSearchCriteria->ItemIndex == 1)
		{
			searchQuery =  "SELECT productName,productPrice, FoodName FROM Items WHERE FoodName = \"" + foodname + "\"";
			DModule->ItemsList->Close();
			DModule->ItemsList->SQL->Clear();
			DModule->ItemsList->SQL->Add(searchQuery);
			DModule->ItemsList->Open();
		}
		if(cmbSearchCriteria->ItemIndex == 2)
		{
			searchQuery = "SELECT productName,productPrice, FG.FoodGroup FROM Items IT, TFood FD, TFoodGroup FG WHERE  IT.FoodName = FD.FoodName AND FD.FoodGroupID = FG.FoodGroupID AND FoodGroup =  \"" + foodname + "\"";
			DModule->ItemsList->Close();
			DModule->ItemsList->SQL->Clear();
			DModule->ItemsList->SQL->Add(searchQuery);
			DModule->ItemsList->Open();
		}
	 }
}
//---------------------------------------------------------------------------

void TshopName::switchPictureGrid(bool status)
{
	dbgItems2Select->Enabled = !status;
	dbgItems2Select->Visible = !status;
	ButtonGroup1->Visible = status;
	ButtonGroup1->Enabled = status;
	imgCategory->Visible = status;
	imgCategory->Enabled = status;
	pnlPicture->Visible = status;
	pnlPicture->Enabled = status;
}

void __fastcall TshopName::cmbSortItemsChange(TObject *Sender)
{
   if(cmbSortItems->ItemIndex == 0){
		UpdateQuery(searchQuery + " ORDER BY productName");
   }if(cmbSortItems->ItemIndex == 1){
		UpdateQuery(searchQuery + " ORDER BY productPrice");
   }
}
//--------------------------------------------------------------------------

void TshopName::UpdateQuery(String query)
{
	DModule->ItemsList->Close();
	DModule->ItemsList->SQL->Clear();
	DModule->ItemsList->SQL->Add(query);
	DModule->ItemsList->Open();
}
void __fastcall TshopName::AscDescChanging(TObject *Sender, bool &AllowChange)
{
   if(cmbSortItems->ItemIndex == 0){
		UpdateQuery(searchQuery + " ORDER BY productName ASC");
   }if(cmbSortItems->ItemIndex == 1){
		UpdateQuery(searchQuery + " ORDER BY productPrice ASC");
   }
}
//---------------------------------------------------------------------------


void __fastcall TshopName::AscDescClick(TObject *Sender, TUDBtnType Button)
{
   if(cmbSortItems->ItemIndex == 0){
		UpdateQuery(searchQuery + " ORDER BY productName DESC");
   }if(cmbSortItems->ItemIndex == 1){
		UpdateQuery(searchQuery + " ORDER BY productPrice DESC");
   }
}
//---------------------------------------------------------------------------
void TshopName::emptyQuery(String query)
{
  	DModule->ItemsList->Close();
	DModule->ItemsList->SQL->Clear();
	DModule->ItemsList->SQL->Add(query);
	DModule->ItemsList->Open();
}
