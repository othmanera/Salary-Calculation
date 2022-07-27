#include <iostream>
#include <string>
using namespace std;

int SMIC = 2500;

//classe Employé
class employe{
    protected:
    int mat;
    string nom,prenom;
    int date;

public:
//constructeur
employe(int m=0, string n="" , string p="" , int d=0){
    mat = m;
    nom = n;
    prenom = p;
    date = d;
    }
//affichage
virtual void afficher(){
    cout <<"Matricute de l'employe:"<< mat <<endl;
    cout <<"Nom de l'employe:"<< nom <<endl;
    cout <<"Prenom de l'employe:"<< prenom <<endl;
    cout <<"Date de l'employe:"<< date <<endl;
}
//Calculer salaire
virtual float calculerSalaire()=0;

}; //Fin classe employé


// classe ouvrier
class ouvrier : public employe{
    int dateE,smic;
    
public:

//constructeur 
ouvrier(int m=0, string n="" , string p="" , int d=0 , int de=0) : employe(m,n,p,d){
    dateE = de;
    smic = SMIC;
}

//Calculer Salaire
float calculerSalaire(){
    float salaire = float ( smic+(2022-dateE)*100 );
        if (salaire>SMIC*2){
            cout <<"Salaire dépassant 5000DHS"<<endl;
            return 5000;
        }
            
        else
            return salaire;

}

//Affichage
void afficher(){
    employe :: afficher();
    cout <<"Date d'entree de l'ouvrier:"<< dateE <<endl;
    
}
}; //Fin de la classe ouvrier

//classe cadre
class cadre : public employe {
    int indice;
public:
//constructeur 
cadre(int m=0, string n="" , string p="" , int d=0,int in=0) : employe(m,n,p,d){
    indice = in;
}

//calculer salaire
float calculerSalaire(){
    
    if (indice == 1)
        return 13000;
    else if (indice == 2)
        return 15000;
    else if (indice == 3)
        return 17000;
    else if (indice == 4)
        return 20000;
}

//affichage
void afficher(){
    employe :: afficher();
    cout <<"Indice du cadre:"<< indice <<endl; 
}
}; //Fin de la classe cadre 

// classe patron
class patron : public employe{
    int CA;
    float percent;

public:
//constructeur 
patron(int m=0, string n="" , string p="" , int d=0 ,int ca=0 , float per=0) :  employe(m,n,p,d){
    CA = ca;
    percent = per;

}

//calculer salaire
float calculerSalaire(){
    float salaire = CA*percent/100;
    return salaire;
}
//affichage
void afficher(){
    employe :: afficher();
    cout <<"Chiffre d'affaires du patron:"<< CA <<endl;
    cout <<"Pourcentage du patron:"<< percent <<endl;    
}

};

main(){
   
    ouvrier O;
    employe *E =&O;
    E->afficher();


}