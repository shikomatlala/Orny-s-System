//---------------------------------------------------------------------------

#ifndef OrderProdH
#define OrderProdH
//---------------------------------------------------------------------------
#endif
#include <System.Classes.hpp>

class Product
{
  private:
	//Product Information
	String prodID;
	String prodName;
	double productPrice;
	double productStockPrice;
	String productStockDate;
	int productStockLevel;
	int productReorderLevel;
	String productExpiaryDate;
	String foodName;
	String foodID;
	String supplierCompanyName;
	String itemSupplierID;

  public:
	Product();
	~Product();
	//SET PRODUCT DETAILS
	void setProdID();
	void setProdName(String , bool &report);
	void setProdPrice(double , bool &report);
	void setProdStockPrice(double , bool &report);
	void setProdStockDate(String , bool &report);
	void setProdStockLevel(int , bool &report);
	void setProdReorderLevel(int , bool &report);
	void setProdExpiaryDate(String , bool &report);
	void setFoodName(String , bool &report);
	void setFoodID(String , bool &report);
	void setSupCompanyName(String , bool &report);
	void setItemSupplierID(String , bool &report);

	//GET PRODUCT DETAILS
	String getProdID();
	String getProdName();
	double getProdPrice();
	double getProdStockPrice();
	String getProdStockDate();
	int getProdStockLevel();
	int getProdReorderLevel();
	String getProdExpiaryDate();
	String getFoodName();
	String getFoodID();
	String getSupCompanyName();
	String getItemSupplierID();


	//GET PRODUCT DETAILS AND OTHERS
	String getProductDetails();
	//CLEAR PRODUCT ID
	void clearProdDetails();

};
