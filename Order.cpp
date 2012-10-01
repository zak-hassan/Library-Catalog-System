#include "Order.h"



Order::Order(){
   ISBN isbn;
   obj_isbn=isbn;
   this->num_deliver=0;
   this->num_order=0;
   *s_str='\0';
   *n_str='\0';
 }

Order::Order(const ISBN& isbn){
	//ISBN *obj; 
	char placeholder[14]={'\0'};
	//obj_isbn.toStr(placeholder);
	//ISBNPrefix item("prefixRanges.txt");
	//this->pre= item;	
//	isbn.toStr(placeholder);
//	obj= new ISBN(placeholder,item);
//	this->obj_isbn = obj;

		//if(isValid(placeholder)){
	isbn.toStrWithStyle(placeholder);
		//}
		
		if(placeholder!=NULL){
			//this->obj_isbn=isbn;
		this->obj_isbn =isbn;
		strcpy(this->s_str, placeholder);
		this->num_order=0;
		this->num_deliver=0;
			}
		else {
			*this=Order();
		}
}


//need to do this
bool Order::has(const ISBN& isbn) const{
	if(obj_isbn==isbn)
		return true;
	else
		return false;
}
	

		
int Order::outstanding() const{
	int rtn=0;
	rtn= num_order-num_deliver;
	return rtn;
}

bool Order::add(istream& is){
	int num;
	bool rtn=false;
	char placeholder[11]={'\0'};
	cout << "Quantity (0 to quit) :";
	is >> num;
		obj_isbn.toStr(placeholder);
	
	if(placeholder[0] != '\0' && num > 0){
			this->num_order+=num;
			rtn = true;
			}
	return rtn;
}


bool Order::add(int n){
	char placeholder[11]={'\0'};
	obj_isbn.toStr(placeholder);
	strcpy(this->s_str,placeholder);
	if(this->s_str[0]!='\0' && n > 0){
	this->num_order+=n;
	return true;
	}
	else
		return false;
}


bool Order::receive(istream& is){
	int flag=false, n_rec=0;
	cout << endl;
		cout <<"Quantity (0 quit):" <<endl;
		is >>n_rec;
	while(n_rec < 0){
		cout << "Enter a positive number.  Try again."<<endl;
		cout <<"Quantity (0 quit):" <<endl;
		is >>n_rec;
	}
	while(outstanding()<n_rec && n_rec !=0){
		cout << n_rec << " not in order. Only  " << outstanding() << " are on order. Try again." << endl;
		cout <<"Quantity (0 quit):" <<endl;
		is >> n_rec;
	}
	if(n_rec==0){
		cout << "** No delivery recorded!" << endl;
		flag=false;
	} else {
		this->num_deliver += n_rec;
		flag=true;
	}
	is.ignore(2000,'\n');
if(flag){
	return true;	
}else
	return false;
}

void Order::display(ostream& os) const{

	
	//if(isValid(strings)){
		//obj_isbn.reg=true;
	//	this->obj_isbn.toStrWithStyle(strings);
	//}
	//	strcpy(this->s_str,strings);
	//os << setw(13)<< right << strings ;
	os <<  setw(13) <<right << this->s_str ;
	os << setw(9) << num_order;
	os << setw(11) << num_deliver; 
}


ostream& operator<<(ostream& os, const Order& order){
	order.display(os); 
	return os;
}
