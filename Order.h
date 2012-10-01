#pragma once
#include "cstdlib"
#include "cstdio"
#include "iostream"
#include <cstring>
#include <iomanip>
#include "ISBN.h"
using namespace std;


class Order{
protected:        //this is protected instead of private in order make this accessable to inheritance::
  char s_str[14];
  char n_str[14];
  int num_order;
  int num_deliver;

public:
 // ISBNPrefix pre;
  ISBN obj_isbn;
  Order();
  Order(const ISBN& isbn);
  bool has(const ISBN& isbn) const;
  int outstanding() const;
 virtual bool add(istream& is);
  bool add(int n);
  bool receive(istream& is);
 virtual void display(ostream& os) const;
  friend ostream& operator<<(ostream& os, const Order& order);
 };





