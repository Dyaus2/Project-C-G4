#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "AES.h"
#include <string.h>
#include <glib.h>


enum
{
ID_DON,
TYPE_SANG,
QUANTITE,
JOURDON,
MOISDON,
ANNEEDON,
COLUMNS
};

enum
{
TYPE_SANG2,
QUANTITE2,
COLUMNS2
};

enum
{
	CIN,
	NOM,
	PRENOM,
	IDET,
	PASSWORD,
	ROLE,
	JOUR,
	MOIS,
	ANNEE,
	SEXE,
	ACTIF,
	COLUMNS3
};


enum r_d_v
{
	EID ,
	ECIN ,
	EHORAIRE ,
	EETABLISSEMENT ,
	EJOUR ,
	EMOIS ,
	EANNEE ,
	COLUMNS4
};

enum d_o_n
{
	HID ,
	HCIN ,
	HTYPE ,
	HQUANTITE ,
	HJOUR ,
	HMOIS ,
	HANNEE ,
	HRISQUE,
	HETAT,
	COLUMNS5
};


enum
{
	EIDDONNEUR,
	ENOM,
	EPRENOM,
	ESEXE,
	EGRPSANGUIN,
	EMALADIES,
	EDATENAISSANCEJOUR,
	EDATENAISSANCEMOIS,
	EDATENAISSANCEANNEE,
	ENUMTEL,
	COLUMNS6
};


enum
{
	ERDVCIN,
	ERDVHORAIRE,
	EIDETS,
	EDTRDVDJOUR,
	EDTRDVDMOIS,
	EDTRDVDANNEE,
	COLUMNS7
};

enum
{
	IDG,
	NOMG,
	TYPEG,
	QUANTITEG,
	JOURG,
	MOISG,
	ANNEEG,
	URGENTG,
	COLUMNS8
};


enum
{
	NOME,
	REGIONE,
	CAPACITEE,
	IDE,
	TELE,
	ADRESSEE,	
	ETATE,
	PRINCIPALE,
	COLUMNS9
};
//****************************************DECLARATIONS GLOBALE********************************************************

Fiche d;

//****************************************fct CRUD********************************************************

//****************************************fct CRUD HAZEM********************************************************
//ajout d'un don 

int ajouterDon(Don d , char filename [])
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %d %s %d %d/%d/%d %d %d %s ]\n",d.IdDon,d.cinDon,d.TypeSangDon,d.QuantiteSangDon,d.dt_don.JourDon,d.dt_don.MoisDon,d.dt_don.AnneeDon,d.Rsq_infDon,d.Etat_DispDon,d.id_ets);
        fclose(f);
        return 1;
    }
    else return 0;
}
// modification d'un don
int modifierDon(char id[], Don nouv, char * filename)
{
Don d;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%s %d %s %d %d/%d/%d %d %d %s ]\n",d.IdDon,&d.cinDon,d.TypeSangDon,&d.QuantiteSangDon,&d.dt_don.JourDon,&d.dt_don.MoisDon,&d.dt_don.AnneeDon,&d.Rsq_infDon,&d.Etat_DispDon,d.id_ets)!=EOF)
{
if(strcmp(d.IdDon,id) != 0)
        fprintf(f2,"%s %d %s %d %d/%d/%d %d %d %s ]\n",d.IdDon,d.cinDon,d.TypeSangDon,d.QuantiteSangDon,d.dt_don.JourDon,d.dt_don.MoisDon,d.dt_don.AnneeDon,d.Rsq_infDon,d.Etat_DispDon,d.id_ets);
else

  fprintf(f2,"%s %d %s %d %d/%d/%d %d %d %s ]\n",nouv.IdDon,nouv.cinDon,nouv.TypeSangDon,nouv.QuantiteSangDon,nouv.dt_don.JourDon,nouv.dt_don.MoisDon,nouv.dt_don.AnneeDon,nouv.Rsq_infDon,nouv.Etat_DispDon,d.id_ets);

}
        fclose(f);
        fclose(f2);
remove(filename);
rename("aux.txt", filename);
        return 1;
    }
  
}
//Suprression d un don
int supprimerDon(char id[], char * filename)
{
Don d;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%s %d %s %d %d/%d/%d %d %d %s ]\n",d.IdDon,&d.cinDon,d.TypeSangDon,&d.QuantiteSangDon,&d.dt_don.JourDon,&d.dt_don.MoisDon,&d.dt_don.AnneeDon,&d.Rsq_infDon,&d.Etat_DispDon,d.id_ets)!=EOF)
{
if(strcmp(d.IdDon,id) != 0)
        fprintf(f2,"%s %d %s %d %d/%d/%d %d %d %s ]\n",d.IdDon,d.cinDon,d.TypeSangDon,d.QuantiteSangDon,d.dt_don.JourDon,d.dt_don.MoisDon,d.dt_don.AnneeDon,d.Rsq_infDon,d.Etat_DispDon,d.id_ets);

}
        fclose(f);
        fclose(f2);
remove(filename);
rename("aux.txt", filename);
        return 1;
    }
}
// chercher un don
Don chercherDon(char id[], char * filename)
{
Don d,d1; int tr=0;
    FILE * f=fopen(filename, "r");
 if(f!=NULL )
    {
while(fscanf(f,"%s %d %s %d %d/%d/%d %d %d %s ]\n",d.IdDon,&d.cinDon,d.TypeSangDon,&d.QuantiteSangDon,&d.dt_don.JourDon,&d.dt_don.MoisDon,&d.dt_don.AnneeDon,&d.Rsq_infDon,&d.Etat_DispDon,d.id_ets)!=EOF && tr==0)
{if(strcmp(d.IdDon,id) == 0)
tr=1;
d1 = d;
}
}
if(tr==0)
strcpy(d1.IdDon,"PNT");;
return d1;

}
// determination du quantite sang par type
int DonQuantite_Type(char filename[], char type_sang[])
{
Don d;
int som_q=0;
FILE *f =fopen(filename,"r");
if(f==NULL)
return -1;
else
{
while(fscanf(f,"%s %d %s %d %d/%d/%d %d %d %s ]\n",d.IdDon,&d.cinDon,d.TypeSangDon,&d.QuantiteSangDon,&d.dt_don.JourDon,&d.dt_don.MoisDon,&d.dt_don.AnneeDon,&d.Rsq_infDon,&d.Etat_DispDon,d.id_ets)!=EOF)
{
if(strcmp(d.TypeSangDon,type_sang)==0)
{
if(d.Etat_DispDon == 1)
som_q = som_q + d.QuantiteSangDon;
}
}
fclose(f);
return som_q;
}
}

// creation du base de donnee sangdispo

void BaseDonnee_QuantiteType(char filename[],char filename2[])
{
int somme_q,i;
char t_sang[8][5]={"a+","a-","b+","b-","ab+","ab-","o+","o-"};
FILE *f=fopen(filename,"w");
if(f!=NULL)
{
for(i=0;i<8;i++)
{
somme_q = DonQuantite_Type(filename2,t_sang[i]);
fprintf(f,"%s %d \n",t_sang[i],somme_q);
}
fclose(f);
}
}
// chercher le sang le plus rare
Don DonSang_Rare(char * filename)
{
int min=9999;
Don d;
char type_s[4];
FILE *f=fopen(filename,"r");
if(f!=NULL)
{
while(fscanf(f,"%s %d \n",d.TypeSangDon,&d.QuantiteSangDon)!=EOF)
{
if(d.QuantiteSangDon<min)
{
min = d.QuantiteSangDon;
strcpy(type_s,d.TypeSangDon);
}
}
strcpy(d.TypeSangDon,type_s);
d.QuantiteSangDon = min;
fclose(f);
}
return d;
}

//****************************************fct CRUD HAZEM********************************************************
//****************************************fct CRUD AZIZ********************************************************
int ajouterRDVD(RDVD p , char filename [])
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%d %d %s %s %d %s %d %d \n",p.RDVDid,p.RDVcin,p.RDVDhoraire,p.RDVD_ID_ETS,p.dt_RDVD.RDVDjour,p.dt_RDVD.RDVDmois,p.dt_RDVD.RDVDannee,p.RDVDcom);
        fclose(f);
        return 1;
    }
    else return 0;
}

