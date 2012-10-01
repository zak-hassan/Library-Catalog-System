#include "SpecialOrder.h"
#include <iostream>
#include <fstream>
using namespace std;




SpecialOrder::SpecialOrder(): Order(){
	special=NULL;
}

SpecialOrder::SpecialOrder(const ISBN& isbn, const char* instr): Order(isbn){
    if(instr!=NULL){
		this->special=NULL;
		this->special= new char[strlen(instr)+1];
     	strcpy(this->special,instr);
	}else
		*this=SpecialOrder();
}

SpecialOrder::SpecialOrder(const SpecialOrder& source) : Order(source){
    special=NULL;
    *this=source;
}


void SpecialOrder::display(ostream& os) const{
	Order::display(os);
	os << "  " << this->special << endl;
}


bool SpecialOrder::add(istream& is){
	bool rtn=false;
	char *instr=NULL;
	instr=new char[100];
			rtn=Order::add(is);
            cout << "Instructions: ";
       
        is.ignore(2000,'\n');
        is.getline(instr,100);
        if(is.fail()){				 
            cerr << "Invalid input. Try again." << endl;	 
            is.clear();
            is.ignore(2000, '\n');
            }

			if(instr!=NULL){
				strcpy(this->special,instr);
                rtn=true;
			}
return rtn;
}

SpecialOrder& SpecialOrder::operator=(const SpecialOrder& source){
	if(this != &source){
		  delete [] this->special;
		if(source.special!=NULL){
		Order::operator=(source);
		this->num_order=source.num_order;
		this->num_deliver=source.num_deliver;
		strcpy(this->s_str,source.s_str);
		this->special= new char[strlen(source.special)+1];
		strcpy(this->special,source.special);
		}
			else
			this->special=NULL;
	}
	return *this;
}



SpecialOrder::~SpecialOrder(){
	if(this->special)
	delete [] this->special;
	this->special=NULL;
}