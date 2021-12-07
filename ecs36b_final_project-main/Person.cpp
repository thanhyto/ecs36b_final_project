#include "Person.h"

unsigned int Person::person_count { };

Person::Person(std::string core_arg_host_url, std::string core_arg_owner_vsID,
	       std::string core_arg_class_id, std::string core_arg_object_id)
  : Core { core_arg_host_url, core_arg_owner_vsID, core_arg_class_id, core_arg_object_id }
{
  person_count++;
  std::cout << "Core Constructor" << std::endl;
}

Person::Person()
{
}
//change arg_avatar_name to arg_patient_name and arg_vsID to arg_phoneNumber
Person::Person(std::string core_arg_host_url, std::string core_arg_owner_vsID,
	       std::string core_arg_class_id, std::string core_arg_object_id,
	       std::string arg_patient_name, std::string arg_phoneNumber)
  : Core { core_arg_host_url, core_arg_owner_vsID, core_arg_class_id, core_arg_object_id }
{
    //change arg_avatar_name and avatar_name to patient name
    //change arg_vsID to and vsID to phoneNumber
  this->patientName = arg_patient_name;
  this->phoneNumber = arg_phoneNumber;
}

Person::Person
(std::string arg_patient_name, std::string arg_phoneNumber)
{
  this->patientName = arg_patient_name;
  this->phoneNumber = arg_phoneNumber;
}


std::string
Person::getPhoneNumber()
{
    //change vsID to phoneNumber
  return this->phoneNumber;
}

std::string
Person::getPatientName()
{
    //change avatar_name to patientName
  return this->patientName;
}

bool
Person::operator==
(Person& aPerson)
{
  return (this->phoneNumber == aPerson.getPhoneNumber());
}

bool
Person::message
(Json::Value myv)
{
  std::cout << "message called\n";
  std::cout << myv["subject"] << std::endl;
  std::cout << myv["body"] << std::endl;
  return true;
}

Json::Value * Person::dumpJ
(void)
{
  Json::Value *result_ptr = new Json::Value();

  (*result_ptr)["patient_name"] = this->patientName;
  (*result_ptr)["phone number"] = this->phoneNumber;
#ifdef _ECS36B_DEBUG_
  std::cout << result_ptr->toStyledString() << std::endl;
#endif /* _ECS36B_DEBUG_ */
  return result_ptr;
}