int modifierRDVD(int id, RDVD nouv, char * filename)
{
RDVD p;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%d %d %s %s %d %s %d %d \n",&p.RDVDid,&p.RDVcin,p.RDVDhoraire,p.RDVD_ID_ETS,&p.dt_RDVD.RDVDjour,p.dt_RDVD.RDVDmois,&p.dt_RDVD.RDVDannee,&p.RDVDcom)!=EOF)
{
if(p.RDVDid!=id)
        fprintf(f2,"%d %d %s %s %d %s %d %d \n",p.RDVDid,p.RDVcin,p.RDVDhoraire,p.RDVD_ID_ETS,p.dt_RDVD.RDVDjour,p.dt_RDVD.RDVDmois,p.dt_RDVD.RDVDannee,p.RDVDcom);
else

  fprintf(f2,"%d %d %s %s %d %s %d %d \n",nouv.RDVDid,nouv.RDVcin,nouv.RDVDhoraire,nouv.RDVD_ID_ETS,nouv.dt_RDVD.RDVDjour,nouv.dt_RDVD.RDVDmois,nouv.dt_RDVD.RDVDannee,nouv.RDVDcom);

}
        fclose(f);
        fclose(f2);
remove(filename);
rename("aux.txt", filename);
        return 1;
    }
  
}

int supprimerRDVD(int id, char * filename)
{
RDVD p;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%d %d %s %s %d %s %d %d \n",&p.RDVDid,&p.RDVcin,p.RDVDhoraire,p.RDVD_ID_ETS,&p.dt_RDVD.RDVDjour,p.dt_RDVD.RDVDmois,&p.dt_RDVD.RDVDannee,&p.RDVDcom)!=EOF)
{
if(p.RDVDid!=id)
        fprintf(f2,"%d %d %s %s %d %s %d %d \n",p.RDVDid,p.RDVcin,p.RDVDhoraire,p.RDVD_ID_ETS,p.dt_RDVD.RDVDjour,p.dt_RDVD.RDVDmois,p.dt_RDVD.RDVDannee,p.RDVDcom);

}
        fclose(f);
        fclose(f2);
remove(filename);
rename("aux.txt", filename);
        return 1;
    }
}

RDVD chercherRDVD(int id, char * filename)
{
RDVD p,p1; int tr=0;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("RDVDCher.txt", "w");
 if(f!=NULL && f2!=NULL)
{
while(fscanf(f,"%d %d %s %s %d %s %d %d \n",&p.RDVDid,&p.RDVcin,p.RDVDhoraire,p.RDVD_ID_ETS,&p.dt_RDVD.RDVDjour,p.dt_RDVD.RDVDmois,&p.dt_RDVD.RDVDannee,&p.RDVDcom)!=EOF && tr==0)
{
if(id==p.RDVDid)
{
tr=1;
p1=p;
fprintf(f2,"%d %d %s %s %d %s %d %d \n",p.RDVDid,p.RDVcin,p.RDVDhoraire,p.RDVD_ID_ETS,p.dt_RDVD.RDVDjour,p.dt_RDVD.RDVDmois,p.dt_RDVD.RDVDannee,p.RDVDcom);
}
}
fclose(f);
fclose(f2);
if(tr==0)
p1.RDVDid=-1;
}
return p1;
}

void historiqueRDVD (int CIN, char * filename)
{
Don p;
FILE * f=fopen(filename, "r");
FILE * f2 =fopen("HistoRDV.txt", "w");
 if(f!=NULL && f2!=NULL )
    {
while(fscanf(f,"%s %d %s %d %d/%d/%d %d %d %s ]\n",p.IdDon,&p.cinDon,p.TypeSangDon,&p.QuantiteSangDon,&p.dt_don.JourDon,&p.dt_don.MoisDon,&p.dt_don.AnneeDon,&p.Rsq_infDon,&p.Etat_DispDon,p.id_ets)!=EOF)
{
if(CIN==p.cinDon)
fprintf(f2,"%s %d %s %d %d/%d/%d %d %d %s ]\n",p.IdDon,p.cinDon,p.TypeSangDon,p.QuantiteSangDon,p.dt_don.JourDon,p.dt_don.MoisDon,p.dt_don.AnneeDon,p.Rsq_infDon,p.Etat_DispDon,p.id_ets);
}
}
fclose(f);
fclose(f2);
}

int capaciteRDVD(char ETS[], char * filename, int cp)
{
ets p;
cp=0;
    FILE * f=fopen(filename, "r");
 if(f!=NULL )
{
	while(fscanf(f,"%s %s %d %s %d %s %d %d \n",p.nom,p.region,&p.capacite,p.ID,&p.tel,p.Adresse,&p.Etat,&p.principal)!=EOF)
	{
	if((strcmp(p.ID,ETS))==0)
	{
	cp=p.capacite;
	}
	}
}
fclose(f);
return cp;
}

int HoraireDispo(char * filename, char ETS[],int capacite, int jour, char mois[] , int annee)
{
RDVD p;
int c;
c=0;
FILE * f=fopen(filename, "r");
FILE * f2=fopen("Dispo.txt", "w");
if(f!=NULL && f2!=NULL )
{
while(fscanf(f,"%d %d %s %s %d %s %d %d \n",&p.RDVDid,&p.RDVcin,p.RDVDhoraire,p.RDVD_ID_ETS,&p.dt_RDVD.RDVDjour,p.dt_RDVD.RDVDmois,&p.dt_RDVD.RDVDannee,&p.RDVDcom)!=EOF)
{
	if (((strcmp(ETS,p.RDVD_ID_ETS))==0) && (p.dt_RDVD.RDVDjour==jour) && ((strcmp(mois,p.dt_RDVD.RDVDmois))==0) && (p.dt_RDVD.RDVDannee==annee))
	{
		fprintf(f2,"%d %d %s %s %d %s %d %d \n",p.RDVDid,p.RDVcin,p.RDVDhoraire,p.RDVD_ID_ETS,p.dt_RDVD.RDVDjour,p.dt_RDVD.RDVDmois,p.dt_RDVD.RDVDannee,p.RDVDcom);
		c++;
	}
}
}
if (c<capacite)
capacite=capacite-c;
else
capacite=0;
fclose(f);
fclose(f2);
return capacite;
}

//****************************************fct CRUD AZIZ********************************************************
//****************************************fct CRUD FEDI********************************************************

int ajouter(user p , char filename [])
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%d %s %s %s %s %s %d %d %d %d %d \n",p.cin,p.nom,p.prenom,p.IDETS,p.pwd,p.role,p.dc.j,p.dc.m,p.dc.a,p.sexe,p.actif);
        fclose(f);
        return 1;
    }
    else return 0;
}



int modifier(int cin, user nouv, char * filename)
{
user p;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%d %s %s %s %s %s %d %d %d %d %d \n",&p.cin,p.nom,p.prenom,p.IDETS,p.pwd,p.role,&p.dc.j,&p.dc.m,&p.dc.a,&p.sexe,&p.actif)!=EOF)
{
if(p.cin!=cin)
        fprintf(f2,"%d %s %s %s %s %s %d %d %d %d %d \n",p.cin,p.nom,p.prenom,p.IDETS,p.pwd,p.role,p.dc.j,p.dc.m,p.dc.a,p.sexe,p.actif);
else

  fprintf(f2,"%d %s %s %s %s %s %d %d %d %d %d \n",nouv.cin,nouv.nom,nouv.prenom,nouv.IDETS,nouv.pwd,nouv.role,nouv.dc.j,nouv.dc.m,nouv.dc.a,nouv.sexe,nouv.actif);

}
        fclose(f);
        fclose(f2);
remove(filename);
rename("aux.txt", filename);
        return 1;
    }

}

