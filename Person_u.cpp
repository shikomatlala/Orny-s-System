//---------------------------------------------------------------------------

#pragma hdrstop
#include "Person_u.h"
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
Person::Person()
{
	name = "Shiko";
	surname = "Matlala";
	id = "0001019999081";
	dOB = "0000/00/00";
	gender = "Male";
}
Person::~Person()
{

}
void Person::nameFunction(String name,String &report)
{
	String finName;
	//Encrypt the name
	if(!name.IsEmpty())
	{
		char checkName;
		String temp  = "";
		//this->username = username;
		for(int x = 1; x <= name.Length();x++)
		{
			checkName = name[x];
			temp = checkName;
			if(!isalpha(checkName)){
				report = "Invalid Name \"" + temp + "\"";
				x = name.Length();
				}
			else{
				this->name = name;
				report = "Good";
			}
		}
	}
	else
		report = "Enter Name";
}
void Person::surnameFunction(String surname,String &report)
{
	//Encrypt the name
	if(!surname.IsEmpty())
	{
		char checkName;
		String temp  = "";
		//this->username = username;
		for(int x = 1; x <= surname.Length();x++)
		{
			checkName = surname[x];
			temp = checkName;
			if(!isalpha(checkName)){
				report = "Invalid Surname \"" + temp + "\"";
				x = surname.Length();
				}
			else{
				this->surname = surname;
				report = "Good";
			}
		}
	}
	else
		report = "Enter Surname";
}
void Person::setName(String name,String &report)
{
	nameFunction(name,report);
}
void Person::setSurname(String surname,String &report)
{
	surnameFunction(surname,report);
}
void Person::setID(String id, String &report)
{
	//Encrypt the name
	if(!id.IsEmpty())
	{
		if(id.Length()==13){
			char checkID;
			String temp  = "";
			for(int x =1; x <= id.Length();x++){
				checkID = id[x];
				temp = checkID;
				if(!isdigit(checkID)){
					report = "Invalid ID \"" + temp + "\"";
					x = id.Length();
				}
				else {
					this->id = id;
					report = "Good";
				}
			}
		}
		else
			report = "Invalid ID";
	}
	else
		report = "Enter ID";
}
void Person::setDOB(String dOB,String &report)
{
	this->dOB = dOB;
	report  = "Good";
}
void Person::setGender(String gender)
{
	this->gender = gender;
}
String Person::getName()
{
	return name;
}
String Person::getSurname()
{
	return surname;
}
String Person::getID()
{
   return id;
}
String Person::getDOB()
{
	return dOB;
}
String Person::getGender()
{
	return gender;
}
String Person::CompareID_Date(String id,String dob)
{
	//Prepare ID number
	id.Delete(7,7);
	//Prepare the Date of Birth
	int pos;
	pos = dob.Pos("/");
	dob.Delete(pos,1);
	pos = dob.Pos("/");
	dob.Delete(pos,1);
	//Remove the first two digits on Date of Birth
	dob.Delete(1,2);

	char valID;
	char valDOB;
	String idStr = "", dobStr = "";

	for(int x = 1; x <= id.Length();x++)
	{
		valID = id[x];
		valDOB = dob[x];
		if(valID != valDOB)
		{
			//Exit the loop and show us the problem
			idStr = valID;
			dobStr = valDOB;
			switch(x)
			{
				case 1: return "Year of Birth \ndoesn't Match ID";
				case 2: return "Year of Birth \ndoes not Match ID";
					break;
				case 3: return "Month of Birth \ndoesn't Match ID";
				case 4: return "Month of Birth \ndoesn't Match ID";
					break;
				case 5: return "Day of Birth \ndoesn't Match ID";
				case 6: return "Day of Birth \ndoesn't Match ID";
					break;
				default:
                    return "DOB does not match ID";
			}
			x = id.Length()+2;
		}
		if(x==id.Length())
		{
			return "Good Match";
		}
	}
}
String Person::getPerson()
{
	String person = "";
	person += name +"#";
	person += surname +"#";
	person += id +"#";
	person += gender +"#";
	person += dOB +"#";
	return person;
}

//String Person::CompareID_Gender(String id,String gender)
//{
//	//Prepare ID number
//	id.Delete(7,7);
//	//Prepare the Date of Birth
//	int pos;
//	pos = dob.Pos("/");
//	dob.Delete(pos,1);
//	pos = dob.Pos("/");
//	dob.Delete(pos,1);
//	//Remove the first two digits on Date of Birth
//	dob.Delete(1,2);
//
//	char valID;
//	char valDOB;
//	String idStr = "", dobStr = "";
//
//	for(int x = 1; x <= id.Length();x++)
//	{
//		valID = id[x];
//		valDOB = dob[x];
//		if(valID != valDOB)
//		{
//			//Exit the loop and show us the problem
//			idStr = valID;
//			dobStr = valDOB;
//			switch(x)
//			{
//				case 1: return "Year of Birth \ndoesn't Match ID";
//				case 2: return "Year of Birth \ndoes not Match ID";
//					break;
//				case 3: return "Month of Birth \ndoesn't Match ID";
//				case 4: return "Month of Birth \ndoesn't Match ID";
//					break;
//				case 5: return "Day of Birth \ndoesn't Match ID";
//				case 6: return "Day of Birth \ndoesn't Match ID";
//					break;
//				default:
//                    return "DOB does not match ID";
//			}
//			x = id.Length()+2;
//		}
//		if(x==id.Length())
//		{
//			return "Good Match";
//		}
//	}
//}
