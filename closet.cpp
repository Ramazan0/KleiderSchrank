#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include"garment.h"
#include"closet.h"
using namespace std;

//Implementierung der Klasse Closet

Closet::Closet(size_t max, vector<Garment> k) : max_capacity{max}, kleidungen{k}
{
  if((max_capacity < 5 || max_capacity > 300) || (kleidungen.size() > max_capacity) || (kleidungen.size() == 0))
    throw runtime_error("Error!");

  bool not_same{false};
  for(size_t i{1}; i < kleidungen.size(); ++i)
  {
      if(kleidungen.at(0).get_type() != kleidungen.at(i).get_type())
      {
        not_same = true;
        break;
      }
  }
  if(not_same == false)
    throw runtime_error("Error!");
}

bool Closet::add(vector<Garment> k)
{
  	vector<Garment> alt;
  	alt = kleidungen;
  	for(int j{static_cast<int>(k.size()) - 1}; j >= 0; --j)
   	{
   		kleidungen.insert(kleidungen.begin(), k.at(j));
   	}
  	if(kleidungen.size() > max_capacity)
    {
      kleidungen = alt;
      return false;
    }
    return true;
}

double Closet::mean_price() const
{
  double summe{0};

  for(size_t i{0}; i < kleidungen.size(); ++i)
  {
  	summe += kleidungen.at(i).get_price();
  }
  return (summe / kleidungen.size());
}

ostream& operator<<(ostream& o, const Closet& c)
{
  o << "[" << c.max_capacity << ", {";

  for(size_t i{0}; i < c.kleidungen.size(); ++i)
  {
  	o << c.kleidungen.at(i);

    if(i != c.kleidungen.size() - 1)
	{
      o << ", ";
	}
  }
  o << "}, " << c.mean_price() << " Cent]";

  return o;
}

vector<int> Closet::content() const
{
  vector<int> anzahl = {0, 0, 0, 0};

  for(size_t i{0}; i < kleidungen.size(); ++i)
  {
  	if(kleidungen.at(i).get_type() == Type::Pants)
      ++anzahl[0];
    if(kleidungen.at(i).get_type() == Type::Blouse)
      ++anzahl[1];
    if(kleidungen.at(i).get_type() == Type::Shirt)
      ++anzahl[2];
    if(kleidungen.at(i).get_type() == Type::Skirt)
      ++anzahl[3];
  }
  return anzahl;
}

vector<Garment> Closet::remove(Color f)
{
	vector<Garment> deleted, remaining;
	for(auto i{0}; i < kleidungen.size(); ++i)
	{
		if (kleidungen.at(i).has_color(f))
		{
			deleted.push_back(kleidungen.at(i));
		}
		else
		{	
			remaining.push_back(kleidungen.at(i));
		}
	}
	bool all_same = true;

	for(size_t i{1}; i < remaining.size(); i++)
	{
		if (remaining.at(0).get_type() != remaining.at(i).get_type())
		{
			all_same = false;
			break;
		}
	}
	if (all_same)
	{
		deleted = {};
	}
	else
	{
		kleidungen = remaining;
	}
	return deleted;
}

 

