int supprimer(int cin, char * filename)
{
user p;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%d %s %s %s %s %s %d %d %d %d %d \n",&p.cin,p.nom,p.prenom,p.IDETS,p.pwd,p.role,&p.dc.j,&p.dc.m,&p.dc.a,&p.sexe,&p.actif)!=EOF)
{
if(p.cin!=cin)
        fprintf(f2,"%d %s %s %s %s %s %d %d %d %d %d \n",p.cin,p.nom,p.prenom,p.IDETS,p.pwd,p.role,p.dc.j,p.dc.m,p.dc.a,p.sexe,p.actif);

}
        fclose(f);
        fclose(f2);
remove(filename);
rename("aux.txt", filename);
        return 1;
    }

}


user chercher(int cin, char * filename)
{
user p,p1; int tr=0;
    FILE * f=fopen(filename, "r");
 if(f!=NULL )
    {
while(fscanf(f,"%d %s %s %s %s %s %d %d %d %d %d \n",&p.cin,p.nom,p.prenom,p.IDETS,p.pwd,p.role,&p.dc.j,&p.dc.m,&p.dc.a,&p.sexe,&p.actif)!=EOF && tr==0)
{if(cin==p.cin)
tr=1;
p1=p;
}
}
if(tr==0)
p1.cin=-1;
return p1;

}


void userrole(char filename [], char f_role[])
{
user p;
FILE * f=fopen(filename, "r");
FILE * f2=fopen("role.txt", "w");
if(f!=NULL )
{
while(fscanf(f,"%d %s %s %s %s %s %d %d %d %d %d \n",&p.cin,p.nom,p.prenom,p.IDETS,p.pwd,p.role,&p.dc.j,&p.dc.m,&p.dc.a,&p.sexe,&p.actif)!=EOF)
{
if(strcmp(f_role,p.role)==0)
fprintf(f2,"%d %s %s %s %s %s %d %d %d %d %d \n",p.cin,p.nom,p.prenom,p.IDETS,p.pwd,p.role,p.dc.j,p.dc.m,p.dc.a,p.sexe,p.actif);
}
}
fclose(f);
fclose(f2);
}

void pourcentageUSER(char filename[], float * nbHomme, float * nbFemme)
{
user p;
float perc1, perc0;
FILE * f=fopen(filename, "r");
if(f!=NULL )
{
while(fscanf(f,"%d %s %s %s %s %s %d %d %d %d %d \n",&p.cin,p.nom,p.prenom,p.IDETS,p.pwd,p.role,&p.dc.j,&p.dc.m,&p.dc.a,&p.sexe,&p.actif)!=EOF)
{
if(p.sexe==1)
*nbHomme=*nbHomme+1 ;
if(p.sexe==0)
*nbFemme=*nbFemme+1;
}
perc1=(*nbHomme/(*nbHomme+*nbFemme))*100;
perc0=(*nbFemme/(*nbHomme+*nbFemme))*100;
*nbHomme=perc1;
*nbFemme=perc0;
}
fclose(f);
}

//****************************************fct CRUD FEDI********************************************************
//****************************************fct CRUD BOUZID********************************************************
int ajouterGddp(Gddp g , char filename [])
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %d %d %d %d %d\n",g.IdGddp,g.nom,g.TypeSangGddp,g.QuantiteSangGddp,g.dt_gddp.JourGddp,g.dt_gddp.MoisGddp,g.dt_gddp.AnneeGddp,g.urgent);
        fclose(f);
        return 1;
    }
    else return 0;
}

int modifierGddp(char id[], Gddp nouv, char * filename)
{
Gddp g;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%s %s %s %d %d %d %d %d \n",g.IdGddp,g.nom,g.TypeSangGddp,&g.QuantiteSangGddp,&g.dt_gddp.JourGddp,&g.dt_gddp.MoisGddp,&g.dt_gddp.AnneeGddp,&g.urgent)!=EOF)
{
if(strcmp(g.IdGddp,id)!= 0)
        fprintf(f2,"%s %s %s %d %d %d %d %d  \n",g.IdGddp,g.nom,g.TypeSangGddp,g.QuantiteSangGddp,g.dt_gddp.JourGddp,g.dt_gddp.MoisGddp,g.dt_gddp.AnneeGddp,g.urgent);
else

  fprintf(f2,"%s %s %s %d %d %d %d %d \n",nouv.IdGddp,nouv.nom,nouv.TypeSangGddp,nouv.QuantiteSangGddp,nouv.dt_gddp.JourGddp,nouv.dt_gddp.MoisGddp,nouv.dt_gddp.AnneeGddp,nouv.urgent);

}
        fclose(f);
        fclose(f2);
remove(filename);
rename("aux.txt", filename);
        return 1;
    }
  
}

int supprimerGddp(char id[], char * filename)
{
Gddp g;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%s %s %s %d %d %d %d %d\n",g.IdGddp,g.nom,g.TypeSangGddp,&g.QuantiteSangGddp,&g.dt_gddp.JourGddp,&g.dt_gddp.MoisGddp,&g.dt_gddp.AnneeGddp,&g.urgent)!=EOF)
{
if(strcmp(g.IdGddp,id)!=0)
    fprintf(f2,"%s %s %s %d %d %d %d %d\n",g.IdGddp,g.nom,g.TypeSangGddp,g.QuantiteSangGddp,g.dt_gddp.JourGddp,g.dt_gddp.MoisGddp,g.dt_gddp.AnneeGddp,g.urgent);
}
        fclose(f);
        fclose(f2);
remove(filename);
rename("aux.txt", filename);
        return 1;
    }
}

Gddp chercherGddp(char id[], char * filename)
{
Gddp g,g1; int tr=0;
    FILE * f=fopen(filename, "r");
 if(f!=NULL )
    {
while(fscanf(f,"%s %s %s %d %d %d %d %d \n",g.IdGddp,g.nom,g.TypeSangGddp,&g.QuantiteSangGddp,&g.dt_gddp.JourGddp,&g.dt_gddp.MoisGddp,&g.dt_gddp.AnneeGddp,&g.urgent)!=EOF && tr==0)
{if(strcmp(g.IdGddp,id) ==0)
tr=1;
g1=g;
}
}
if(tr==0)
strcpy(g1.IdGddp,"pnt");;
return g1;

}

float pourcentage(char nomFichier[], char demandeur[]) {   
    FILE *file = fopen(nomFichier, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", nomFichier);
        return -1.0; 
    }
    int demandeurCount = 0;
    int totalCount = 0;
    char buffer[256];  
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
       
        if (strstr(buffer, demandeur) != NULL) {
            demandeurCount++;
        }
        totalCount++;
    }
    fclose(file);
     float percentage = (demandeurCount / (float)totalCount) * 100.0;
     return percentage;
}

int QuantiteDemandee_type(char nomFichier[], char ETBdemandeur[]) {
    FILE *file = fopen(nomFichier, "r");

    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", nomFichier);
        return -1;
    }

    int nbdmde= 0, nbtot=0;
    Gddp gddp;

    while (fscanf(file, "%s %s %s %d %d %d %d %d",
                  gddp.IdGddp,gddp.nom,gddp.TypeSangGddp, &gddp.QuantiteSangGddp,
                  &gddp.dt_gddp.JourGddp, &gddp.dt_gddp.MoisGddp, &gddp.dt_gddp.AnneeGddp,
                  &gddp.urgent) != EOF) {
        if (strcmp(gddp.nom, ETBdemandeur) == 0) {
            nbdmde += 1;
        }
	nbtot +=1;
    }

    fclose(file);

    return (double) (nbdmde)/(nbtot)*100;
}

