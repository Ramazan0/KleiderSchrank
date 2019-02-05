#ifndef GARMENT_H
#define GARMENT_H

#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
using namespace std;

enum class Color{Red, Blue, Gray, Yellow};
const std::vector<std::string> color_names{"red", "blue", "gray", "yellow"};

enum class Type{Pants, Blouse, Shirt, Skirt};
const std::vector<std::string> type_names{"pants", "blouse", "shirt", "skirt"};


//Definition der Klasse Garment

class Garment
{
  int preis;
  Color color;
  Type type;
public:
  Garment(const int&, Color color = Color::Gray, Type type = Type::Pants);
  int get_price() const;
  Type get_type() const;
  Color get_color() const;
  bool has_color(Color f) const;
  void deteriorate(int w);
  friend ostream& operator<<(ostream&, const Garment&);
};
#endif
