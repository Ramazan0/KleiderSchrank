#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include"garment.h"
using namespace std;

//Implementierung der Klasse Garment

 Garment::Garment(const int& p, Color farbe, Type typ) : preis{p}, color{farbe}, type{typ}
{
	if(preis < 0)
    throw runtime_error("Error!");
}

int Garment::get_price() const
{
	return preis;
}

Type Garment::get_type() const
{
	return type;
}

bool Garment::has_color(Color f) const
{
	return (color == f);
}

Color Garment::get_color() const
{
	return color;
}


void Garment::deteriorate(int w)
{
  if(w < 0)
    throw runtime_error("Error!");
  preis -= w;
  if(preis < 0)
    preis = 0;
}

ostream& operator<<(ostream& o, const Garment& g)
{
	o << "[" << g.preis << " Cent, " << color_names.at(static_cast<size_t>(g.color)) << " ";
    o << type_names.at(static_cast<size_t>(g.type)) << "]";
  return o;
}
