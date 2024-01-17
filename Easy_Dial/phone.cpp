#include "phone.hpp"

//Cost: O(1), on L és la longitud de la cadena name.
phone::phone(nat num, const string& name, nat compt) throw(error){
  size_t trobat = name.find_first_of("<|\0");
  if(trobat != string::npos) throw error(ErrNomIncorrecte);
  _tel = num;
  _freq = compt;
  _name = name;
}

//Cost: O(1). La còpia de membres simples té un cost constant.
phone::phone(const phone& t) throw(error){
  _tel = t._tel;
  _freq = t._freq;
  _name = t._name;
}

//Cost: O(1). Similar a la funció de còpia, l'assignació té un cost constant.
phone& phone::operator=(const phone& t) throw(error){
  _tel = t._tel;
  _freq = t._freq;
  _name = t._name;
  return *this;
}

phone::~phone() throw(){}

//Cost: O(1). La funció simplement retorna el valor de _tel, el que es fa en temps constant.
nat phone::numero() const throw(){
  return _tel;
}

//Cost: O(1). La funció retorna _name, que és una operació de còpia de cadena amb un cost constant.
string phone::nom() const throw(){
  return _name;
}

//Cost: O(1). La funció retorna _freq, que és un membre simple i s'hi accedeix en temps constant.
nat phone::frequencia() const throw(){
  return _freq;
}

//Cost: O(1). La funció incrementa _freq en 1 i retorna una referència a l'objecte.
phone& phone::operator++() throw(){
  ++_freq;
  return *this;
}

//Cost: O(1). Similar a l'operador de preincrement, incrementa _freq en 1 i retorna una còpia de l'objecte abans de l'increment.
phone phone::operator++(int) throw(){
  phone phone1(*this);
  ++_freq;
  return phone1;
}

//Cost: O(1). Compara _freq i _name en temps constant.
bool phone::operator==(const phone& t) const throw(){
  if(_freq == t._freq and _name == t._name) return true; //quizas puede ser sin el name i solo el freq
  else return false;
}

//Cost: O(1). Utilitza l'operador d'igualtat, que té un cost constant.
bool phone::operator!=(const phone& t) const throw(){
  return not(*this == t);
}

//Cost: O(1), on L és la longitud de la cadena _name.
bool phone::operator<(const phone& t) const throw(){
  if(_freq<t._freq) return true;
  else if(_freq>t._freq) return false;
  else{
    if(_name<t._name) return true;
    else return false;
  }
}

//Cost: O(1), similar a l'operador <.
bool phone::operator>(const phone& t) const throw(){
  if(_freq>t._freq) return true;
  else if(_freq<t._freq) return false;
  else{
    if(_name>t._name) return true;
    else return false;
  }
}

//Cost: O(1), similar als operadors < i >,
bool phone::operator<=(const phone& t) const throw(){

  if(_freq<t._freq)return true;
  else if(_freq>t._freq) return false;
  else{
    if(_name<=t._name) return true;
    else return false;
  }
}
//Cost: O(1), similar als operadors <, >, i <=.
bool phone::operator>=(const phone& t) const throw(){
  if(_freq>t._freq)return true;
  else if(_freq<t._freq) return false;
  else{
    if(_name>=t._name) return true;
    else return false;
  }
}


