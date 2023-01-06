#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <conio.h>
using namespace std;


class privilege
{
    int id ;
    string description;
    double price;
  
    public:
    privilege(int id = 0,string desc="",double pric=0)
    {
        this->id = id ;
        description = desc;
        price = pric;
    }
    string getdescription()
    {
        return description;
    }
    void setdescription(string a)
    {
        description = a;
    }
    double getprice()
    {
        return price;

    }
    void setprice(double a)
    {
        price = a;
    }
    void savepriv()
    {
        ofstream fout;
        fout.open("privileges.txt",ios::app);
        fout<<endl<<id<<","<<description<<","<<price;

    }
    friend ostream& operator<<(ostream&,const privilege&);
    friend istream& operator>>(istream&,privilege&);
    friend class camping;
    friend class MaBaseDeDonnee;
    friend class campings;

};
double money ;
istream& operator>>(istream& a,privilege& b)
{
cout<<"donner l'id:"<<endl;
a>>b.id;
cout<<"donner la description"<<endl;
a>>b.description;
cout<<"donner le prix:"<<endl;
a>>b.price;
return a ;
}
int pin=678452056;

void signup()
{
    cout<<"entrer 1 pour s'enregistrer comme un client:"<<endl;
    cout<<"entrer 2 pour s'enregistrer comme un guide:"<<endl;

}

ostream& operator<<(ostream& a,const privilege& b)
{
 a<<b.id<<','<<b.description<<","<<b.price;
 return a;
}
class person
{
protected:
    bool logedin ;
    string courier;
    string nom;
    string prenom;
    string Cin;
    string pass;
    int tel;
    string etat_civil;
    string mailadress;
    int datenaissance[3] ;
    double solde;
public:

    person(string cour="",string a="",string b="", string c="",string d="",int e=0,string f="",int g=0,int h=0,int i=0,double x=0 ,string a1="")
    {
        logedin =true;
    courier=cour;
    etat_civil = a1;
    nom=a;
    prenom=b;
    Cin=c;
    pass=d;
    tel=e;
    mailadress=f;
    datenaissance[0]=g;
    datenaissance[1]=h;
    datenaissance[2] =i;
    solde = x;

    }
    virtual void identify()
    {
    cout<<"i'm a parent";
    }
    void setpass(string a)
    {
        pass =a ;
    }
    void setnum (int a)
    {
        tel =a ;
    }
    double getsolde()
    {
        return solde;
    }
    string get_cin (){return Cin ; }
    void setid(string a)
    {
        Cin=a;
    }
    void retrait(float b){if(solde>= b) solde -= b ;}
    void message()
    {
        cout<<"vos messages:"<<endl;
        cout<<courier<<endl;
    }
    void transfere (float b, person& per)
    {
        if (solde >= b ) { per.solde+= b ; solde -=b ;}
        else cout<< "transfere impossible " <<endl ;
    }
    void logout()
{
     logedin = false;
}

    void campingactions()
    {
    cout<<"entrer 1 pour consulter nos campings:"<<endl;
    cout<<"entrer 2 pour faire une reservation:"<<endl;
    }
    friend ostream& operator<<(ostream&a,const person& b) ;
    friend istream& operator>> (istream & , person &  ) ;
    friend class MaBaseDeDonnee;
    ~person () {}


};

 ostream& operator<<(ostream&a,const person& b)
{
  a<<"nom:"<<b.nom<<endl<<"prenom:"<<b.prenom<<endl<<"cin:"<<b.Cin<<endl<<"numtel:"<<b.tel<<endl<<"etat civile:"<<b.etat_civil<<endl<<"adressmail:"<<b.mailadress<<endl<<"date naissance:"<<b.datenaissance[0]<<"/"<<b.datenaissance[1]<<"/"<<b.datenaissance[2]<<endl<<"solde:"<<b.solde<<endl;
 return a;
}
istream& operator>> (istream &in ,person &per  )
{
    cout<< "donner le nom:" ;
    in>> per.nom ;
    cout<< "donner le prenom:" ;
    in>> per.prenom ;
    cout<< "donner le mots de passe:" ;
    in>> per.pass ;
    cout<< "donner le num tel:" ;
    in>> per.tel ;
    cout<< "donner votre etat civile:" ;
    in>> per.etat_civil  ;
    cout<< "donner votre adresse mail:" ;
    in>> per.mailadress ;
    cout<< "donner votre date de naissance:" ;
    for (int i=0 ; i<3 ; i++ )
        in>>per.datenaissance[i] ;// jj/mm/aa
    per.solde =0 ;
    return in ;
}




class client : public person
{
    int numassurance;
    int code_parrainage;
    float scoreparrainage;
    float remise;
    bool isBlacklisted;
    string adress;
    public:
    client (string cour="",string a="",string b="", string c="",string d="",int e=0,string f="",int g=0,int h=0,int i=0,double x=0 ,string a1="",int j=0,int k=0,float l=0,float m=0,string o="")  :person(cour,a,b,c,d,e,f,g,h,i,x,a1)
    {
    numassurance=j;
    code_parrainage=k;
    scoreparrainage=l;
    remise=m;
    isBlacklisted=false;
    adress=o;
    }
    void depot(double a){stringstream sold;this->solde += a ;
    cout<<"sucess"<<endl<<"taper entrer pour continuer";getch();}
    
