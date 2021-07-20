//---------------------------------------------------------------------------

#ifndef InvoiceH
#define InvoiceH
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class Invoice
{
private:
	int invID;
	String invNumber;
	String invDate;
	String CID;
	String productName;
	String productID;
	double productPrice;
	double varSumPrice;
	int itemsCount;

public:
	Invoice();
	~Invoice();
	void resetInvoice();
	void setProdName(String);
	void setProdID(String);
	void setProdPrice(float price);
	void sumPrice(float price);
	void subPrice(float price);
	void sumItems();
	void subItems();
	void NoItems(int items);
	int getInvID();
	String getInvNumber();
	String getInvDate();
	String getCID();
	String getProdName();
	String getProdIDs();
	double getProdPrices();
	double getSumPrice();
	int getSumItems();

};

#endif
