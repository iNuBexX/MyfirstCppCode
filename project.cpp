#include <iostream>
#include "projectheader(clean).h"
#include <fstream>
#include <map>
#include <exception>
#include <stdlib.h>
using namespace std;
int main()
{
    admin* ad;
    guide* guid;
    client* clt;
    int pos;
    int warning=0;
    string id;
    string pass;
    bool isBlocked=false;
    bool LoginStatus=false;
    string status;
    person *user;
    MaBaseDeDonnee base;
    while(isBlocked==false & LoginStatus==false )//for internaut 
    {   
        try
        {
        int choice=0;
        internautmenu();
        cin>>choice;
        string errorstring ="error choix n'existe pas ";
        if (choice!=1 && choice!=2 && choice!=3) throw(errorstring);
                system("CLS");
            if (choice==1) //identification (login) works good
            {

                choice=0;
                cout<<"Cin:"<<endl;
                cin>>id;
                cout<<"mot de pass:"<<endl;
                cin>>pass;
                if(base.validate(id,pos,pass, status)==false)
            {
                cout<<base.validate(id,pos,pass, status);
            warning++;
            
            system("CLS");
            cout<<"avertissement:"<<warning<<endl;
            if( warning == 3)
            {
                cout<<"session bloquee (plusieur echec de login)";
                isBlocked = true;
            }
            }
                else    //successfull login
            {
            system("CLS");
            cout<<"successfull login:"<<endl;
            cout<<status<<endl;// debugging
            LoginStatus = true;
            }
            }
            if(choice ==2) //signup 
            {
                signup();
                cin>>choice;
                if (choice==1)
                {
                string id;
                cout<<"entrer votre cin:";
                cin>>id;
                if(base.existsId(id)==true)
                {system("CLS");
                cout<<"cin existe deja! contacter l'administration via mail si vou voulez recevoire votre mot de pass"<<endl<<"taper entrer pour retourner"<<endl;
                getch();
                }

                else
               { clt->setid(id);
                   cin>>*clt;
                base.ajouter_personne(*clt);}
                }
                if (choice==2)
                {
                int pincode;
                cout<<"entrer votre codepin:"<<endl;
                cin>>pincode;
                if(pincode!=pin)
                {
                system("CLS");
                cout<<"movaise code pin entree"<<endl<<"taper entrer pour continuer";getch();
                continue;}
                string id;
                cout<<"entrer votre cin:";
                cin>>id;
                if(base.existsId(id)==true)
                {system("CLS");
                cout<<"cin existe deja! contacter l'administration via mail si vou voulez recevoire votre mot de pass"<<endl<<"taper entrer pour retourner"<<endl;
                getch();
                }

                else
               { 
                cin>>*guid;
                base.ajouter_personne(*guid);
                }
                
                
                }
            choice=0;

            }
            if(choice ==3)
            {
            base.afficher_campings();cout<<"taper entrer pour retourner au menu principal:";getch();system("CLS");
            }
  
        }
        catch(string a)
        {
            cout<<a<<"taper entrer pour continuer";getch();
            system("CLS");
            //cout<<"error choix n'existe pas:"<<endl<<"taper entrer pour continuer";getch();
            continue;
        }
    
  }
    if (status == "admin")//for admin when logged in
    {
        //admin p = static_cast<const admin&>(*user);
        user=base[pos];
        // cout<<*user<<endl;
            if(typeid(*user)==typeid(admin))
            //cout<<*user<<endl;
                
            ad= new admin(static_cast<const admin&>(*user));

        while (LoginStatus==true)
        {
            int x ;
            ad->adminmenu();
            cin>>x;
            if(x==1) 
            {
                int i;
                ad->monitaire();

                base.updateperson(*ad);
            }
            if(x==2) {system("CLS");cout<<*ad<<endl<<"taper entrer pour retourner au menu principal";getch(); }//works
            if(x==3) {system("CLS");ad->message(),cout<<"taper entrer pour retourner au menu principal";getch();}
            if(x==4){system("CLS");cout<<"donner votre cin:"<<endl;string b; cin>>b;if (b==user->get_cin())base.modifier_personne(b);}
            if(x==5) {system("CLS");ad->campingactions();
                int choix;cin>>choix;
                if(choix==1)//show the available camppings
                {
                    base.afficher_campings();cout<<"taper entrer pour retourner au menu principal";getch();
                }
                if(choix==2)//creates a camping with existing priveleges
                {
                    camping a ;
                    string campid;
                    system("cls");
                    cout<<"entrer l'id du camping:"<<endl;
                    cin>>campid;
                    if(base.existscampid(campid)==false)
                    {                                                 
                        cin>>a;
                        cout<<"entrer le nombre des priv du camping:";
                        int nb;
                        a.setid(campid);
                        cin>>nb;
                        for (int i = 0; i < nb; i++)
                        {
                            int idpriv;
                            cout<<"donner l'id du privilege a ajouter a votre camping:";
                            cin>>idpriv;
                            if(base.ExistsIdPriv(idpriv)==true)
                            {
                                a.addcin(idpriv);
                            }
                            else
                            {
                                cout<<"id du priv inexistant:"<<endl;
                            }
                        }
                        base.cinup(a);
                        base.ajouter_camping(a);
                        base.savecamps();
                        base.enregistrer();
                        cout<<"camping cree avec success:"<<endl<<"taper entrer pour continuer"<<endl;

                    }
                    else
                    cout<<"l'id du camping deja existe"<<endl<<"taper entrer pour continuer"<<endl;getch();
                 }
                if(choix==3)//creates a privilege
                {
                    privilege *p ;
                    cin>>*p;
                    base.addpriv(*p);
                    base.enregistrer();
                    base.save();base.enregistrer();
                }
                if(choix==4)//show all privileges
                {
                    base.afficher_priv();
                }
            }
            if(x==6){system("CLS");cout<<base<<"taper entrer pour retourner au menu principal";getch();}
            if(x==7){cout<<"a bientot :) ";base.save();base.enregistrer(); LoginStatus=false; }//works
            
            
            
            
            
        }
    }
    if (status == "client")//for client when logged in
        {
             user=base[pos];
            clt =new client(static_cast<const client&>(*user));
            cout<<"client"<<endl;
           
            
            while (LoginStatus==true)
            {
             int x ;
            clt->acceuil();
            cin>>x;
            if(x==1) 
            {
                int i;
                clt->monitaire();

                base.updateperson(*clt);
            }          
            if(x==2) {system("CLS");cout<<*clt<<endl<<"taper entrer pour retourner au menu principal"<<endl;getch(); }//works

            if(x==3){system("CLS");clt->envoyer_feedback();}

            if(x==4) {system("CLS");clt->campingactions();
                int choix;cin>>choix;
                if(choix==1)//show the available camppings
                {
                    base.afficher_campings();cout<<"taper entrer pour retourner au menu principal";getch();
                }
                if(choix==2)//makes reservation
                {
                    string resid;
                cout<<"entrer l'id du camping a reserver:"<<endl;
                cin>>resid;
                if(base.existscampid(resid))
                {
                    base.reserv(resid,clt,trisorie);
                    while (1)
                    {
                        string answere;
                        cout<<"voulez vous acheter des privileges(y/n):";
                        cin>>answere;
                        if(answere=="n")break;
                        if(answere=="y"){
                            int idpriv;cout<<"\nentrer l'id du privilege"<<endl;cin>>idpriv;
                            if (base.ExistsIdPriv(idpriv)){
                                base.buypriv(idpriv,clt);
                            }
                        }
                    }
                    

                    
                }
                else cout<<"id du camping n'existe pas"<<endl;
                }


            }
            if(x==5) {system("CLS");clt->message(),cout<<"taper entrer pour retourner au menu principal";getch();}
            if(x==6){cout<<"a bientot :) ";base.save();base.enregistrer(); LoginStatus=false; }//works
            }
            
        }
    if (status == "guide")//for guide when logged in 
        {
            user=base[pos];
             if(typeid(*user)==typeid(guide))
            guid = new guide(static_cast<const guide&>(*user));
            while (LoginStatus==true)
            {
               int x ;
               system("CLS");
            guid->guidemenu();
               cin>>x;
               if (x==1)
               {
                   guid->monitaire();
               }
               if(x==2)
               {
                   system("CLS");
                cout<<"donner l'id du camping a prendre en charge:"<<endl;
                string idcamp;
                cin>>idcamp;
                if(base.existscampid(idcamp)){guid->set_id_reservation(idcamp);cout<<"prise en charge faite avec succes\ntaper entrer pour continuer"<<endl;getch();base.save();base.enregistrer();}
                else cout<<"id du camping n'existe pas!"<<endl<<"taper entrer pour continuer";getch();
               }
                if(x==3)
               {
                base.afficher_campings();
                cout<<endl<<"taper entrer pour continuer";getch();
               }
               if(x==4)
               {
                cout<<"a bientot :) ";base.save();base.enregistrer(); LoginStatus=false;
               }
            }
            

        }






    return 0;
}