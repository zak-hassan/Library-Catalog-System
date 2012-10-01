#include "ISBN.h"
#include "ISBNPrefix.h"


//this is new

//	ISBNPrefix::ISBNPrefix(){

//	}

	ISBNPrefix::ISBNPrefix(const ISBNPrefix& source){
	*this = source;	
	}


 	//ISBNPrefix& ISBNPrefix::operator=(const ISBNPrefix& source){
	  
  //if(this != &source){
 //   fp=source.fp;
 // }
 //	  return *this;	      
//	}





//end of new



ISBNPrefix::ISBNPrefix(const char* filename) {

	if(filename!=NULL){
		this->fp = fopen(filename,"r");
	}
	else{
		this->fp = NULL;
	}

}


bool ISBNPrefix::isRegistered(int area) const{
	int count=0;
	char ir2_area_id[6]={'\0'};
	bool value_return=false;
    if(fp!=NULL){
	rewind(this->fp);
        while(fscanf(this->fp,"%s %*s %*s",ir2_area_id) != EOF && value_return !=true){
            count++;
            if(atoi(ir2_area_id)==area)
                value_return = true;
        }
    }
	return value_return;
}


int ISBNPrefix::minNoDigits(int area) const{
	int i=0,len_pub=0;	
	char m_area_id[6]={'\0'};
	char m_pub_min[8]={'\0'};


	rewind(this->fp);
	while(fscanf(this->fp,"%s %s %*s",m_area_id,m_pub_min)!=EOF)
	{

		if (atoi(m_area_id)== area)
		{
			i++;
			if (i<=1) 
				len_pub = int(strlen(m_pub_min));
			else{
				if(len_pub > int(strlen(m_pub_min)))
					len_pub = int(strlen(m_pub_min));
			}
		}

	}
	return len_pub;

}


bool ISBNPrefix::isRegistered(int area, const char* publisher) const{

	int count=0;
	bool check_pub=false;
	char ir3_area_id[6]={'\0'};
	char ir3_pub_max[8]={'\0'};
	char ir3_pub_min[8]={'\0'};	

	rewind(this->fp);		
	while(fscanf(this->fp,"%s %s %s",ir3_area_id,ir3_pub_min,ir3_pub_max) != EOF)
	{
		count++;
		if(area == atoi(ir3_area_id))
		{
			if(atoi(publisher) <= atoi(ir3_pub_max) && atoi(publisher) >= atoi(ir3_pub_min)&& strlen(ir3_pub_min)== strlen(publisher))
			{
				check_pub = true;
				count++;
			}
		}
	}
	return check_pub;

}


ISBNPrefix::~ISBNPrefix(){
	if(this->fp)
		fclose(this->fp);
}