Gddp sang_demande(char nomFichier[]) {
    Gddp p;
    Gddp g;
    char bloodTypes[8][4] = {"A+", "A-", "B+", "B-", "AB+", "AB-", "O+", "O-"};
    int maxQuantite = 0;
    int i;
    FILE *f;
    
    if(f == NULL)
	printf("error file");

    for ( i = 0; i < 8; i++) 
	{
		int quantite = 0;
        	
   		 f=fopen("GDDP.txt","r");
		while(fscanf(f,"%s %s %s %d %d %d %d %d \n",g.IdGddp,g.nom,g.TypeSangGddp,&g.QuantiteSangGddp,&g.dt_gddp.JourGddp,&g.dt_gddp.MoisGddp,&g.dt_gddp.AnneeGddp,&g.urgent)!=EOF)
		{
			if(strcmp(g.TypeSangGddp,bloodTypes[i])==0)
				quantite += g.QuantiteSangGddp;
		}
		

        	if (quantite > maxQuantite) {
            		maxQuantite = quantite;
            		strcpy(p.TypeSangGddp, bloodTypes[i]);
        	}
        	fclose(f);
        	printf("Quantité demandée pour le type %s : %d\n", bloodTypes[i], quantite);
        }

    printf("Type de sang avec la plus grande quantité demandée : %s\n", p.TypeSangGddp);
    return p;
}

//****************************************fct CRUD BOUZID********************************************************
//****************************************fct CRUD WANIS********************************************************
int ajouterFiche(Fiche d, char filename[])
{
    FILE *f = fopen(filename, "a"); 
    if (f != NULL) 
    {
        fprintf(f, "%d %s %s %s %s %d %d/%d/%d %d\n", d.IdDonneur, d.Nom, d.Prenom, d.Sexe, d.GrpSanguin, d.Maladies, d.DateNaissance.Jour, d.DateNaissance.Mois, d.DateNaissance.Annee, d.NumTel);
        fclose(f);
        return 1;
    }
    else
        return 0;
}

int modifierFiche(int id, Fiche nouv, char *filename)
{
    Fiche d;
    FILE *f = fopen(filename, "r");
    FILE *f2 = fopen("nouv.txt", "w");
    if (f == NULL || f2 == NULL)
        return 0;
    while (fscanf(f,"%d %s %s %s %s %d %d/%d/%d %d\n", &d.IdDonneur, d.Nom, d.Prenom, d.Sexe, d.GrpSanguin, &d.Maladies, &d.DateNaissance.Jour, &d.DateNaissance.Mois, &d.DateNaissance.Annee, &d.NumTel) != EOF)
    {
        if (d.IdDonneur != id)
        {
            fprintf(f2,"%d %s %s %s %s %d %d/%d/%d %d\n", d.IdDonneur, d.Nom, d.Prenom, d.Sexe, d.GrpSanguin, d.Maladies, d.DateNaissance.Jour, d.DateNaissance.Mois, d.DateNaissance.Annee, d.NumTel);
        }
        else
            fprintf(f2,"%d %s %s %s %s %d %d/%d/%d %d\n", nouv.IdDonneur, nouv.Nom, nouv.Prenom, nouv.Sexe, nouv.GrpSanguin, nouv.Maladies, nouv.DateNaissance.Jour, nouv.DateNaissance.Mois, nouv.DateNaissance.Annee, nouv.NumTel);
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return 1;
}

int supprimerFiche(int id, char * filename)
{
    Fiche d;
    FILE *f = fopen(filename, "r");
    FILE *f2 = fopen("aux.txt", "w");
    if (f == NULL || f2 == NULL)
        return 0;
    else
{
    while (fscanf(f,"%d %s %s %s %s %d %d/%d/%d %d\n", &d.IdDonneur, d.Nom, d.Prenom, d.Sexe, d.GrpSanguin, &d.Maladies, &d.DateNaissance.Jour, &d.DateNaissance.Mois, &d.DateNaissance.Annee, &d.NumTel) != EOF)
    {
        if (d.IdDonneur != id)
            fprintf(f2, "%d %s %s %s %s %d %d/%d/%d %d\n", d.IdDonneur, d.Nom, d.Prenom, d.Sexe, d.GrpSanguin, d.Maladies, d.DateNaissance.Jour, d.DateNaissance.Mois, d.DateNaissance.Annee, d.NumTel);
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("aux.txt", filename);
    return 1;
}
}

Fiche chercherFiche(int id, char * filename)
{
    Fiche d,d1; int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL )
    {
        while((fscanf(f,"%d %s %s %s %s %d %d/%d/%d %d\n", &d.IdDonneur, d.Nom, d.Prenom, d.Sexe, d.GrpSanguin, &d.Maladies, &d.DateNaissance.Jour, &d.DateNaissance.Mois, &d.DateNaissance.Annee, &d.NumTel)!=EOF)&& (tr==0))

    {
        if(d.IdDonneur==id)
        {
        tr=1;
	d1=d;
        }
    }
    }
    if(tr==0)
    d1.IdDonneur=-1;
    return d1;
}


int listeRDVJour(char filename[], char ETS[], int jour, char mois[] , int annee){
   FILE *f = fopen(filename, "r");
   FILE *f2 = fopen("RDVETSJour.txt", "w");
   if (f == NULL || f2 == NULL)
        return 0;
    else { 
    RDVD rdv;
    int nbRDVJour = 0;
     while (fscanf(f,"%d %s %s %d %s %d",&rdv.RDVcin,rdv.RDVDhoraire,rdv.RDVD_ID_ETS,&rdv.dt_RDVD.RDVDjour,rdv.dt_RDVD.RDVDmois,&rdv.dt_RDVD.RDVDannee)!=EOF) {
              if ((strcmp(rdv.RDVD_ID_ETS, ETS) == 0) && (rdv.dt_RDVD.RDVDjour == jour) && (strcmp(rdv.dt_RDVD.RDVDmois, mois) == 0) && (rdv.dt_RDVD.RDVDannee == annee)) {
                    fprintf(f2,"%d %s %s %d %s %d",rdv.RDVcin,rdv.RDVDhoraire,rdv.RDVD_ID_ETS,rdv.dt_RDVD.RDVDjour,rdv.dt_RDVD.RDVDmois,rdv.dt_RDVD.RDVDannee);
                nbRDVJour++;
        }
    }
    fclose(f);
    fclose(f2);
    return nbRDVJour;
}
}

int listeRDVMois (char filename[], char ETS[], char mois[] , int annee){
   FILE *f = fopen(filename, "r");
   FILE *f2 = fopen("RDVETSMois.txt", "w");
   if (f == NULL || f2 == NULL)
        return 0;
    else { 
    RDVD rdv;
    int nbRDVMois = 0;
     while (fscanf(f,"%d %s %s %d %s %d",&rdv.RDVcin,rdv.RDVDhoraire,rdv.RDVD_ID_ETS,&rdv.dt_RDVD.RDVDjour,rdv.dt_RDVD.RDVDmois,&rdv.dt_RDVD.RDVDannee)!=EOF) {
              if ((strcmp(rdv.RDVD_ID_ETS, ETS) == 0) && (strcmp(rdv.dt_RDVD.RDVDmois, mois) == 0) && (rdv.dt_RDVD.RDVDannee == annee)) {
                    fprintf(f2,"%d %s %s %d %s %d",rdv.RDVcin,rdv.RDVDhoraire,rdv.RDVD_ID_ETS,rdv.dt_RDVD.RDVDjour,rdv.dt_RDVD.RDVDmois,rdv.dt_RDVD.RDVDannee);
                nbRDVMois++;
        }
    }
    fclose(f);
    fclose(f2);
    return nbRDVMois;
}
}

//****************************************fct CRUD WANIS********************************************************
//****************************************fct CRUD RAYEN********************************************************
int ajouterETS(ETS ets , char filename [])
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %d %s %d %s %d %d \n",ets.nom,ets.region,ets.capacite,ets.ID,ets.tel,ets.Adresse,ets.Etat,ets.principal);
        fclose(f);
        return 1;
    }
    else return 0;
}

