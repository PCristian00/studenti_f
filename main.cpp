#include <iostream>
#include <fstream>

using namespace std;

struct date{
    int g;
    int m;
    int a;
};

struct studente{
    char mat[6];
    char nome[21];
    char cognome[21];
    date dob;
};

//TODO rivedere
//Restituisce true se a e' piu' vecchio di b
bool confrontaData(date a,date b){


    if(a.a < b.a){
        a.a=b.a;
        a.m=b.m;
        a.g=b.g;
        return true;
    }
    else if(a.a==b.a){

        if(a.m<b.m){
            a.m=b.m;
            a.g=b.g;
            return true;
        }else if(a.m==b.m){
            if(a.g<b.g){
                a.g=b.g;
                return true;
            }
        }
    }
    return false;
}

void stampaStud(studente s){
    cout<<"M: "<<s.mat<<endl<<"Nome: "<<s.nome<<" Cognome: "<<s.cognome<<endl;
    cout<<"Data di nascita: "<<s.dob.g<<"/"<<s.dob.m<<"/"<<s.dob.a<<endl;
}


int main() {
    cout << "- Studenti -" << endl;

    char filename[]="C:\\Users\\Thinkpad User\\CLionProjects\\studenti_f\\studenti.txt";
    fstream input;

    input.open(filename,ios::in);
    if(!input.is_open()){
        cout<<"Errore apertura file"<<endl;
    }

    studente s[49];

    studente young,old;

    //TODO rivedere, sembra andare
    old.dob.g=32;
    old.dob.m=13;
    old.dob.a=3000;
    young.dob.g=-10;
    young.dob.m=-10;
    young.dob.a=-10;


    int i=0;
    //TODO mettere i<49
    while(i<49){

        input>>s[i].mat;

        input>>s[i].nome;

        input>>s[i].cognome;

        input>>s[i].dob.g;

        input.ignore(1);
        input>>s[i].dob.m;

        input.ignore(1);
        input>>s[i].dob.a;


        if(confrontaData(s[i].dob,old.dob))
            old=s[i];



        if(!confrontaData(s[i].dob,young.dob))
            young=s[i];

        //stampaStud(s[i]);

        cout<<endl;
        i++;
    }

    cout<<"Il piu vecchio"<<endl;
    stampaStud(old);
    cout<<endl;
    cout<<"Il piu giovane"<<endl;
    stampaStud(young);



    return 0;
}
