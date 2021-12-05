
#ifndef _Symptom_H_
#define _Symptom_H_

// Symptom.h
#include "Core.h"
#include "Person.h"
#include "JvTime.h"

class Symptom
{
 private:
 protected:
 public:
  std::string type;
  Person * patient; //change patient to patient
  JvTime * created;
  Symptom(std::string arg_type, Person * arg_patient, JvTime * arg_created); // change patient to patient
  virtual Json::Value * dumpJ();
};

#endif /* _Symptom_H_ */
