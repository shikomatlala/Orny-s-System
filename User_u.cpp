//---------------------------------------------------------------------------

#pragma hdrstop

#include "User_u.h"
#include "Person_u.h"
#include "Person_u.cpp"
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)

User::User()
{

}
User::~User()
{

}
void User::userNameFunction(String name,String &report)
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
			if(isspace(checkName)){
				report = "Invalid Username \"" + temp + "\"";
				x = name.Length();
				}
			else{
				this->username = name;
				report = "Good";
			}
		}
	}
	else
		report = "Enter Username";
}
void User::setUserID()
{
	String date,time;
	int pos;
	userID = "CID";
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
//	pos = time.Pos("A");
//	time.Delete(pos,1);
//	pos = time.Pos("P");
//	time.Delete(pos,1);
	pos = time.Pos("M");
	time.Delete(pos,1);
	userID += time + date;
}
void User::setUsername(String username,String &report)
{
	userNameFunction(username,report);
}
void User::setPassword(String password)
{
	  this->password = password;
	  //How do we set a string password?
}
void User::setJobPos(String jobPosition)
{
	this->jobPosition = jobPosition;
}
String User::getUserID()
{
	  return userID;
}
String User::getUsername()
{
	 return username;
}
String User::getPassword()
{
   return password;
}
String User::custXID()
{
    String date,time;
	int pos;
	userID = "XID";
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
//	pos = time.Pos("A");
//	time.Delete(pos,1);
//	pos = time.Pos("P");
//	time.Delete(pos,1);
	pos = time.Pos("M");
	time.Delete(pos,1);
	userID += time + date;
	return userID;
}
String User::custXName()
{
	return "XCustomer";
}