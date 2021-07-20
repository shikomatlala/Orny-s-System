//---------------------------------------------------------------------------

#ifndef Person_uH
#define Person_uH
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class Person
{
private:
	String name;
	String surname;
	String id;
	String dOB;
	String gender;
public:
	Person();
	~Person();
	void setName(String name,String &report);
	void nameFunction(String name,String &report);
	void surnameFunction(String surname,String &report);
	void setSurname(String surname,String &report);
	void setID(String id,String &report);
	void setDOB(String dOB, String &report);
	void setGender(String gender);
	String getName();
	String getSurname();
	String getID();
	String getDOB();
	String getGender();
	String getPerson();
    String CompareID_Date(String id,String dob);
};
#endif
