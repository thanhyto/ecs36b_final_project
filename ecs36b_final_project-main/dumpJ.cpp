
#include <iostream>

// JSON RPC part
#include <stdlib.h>
#include <jsonrpccpp/client/connectors/httpclient.h>

#include "Advice.h"
#include "Symptom.h"
#include "Person.h"

using namespace jsonrpc;
using namespace std;

int
main(void)
{
  // new advice (preparation)
  std::string s_profile { "1234567" };
  std::string s_post { "123098912" };
  std::string s_advice { "5001234" };

  Person * patient_ptr = new Person("PatientA", "123456789"); // Patient's name and phone number
  Message * msg_ptr = new Message("Describing patient's conditions: ");
  JvTime * created_time_ptr = new JvTime("2020-11-03T17:01:24+0000");

  Advice * advice_ptr = new Advice(s_profile, s_post, s_advice,
				      patient_ptr, msg_ptr, created_time_ptr);

  // dumpJ
  Json::Value * myv1_ptr = advice_ptr->dumpJ();
  if (myv1_ptr != NULL)
    std::cout << myv1_ptr->toStyledString() << std::endl;
  else
    std::cout << "null JSON pointer" << std::endl;

  // handling the symptoms
  advice_ptr->symptoms = new vector<Symptom *>();

  JvTime *symptom1_time_ptr = new JvTime("2020-11-03T17:02:01+0000");
  Symptom * symptom1_ptr = new Symptom("Fever", patient_ptr, symptom1_time_ptr);
  (*(advice_ptr->symptoms)).push_back(symptom1_ptr);

  JvTime *symptom2_time_ptr = new JvTime("2020-11-03T17:02:01+0000");
  Symptom * symptom2_ptr = new Symptom("Fever Goes Down", patient_ptr, symptom1_time_ptr);
  (*(advice_ptr->symptoms)).push_back(symptom2_ptr);

  // dumpJ
  Json::Value * myv2_ptr = advice_ptr->dumpJ();
  if (myv2_ptr != NULL)
    std::cout << myv2_ptr->toStyledString() << std::endl;
  else
    std::cout << "null JSON pointer" << std::endl;

  return 0;
}
