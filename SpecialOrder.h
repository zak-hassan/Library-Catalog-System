#include "Order.h"
#include "iostream"
using namespace std;


class SpecialOrder : public Order{
	//datamembers
	char* special;
	//char* specialisbn;





	//methods
public:
	SpecialOrder();
	SpecialOrder(const ISBN& isbn, const char* instr);
	SpecialOrder(const SpecialOrder& source);
	bool add(istream& is);
	void display(ostream& os) const;
	SpecialOrder& operator=(const SpecialOrder& source);
	~SpecialOrder();

};