    float getremise() {return remise;}
    void updatescore(int a );
    void acceuil()
        {

            system("CLS");
            cout<<"entrer 1 pour des action monitaire: "<<endl;
            cout<<"entrer 2 consulter votre profil: "<<endl;
            cout<<"entrer 3 pour envoyer un feedback : "<<endl;
            cout<<"entrer 4 pour des action reliee au camping : "<<endl;
            cout<<"entrer 5 pour consulter votre boite des message : "<<endl;
            cout<<"entrer 6 se deconnecter: "<<endl;
            /*
            if (x== 1) monitaire() ;
            if (x== 2) afficher();
            if (x== 3) envoyer_feedback();
            if (x== 4) messagerie () ;
            if (x== 5) logout();*/
        }
    void afficher()
        {
            cout<<"nom:"<<nom<<endl<<"prenom:"<<prenom<<endl<<"cin:"<<Cin<<endl<<"numtel:"<<tel<<endl<<"etat civile:"<<etat_civil<<endl<<"adressmail:"<<mailadress<<endl<<"date naissance:"<<datenaissance[0]<<"/"<<datenaissance[1]<<"/"<<datenaissance[2]<<endl<<"solde:"<<solde<<endl;
            cout<<"le num d'assurance "<< numassurance <<"\n le code parrainage" <<code_parrainage << "l<\n e score parrainage "<<scoreparrainage<<endl;
            cout<< "votre adresse " << adress <<endl;
        }
    void campingactions()
    {

        cout<<"entrer 1 pour consulter les campings:"<<endl;
        cout<<"entrer 2 pour faire un reservation:"<<endl;


    }
    void payer(double a )
    {
        solde -=a;
    }
    void save();
    string getcin()
    {
        return Cin;
    }
    void updateremise(float a ) {remise = a ;}
    void monitaire()
    {
            system("CLS");
            cout<<"entrer 1 pour consulter votre solde: "<<endl;
            cout<<"entrer 2 pour faire un depot: "<<endl;
            cout<<"entrer 3 pour retirer de l'argent: "<<endl;
            cout<<"entrer 4 pour retourner au menu principale: "<<endl;
            int x1 ;
            cin>> x1;
            if (x1==1) {cout<< "votre solde est : "<<solde<<endl<<"taper entrer pour retourner"<<getch();}
        
            if (x1==2)
            {
                cout<<"donner le montant a ajouter :" << endl ;

                cin>> money;
                
                this->solde+=money ;
                return;
            }
       
            if (x1==3)
            {
                cout<<"donner le montant a retirer :" << endl ;
                float d;
                cin>> d ;
                this->retrait(d) ;
                return;
            }
        
            if (x1==4) acceuil() ;
        return;
    }

    void modifier () ; // 1 2 3 4
    friend ostream& operator<< (ostream &in , client &clt ) ;
    friend istream& operator>> (istream & ,client & ) ;
    void set_blacklisted () {isBlacklisted = true ; }
    void messagerie () {cout<< courier ;}
    void envoyer_feedback() 
    {
        string feedback;
        cout<<"le client est roi! entrer votre feedback:"<<endl;
        cin>>feedback;
        ofstream in;
        in.open("feedback.txt",ios::app);
        in<<endl<<feedback;
        


    }
    bool existsId(string  );
    friend class MaBaseDeDonnee;
    float get_solde () {return solde ;}
    bool verifier_black () {if (isBlacklisted == false) return true ; }
    void payer (float a) {solde-=a ;}
};