int modifierETS(char id[], ETS etsnv, char * filename)
{
ETS ets;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%s %s %d %s %d %s %d %d \n",ets.nom,ets.region,&ets.capacite,ets.ID,&ets.tel,ets.Adresse,&ets.Etat,&ets.principal)!=EOF)
{
if(strcmp(ets.ID,id) != 0)
        fprintf(f2,"%s %s %d %s %d %s %d %d \n",ets.nom,ets.region,ets.capacite,ets.ID,ets.tel,ets.Adresse,ets.Etat,ets.principal);
else

  fprintf(f2,"%s %s %d %s %d %s %d %d \n",etsnv.nom,etsnv.region,etsnv.capacite,etsnv.ID,etsnv.tel,etsnv.Adresse,etsnv.Etat,etsnv.principal);

}
        fclose(f);
        fclose(f2);
remove(filename);
rename("aux.txt", filename);
        return 1;
    }

}

int supprimerETS(char id[], char * filename)
{
ETS ets;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%s %s %d %s %d %s %d %d \n",ets.nom,ets.region,&ets.capacite,ets.ID,&ets.tel,ets.Adresse,&ets.Etat,&ets.principal)!=EOF)
{
if(strcmp(ets.ID,id) != 0)
        fprintf(f2,"%s %s %d %s %d %s %d %d \n",ets.nom,ets.region,ets.capacite,ets.ID,ets.tel,ets.Adresse,ets.Etat,ets.principal);

}
        fclose(f);
        fclose(f2);
remove(filename);
rename("aux.txt", filename);
        return 1;
    }
}

ETS chercherETS(char id[], char * filename)
{
ETS ets,ets1; int tr=0;
    FILE * f=fopen(filename, "r");
 if(f!=NULL )
    {
while(fscanf(f,"%s %s %d %s %d %s %d %d \n",ets.nom,ets.region,&ets.capacite,ets.ID,&ets.tel,ets.Adresse,&ets.Etat,&ets.principal)!=EOF && tr==0)
{if(strcmp(ets.ID,id) == 0)
tr=1;
ets1=ets;
}
 fclose(f);
}
if(tr==0)
strcpy(ets1.ID,"PNT");
return ets1;

}


int ETSParRegion(char *filename, char region[], char *aux) {
    FILE *f = fopen(filename, "r");
    FILE *auxdoc = fopen(aux, "w");
    ETS ets;
    int count = 0;

    while (fscanf(f,"%s %s %d %s %d %s %d %d \n",ets.nom,ets.region,&ets.capacite,ets.ID,&ets.tel,ets.Adresse,&ets.Etat,&ets.principal) != EOF) {
        if (strcmp(ets.region, region) == 0) {
            fprintf(auxdoc,"%s %s %d %s %d %s %d %d \n",ets.nom,ets.region,ets.capacite,ets.ID,ets.tel,ets.Adresse,ets.Etat,ets.principal);
            count++;
        }
    }

    fclose(f);
    fclose(auxdoc);

    return count;
}



void ETSTriecapacite(char nomFichier[])
{
  ETS ets,capets[100],tampon;
  int i,n=-1,j,min;
  FILE * f=fopen(nomFichier, "r");
  FILE * f2 =fopen("tricapacite.txt", "w");
  if (f!=NULL && f2!=NULL)
  {
     while(fscanf(f,"%s %s %d %s %d %s %d %d \n",ets.nom,ets.region,&ets.capacite,ets.ID,&ets.tel,ets.Adresse,&ets.Etat,&ets.principal)!=EOF)
     {
        n+=1;
        capets[n]=ets;
     }
     for (i=0;i<=n-1;i++)
     {
       min=i ;
       for (j=i+1;j<=n;j++) 
       {
          if (capets[j].capacite>capets[min].capacite)
               min=j;
       }
       tampon=capets[i];
       capets[i]=capets[min];
       capets[min]=tampon;
     }
     i=0;
     while(i<=n)
     {
       fprintf(f2,"%s %s %d %s %d %s %d %d                 \n",capets[i].nom,capets[i].region,capets[i].capacite,capets[i].ID,capets[i].tel,capets[i].Adresse,capets[i].Etat,capets[i].principal);
       i+=1;
     }
     fclose(f);
     fclose(f2);
  }
  else 
  {
     printf("impossible de faire cette operation");
  }
}

//****************************************fct CRUD RAYEN********************************************************
//******************************************************************************************************************
//*******************************************************fct affichage treeview**************************************

//*******************************************************fct affichage treeview HAZEM**************************************
// Affichage du tree view sangdispo

void afficher_DS(GtkWidget * liste)
{
g_print("liste : %p \n",liste);

GtkCellRenderer *renderer;

GtkTreeViewColumn *column;

GtkTreeIter iter;

GtkListStore *store_ds;


char type_sang[10];

int quantite_sang;

store_ds = NULL;
g_print("store : %p \n",store_ds);
FILE *f;

store_ds = gtk_tree_view_get_model(liste);
g_print("store : %p \n",store_ds);
if(store_ds == NULL)
{

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Type Sang",renderer,"text",TYPE_SANG2,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Quantite Sang",renderer,"text",QUANTITE2,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


g_print("store : %p \n",store_ds);
store_ds = gtk_list_store_new(COLUMNS2, G_TYPE_STRING, G_TYPE_INT);
g_print("store : %p \n",store_ds);

f = fopen("SangDispo.txt","r");
if(f==NULL)
{
return;
}
else
{
f = fopen("SangDispo.txt","r+");
while(fscanf(f,"%s %d \n",type_sang,&quantite_sang)!=EOF)
{
gtk_list_store_append(store_ds, &iter);

gtk_list_store_set(store_ds, &iter, TYPE_SANG2, type_sang, QUANTITE2, quantite_sang, -1);
g_print("store : %p \n",store_ds);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store_ds));
g_print("store : %p \n",store_ds);
g_object_unref(store_ds);
g_print("store : %p \n",store_ds);
}
}
}

// affichage rarité sang

void afficher_RS(GtkLabel *label)
{
char str_q[20];
char space[3] = " ";
Don don3;
don3 = DonSang_Rare("SangDispo.txt");
sprintf(str_q,"%d",don3.QuantiteSangDon);
strcat(don3.TypeSangDon,space);
strcat(don3.TypeSangDon,str_q);
gtk_label_set_text(GTK_LABEL(label),don3.TypeSangDon);
}


//Affichage treeview GSDon

