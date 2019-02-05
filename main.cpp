#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include"garment.h"
#include"closet.h"

using namespace std;

int main(){
//Basisfunktionalitaet Beginn
 try{
    Garment garment{0, Color::Blue};
    cout << garment << '\n';
  }
  catch(runtime_error& e){
    cout << "Error1" << '\n';
  }
  try{
    cout << Garment {30000} << '\n';
  }
  catch(runtime_error& e){
    cout << "Error2" << '\n';
  }
  try{
    Garment garment{-300000, Color::Blue, Type::Pants};
	cout << garment << '\n';
  }
  catch(runtime_error& e){
    cout << "Error3" << '\n';
  }
  try{
    Garment garment{300000, Color::Blue, Type::Pants};
	cout << garment << '\n';
  }
  catch(runtime_error& e){
    cerr << "Error4" << '\n';
  }

  Garment pants{34500, Color::Blue, Type::Pants};
  Garment blouse{12700, Color::Red, Type::Blouse};
  const Garment shirt{2300, Color::Yellow, Type::Shirt};
  Garment shirt2{23500, Color::Red, Type::Shirt};
  Garment skirt{26600, Color::Gray, Type::Skirt};
  Garment skirt2{4600, Color::Blue, Type::Skirt};

  cout << Garment {300001, Color::Blue, Type::Pants} << '\n';
  cerr << Garment {300001, Color::Blue, Type::Pants} << '\n';
  cout << Garment {34500, Color::Blue, Type::Pants}.get_price() << '\n';
  cout << shirt.has_color(Color::Yellow) << " " << shirt.has_color(Color::Red) << '\n';
  cout << (shirt.get_type() == Type::Pants) << " " << (Garment(30001).get_type() == Type::Pants) << '\n';
  cout << (shirt.get_type() == Type::Shirt) << " " << (Garment(30001).get_type() == Type::Shirt) << '\n';
  cout << shirt.get_price() << '\n';
  Garment {26600, Color::Gray, Type::Skirt}.deteriorate(50);
  skirt.deteriorate(50);
  cout << skirt << '\n';

  try{
    pants.deteriorate(500000);
    pants.deteriorate(-500000);
  }
  catch(runtime_error& e){
    cout << "Error5" << '\n';
  }
  cout << pants << '\n';

  try{
    Closet closet1 {5, {skirt, blouse, shirt, pants}};
	cout << closet1 << '\n';
	cerr << closet1 << '\n';
    Closet closet2 {4, {skirt, blouse, shirt, pants}};
	cout << closet2 << '\n';
  }
  catch(runtime_error& e){
    cout << "Error6" << '\n';
  }

  try{
    Closet closet {5, {skirt, blouse, shirt, pants, skirt, pants}};
	cout << closet << '\n';
  }
  catch(runtime_error& e){
    cout << "Error7" << '\n';
  }

  try{
    Closet closet2 {300, {skirt, blouse, shirt, pants}};
	cout << closet2 << '\n';
    Closet closet1 {301, {skirt, blouse, shirt, pants}};
	cout << closet1 << '\n';
  }
  catch(runtime_error& e){
    cout << "Error8" << "\n";
  }

  try{
    Closet closet {5, {skirt, skirt2, skirt2, skirt}};
	cout << closet << '\n';
  }
  catch(runtime_error& e){
    cout << "Error9" << '\n';
  }
  try{
    Closet closet {5, {skirt, skirt2, blouse, skirt}};
	cout << closet << '\n';

  }
  catch(runtime_error& e){
    cout << "Error10" << '\n';
  }
  try{
    Closet closet {5, {shirt}};
	cout << closet << '\n';
  }
  catch(runtime_error& e){
    cout << "Error11" << '\n';
  }
  try{
    Closet closet{5, {}};
	cout << closet << '\n';
  }
  catch(runtime_error& e){
    cout << "Error12" << '\n';
  }

  cout << Closet{10, {skirt, blouse, shirt, pants, skirt}} << '\n';
  cerr << Closet{10, {skirt, blouse, shirt, pants, skirt}} << '\n';
  cout << Closet{10, {Garment {34500, Color::Blue, Type::Pants}, Garment {12700, Color::Red, Type::Blouse}, Garment {2300, Color::Yellow, Type::Shirt}, Garment {26600, Color::Gray, Type::Skirt}}} << '\n';
  Closet closet {10, {skirt, blouse, shirt, pants, skirt}};
  cout << closet.add({shirt2, skirt2}) << closet.add({blouse,skirt,pants}) << closet.add({}) << closet.add({pants}) << '\n';
  cout << closet << '\n';
  cout << closet.add({blouse, blouse, blouse, blouse, shirt}) << '\n';
  cout << closet.mean_price() << '\n';
  cout << closet << '\n';
  const Closet const_closet{closet};
  cout << const_closet.mean_price() << '\n';
  //Basisfunktionalitaet Ende



  //Zusatz fuer 10 Punkte
 
  cout << "\n\nZusatz 10 Punkte" << '\n';
  vector<int> vec{const_closet.content()};
  for(size_t i{0}; i<4; ++i){
    cout << type_names.at(i) << ": " << vec.at(i) << '\n';
  }
  
  vec = Closet{10, {Garment {34500, Color::Blue, Type::Pants}, Garment {12700, Color::Red, Type::Blouse}, Garment {2300, Color::Yellow, Type::Shirt}, Garment {26600, Color::Gray, Type::Skirt}}}.content();
  for(size_t i{0}; i<4; ++i){
    cout << type_names.at(i) << ": " << vec.at(i) << '\n';
  }
 

  //Zusatz fuer 15 Punkte

  cout << "\n\nZusatz 15 Punkte" << "\n";
  vector<Garment> old{closet.remove(Color::Yellow)};
  for(const auto& o:old)
    cout << o << '\n';
  cout << closet << '\n';
  old = closet.remove(Color::Yellow);
  for(const auto& o:old)
    cout << o << '\n';
  cout << closet << '\n';
  old = closet.remove(Color::Red);
  for(const auto& o:old)
    cout << o << '\n';
  cout << closet << '\n';
  old = closet.remove(Color::Blue);
  for(const auto& o:old)
    cout << o << '\n';
  cout << closet << '\n';
  old = closet.remove(Color::Gray);
  for(const auto& o:old)
    cout << o << '\n';
  cout << closet << '\n';
 

  return 0;
}