class admin : public person
{
public:
    admin(string cour="",string a="",string b="", string c="",string d="",int e=0,string f="",int g=0,int h=0,int i=0,double x=0 ,string a1=""): person::person(cour,a,b,c,d,e,f,g,h,i,x,a1)
    {
    }
    void set_blacklisted (int a ) {
    }//a.set_blacklisted() ; }
    void readfeedback()
    {
        char ch [100000];
        
        ifstream ina;
        ina.open("feedback.txt");
        ina.getline(ch,100000);
        cout<<ch;

        
    }
    void adminmenu()
    {
        system("CLS");
        cout<<"admin logged:"<<endl;
        cout<<"entrer 1 pour des action monitaire: "<<endl;
        cout<<"entrer 2 consulter votre profil: "<<endl;
        cout<<"entrer 3 pour consulter votre boite des message : "<<endl;
        cout<<"entrer 4 pour modifier votre compte: "<<endl;
        cout<<"entrer 5 pour des actions reliee au campings"<<endl;
        cout<<"entrer 6 pour consulter votre base de donne(personne):"<<endl;
        cout<<"entrer 7 se deconnecter: "<<endl;


    }
    void monitaire()
    {
        system("CLS");
        cout<<"entrer 1 pour consulter votre solde: "<<endl;
        cout<<"entrer 2 pour faire un depot: "<<endl;
        cout<<"entrer 3 pour retirer de l'argent: "<<endl;
        cout<<"entrer 4 pour retourner au menu principale: "<<endl;
        int x ;
     
        cin>> x;
        if (x==1){ cout<< "votre solde est : "<<solde << endl<<"taper entrer pour continuer" ;getch();}
        if (x==2)
        {

            cout<<"donner le montant a ajouter :" << endl ;
            cin>> money ;
            this->depot(money) ;
            
        }
        if (x==3)
        {
            cout<<"donner le montant a retirer:"<< endl ;
            cin>> money ;
            this->retrait(money) ;
        }
        if (x==4) adminmenu() ;
    }
    void depot(double a)
    {
        this->solde += a ;
        //cout<<"sucess"<<solde<<endl<<"taper entrer pour continuer";getch();
    }
    double getsolde()
    {
        return solde;
    }
    void campingactions()
    {
        system("CLS");
        cout<<"entrer 1 pour consulter les campings:"<<endl;
        cout<<"entrer 2 pour creer un camping:"<<endl;
        cout<<"entrer 3 pour creer des privileges:"<<endl;
        cout<<"entrer 4 pour afficher les privileges:"<<endl;
    }
    friend ostream& operator<<(ostream& , admin&);
    friend class MaBaseDeDonne;
};

ostream& operator<<(ostream&a, admin& b)
{
//person *p= static_cast<const person&>(b);
    a<<static_cast<const admin&>(b); 
    return a;
}


class guide : public person
{
    string id_reservation_courante ;
    public:
    guide(string cour="",string a="",string b="", string c="",string d="",int e=0,string f="",int g=0,int h=0,int i=0,double x=0 ,string a1="",int l=0):person(cour,a,b,c,d,e,f,g,h,i,x,a1)
    {
    id_reservation_courante=l;
    }
    void set_id_reservation (string a ) {id_reservation_courante = a ;}
    void guidemenu()
    {
        cout<<"entrer 1 pour des action monitaires:"<<endl;
        cout<<"entrer 2 pour choisir un camping a prendre en charge:"<<endl;
        cout<<"entrer 3 pour consulter les campings:"<<endl;
        cout<<"entrer 4 pour se deconnecter"<<endl;
    }
    void monitaire()
    {
            system("CLS");
            cout<<"entrer 1 pour consulter votre solde: "<<endl;
            cout<<"entrer 2 pour faire un depot: "<<endl;
            cout<<"entrer 3 pour retirer de l'argent: "<<endl;
            cout<<"entrer 4 pour retourner au menu principale: "<<endl;
            int x1 ;
            cin>> x1;
            if (x1==1) {cout<< "votre solde est : "<<solde<<endl<<"taper entrer pour retourner"<<getch();}
        
            if (x1==2)
            {
                cout<<"donner le montant a ajouter :" << endl ;

                cin>> money;
                
                this->solde+=money ;
                return;
            }
       
            if (x1==3)
            {
                cout<<"donner le montant a retirer :" << endl ;
                float d;
                cin>> d ;
                this->retrait(d) ;
                return;
            }
        
            if (x1==4) guidemenu() ;
        return;
    }

    friend class MaBaseDeDonnee;
    friend istream& operator>> (istream &in , guide& g   );
};


ostream& operator<< (ostream &out ,client &clt  )
{
    person *c = &clt ;
    out<< *c ;
    out<<"le num d'assurance :"<< clt.numassurance <<"\n le code parrainage:" <<clt.code_parrainage << "l<\n e score parrainage: "<<clt.scoreparrainage<<endl;
    out<< "votre adresse: " << clt.adress <<endl;
    return out ;
}


istream& operator>> (istream &in , client &clt  )
{
    person *c = &clt ;
    in>>*c;
    cout<< "donner le num d'assurance " << endl;
    in>> clt.numassurance ;
    cout<< "si vous etes parrainé donner le code parrainage" << endl;
    string a;
    cin>>a;
    clt.scoreparrainage = 0 ;
    clt.remise = 666666 ;
    cout<< "donner l'adresse  " << endl;
    in>> clt.adress ;
    return in;
}

