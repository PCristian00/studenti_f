#include <iostream>
#include <fstream>

using namespace std;

struct date{
    int g;
    int m;
    int a;
};

struct studente{
    char mat[5];
    char nome[21];
    char cognome[21];
    date dob;
};


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
}

void stampaStud(studente s){
    cout<<s.mat<<' '<<s.nome<<' '<<s.cognome;
    cout<<s.dob.g<<"/"<<s.dob.m<<"/"<<s.dob.a<<endl;
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

    young.dob.g=32;
    young.dob.m=13;
    young.dob.a=3000;

    old.dob.g=-10;
    old.dob.m=-10;
    old.dob.a=-10;


    int i=0;
    while(i<3){

        input>>s[i].mat;
        cout<<"mat: "<<s[i].mat<<endl;

        input.ignore(1);
        input.getline(s[i].nome,sizeof s->nome);
        cout<<"nome: "<<s[i].nome<<endl;

        input.ignore(1);
        input.getline(s[i].cognome,sizeof s->cognome);
        cout<<"cognome: "<<s[i].cognome<<endl;

        input.ignore(1);
        input>>s[i].dob.g;
        cout << "dob: " << s[i].dob.g << "\t";


        if(s[i].dob.g > young.dob.g) young.dob.g=s[i].dob.g;

        input.ignore(1);
        input<<s[i].dob.m;
        cout << s[i].dob.m << "\t";

        if(s[i].dob.m < old.dob.m)
        if(s[i].dob.m > young.dob.m) young.dob.m=s[i].dob.m;



        input.ignore(1);
        input>>s[i].dob.a;
        cout << s[i].dob.a << "\t" << endl;


        if(confrontaData(s[i].dob,old.dob))
            old=s[i];



        if(confrontaData(young.dob,s[i].dob))
            young=s[i];



        stampaStud(s[i]);

        cout<<endl;


        //input>>s[i].nome>>s[i].cognome>>s[i].dob.g>>s[i].dob.m>>s[i].dob.a;
        //cout<<s[i].mat<<" "<<s[i].nome<<" "<<s[i].cognome<<" "<<s[i].dob.g<<" / "<<s[i].dob.m<<" / "<<s[i].dob.a<<endl;
        i++;
    }

    cout<<"Il piu vecchio"<<endl;
    stampaStud(old);
    cout<<"Il piu giovane"<<endl;
    stampaStud(young);

    return 0;
}
