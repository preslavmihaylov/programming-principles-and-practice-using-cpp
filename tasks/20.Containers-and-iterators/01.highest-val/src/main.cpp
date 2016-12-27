#include <iostream>
#include <vector>

using namespace std;

double * getJackData(int * jackCnt)
{
	double * jackData = new double[10];
	jackData[0] = 20.5;
	jackData[1] = 30.1;
	jackData[2] = 1;
	jackData[3] = 14.4;
	jackData[4] = 21.1;
	jackData[5] = 7.5;
	jackData[6] = 5.3;
	jackData[7] = 3.3;
	jackData[8] = 35;
	jackData[9] = 2;
	*jackCnt = 10;

	return jackData;
}

vector<double>* getJillData()
{
	vector<double> * v = new vector<double>();
	v->push_back(10);
	v->push_back(12);
	v->push_back(1);
	v->push_back(5);
	v->push_back(30.4);
	v->push_back(32.1);
	v->push_back(21.1);
	v->push_back(7.7);
	v->push_back(14);
	v->push_back(2);

	return v;
}

double* highest(double * start, double * end)
{
	if (start == end) return end;
	
	double * highest = start;
	while (start != end)
	{
		if (*highest < *start) highest = start;
		++start;
	}

	return highest;
}

int main()
{
	int jackCnt;
	double * jackData = getJackData(&jackCnt);
	vector<double> * jillData = getJillData();

	double * jackHighest = highest(jackData, jackData+jackCnt);
	double * jillHighest = highest(&(*jillData)[0], 
								   ((&(*jillData)[0])+jillData->size()));

	cout << "Jack highest: " << *jackHighest << endl;
	cout << "Jill highest: " << *jillHighest << endl;

	return 0;
}