class camping
{
    int privs;
    string id ;
    string cat;
    string lieu ;
    int date[3];
    int duree;
    string description;
    int maxemp;
    double prix;
    vector<int>cins;
    vector<string>reserved;
    vector<privilege>priv;
    public:
    camping(string id="",string a="",string b="",int c=0,int d=0,int e=0,int x=0,string f="",double g=0,int duree=0)
    {
        this->id = id;
       this->duree= duree;
    cat=a;
    lieu=b ;
    date[0]=c;
    date[1]=d;
    date[2]=e;
    description=f;
    maxemp=x;
    prix=g;  
    privs=0;  
    }
    void loadcamp(int a)
    {
    ifstream in("Campings2.txt");
    char ch[400];
    in.getline(ch,400,'\n');
    for (int i = 0; i < a; i++)
    {
        in.getline(ch,400,'\n');
    }
    //id    cat     lieu date duree description maxemp pric,privs,idprivs
    in.getline(ch,400,',');
    stringstream b ;
    b<<ch;
    b>>id;

    in.getline(ch,400,',');
    stringstream c;
    c<<ch;
    c>>cat;
    in.getline(ch,400,',');
    stringstream  d;
    d<<ch;
    d>>lieu;

    in.getline(ch,400,'/');
    stringstream  e;
    e<<ch;
    e>>date[0];

    in.getline(ch,400,'/');
    stringstream  f;
    f<<ch;
    f>>date[1];

    in.getline(ch,400,',');
    stringstream  g;
    g<<ch;
    g>>date[2];

    in.getline(ch,400,',');
    stringstream  d1;
    d1<<ch;
    d1>>duree;

    in.getline(ch,400,',');
    stringstream  h;
    h<<ch;
    h>>description;
    in.getline(ch,400,',');
    stringstream  j;
    j<<ch;
    j>>prix;
    in.getline(ch,400,',');
    stringstream pri;
    pri<<ch;
    pri>>maxemp;
    in.getline(ch,400,',');
    stringstream  kkk;
    kkk<<ch;
    kkk>>privs;
    for (int i = 0; i < privs; i++)
    {
        in.getline(ch,400,',');
        stringstream  x;
        x<<ch;
        int i1 ;
        x>>i1;
        cins.push_back(i1);
    }
    in.close();
    }
    void addcin(int a)
    {
        cins.push_back(a);
    }
    int getmaxemp()
    {
        return maxemp;
    }
    void  setprivs(int nb)
    {
        privs = nb;
    }
    void setid(string a)
    {
        id=a;
    }
    int getprivs()
    {
        return privs;
    }
    void addpriv(const privilege& a)
    {
        priv.push_back(a);
    }
    double getprix()
    {
        return prix;
    }
    void setmaxemp(int a)
    {
        maxemp =a ;
    }
    void savecamp()
    {
        ofstream fout;
        fout.open("Campings.txt",ios::app);
        fout<<"\n"<<id<<","<<cat<<","<<lieu<<","<<date[0]<<"/"<<date[1]<<"/"<<date[2]<<","<<duree<<","<<description<<","<<maxemp<<","<<prix<<",";
        fout<<priv.size()<<",";
        for (int i = 0; i < priv.size(); i++)
        {
            fout<<priv[i].id<<",";
        }
        fout<<reserved.size()<<",";
        for (int i = 0; i < reserved.size(); i++)
        {
            fout<<priv[i]<<",";
        }
        
        fout.close();


        
    }
    void showprivs()
    {
        for (int i = 0; i < priv.size(); i++)
        {
            cout<<priv[i]<<endl;
        }
        
    }
    double calcultotal(client a)
    {
        return prix - a.getremise() ;
    }
    void showids()
    {
        for (int i = 0; i < cins.size(); i++)
        {
            cout<<cins[i]<<endl;
        }
        
    }
    friend ostream & operator<<(ostream& a,const camping & );
    string getid(){return id;}
    double get_prix (){return prix ;}
    int get_empla (){return maxemp ;}
    friend class campings;
    friend istream & operator>>(istream&,camping& );
    friend class MaBaseDeDonnee;
};
ostream & operator<<(ostream& a,const camping & b)
{

        a<<"id camping :"<<b.id<<"\ncat:"<<b.cat<<"\nlieu:"<<b.lieu<<"\ndate(jj/mm/aa):"<<b.date[0]<<"/"<<b.date[1]<<"/"<<b.date[2]<<"\nduree:"<<b.duree<<"\ndiscription:"<<b.description<<"\nprix:"<<b.prix<<"\nnombre max d'emplacement:"<<b.maxemp<<endl<<"nombre de privilege:"<<b.privs<<endl;

    return a ;
}
class campings
{
int number;//number of privileges;
vector<privilege> privs;
vector<camping> camps;
public:
campings()
{
    number = 0;
}
void loadCampings()
{
    int i =0;
char ch[401];
ifstream in("Campings2.txt");
in.getline(ch,400,'\n');
while (!in.eof())
{
    char ch[401];
    camping* b;
    b= new camping();
    b->loadcamp(i);
    i++;
    in.getline(ch,400,'\n');
    camps.push_back(*b);
}
in.close();
}
friend ostream & operator<<(ostream& ,const campings & );
friend class person;
void ajouter_camping (const camping & a)
    { 
        camps.push_back (a) ;
    }
void supprimer_campning (string k )
    {
        for (int i=0; i<camps.size(); i++ )
            {
                   if (camps[i].getid() == k ) camps.erase(camps.begin()+i) ;
            }
        cout << "camping supprimee "   <<endl ;
    }
void modifier_camping () ;
void setnumber(int nb)
{
    number = nb;
}
void ajouter_previlege (const privilege& pr )
    {
        privs.push_back (pr) ;
    }
void savecamps()//trunk that sh**t
{
    ofstream fout;
    fout.open("Campings2.txt");
    for (int i = 0; i < camps.size(); i++)
    {
        fout<<"\n";
        fout<<camps[i].id<<","<<camps[i].cat<<","<<camps[i].lieu<<","<<camps[i].date[0]<<"/"<<camps[i].date[1]<<"/"<<camps[i].date[2]<<","<<camps[i].duree<<","<<camps[i].description<<","<<camps[i].maxemp<<","<<camps[i].prix<<","<<camps[i].priv.size()<<","; 
        if (camps[i].priv.size()==0)fout<<"0,";
        else
        for (int k = 0;k < camps[i].priv.size(); k++)
        {
            if(k==camps[i].priv.size()-1)
            { fout<<camps[i].priv[k].id;}
            else 
            {fout<<camps[i].priv[k].id<<",";}
        }
        
    }
    
}
int size()
{
    return camps.size();
}
friend class admin;
friend class MaBaseDeDonnee;
friend ostream& operator<<(ostream& out ,const campings* B);
friend istream& operator>>(istream& a,campings* b);
};
ostream & operator<<(ostream& a,const campings & b)
{
    for (int i = 0; i < b.camps.size(  ); i++)
    {
        a<<"********************"<<endl;
        a<<b.camps[i];
        a<<"********************"<<endl;
    }
    return a ;
}

