#include<iostream>
#include<string>
#include<vector>
#include "File2.h"
#include <tchar.h>
using namespace std;


   voiture::voiture(string ma, string mo, int a, float k) {
		marque = ma;
		model = mo;
		anne = a;
		kilomter = k;
	}

	void voiture::setMarque(const string &ma) {
		marque = ma;
	}

	void voiture::setmodel(const string &mo) {
		model = mo;
	}

	void voiture::setanne(const int &a) {
		anne = a;
	}

	void voiture::setkilomter(const float &k) {
		kilomter = k;
	}

	string voiture::getMarque() const {
		return marque;
	}

	string voiture::getmodel() const {
		return model;
	}

	int voiture::getanne() const {
		return anne;
	}

	float voiture::getkilomter() const {
		return kilomter;
	}

	void voiture::afficher() const {
		cout << "marque: " << marque << endl;
		cout << "model: " << model << endl;
		cout << "anne: " << anne << endl;
		cout << "kilomter: " << kilomter << " k" << endl;
	}


int _tmain(int argc, _TCHAR* argv[]) {


	vector<voiture> voitures;

	int ch;
	do {
		cout << "\n Gestion des voitures \n";
		cout << "1.Ajout voiture\n";
		cout << "2.Afficher voitures\n";
		cout << "3.Afficher les voiture avec kilomter > valeur anne\n";
		cout << "4.Rechercher un voiture par marque\n";
		cout << "0.Quiter\n";
		cout << "ch : ";
		cin >> ch;

		switch (ch) {
		case 1: {
				int n;
				cout << "Combieb ajoute voiture ? ";
				cin >> n;

				for (int i = 0; i < n; i++) {
					string marque, model;
					int anne;
					float kilomter;

					cout << "\nVoiture " << i + 1 << " :\n";
					cout << "Marque : ";
					cin >> marque;
					cout << "Modèle : ";
					cin >> model;
					cout << "Année : ";
					cin >> anne;
					cout << "Kilométrage : ";
					cin >> kilomter;

					voitures.push_back(voiture(marque, model, anne, kilomter));
				}
				break;
			}

		case 2: {
				if (voitures.empty())
					cout << "Aucune voiture enregistrée.\n";
				else {
					cout << "\nListe des voitures :\n";
					for (const auto &v : voitures)
						v.afficher();
				}
				break;
			}

		case 3: {
				float limite;
				cout << "Afficher les voitures avec kilometrage > ";
				cin >> limite;

				bool trouve = false;
				for (auto&v : voitures) {
					if (v.getkilomter() > limite) {
						v.afficher();
						trouve = true;
					}
				}
				if (!trouve)
					cout << "Aucune voiture ne dépasse " << limite << " km.\n";
				break;
			}

		case 4: {
				string rech;
				cout << "Entrez la marque à rechercher : ";
				cin >> rech;

				bool trouve = false;
				for (auto&v : voitures) {
					if (v.getMarque() == rech) {
						v.afficher();
						trouve = true;
					}
				}
				if (!trouve)
					cout << "Aucune voiture trouvée avec la marque " <<
						rech << ".\n";
				break;
			}

		case 0:
			cout << " Fin du programme..\n";
			break;

		default:
			cout << "Ch invalid.\n";
			break;
		}

	}
	while (ch != 0);

	return 0;
}
