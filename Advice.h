
#ifndef _ADVICE_H_
#define _ADVICE_H_

// Advice.h - change Comment to advice
#include "Core.h"
#include "Symptom.h"
#include "Message.h"
#include "Person.h"
#include "JvTime.h"

class Advice
{
 private:
 protected:
 public:
  std::string profile_id;
  std::string post_id;
  std::string advice_id;

  Person * patient; // change patient to patient
  Message * msg;
  JvTime * created;

    // change symptoms to symptoms
  std::vector<Symptom *> * symptoms;

  Advice(std::string arg_profile_id, std::string arg_post_id, std::string arg_advice_id,
	  Person * arg_patient, Message * arg_msg, JvTime * arg_created);
  virtual Json::Value * dumpJ();
};

#endif /* _ADVICE_H_ */
