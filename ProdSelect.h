//---------------------------------------------------------------------------

#ifndef ProdSelectH
#define ProdSelectH
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class ProdSelected //This class should be able to produce Data
{                  //But the question is where will our data actually go?

private:
	String allItems;
	String itemCategory;
	String itemGroup;
public:
	String callAllItems();
	String callItemCategory();
	String callItemGroup(String itemType);
	void AllItemsShow();
	void ItemCatShow();
};
#endif
