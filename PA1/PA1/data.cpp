#include "data.h"
Data::Data(int num1)
{
	num = num1;
}

Data::Data(Data &copyData)
{
	num = copyData.get_num();
}

Data::~Data()
{

}

int const Data::get_num()
{
	return this->num;
}