void afficher_GSDon(GtkWidget * liste)
{
GtkCellRenderer *renderer;

GtkTreeViewColumn *column;

GtkTreeIter iter;

GtkListStore *store;

char id_don[20];

char ets[20];

char type_sang[10];

int quantite_sang,cinDon,Ri,ED;
int j,m,a;

store = NULL;
FILE *f;

store = gtk_tree_view_get_model(liste);
if(store == NULL)
{
renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" ID Don",renderer,"text",ID_DON,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Type Sang",renderer,"text",TYPE_SANG,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Quantite Sang",renderer,"text",QUANTITE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Jour",renderer,"text",JOURDON,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Mois",renderer,"text",MOISDON,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Annee",renderer,"text",ANNEEDON,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT);

f = fopen("Dons.txt","r");
if(f==NULL)
{
return;
}
else
{
f = fopen("Dons.txt","r+");
while(fscanf(f,"%s %d %s %d %d/%d/%d %d %d %s ]\n",id_don,&cinDon,type_sang,&quantite_sang,&j,&m,&a,&Ri,&ED,ets)!=EOF)
{
gtk_list_store_append(store, &iter);

gtk_list_store_set(store, &iter, ID_DON, id_don, TYPE_SANG, type_sang, QUANTITE, quantite_sang, JOURDON, j, MOISDON, m, ANNEEDON, a, -1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
}


// affichage treeview epinglement
void Setup_Treeview_GSDon_Epingle(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeModel* store_destination;
GtkTreeIter iter;
FILE* f;

char id_don[20];

char ets[20];

char type_sang[10];

int quantite_sang,cinDon,Ri,ED;
int j,m,a;
store_destination = NULL;

store_destination = gtk_tree_view_get_model(liste);
if(store_destination == NULL)
{
renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" ID Don",renderer,"text",ID_DON,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Type Sang",renderer,"text",TYPE_SANG,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Quantite Sang",renderer,"text",QUANTITE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Jour",renderer,"text",JOURDON,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Mois",renderer,"text",MOISDON,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Annee",renderer,"text",ANNEEDON,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


store_destination = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT);

f = fopen("DonsEpingle.txt","r");
if(f==NULL)
{
return;
}
else
{
f = fopen("DonsEpingle.txt","r+");
while(fscanf(f,"%s %d %s %d %d/%d/%d %d %d %s ]\n",id_don,&cinDon,type_sang,&quantite_sang,&j,&m,&a,&Ri,&ED,ets)!=EOF)
{
gtk_list_store_append(store_destination, &iter);

gtk_list_store_set(store_destination, &iter, ID_DON, id_don, TYPE_SANG, type_sang, QUANTITE, quantite_sang, JOURDON, j, MOISDON, m, ANNEEDON, a, -1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store_destination));
g_object_unref(store_destination);
}
}
}
//*******************************************************fct affichage treeview HAZEM**************************************
//*******************************************************fct affichage treeview AZIZ**************************************
void afficherRDVD(GtkWidget *liste,char nomfichier[])
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	RDVD p;
	store=NULL;
	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Id", renderer, "text", EID,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
		//g_print("renderer : %p",renderer);
		//g_print("column 1 : %p",column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Cin", renderer, "text", ECIN,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Horaire", renderer, "text", EHORAIRE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Etablissement", renderer, "text", EETABLISSEMENT,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Jour", renderer, "text", EJOUR,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Mois", renderer, "text", EMOIS,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Annee", renderer, "text", EANNEE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

		store = gtk_list_store_new(COLUMNS4, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING, G_TYPE_INT);

		//g_print("store : %p",store);
		
		f= fopen(nomfichier,"r");
		//g_print("file : %p",f);
		if(f==NULL)
		{
			return;
		}
		else
		{	
			f= fopen(nomfichier,"a+");
			//g_print("file : %p",f);
			while(fscanf(f,"%d %d %s %s %d %s %d %d \n",&p.RDVDid,&p.RDVcin,p.RDVDhoraire,p.RDVD_ID_ETS,&p.dt_RDVD.RDVDjour,p.dt_RDVD.RDVDmois,&p.dt_RDVD.RDVDannee,&p.RDVDcom)!=EOF)
			{
				//g_print("id : %d",p.RDVDid);
				gtk_list_store_append (store, &iter);
				gtk_list_store_set (store, &iter, EID, p.RDVDid, ECIN, p.RDVcin, EHORAIRE, p.RDVDhoraire, EETABLISSEMENT, p.RDVD_ID_ETS, EJOUR, p.dt_RDVD.RDVDjour, EMOIS, p.dt_RDVD.RDVDmois, EANNEE, p.dt_RDVD.RDVDannee, -1);
			}
			fclose(f);
			//g_print("store : %p",store);
			gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
			g_object_unref (store);
			//g_print("store : %p",store);
		}
	}
}


void afficher_HistoRDV(GtkWidget *liste,char nomfichier[])
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	Don p;
	store=NULL;
	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Id", renderer, "text", HID,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Cin", renderer, "text", HCIN,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Type Du Sang", renderer, "text", HTYPE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Quantite Du Sang", renderer, "text", HQUANTITE,NULL);

		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Jour", renderer, "text", HJOUR,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Mois", renderer, "text", HMOIS,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Annee", renderer, "text", HANNEE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Risque", renderer, "text", HRISQUE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Etat", renderer, "text", HETAT,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

		store = gtk_list_store_new(COLUMNS5, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT);
		
		f= fopen(nomfichier,"r");

		if(f==NULL)
		{
			return;
		}
		else
		{	 f= fopen(nomfichier,"a+");
			while(fscanf(f,"%s %d %s %d %d/%d/%d %d %d %s ]\n",p.IdDon,&p.cinDon,p.TypeSangDon,&p.QuantiteSangDon,&p.dt_don.JourDon,&p.dt_don.MoisDon,&p.dt_don.AnneeDon,&p.Rsq_infDon,&p.Etat_DispDon,p.id_ets)!=EOF)
				{
					gtk_list_store_append (store, &iter);
					gtk_list_store_set (store, &iter, HID, p.IdDon, HCIN, p.cinDon, HTYPE, p.TypeSangDon, HQUANTITE, p.QuantiteSangDon, HJOUR, p.dt_don.JourDon, HMOIS, p.dt_don.MoisDon, HANNEE, p.dt_don.AnneeDon, HRISQUE, p.Rsq_infDon, HETAT, p.Etat_DispDon, -1);
				}
			fclose(f);
			gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
			g_object_unref (store);
		}
	}
}
//*******************************************************fct affichage treeview AZIZ**************************************
//*******************************************************fct affichage treeview FEDI**************************************

