//---------------------------------------------------------------------------

#pragma hdrstop

#include "OrderProd.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Product::Product()
{
	prodID = "NULL";
	prodName = "NULL";
	productPrice = 00.00;
	productStockPrice = 0;
	productStockDate = Date();
	productStockLevel = 0;
	productReorderLevel = 0;
	productExpiaryDate = Date();
	foodName = "EMPTY";
	foodID = "EMPTY";
	supplierCompanyName = "EMPTY";
	itemSupplierID = "NULL";
}
Product::~Product()
{
}
//SET PRODUCT DETAILS
void Product::setProdID()
{
	String date,time;
	int pos;
	prodID = "PID";
	date = Date();
	time  = Time();
	pos = date.Pos("/");
	date.Delete(pos,1);
	pos = date.Pos("/");
	date.Delete(pos,1);
	pos = time.Pos(":");
	time.Delete(pos,1);
	pos = time.Pos(":");
	time.Delete(pos,1);
	pos = time.Pos(" ");
	time.Delete(pos,1);
	pos = time.Pos("M");
	time.Delete(pos,1);
	prodID += time + date;
}

void Product::setProdName(String prodName, bool &report)
{
	if(!prodName.IsEmpty()){
		if(prodName.Length() < 50)
		{
			this->prodName = prodName;
			report = 1;
		}
		else { //TAKE ONLY THE POTION THAT IS REQUIRED
			this->prodName = prodName.SubString(0,49);
			report = 1;
		}
	}
	else{
		report = 0;
	}
}
void Product::setProdPrice(double productPrice, bool &report)
{
	if(productPrice>0){
		this->productPrice = productPrice;
		report = 1;
	}
	else
		report = 0;
}
void Product::setProdStockPrice(double productStockPrice, bool &report)
{
	if(productStockPrice > 0){
		this->productStockPrice = productStockPrice;
		report = 1;
	}
	else
		report = 0;

}
void Product::setProdStockDate(String productStockDate, bool &report)
{
	this->productStockDate = productStockDate;
	report = true;
}
void Product::setProdStockLevel(int productStockLevel, bool &report)
{
	if(productStockLevel > 0){
		this->productStockLevel = productStockLevel;
		report = true;
	}
	else
		report =false;
}
void Product::setProdReorderLevel(int productReorderLevel, bool &report)
{
	this->productReorderLevel = productReorderLevel;
	report = true;
}
void Product::setProdExpiaryDate(String productExpiaryDate, bool &report)
{
	this->productExpiaryDate = productExpiaryDate;
	report = true;
}
void Product::setFoodName(String foodName, bool &report)
{
	this->foodName = foodName;
	report = true;
}

void Product::setFoodID(String foodID, bool &report)
{
	this->foodID = foodID;
	report = true;
}
void Product::setSupCompanyName(String supplierCompanyName,bool &report)
{
	this->supplierCompanyName = supplierCompanyName;
	report = true;
}
void Product::setItemSupplierID(String itemSupplierID, bool & report)
{
	this->itemSupplierID = itemSupplierID;
	report = true;
}

//GET PRODUCT DETAILS
String Product::getProdID(){
	return prodID;
}
String Product::getProdName(){
	return prodName;
}
double Product::getProdPrice()
{
	return productPrice;
}
double Product::getProdStockPrice(){
	return productStockPrice;
}
String Product::getProdStockDate(){
	return productStockDate;
}
int Product::getProdStockLevel(){
	return productStockLevel;
}
int Product::getProdReorderLevel(){
	return productReorderLevel;
}
String Product::getProdExpiaryDate(){
	return productExpiaryDate;
}
String Product::getFoodName(){
	return foodName;
}
String Product::getFoodID(){
	return foodID;
}
String Product::getSupCompanyName(){
	return supplierCompanyName;
}
String Product::getItemSupplierID(){
	return itemSupplierID;
}


//GET PRODUCT DETAILS
String Product::getProductDetails()
{
	String productDetails = "";
	productDetails = prodID + "#";
	productDetails += prodName+ "#";
	productDetails += FloatToStr(productPrice);
	productDetails += "#";
	productDetails += FloatToStr(productStockPrice);
	productDetails += "#";
	productDetails += productStockDate+ "#";
	productDetails += IntToStr(productStockLevel);
	productDetails += "#";
	productDetails += IntToStr(productReorderLevel);
	productDetails += "#";
	productDetails += productExpiaryDate + "#";
	productDetails += foodName + "#";
	productDetails += foodID + "#";
	productDetails += supplierCompanyName + "#";
	productDetails += itemSupplierID + "#";
	return productDetails;
}
