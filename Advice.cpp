
#include "Advice.h"
//change author to patient and symptoms to symptoms
Advice::Advice
(std::string arg_profile_id, std::string arg_post_id, std::string arg_advice_id,
 Person * arg_patient, Message * arg_msg, JvTime * arg_created)
{
  this->profile_id = arg_profile_id;
  this->post_id = arg_post_id;
  this->advice_id = arg_advice_id;
  this->patient = arg_patient;
  this->msg = arg_msg;
  this->created = arg_created;

  this->symptoms = NULL;
}

Json::Value * Advice::dumpJ
(void)
{
  
  std::cout << "dumpJ of Advice ==> begin" << std::endl;
  int i;

  Json::Value * result_ptr = new Json::Value();
  std::string l_id = this->profile_id + "_" + this->post_id + "_" + this->Advice_id;

  (*result_ptr)["id"] = l_id;
  (*result_ptr)["from"] = (*(this->patient)->dumpJ());
  (*result_ptr)["message"] = (this->msg)->content;

  std::string * str_ptr = (this->created)->getTimeString();
  (*result_ptr)["created_time"] = *str_ptr;
  delete str_ptr;

  Json::Value json_c_symptoms;
  Json::Value json_c_symptoms_array;

  if((this->symptoms != NULL)&&
  ((this->symptoms)->size()>0))
  {
    for (i=0; i<(this->symptoms)->size();i++)
    {
      Json::Value * dumpjv_ptr = ((*(this->symptoms))[i])->dumpJ();
      json_c_symptoms[i]=(*dumpjv_ptr);
      delete dumpjv_ptr;
    }
    json_c_symptoms_array["data"] = json_c_symptoms;
    json_c_symptoms_array["count"] = ((int) (*(this->symptoms)).size());
    (*result_ptr)["symptoms"] = json_c_symptoms_array;
  }

#ifdef _ECS36B_DEBUG
  std::cout << result_ptr->toStyledString() << std::endl;
#endif /*_ECS36B_DEBUG_*/

  std::cout << "dumpJ of Advice ==> end" << std::endl;
  return result_ptr;
}
