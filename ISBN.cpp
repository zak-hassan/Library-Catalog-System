#include "ISBN.h"
#include "ISBNPrefix.h"



  bool operator==(const ISBN& left, const ISBN& right){
	if(strcmp(left.s_string,right.s_string)==0){
		return true;
		}
		else
		return false;
		}

	ostream& operator<<(ostream& os, const ISBN& isbn){
		isbn.display(os);
	return os;
	}


	extern int isValid(const char* str){
		int i=0, a=10, num=0, pass=0,check=0;


	if(str!=NULL && strlen(str)==10){
		a=10;
		for(i=0;i<10;i++)
		{
			if (str[i] != 'X'){
				num += ((str[i] - '0')*a);
				a--; 
			} else {	
				num += 10;
				check=1;
			}
		}
	}	  
	if(num % 11 == 0 && a<=1)
		pass = 1;
	else
		pass=0;
	return pass;

}
/*
ISBN::ISBN(const ISBN& isbn){
		*this = isbn;	
} */

/*
ISBN& ISBN::operator=(const ISBN& isbn){
 
	if(this != &isbn){
		this->reg= isbn.reg;
		strcpy(this->s_string,isbn.s_string);
		strcpy(this->s_style,isbn.s_style);
		strcpy(this->p_area,isbn.p_area);
		strcpy(this->p_pub,isbn.p_pub);
		strcpy(this->p_title,isbn.p_title);
		this->check_digit=isbn.check_digit;
		this->emp= isbn.emp;
	}

	  return *this;	      

}

	*/

ISBN::ISBN(void){
	int i=0;
	for(i=0;i<14;i++)
	this->s_style[i]='\0';
	for(i=0;i<11;i++)
	this->s_string[i]='\0';
	for(i=0;i<6;i++)
	this->p_area[i]='\0';
	for(i=0;i<8;i++)
	this->p_pub[i]='\0';
	for(i=0;i<7;i++)
	this->p_title[i]='\0';
	this->emp=true;
	this->reg=false;
	this->check_digit='\0';
}

ISBN::ISBN(const char* str, const ISBNPrefix& list)
{
	int err_catch=0,i=0,j=0,flag=0,stage=0,len=0;
	bool reg=false;


	*this = ISBN();

	if(isValid(str))
	{	
		strcpy(this->s_string,str);

		for(i=0;i<6 ;i++){
			this->p_area[i]=this->s_string[i];
			this->p_area[i+1]='\0';
			j++;
			if(list.isRegistered(atoi(this->p_area))){
				stage++;
				break;
			}
		}

		if(stage){
			for(i=0;i<7;i++)
			{
				this->p_pub[i]=this->s_string[j];
				this->p_pub[i+1]='\0';
				j++;
				if(list.isRegistered(atoi(this->p_area),this->p_pub)){
					flag++;
					break;
				}
			}
		}

		if(flag==1){
			len= (int)strlen(this->p_area) + (int)strlen(this->p_pub);
			j=len;
			for(i=0;i<7;i++){
				this->p_title[i]=this->s_string[j];
				this->p_title[i+1]='\0';
				j++;

				if(j==9){
					this->check_digit=*(str+ 9);
					break;
				}
			}
			flag++;
		}

		if(flag==2){
			reg=this->isRegistered(list);
			if(reg)
				this->emp=false;
		} 
		if(stage==0 && flag!=2)
			err_catch++;


	} 
	else
		err_catch++;




	//if(err_catch)
		//*this=ISBN();

}

bool ISBN::isRegistered() const{
	return this->reg;		

}






bool ISBN::isRegistered(const ISBNPrefix& list){
	/*int err_catch=0,i=0,j=0,flag=0,stage=0,len=0;
	bool reg=false;
	char *str={'\0'};
	str=this->s_string;

		for(i=0;i<6 ;i++){
			this->p_area[i]=this->s_string[i];
			this->p_area[i+1]='\0';
			j++;
			if(list.isRegistered(atoi(this->p_area))){
				stage++;
				break;
			}
		}

		if(stage){
			for(i=0;i<7;i++)
			{
				this->p_pub[i]=this->s_string[j];
				this->p_pub[i+1]='\0';
				j++;
				if(list.isRegistered(atoi(this->p_area),this->p_pub)){
					flag++;
					break;
				}
			}
		}

		if(flag=1){
			len=strlen(this->p_area) + strlen(this->p_pub);
			j=len;
			for(i=0;i<7;i++){
				this->p_title[i]=this->s_string[j];
				this->p_title[i+1]='\0';
				j++;

				if(j==9){
					this->check_digit=this->s_string[9];
					break;
				}
			}
			flag++;
		}*/
	if(list.isRegistered(atoi(this->p_area)) && list.isRegistered(atoi(this->p_area), this->p_pub) && isValid(this->s_string))
		this->reg=true;
	return this->reg;

}

bool ISBN::empty() const{
	if(this->p_area[0]=='\0'|| this->p_pub[0]=='\0' ||this->p_title=='\0')
		return true;
	else
		return false;

}

void ISBN::toStr(char* str) const{
	

	strcpy(str,this->s_string);
}

void ISBN::toStrWithStyle(char* str) const{


	char delimeter[2]={'-','\0'};		
	char end[3]={'-',this->check_digit,'\0'};
	if(this->reg){

		strcpy(str, this->p_area);		
		strcat(str, delimeter);			
		strcat(str,this->p_pub);			 
		strcat(str, delimeter);			
		strcat(str, this->p_title);				
		strcat(str, end);			


	}
	else{
		strcpy(str,this->s_string);
	}


}

void ISBN::display(ostream& os) const{
	char string[13];
	strcpy(string,this->s_string);

os << right << setw(13) <<string << endl;
os << setw(9) <<string << endl;
os << setw(11) <<string << endl;

//	if(this->reg){
//		this->toStrWithStyle(string);
		os << setw(13) <<string << endl;
//	}else
		os << setw(13) << string << endl;











}




bool ISBN::read(istream& is, const ISBNPrefix& list){
	int v=0, pass=0;
	bool red=false;
	char isbn[11]="";
	
	do{
		v=0;
		cout << "ISBN(0 to quit): ";
		//is.getline(isbn,10)>> isbn;
		is.getline(isbn,11);
		if(strlen(isbn)==10)
			pass=1;
		//is >> isbn;
		if(is.fail()){				 
			cerr << "Invalid input. Try again." << endl;	 
			is.clear();
			is.ignore(2000, '\n');
			v++;	
		}

		if(strlen(isbn)!=10)
		{
			is.clear();
			is.ignore(2000, '\n');
			cerr << "Incorrect number of digits. Try again." << endl;
			v++;
		} 
		if(isValid(isbn)==false){
			is.clear();
			pass=0;
			//is.ignore(2000, '\n');
			cerr << "Invalid check digit. Try again." << endl;	
			v++;
		}


	}while(atoi(isbn)!=0&& pass!=1);



	if(v==0 && pass==1){
		*this=ISBN(isbn,list);
		//this->isRegistered(list);
		//strcpy(this->s_string,isbn);
		red=true;
	}

	return red;

}

ISBN::~ISBN(void)
{

}