/** Erwartete Ausgabe
[0 Cent, blue pants]
[30000 Cent, gray pants]
Error3
[300000 Cent, blue pants]
[300001 Cent, blue pants]
[300001 Cent, blue pants]
34500
1 0
0 1
1 0
2300
[26550 Cent, gray skirt]
Error5
[0 Cent, blue pants]
[5, {[26550 Cent, gray skirt], [12700 Cent, red blouse], [2300 Cent, yellow shirt], [0 Cent, blue pants]}, 10387.5 Cent]
[5, {[26550 Cent, gray skirt], [12700 Cent, red blouse], [2300 Cent, yellow shirt], [0 Cent, blue pants]}, 10387.5 Cent]
Error6
Error7
[300, {[26550 Cent, gray skirt], [12700 Cent, red blouse], [2300 Cent, yellow shirt], [0 Cent, blue pants]}, 10387.5 Cent]
Error8
Error9
[5, {[26550 Cent, gray skirt], [4600 Cent, blue skirt], [12700 Cent, red blouse], [26550 Cent, gray skirt]}, 17600 Cent]
Error11
Error12
[10, {[26550 Cent, gray skirt], [12700 Cent, red blouse], [2300 Cent, yellow shirt], [0 Cent, blue pants], [26550 Cent, gray skirt]}, 13620 Cent]
[10, {[26550 Cent, gray skirt], [12700 Cent, red blouse], [2300 Cent, yellow shirt], [0 Cent, blue pants], [26550 Cent, gray skirt]}, 13620 Cent]
[10, {[34500 Cent, blue pants], [12700 Cent, red blouse], [2300 Cent, yellow shirt], [26600 Cent, gray skirt]}, 19025 Cent]
1110
[10, {[12700 Cent, red blouse], [26550 Cent, gray skirt], [0 Cent, blue pants], [23500 Cent, red shirt], [4600 Cent, blue skirt], [26550 Cent, gray skirt], [12700 Cent, red blouse], [2300 Cent, yellow shirt], [0 Cent, blue pants], [26550 Cent, gray skirt]}, 13545 Cent]
0
13545
[10, {[12700 Cent, red blouse], [26550 Cent, gray skirt], [0 Cent, blue pants], [23500 Cent, red shirt], [4600 Cent, blue skirt], [26550 Cent, gray skirt], [12700 Cent, red blouse], [2300 Cent, yellow shirt], [0 Cent, blue pants], [26550 Cent, gray skirt]}, 13545 Cent]
13545


Zusatz 10 Punkte
pants: 2
blouse: 2
shirt: 2
skirt: 4
pants: 1
blouse: 1
shirt: 1
skirt: 1


Zusatz 15 Punkte
[2300 Cent, yellow shirt]
[10, {[12700 Cent, red blouse], [26550 Cent, gray skirt], [0 Cent, blue pants], [23500 Cent, red shirt], [4600 Cent, blue skirt], [26550 Cent, gray skirt], [12700 Cent, red blouse], [0 Cent, blue pants], [26550 Cent, gray skirt]}, 14794.4 Cent]
[10, {[12700 Cent, red blouse], [26550 Cent, gray skirt], [0 Cent, blue pants], [23500 Cent, red shirt], [4600 Cent, blue skirt], [26550 Cent, gray skirt], [12700 Cent, red blouse], [0 Cent, blue pants], [26550 Cent, gray skirt]}, 14794.4 Cent]
[12700 Cent, red blouse]
[23500 Cent, red shirt]
[12700 Cent, red blouse]
[10, {[26550 Cent, gray skirt], [0 Cent, blue pants], [4600 Cent, blue skirt], [26550 Cent, gray skirt], [0 Cent, blue pants], [26550 Cent, gray skirt]}, 14041.7 Cent]
[10, {[26550 Cent, gray skirt], [0 Cent, blue pants], [4600 Cent, blue skirt], [26550 Cent, gray skirt], [0 Cent, blue pants], [26550 Cent, gray skirt]}, 14041.7 Cent]
[26550 Cent, gray skirt]
[26550 Cent, gray skirt]
[26550 Cent, gray skirt]
[10, {[0 Cent, blue pants], [4600 Cent, blue skirt], [0 Cent, blue pants]}, 1533.33 Cent]
**/
