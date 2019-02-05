#ifndef CLOSET_H
#define CLOSET_H

#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include"garment.h"
using namespace std;

//Definition der Klasse Closet

class Closet
{
  size_t max_capacity;
  vector<Garment> kleidungen;
public:
  Closet(size_t, vector<Garment>);
  bool add(vector<Garment>);
  double mean_price() const;
  vector<int> content() const;
  vector<Garment> remove(Color f);
  friend ostream& operator<<(ostream&, const Closet&);
};

#endif
