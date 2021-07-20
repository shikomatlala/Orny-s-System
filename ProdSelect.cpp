//---------------------------------------------------------------------------

#pragma hdrstop
#include <vcl.h>
#include "ProdSelect.h"
#include "TDMSelectProduct.h"
#include "ShopSystemDataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


//Calling functions
String ProdSelected::callAllItems()
{
	allItems = "SELECT productName, productPrice, FoodName FROM Items;";
	return allItems;
}
String ProdSelected::callItemCategory()
{
	itemCategory = "SELECT foodType FROM TFoodType";
	return itemCategory;
}
String ProdSelected::callItemGroup(String itemType)
{
	itemGroup = "SELECT FoodGroup FROM TFoodGroup WHERE FoodTypeID = \"" + itemType + "\"";
	return itemGroup;
}


//Showing functions
void ProdSelected::AllItemsShow()
{
	DModule->ItemsList->Close();
	DModule->ItemsList->SQL->Clear();
	DModule->ItemsList->SQL->Add(callAllItems());
	DModule->ItemsList->Open();
}
void ProdSelected::ItemCatShow()
{
	DModule->ItemsList->Close();
	DModule->ItemsList->SQL->Clear();
	DModule->ItemsList->SQL->Add(callItemCategory());
	DModule->ItemsList->Open();
}