void afficher_personne(GtkWidget* liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
int cin;
char nom [50];
char prenom [50];
char IDETS[50];
char pwd[50];
char role [50];
date dc;
int sexe;
int actif;
store=NULL;
FILE *f;
store= GTK_LIST_STORE (gtk_tree_view_get_model(liste));
	if (store==NULL)
	{
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes(" cin",renderer,"text",CIN,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes(" nom",renderer,"text",NOM,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes(" prenom",renderer,"text",PRENOM,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes(" IDETS",renderer,"text",IDET,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes(" password",renderer,"text",PASSWORD,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes(" role",renderer,"text",ROLE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes(" j",renderer,"text",JOUR,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes(" m",renderer,"text",MOIS,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes(" a",renderer,"text",ANNEE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes(" sexe",renderer,"text",SEXE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes(" actif",renderer,"text",ACTIF,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	store=gtk_list_store_new(COLUMNS3,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
		f=fopen("user.txt","r");
		if(f==NULL)
		{
			return;
		}
		else
		{
			f=fopen("user.txt","a+");
			while(fscanf(f,"%d %s %s %s %s %s %d %d %d %d %d \n",&cin,nom,prenom,IDETS,pwd,role,&dc.j,&dc.m,&dc.a,&sexe,&actif)!=EOF)
			{
		gtk_list_store_append (store,&iter);

		gtk_list_store_set (store,&iter,CIN,cin,NOM,nom,PRENOM,prenom,IDET,IDETS,PASSWORD,pwd,ROLE,role,JOUR,dc.j,MOIS,dc.m,ANNEE,dc.a,SEXE,sexe,ACTIF,actif,-1);
			}
			fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		g_object_unref(store);
		}
	}
}

void afficher_role(GtkWidget* liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
int cin;
char nom [10];
char prenom [10];
char IDETS[10];
char pwd[10];
char role [10];
date dc;
int sexe;
int actif;
store=NULL;
FILE *f;
store= GTK_LIST_STORE (gtk_tree_view_get_model(liste));
	if (store==NULL)
	{
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes(" cin",renderer,"text",CIN,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes(" nom",renderer,"text",NOM,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes(" prenom",renderer,"text",PRENOM,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes(" IDETS",renderer,"text",IDET,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes(" pwd",renderer,"text",PASSWORD,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes(" role",renderer,"text",ROLE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes(" j",renderer,"text",JOUR,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes(" m",renderer,"text",MOIS,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes(" a",renderer,"text",ANNEE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes(" sexe",renderer,"text",SEXE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes(" actif",renderer,"text",ACTIF,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	store=gtk_list_store_new(COLUMNS3,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
		f=fopen("user.txt","r");
		if(f==NULL)
		{
			return;
		}
		else
		{
			f=fopen("role.txt","a+");
			while(fscanf(f,"%d %s %s %s %s %s %d %d %d %d %d \n",&cin,nom,prenom,IDETS,pwd,role,&dc.j,&dc.m,&dc.a,&sexe,&actif)!=EOF)
			{
		gtk_list_store_append (store,&iter);	gtk_list_store_set(store,&iter,CIN,cin,NOM,nom,PRENOM,prenom,IDET,IDETS,PASSWORD,pwd,ROLE,role,JOUR,dc.j,MOIS,dc.m,ANNEE,dc.a,SEXE,sexe,ACTIF,actif,-1);
			}
			fclose(f);
		}
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));


	}
}
//*******************************************************fct affichage treeview FEDI**************************************
//*******************************************************fct affichage treeview WANIS**************************************

void afficherFiche (GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	int IdDonneur;
        char Nom[20];
        char Prenom[20];
        char Sexe[10];
        char GrpSanguin [10];
        int Maladies;
        int DateNaissance_Jour;
	int DateNaissance_Mois;
	int DateNaissance_Annee;
        int NumTel;
	store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);

	if (store==NULL)
	{
	renderer=gtk_cell_renderer_text_new();
	column= gtk_tree_view_column_new_with_attributes (" CIN ",renderer,"text",EIDDONNEUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column= gtk_tree_view_column_new_with_attributes (" Nom ",renderer,"text",ENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column= gtk_tree_view_column_new_with_attributes (" Prenom ",renderer,"text",EPRENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
 
	renderer=gtk_cell_renderer_text_new();
	column= gtk_tree_view_column_new_with_attributes (" Sexe ",renderer,"text",ESEXE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column= gtk_tree_view_column_new_with_attributes (" Groupe Sanguin ",renderer,"text",EGRPSANGUIN,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column= gtk_tree_view_column_new_with_attributes(" Maladies ",renderer,"text",EMALADIES,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column= gtk_tree_view_column_new_with_attributes (" JJ ",renderer,"text",EDATENAISSANCEJOUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column= gtk_tree_view_column_new_with_attributes (" MM ",renderer,"text",EDATENAISSANCEMOIS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column= gtk_tree_view_column_new_with_attributes (" ANNEE ",renderer,"text",EDATENAISSANCEANNEE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column= gtk_tree_view_column_new_with_attributes (" tel ",renderer,"text",ENUMTEL,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	store=gtk_list_store_new (COLUMNS6,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
	
	f=fopen("fichesdonneurs.txt","r");
	if (f==NULL)
	{
		return;
	}
	else
	{
		f=fopen("fichesdonneurs.txt","a+");
		while (fscanf(f, " %d %s %s %s %s %d %d/%d/%d %d]\n", &IdDonneur, Nom, Prenom, Sexe, GrpSanguin, &Maladies, &DateNaissance_Jour, &DateNaissance_Mois, &DateNaissance_Annee, &NumTel) != EOF)
		{
		gtk_list_store_append (store,&iter);
		gtk_list_store_set (store,&iter,EIDDONNEUR,IdDonneur,ENOM,Nom,EPRENOM,Prenom,ESEXE,Sexe,EGRPSANGUIN,GrpSanguin,EMALADIES,Maladies,EDATENAISSANCEJOUR,DateNaissance_Jour,EDATENAISSANCEMOIS,DateNaissance_Mois,EDATENAISSANCEANNEE,DateNaissance_Annee,ENUMTEL,NumTel,-1);
		}
	fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
	}
}
}



void afficherRDV (GtkWidget *liste, char IDETS [], int jour, char mois[], int annee)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	int RDVcin;
	char RDVDhoraire[20];
	char RDVD_ID_ETS[50];
	int dt_RDVD_Jour;
	char dt_RDVD_Mois[20];
	int dt_RDVD_Annee;
	store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);

	if (store==NULL)
	{
	renderer=gtk_cell_renderer_text_new();
	column= gtk_tree_view_column_new_with_attributes (" CIN ",renderer,"text",ERDVCIN,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column= gtk_tree_view_column_new_with_attributes (" Horaire ",renderer,"text",ERDVHORAIRE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column= gtk_tree_view_column_new_with_attributes (" ID ETS ",renderer,"text",EIDETS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column= gtk_tree_view_column_new_with_attributes (" RDV JJ ",renderer,"text",EDTRDVDJOUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column= gtk_tree_view_column_new_with_attributes (" RDV MM ",renderer,"text",EDTRDVDMOIS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column= gtk_tree_view_column_new_with_attributes (" RDV ANNEE ",renderer,"text",EDTRDVDANNEE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	store=gtk_list_store_new (COLUMNS7,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT);

	f=fopen("RDVD.txt","r");
	if (f==NULL)
	{
		return;
	}
	else
	{
		f=fopen("RDVD.txt","a+");
		while (fscanf(f, " %d %s %s %d %s %d]\n", &RDVcin, RDVDhoraire, RDVD_ID_ETS, &dt_RDVD_Jour, dt_RDVD_Mois, &dt_RDVD_Annee) != EOF)
		{
 		 if ((strcmp(RDVD_ID_ETS,IDETS)==0)&&(dt_RDVD_Jour==jour)&&(strcmp(dt_RDVD_Mois,mois)==0)&&(dt_RDVD_Annee==annee))
		{
		gtk_list_store_append (store,&iter);
		gtk_list_store_set (store,&iter,ERDVCIN,RDVcin,ERDVHORAIRE,RDVDhoraire,EIDETS,RDVD_ID_ETS,EDTRDVDJOUR,dt_RDVD_Jour,EDTRDVDMOIS,dt_RDVD_Mois,EDTRDVDANNEE,dt_RDVD_Annee,-1);
		}
		}
	fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
	}
}
}


void afficherparID (GtkWidget *liste, int CIND)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	int IdDonneur;
        char Nom[20];
        char Prenom[20];
        char Sexe[10];
        char GrpSanguin [10];
        int Maladies;
        int DateNaissance_Jour;
	int DateNaissance_Mois;
	int DateNaissance_Annee;
        int NumTel;
	store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);

	if (store==NULL)
	{
	renderer=gtk_cell_renderer_text_new();
	column= gtk_tree_view_column_new_with_attributes (" CIN ",renderer,"text",EIDDONNEUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column= gtk_tree_view_column_new_with_attributes (" Nom ",renderer,"text",ENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column= gtk_tree_view_column_new_with_attributes (" Prenom ",renderer,"text",EPRENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
 
	renderer=gtk_cell_renderer_text_new();
	column= gtk_tree_view_column_new_with_attributes (" Sexe ",renderer,"text",ESEXE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column= gtk_tree_view_column_new_with_attributes (" Groupe Sanguin ",renderer,"text",EGRPSANGUIN,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column= gtk_tree_view_column_new_with_attributes(" Maladies ",renderer,"text",EMALADIES,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column= gtk_tree_view_column_new_with_attributes (" JJ ",renderer,"text",EDATENAISSANCEJOUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column= gtk_tree_view_column_new_with_attributes (" MM ",renderer,"text",EDATENAISSANCEMOIS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column= gtk_tree_view_column_new_with_attributes (" ANNEE ",renderer,"text",EDATENAISSANCEANNEE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column= gtk_tree_view_column_new_with_attributes (" tel ",renderer,"text",ENUMTEL,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	store=gtk_list_store_new (COLUMNS6,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
	
	f=fopen("fichesdonneurs.txt","r");
	if (f==NULL)
	{
		return;
	}
	else
	{
		f=fopen("fichesdonneurs.txt","a+");
		while (fscanf(f, " %d %s %s %s %s %d %d/%d/%d %d]\n", &IdDonneur, Nom, Prenom, Sexe, GrpSanguin, &Maladies, &DateNaissance_Jour, &DateNaissance_Mois, &DateNaissance_Annee, &NumTel) != EOF)
		{
		if (IdDonneur==CIND)
		{
		gtk_list_store_append (store,&iter);
		gtk_list_store_set (store,&iter,EIDDONNEUR,IdDonneur,ENOM,Nom,EPRENOM,Prenom,ESEXE,Sexe,EGRPSANGUIN,GrpSanguin,EMALADIES,Maladies,EDATENAISSANCEJOUR,DateNaissance_Jour,EDATENAISSANCEMOIS,DateNaissance_Mois,EDATENAISSANCEANNEE,DateNaissance_Annee,ENUMTEL,NumTel,-1);
		}
		}
	fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
	}
}
}

//*******************************************************fct affichage treeview WANIS**************************************
//*******************************************************fct affichage treeview BOUZID**************************************
void afficher_GDDP(GtkWidget *liste, char namefile[])
{
      GtkCellRenderer *renderer;
      GtkTreeViewColumn *column;
      GtkTreeIter iter;
      GtkListStore *store; 

      char IdGddp[20];
    char nom[20];
    char TypeSangGddp[10];
    int QuantiteSangGddp;
    dateG dt_gddp;
    int urgent;
    store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
{
    	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" IdGddp", renderer, "text",IDG, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column); 

	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" nom" , renderer, "text",NOMG, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" TypeSangGddp" ,  renderer, "text",TYPEG, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" QuantiteSangGddp" , renderer, "text",QUANTITEG, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" Jour" , renderer, "text",JOURG, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" Mois" , renderer, "text",MOISG, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" Annee" , renderer, "text",ANNEEG, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" Urgent" , renderer, "text",URGENTG, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
}
store=gtk_list_store_new (COLUMNS8, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT);

f = fopen(namefile,"r");
if(f==NULL)
{

	return;
}
else
{
	f = fopen(namefile, "a+");
	while(fscanf(f,"%s %s %s %d %d %d %d %d \n",IdGddp,nom,TypeSangGddp,&QuantiteSangGddp,&dt_gddp.JourGddp,&dt_gddp.MoisGddp,&dt_gddp.AnneeGddp,&urgent)!=EOF)
	{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, IDG, IdGddp, NOMG, nom, TYPEG, TypeSangGddp, QUANTITEG, QuantiteSangGddp, JOURG, dt_gddp.JourGddp, MOISG, dt_gddp.MoisGddp, ANNEEG, dt_gddp.AnneeGddp, URGENTG, urgent, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}
//*******************************************************fct affichage treeview BOUZID**************************************
//*******************************************************fct affichage treeview RAYEN**************************************
void afficherETS(GtkWidget *liste,char nomfichier[])
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char nom[50];
    	char region[30];
    	int capacite;
    	char id[20];
    	int tel;
    	char Adresse[30];
    	int Etat;
    	int principal; 
	store=NULL;
	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" nom", renderer, "text",NOME,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" region", renderer, "text",REGIONE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" capacite", renderer, "text",CAPACITEE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" ID", renderer, "text",IDE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" tel", renderer, "text",TELE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Adresse", renderer, "text",ADRESSEE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Etat", renderer, "text",ETATE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Principal", renderer, "text",PRINCIPALE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

		store = gtk_list_store_new(COLUMNS9, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT);
		f= fopen(nomfichier,"r");

		if(f==NULL)
		{
			return;
		}
		else
		{	 f= fopen(nomfichier,"a+");
			while(fscanf(f,"%s %s %d %s %d %s %d %d \n",nom,region,&capacite,id,&tel,Adresse,&Etat,&principal)!=EOF)
				{
					gtk_list_store_append (store, &iter);
					gtk_list_store_set (store, &iter, NOME, nom, REGIONE, region, CAPACITEE, capacite, IDE, id, TELE, tel, ADRESSEE, Adresse, ETATE, Etat, PRINCIPALE, principal, -1);
				}
			fclose(f);
			gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
			g_object_unref (store);
		}
	}
}

//*******************************************************fct affichage treeview RAYEN**************************************
//*******************************************************************************************************
//********************************************fct vider treeview*****************************************


//vider le tree view du DS
void vider_DS(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char type_sang[10];
int quantite_sang;
store = NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Type Sang",renderer,"text",TYPE_SANG2,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Quantite Sang",renderer,"text",QUANTITE2,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}

store=gtk_list_store_new(COLUMNS2, G_TYPE_STRING, G_TYPE_INT);
gtk_list_store_append(store, &iter);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
}

//vider le tree view du GSDon
void vider_GSDon(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char id_don[20];

char type_sang[10];

int quantite_sang,cinDon,Ri,ED;
int j,m,a;
store = NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" ID Don",renderer,"text",ID_DON,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Type Sang",renderer,"text",TYPE_SANG,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Quantite Sang",renderer,"text",QUANTITE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Jour",renderer,"text",JOURDON,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Mois",renderer,"text",MOISDON,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Annee",renderer,"text",ANNEEDON,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}

store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT);
gtk_list_store_append(store, &iter);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
}

//*********************************************************************************************************************************
//******************************************************fct autre*********************************************************************

// intialiser les valeurs de callbacks
void initialiser_valeurAM(int *a,int *b, int *c)
{
*a = 0;
*b = 1;
*c = 100;
}

// resultat du barre recherche dans text view
void TextView_BarreRecherche(GtkTextView *text_view, Don d)
{
GtkTextBuffer *text_buffer;
char str_cindon[30];
char str_quantitesang[10];
char str_jourdon[5];
char str_moisdon[5];
char str_anneedon[10];
char str_risque[5];
char str_dispo[5];
char space[3] = " ";
char text[512] = "";

text_buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
if(strcmp(d.IdDon,"PNT")!=0)
{
sprintf(str_cindon,"%d",d.cinDon);
sprintf(str_quantitesang,"%d",d.QuantiteSangDon);
sprintf(str_jourdon,"%d",d.dt_don.JourDon);
sprintf(str_moisdon,"%d",d.dt_don.MoisDon);
sprintf(str_anneedon,"%d",d.dt_don.AnneeDon);
sprintf(str_risque,"%d",d.Rsq_infDon);
sprintf(str_dispo,"%d",d.Etat_DispDon);
strcat(text,d.IdDon);
strcat(text,space);
strcat(text,str_cindon);
strcat(text,space);
strcat(text,d.TypeSangDon);
strcat(text,space);
strcat(text,str_quantitesang);
strcat(text,space);
strcat(text,str_jourdon);
strcat(text,space);
strcat(text,str_moisdon);
strcat(text,space);
strcat(text,str_anneedon);
strcat(text,space);
strcat(text,str_risque);
strcat(text,space);
strcat(text,str_dispo);
strcat(text,space);
strcat(text,d.id_ets);
gtk_text_buffer_set_text(text_buffer,text,-1);
gtk_text_view_set_buffer(GTK_TEXT_VIEW(text_view),text_buffer);
}
else
{
strcpy(text,"ID Don non trouvee");
gtk_text_buffer_set_text(text_buffer,text,-1);
gtk_text_view_set_buffer(GTK_TEXT_VIEW(text_view),text_buffer);
}
}



// epingle un ROW
void Transfer_Row_Selected(GtkWidget *liste_source)
{
GtkTreeModel *source_model;
GtkTreeSelection *source_selection;
source_model = gtk_tree_view_get_model(liste_source);
source_selection = gtk_tree_view_get_selection(liste_source);
GtkTreeIter iter;
char id_t[20];
Don d2;
if (gtk_tree_selection_get_selected(source_selection, &source_model, &iter)) 
{
// Get data from the selected row in the source TreeView
gchar *data1;

gtk_tree_model_get(source_model, &iter, 0, &data1, -1);  // model 1 columns
// Insert the data into the destination file.
strcpy(id_t,data1);
d2 = chercherDon(id_t, "Dons.txt");
ajouterDon(d2, "DonsEpingle.txt");

g_free(data1);
}
}

int ne_contient_pas_d_espaces(const char *chaine) {
    while (*chaine) {
        if (*chaine == ' ') {
            return 1; 
        }
        chaine++;
    }
    return 0;
}


int valider(int um, char pw[])
{
FILE *f;
int r =0;
user u;
f = fopen("user.txt","r");
while(fscanf(f,"%d %s %s %s %s %s %d %d %d %d %d \n",&u.cin,u.nom,u.prenom,u.IDETS,u.pwd,u.role,&u.dc.j,&u.dc.m,&u.dc.a,&u.sexe,&u.actif)!=EOF)
{
if ((strcmp(pw,u.pwd)==0) && (um == u.cin))
r = 1 ;
}
fclose(f);
return r;
}



