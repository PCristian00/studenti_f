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
    cout<<"M: "<<s.mat<<endl<<" Nome: "<<s.nome<<" Cognome: "<<s.cognome<<endl;
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
    young.dob.g=32;
    young.dob.m=13;
    young.dob.a=3000;
    old.dob.g=-10;
    old.dob.m=-10;
    old.dob.a=-10;


    int i=0;
    //TODO mettere i<49
    while(i<1){



        input>>s[i].mat;
        //cout<<"mat: "<<s[i].mat<<endl;

        input>>s[i].nome;

        //input.ignore(1);
        //input.get(s[i].nome,10);
        //cout<<"nome: "<<s[i].nome<<endl;

        //input.ignore(1);
        input>>s[i].cognome;
        //cout<<"cognome: "<<s[i].cognome<<endl;

        //input.ignore(1);
        input>>s[i].dob.g;
        //cout << "dob: " << s[i].dob.g << "\t";

        input.ignore(1);
        input>>s[i].dob.m;
        //cout << s[i].dob.m << "\t";

        input.ignore(1);
        input>>s[i].dob.a;
        //cout << s[i].dob.a << "\t" << endl;


        if(confrontaData(s[i].dob,old.dob))
            old=s[i];



        if(!confrontaData(s[i].dob,young.dob))
            young=s[i];



        stampaStud(s[i]);

        cout<<endl;


        //input>>s[i].nome>>s[i].cognome>>s[i].dob.g>>s[i].dob.m>>s[i].dob.a;
        //cout<<s[i].mat<<" "<<s[i].nome<<" "<<s[i].cognome<<" "<<s[i].dob.g<<" / "<<s[i].dob.m<<" / "<<s[i].dob.a<<endl;
        i++;
    }

    cout<<"Il piu vecchio"<<endl;
    stampaStud(old);
    cout<<endl;
    cout<<"Il piu giovane"<<endl;
    stampaStud(young);

    return 0;
}
