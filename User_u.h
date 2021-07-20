//---------------------------------------------------------------------------

#ifndef User_uH
#define User_uH
#include "Person_u.h"
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//Person motho;
//---------------------------------------------------------------------------
class User : public Person
{
  //Alrady we have person information (name, surname, dateof birth, person id and gender)
private:
	String jobPosition;
	String userID;
	String username;
	String password;

public:
	User();
	~User();
	void setJobPos(String jobPosition);
	void setUserID();
	void setUsername(String username,String &report);
	void setPassword(String password);
	void userNameFunction(String name,String &report);
	String nameFunction(String name);
	String getJobPos();
	String getUserID();
	String getUsername();
	String getPassword();
	String custXID();
	String custXName();
};
#endif
