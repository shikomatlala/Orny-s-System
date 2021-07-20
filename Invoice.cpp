//---------------------------------------------------------------------------

#pragma hdrstop

#include "Invoice.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//SETTERS
Invoice::Invoice()
{
	invID = 0;
	invNumber  = "1";
	invDate = Date();
	CID = "0000";
	productName = "Genesis";
	productID = "1";
	productPrice = 90;
	varSumPrice = 0;
}
Invoice::~Invoice()
{

}
void Invoice::resetInvoice()
{
	invID = 0;
	invNumber  = "1";
	invDate = Date();
	CID = "0000";
	productName = "Genesis";
	productID = "1";
	productPrice = 90;
	varSumPrice = 0;
}
void Invoice::setProdName(String productName)
{
	this->productName = productName;
}

void Invoice::setProdID(String productID)
{
	this->productID = productID;
}

void Invoice::setProdPrice(float price)
{
	productPrice = StrToFloat(price);

}
void Invoice::sumPrice(float price)
{
	varSumPrice   = varSumPrice + price;
}
void Invoice::subPrice(float price)
{
   varSumPrice = varSumPrice - price;
}
void Invoice::sumItems()
{
   itemsCount++;
}
void Invoice::subItems()
{
   itemsCount--;
}
void Invoice::NoItems(int items)
{
	itemsCount = items;
}

//GETTERS
int Invoice::getInvID()
{
	return invID;
}


String Invoice::getInvNumber()
{
	return invNumber;
}
String Invoice::getInvDate()
{
	invDate = Date() + Time();
	return invDate;
}
String Invoice::getCID()
{
	return CID;
}
String Invoice::getProdName()
{
	return productName;
}
String Invoice::getProdIDs()
{
	return productID;
}
double Invoice::getProdPrices()
{
	return productPrice;
}
double Invoice::getSumPrice()
{
	return varSumPrice;
}
int Invoice::getSumItems()
{
	return itemsCount;
}