bool client::existsId(string a )
{
ifstream fin("Accounts.txt");
    while (!fin.eof())
    {
        char ch[400];
        fin.getline(ch,400,',');
        string a1(ch);
        cout<<a1<<endl;
        if (a1==a)
        {
        return false;
        }
        fin.getline(ch,400,'\n');
        fin.getline(ch,400,'\n');

    }
        return true;

}

class MaBaseDeDonnee
{
    vector<privilege> privs;
    campings a ;
    vector <person*> tab1 ;
    public: 
    MaBaseDeDonnee()
    {
        loadpersonne();
        loadprivs();
        a.loadCampings();
        for (int i = 0; i < a.camps.size(); i++)
        {
            cinup(a.camps[i]);
        }
        
    }
    ~MaBaseDeDonnee()
    {
        for (int i = 0; i < tab1.size(); i++)
        {
            delete tab1[i];
        }
        
    }
    void empty()
    {
               for (int i = 0; i < tab1.size(); i++)
        {
            delete tab1[i];
        }
         
    }
    void cinup( camping& b)
    {   
        for (int i = 0; i < b.cins.size(); i++)
        {
            if(ExistsIdPriv(b.cins[i]))
            b.priv.push_back(getpriv(b.cins[i]));
        }
        
    }
    privilege& getpriv(int a)
    {
        privilege* p;
        for (int i = 0; i < privs.size(); i++)
        {
            if (privs[i].id==a)
            {
                return privs[i];
            }

            
        }
        return* p;
        
    } 
    camping* getcamping(string a1)
    {
        camping* p;
        for (int i = 0; i < a.size(); i++)
        {
            if (a1==a.camps[i].getid())
            {
                *p=a.camps[i];
                return p;
            }
            
        }
        return p ;
        
    }
    void reserv(string a1,person* b,double & c)
    {
    for (int i = 0; i < a.size(); i++)
    {
        if (a.camps[i].prix>b->solde)cout<<"solde insufisant"<<endl;
        else if(a.camps[i].maxemp==0) cout<<"reservation full";
        else{b->solde-=a.camps[i].prix;a.camps[i].maxemp-=1;c+=a.camps[i].prix;cout<<"reservation faite:"<<endl<<"taper entrer pour continuer";getch();break;}
        
    }
    
    }
    void deleteprivs()
    {
        privs.clear();
        
    }
    void reloadcampings()
    {
        empty();
        a.loadCampings();
    }
    void enregistrer ()
{
    ofstream fout ;
    fout.open("privileges.txt" , ios::trunc) ;
    for(int i=0;i<privs.size();i++)  {fout<<"\n"<<privs[i].id<<","<<privs[i].description<<","<<privs[i].price;}
    fout.close() ;
}
    void ajouter_personne(person& per )
    {
        person *p ;
        if (typeid(per)==typeid(client))      p=new client (static_cast <const client&> (per) );
        else if (typeid(per)==typeid(admin))  p=new admin (static_cast <const admin&> (per) ) ;
        else if (typeid(per)==typeid(guide))  p=new guide (static_cast <const guide&> (per) ) ;
        tab1.push_back (p) ;
    }
    void loadprivs()
    {
    privilege a ;
    ifstream in("privileges.txt");
    char ch[400];
    in.getline(ch,400,'\n');
    while(!in.eof())
    {
    in.getline(ch,400,',');
    stringstream b;
    b<<ch,
    b>>a.id;

    in.getline(ch,400,',');
    stringstream c;
    c<<ch;
    c>>a.description;
    in.getline(ch,400,'\n');
    stringstream  d;
    d<<ch;
    d>>a.price;
    privs.push_back(a);
    }
    in.close();
    }
    void clientsignup()
{
    person* p;
    p=new client();
    cin>>*p;
    tab1.push_back(p);
}
    void supprimer_camping (string a1)
    {
    for (int i=0;i<a.camps.size();i++)
    {
        if (a1==a.camps[i].getid())
        a.camps.erase(a.camps.begin()+i);
    }
    }
    void loadpersonne()
    {
    ifstream in("Accounts2.txt");
    char ch[400];
    in.getline(ch,400,'\n');
    int grigs=0;
    while(!in.eof())
    {    
        grigs++;
    in.getline(ch,400,',');
    string status;
    stringstream x;
    x<<ch;
    int i ;
    x>>status;
    if (status=="client")   
    {
    client *p=new client();
    in.getline(ch,400,',');
    stringstream x1;
    x1<<ch;
    x1>>p->Cin;
    in.getline(ch,400,'\n');
    stringstream x2;
    string passs(ch);
   // decrypt(passs);
    x2<<ch;
    x2>>p->pass;
    in.getline(ch,400,';');
    stringstream x;
    x<<ch;
    x>>p->nom;
    in.getline(ch,400,';');

    stringstream b;
    b<<ch;
    b>>p->prenom;
    in.getline(ch,400,';');

    stringstream c;
    c<<ch;
    c>>p->tel;
    in.getline(ch,400,';');

    stringstream d;
    d<<ch;
    d>>p->etat_civil;
    in.getline(ch,400,';');

    stringstream e;
    e<<ch;
    e>>p->mailadress;
    in.getline(ch,400,'/');

    stringstream f;
    f<<ch;
    f>>p->datenaissance[0];
    in.getline(ch,400,'/');

    stringstream g;
    g<<ch;
    g>>p->datenaissance[1];
    in.getline(ch,400,';');

    stringstream h;
    h<<ch;
    h>>p->datenaissance[2];
    in.getline(ch,400,';');
    stringstream hx;
    hx<<ch;
    hx>>p->solde;
    in.getline(ch,400,';');
    stringstream hz;
    hz<<ch;
    hz>>p->numassurance;
    in.getline(ch,400,';');
    stringstream xy;
    xy<<ch;
    xy>>p->code_parrainage;
    in.getline(ch,400,';');
    //name0;prenom;tel;etat_civil;mailadress;aa/mm/jj;solde;numassurance;scoreparrainage;remise;courier;adress;false
    stringstream h1;
    h1<<ch;
    h1>>p->scoreparrainage;
    in.getline(ch,400,';');
    stringstream h2;
    h2<<ch;
    h2>>p->remise;
    in.getline(ch,400,';');
    stringstream h3;
    h3<<ch;
    h3>>p->courier;
    in.getline(ch,400,';');
    stringstream h4;
    h4<<ch;
    h4>>p->adress;
    in.getline(ch,400,'\n');
    if (ch == "false")
    p->isBlacklisted = false;
    else 
    p->isBlacklisted =true;
    person * p1=new client(static_cast<const client &>(*p));
    tab1.push_back(p1);
    }
    else if (status=="admin") 
    {
    admin *p=new admin();
    in.getline(ch,400,',');
    stringstream x1;
    x1<<ch;
    x1>>p->Cin;
    in.getline(ch,400,'\n');
    stringstream x2;
    string passs(ch);
    //decrypt(passs);
    x2<<ch;
    x2>>p->pass;
    in.getline(ch,400,';');
    stringstream x;
    x<<ch;
    x>>p->nom;
    in.getline(ch,400,';');

    stringstream b;
    b<<ch;
    b>>p->prenom;
    in.getline(ch,400,';');

    stringstream c;
    c<<ch;
    c>>p->tel;
    in.getline(ch,400,';');

    stringstream d;
    d<<ch;
    d>>p->etat_civil;
    in.getline(ch,400,';');

    stringstream e;
    e<<ch;
    e>>p->mailadress;
    in.getline(ch,400,'/');

    stringstream f;
    f<<ch;
    f>>p->datenaissance[0];
    in.getline(ch,400,'/');

    stringstream g;
    g<<ch;
    g>>p->datenaissance[1];
    in.getline(ch,400,';');

    stringstream h;
    h<<ch;
    h>>p->datenaissance[2];
    in.getline(ch,400,';');
    stringstream hw;
    hw<<ch;
    hw>>p->solde;
    in.getline(ch,400,'\n');
    hw<<ch;
    hw>>p->courier;
    //name0;prenom;tel;etat_civil;mailadress;aa/mm/jj;solde;numassurance;scoreparrainage;remise;courier;adress;false
    person *p1=  new admin(static_cast<const admin&>(*p)) ;
    tab1.push_back(p1);

    }
    else if (status=="guide") 
     { guide *p=  new guide() ;

    in.getline(ch,400,',');
    stringstream x1;
    x1<<ch;
    x1>>p->Cin;
    in.getline(ch,400,'\n');
    stringstream x2;
    string passs(ch);
    //decrypt(passs);
    x2<<ch;
    x2>>p->pass;
    in.getline(ch,400,';');
    stringstream x;
    x<<ch;
    x>>p->nom;
    in.getline(ch,400,';');

    stringstream b;
    b<<ch;
    b>>p->prenom;
    in.getline(ch,400,';');

    stringstream c;
    c<<ch;
    c>>p->tel;
    in.getline(ch,400,';');

    stringstream d;
    d<<ch;
    d>>p->etat_civil;
    in.getline(ch,400,';');

    stringstream e;
    e<<ch;
    e>>p->mailadress;
    in.getline(ch,400,'/');

    stringstream f;
    f<<ch;
    f>>p->datenaissance[0];
    in.getline(ch,400,'/');

    stringstream g;
    g<<ch;
    g>>p->datenaissance[1];
    in.getline(ch,400,';');

    stringstream h;
    h<<ch;
    h>>p->datenaissance[2];
    in.getline(ch,400,';');
    stringstream hx;
    hx<<ch;
    hx>>p->solde;
    in.getline(ch,400,';');
    stringstream hw;
    hw<<ch;
    hw>>p->id_reservation_courante;
    in.getline(ch,400,'\n');
    stringstream hzz;
    hzz<<ch;
    hzz>>p->courier;
    person *p1=  new guide(*p) ;
    tab1.push_back(p1);
    }
    }

   
    //for (int i = 0; i < privs; i++)
    //{
    //    in.getline(ch,400,',');
    //    stringstream  x;
     //   x<<ch;
     //   int i1 ;
     //   x>>i1;
     //   loadpriv(i1);
   // }
    in.close();
    
    }
    void save()//saves personne
    {
    ofstream fout;
    fout.open("Accounts2.txt");
    if(!fout) cout<< "imppossible" ;
    fout<<"\n";
    for (int i = 0; i < tab1.size(); i++)
    {

        if(typeid(*tab1[i])==typeid(guide))
            {
                guide* p=new guide(static_cast<const guide&>(*tab1[i])); fout<<"guide,"<<p->Cin<<","<<p->pass<<endl;
                fout<<p->nom<<";"<<p->prenom<<";"<<p->tel<<";"<<p->etat_civil<<";"<<p->mailadress<<";"<<p->datenaissance[0]<<"/"<<p->datenaissance[1]<<"/"<<p->datenaissance[2]<<";"<<p->solde<<";"<<p->id_reservation_courante<<";"<<p->courier<<"\n";
            }

        if(typeid(*tab1[i])==typeid(client))
            {
                client* p=new client(static_cast<const client&>(*tab1[i]));fout<<"client,"<<p->Cin<<","<<p->pass<<endl;
                fout<<p->nom<<";"<<p->prenom<<";"<<p->tel<<";"<<p->etat_civil<<";"<<p->mailadress<<";"<<p->datenaissance[0]<<"/"<<p->datenaissance[1]<<"/"<<p->datenaissance[2]<<";"<<p->solde<<";"<<p->numassurance<<";"<<p->code_parrainage<<";"<<p->scoreparrainage<<";"<<p->remise<<";"<<p->courier<<";"<<p->adress<<";"<<p->isBlacklisted<<"\n";
            }
        if(typeid(*tab1[i])==typeid(admin))
            {
                admin* p=new admin(static_cast<const admin&>(*tab1[i]));fout<<"admin,"<<p->Cin<<","<<p->pass<<endl;
                fout<<p->nom<<";"<<p->prenom<<";"<<p->tel<<";"<<p->etat_civil<<";"<<p->mailadress<<";"<<p->datenaissance[0]<<"/"<<p->datenaissance[1]<<"/"<<p->datenaissance[2]<<";"<<p->getsolde()<<";"<<p->courier<<"\n";
            }
    }

    }
    bool validate(string a ,int& d, string b,string& c)// id // pass //status
{
    for(int i=0;i<tab1.size();i++)
    {
        c="";
        if((tab1[i]->Cin==a) && (tab1[i]->pass == b))
        {
            if (typeid(*tab1[i])==typeid(admin))
            {
                cout<<"admin found"<<endl;
                c="admin";
            }
            if (typeid(*tab1[i])==typeid(client))
            {
                cout<<"admin found"<<endl;
                c="client";
            }
            if (typeid(*tab1[i])==typeid(guide))
            {
                cout<<"admin found"<<endl;
                c="guide";
                cout<<"guide login";
            }
            d=i;
            return true;
        }
       
    }
     return false;
}
    person* operator[](int a)//gives a person pointer
    {
        return tab1[a];
    }
    bool existsId(string a )
{
    for (int i = 0; i < tab1.size(); i++)
    {
        if (a==tab1[i]->Cin)
        {
            return true;
        }
        
    }
    
    return false;

}
    void buypriv(int a,person* b)
    {
        for (int i = 0; i < privs.size(); i++)
        {
            if (privs[i].id==a && b->solde>privs[i].price)
            {
             b->solde-=   privs[i].price;
             cout<<"achat du privilege avec success"<<endl;break;
            }
            
        }
        
    }
    bool existscampid(string ab)
    {
        for (int i = 0; i < a.camps.size(); i++)
        {
            if (ab==a.camps[i].id)
            {
                return true;
            }
            
        }
        return false;
        
    }
    void modifier_personne (string c)
    {
        int n ;
        string a;
        char t , u;
        cout<< "vous voulez changer votre mots de passe ? y/n \n   " ;
        cin>> t ;
        if (t =='y' )
        {
            cout << "donnez votre nouveau mdp ici " << endl ;
            cin>> a ;
            for (int i=0; i<tab1.size(); i++ )
            {
                if (tab1[i]->get_cin() == c )
                {
                    tab1[i]->setpass(a) ;
                }
            }
        }
        cout<< "vous voulez changer votre numero de tel ? y/n \n   " ;
        cin>> u ;
        if (u== 'y' )
        {
            cout << "donnez le nouveau numero du tel ici " << endl ;
            cin>> n ;
            for (int i=0; i<tab1.size(); i++ )
            {
                if (tab1[i]->get_cin() == c )
                {
                    tab1[i]->setnum(n) ;
                }
            }
        }
        save();

    }
    void afficher_campings()
    {
        cout<<"affichage des campings:"<<endl;
        for (int i = 0; i < a.camps.size(); i++)
        {
            cout<<"***********************"<<endl;
            cout<<a.camps[i];
            cout<<"les privileges associe:"<<endl;
            a.camps[i].showprivs();
            cout<<"***********************"<<endl;
        }   

    }
    void ajouter_camping(const camping& b)
    {
        a.ajouter_camping(b);
    }
    void addpriv(const privilege & a )
    {
    privs.push_back(a);
    }
    bool ExistsIdPriv(int idpriv)
    {
    for (int i = 0; i <privs.size(); i++)
    {
        if (idpriv==privs[i].id)
        {
            return true;
        }
        
    }
    return false;
    
    }
    void afficher_priv()
    {
        system("CLS");
        for (int i = 0; i < privs.size(); i++)
        {
            cout<<"privilege(id,description,prix):"<<privs[i]<<endl;
        }
        cout<<"taper entrer pour continuer"<<endl;
        getch();
        
    }
    int totalprivs()
    {
        return privs.size();
    }
    void savecamps()
    {
    a.savecamps();
    }
    void updateperson(const person& a)
    {
        for (int i = 0; i < tab1.size(); i++)
        {
            if (tab1[i]->Cin==a.Cin)
            {
                *tab1[i]=a;
            }
            
        }
        
    }
    friend ostream& operator<<(ostream &out,const MaBaseDeDonnee &B);
    friend class admin;
    friend class person;
    friend class campings;
    friend class camping;
};
ostream& operator<<(ostream &out,const MaBaseDeDonnee &B)
{
    out<<"affichage de la base:"<<B.tab1.size()<<" elements"<<endl;
for (int i=0; i<B.tab1.size(); i++)
{
    out<<"********************"<<endl;
    
    
    if ( typeid(*B.tab1[i]) == typeid(client) )
    {
     out<<"client:"<<endl<<static_cast<const client&>(*B.tab1[i]);
     }


    if ( typeid(*B.tab1[i])==typeid(admin) ) 
    {
     out<<"admin:"<<endl<<static_cast<const admin&>(*B.tab1[i]);
     }

     if ( typeid(*B.tab1[i])==typeid(guide) ) 
    {
     out<<"guide:"<<endl<<static_cast<const guide&>(*B.tab1[i]);}
}
return out;
}
istream & operator>>(istream&in,camping& a)
{
cout<<"donner la categorie:";
in>>a.cat;
cout<<"\ndonne le lieu:";
in>>a.lieu;
cout<<"\ndonner la date(jj/mm/aa):";
in>>a.date[0]>>a.date[1]>>a.date[2];
cout<<"\ndonner la description:";
in>>a.description;
cout<<"\ndonner les emplacements maximales:";
in>>a.maxemp;
cout<<"\ndonner le prix du reservation:";
in>>a.prix;
cout<<"\ndonner la duree:";
in>>a.duree;


return in;
}
void internautmenu()
{
    system("CLS");
    cout<<"entrer 1 pour s'identifier:"<<endl;//signub
    cout<<"entrer 2 pour s'enregistrer:"<<endl;//login
    cout<<"entrer 3 pour consulter nos campings:"<<endl;
}
istream& operator>> (istream &in , guide& g   )
{
    person *c = &g ;
    in>> *c ;
    cout<< "donner id_reservation " << endl;
    in>> g.id_reservation_courante ;
    return in;
}
double trisorie;