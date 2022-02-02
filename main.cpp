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
    date nascita;
};



int main() {
    cout << "- Studenti -" << endl;
    char filename[]="C:\\Users\\Thinkpad User\\CLionProjects\\studenti_f\\studenti.txt";

    fstream input;
    input.open(filename,ios::in);
    if(!input.is_open()){
        cout<<"Errore apertura file"<<endl;
    }

    studente s[49];

    int i=0;
    while(i<3){

        input>>s[i].mat;
        cout<<"mat: "<<s[i].mat<<endl;

        input.ignore(1);
        input.getline(s[i].nome,sizeof s->nome);
        cout<<"nome: "<<s[i].nome<<endl;

        input.ignore(1);
        input.getline(s[i].cognome, 21);
        cout<<"cognome: "<<s[i].cognome<<endl;

        input.ignore(1);
        input>>s[i].nascita.g;
        cout<<"nascita: "<<s[i].nascita.g<<"\t";

        input.ignore(1);
        input<<s[i].nascita.m;
        cout<<s[i].nascita.m<<"\t";

        input.ignore(1);
        input>>s[i].nascita.a;
        cout<<s[i].nascita.a<<"\t"<<endl;

        cout<<endl;


        //input>>s[i].nome>>s[i].cognome>>s[i].nascita.g>>s[i].nascita.m>>s[i].nascita.a;
        //cout<<s[i].mat<<" "<<s[i].nome<<" "<<s[i].cognome<<" "<<s[i].nascita.g<<" / "<<s[i].nascita.m<<" / "<<s[i].nascita.a<<endl;
        i++;
    }

    return 0;
}
