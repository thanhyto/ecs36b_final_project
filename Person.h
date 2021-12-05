#ifndef _PERSON_H_
#define _PERSON_H_

#include "Core.h"

class Person : public Core
{
 private:
  static unsigned int person_count;
  std::string phoneNumber; // change to phone number
  std::string patientName; // change to patientName
  std::string hometown;
  GPS_DD home;
 public:
  Person(std::string, std::string, std::string, std::string);
  Person();
  Person(std::string, std::string, std::string, std::string, std::string, std::string);
  Person(std::string, std::string);
  void setHome(std::string);
  void setHome(GPS_DD);

  virtual bool operator==(Person& aPerson);
  virtual std::string getPhoneNumber(); //change getVsID to getPhoneNumber
  virtual std::string getPatientName(); // change getAvatarName to getPatientName
  virtual GPS_DD getHome();
  virtual bool message(Json::Value);
  virtual Json::Value * dumpJ();
  
};

#endif  /* _PERSON_H_ */