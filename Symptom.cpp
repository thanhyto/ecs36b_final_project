
#include "Symptom.h"

Symptom::Symptom
Symptom(std::string arg_type, Person * arg_patient, JvTime * arg_created)
{
  this->type = arg_type;
  this->patient = arg_patient;
  this->created = arg_created;
}

Json::Value * Symptom::dumpJ
(void)
{
  // to be implemented for hw4 part3
  // return (Json::Value *) NULL; // this line is incorrect, just to avoid a g++ warning
  std::cout << "dumpJ of Symptom ==> begin" << std::endl;

  Json::Value * result_ptr = new Json::Value();
  (*result_ptr)["from"] = (*(this->patient)->dumpJ());
  (*result_ptr)["type"] = this -> type;

  std::string * str_ptr = (this->created)->getTimeString();
  (*result_ptr)["created_time"] = *str_ptr;
  delete str_ptr;
  
#ifdef _ECS36B_DEBUG_
  std::cout << result_ptr->toStyledString() << std::endl;
#endif /*_ECS36B_DEBUG_*/

  std::cout << "dumpJ of Symptom ==> end" << std::endl;
  return result_ptr;
}
