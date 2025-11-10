#ifndef File2h
#define File2h
#include <string>
using namespace std;
class voiture{
private:
	string marque;
	string model;
	int anne;
	float kilomter;

public:
	voiture(string ma, string mo, int a, float k) ;

	void setMarque(const string &ma) ;

	void setmodel(const string &mo);

	void setanne(const int &a) ;

	void setkilomter(const float &k);

	string getMarque() const ;

	string getmodel() const ;

	int getanne() const ;

	float getkilomter() const ;

	void afficher() const ;

};
#endif