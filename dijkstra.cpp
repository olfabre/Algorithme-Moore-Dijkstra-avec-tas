#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <stack>

using namespace std;

#include "dijkstra.h"

/****************************************/
/* Objectif : Constructeur avec comme argument
le nom du fichier contenant le graphe.
Il doit :
-> ouvrir le fichier filename
-> initialiser, avec son contenu, les attributs "n", "m" et "L",
/****************************************/
graphe::graphe(char* filename)
{
    	ifstream file(filename);

	file >> n;
	file >> m;
	
	T = new int[n];
	I = new int[n];
	d = new int[n];
	pere = new int[n];

	int i,j,k,l;

	for(i = 0 ; i < n; i++){
		vector<sommetadjacent> vect;
		L.push_back(vect);
	}

	for(i = 0 ; i < m; i++){
		file >> j;
		file >> k;		
		file >> l;	
		L[j].push_back(make_pair(k,l));
		L[k].push_back(make_pair(j,l));
	}	
		
	file.close();

}


/****************************************/
/* Objectif : Affichage des arêtes et longueurs
/****************************************/
void graphe::donnees()
{
	cout << "arête : " << "longueur" << endl;
	for(int i = 0; i < L.size(); i++)
		for(int j = 0; j < L[i].size(); j++)
			if(i < L[i][j].first)
				cout << "(" << i << "," << L[i][j].first << ")" << ": " << L[i][j].second << endl;
}

/****************************************/
/* Objectif : Affichage des valeurs des plus courts
chemins trouvés avec l'algorithme de dijkstra avec tas
/****************************************/
void graphe::resultats(int s)
{
	cout << "La valeur du plus court chemin de " << s << " à : " << endl ;
	for(int i = 0; i < n; i++)
		cout << "-> " <<  i << " est égale à " << d[i] << endl;
}


/****************************************/
/* Objectif : Calcul de tous les plus courts de s aux 
autres sommets. A la fin de la méthode :
-> le tableau d doit contenir la valeur des plus courts chemins
/****************************************/
void graphe::dijkstra(int s)
{
    // !!! TODO !!! //
}
