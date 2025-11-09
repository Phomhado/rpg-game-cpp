#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

struct Attributes {
  int strenght;
  int charisma;
  int intelligence;

  Attributes(int str = 0, int cha = 0, int intel = 0) : strenght(str), charisma(cha), intelligence(intel) {} 
};

#endif