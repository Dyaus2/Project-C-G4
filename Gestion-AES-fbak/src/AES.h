#include <gtk/gtk.h>

//***********************************************************HAZEM***********************************************************
typedef struct
{
    int JourDon,MoisDon,AnneeDon;
}Date;
typedef struct
{
    char IdDon[20];
    int cinDon;
    char TypeSangDon[10];
    int QuantiteSangDon;
    Date dt_don;
    int Rsq_infDon,Etat_DispDon;
    char id_ets[20];
}Don;
// fct CRUD 
int ajouterDon(Don d, char filename []);
int modifierDon(char id[], Don nouv, char * filename);
int supprimerDon(char id[], char * filename);
Don chercherDon(char id[], char * filename);
int DonQuantite_Type(char filename[], char type_sang[]);
void BaseDonnee_QuantiteType(char filename[],char filename2[]);
Don DonSang_Rare(char * filename);
//fct affiche treeview
void afficher_DS(GtkWidget * liste);
void afficher_RS(GtkLabel *label);
void afficher_GSDon(GtkWidget * liste);
void Setup_Treeview_GSDon_Epingle(GtkWidget *liste);
//fct vider treeview
void vider_DS(GtkWidget *liste);
void vider_GSDon(GtkWidget *liste);//ceci pour GSDon normale et epingle

//autres fonctions
void Transfer_Row_Selected(GtkWidget *liste_source);
void TextView_BarreRecherche(GtkTextView *text_view, Don d);
void initialiser_valeurAM(int *a,int *b, int *c);

//***********************************************************HAZEM***********************************************************
//***********************************************************FEDI***********************************************************
typedef struct
{
int j, m, a;
}date;


typedef struct
{
int cin;
char nom [50];
char prenom [50];
char IDETS[50];
char pwd[50];
char role [50];
date dc;
int sexe;
int actif;
}user;

int valider(int um, char pw[]);

int ajouter(user p , char filename []);

int modifier(int cin, user nouv, char * filename);

int supprimer(int cin, char * filename);

user chercher(int cin, char * filename);

void userrole(char filename [], char role[]);

void pourcentageUSER(char filename[], float * nbHomme, float * nbFemme);

void afficher_personne(GtkWidget *liste);

void afficher_role(GtkWidget *liste);

//***********************************************************FEDI***********************************************************
//***********************************************************WANIS***********************************************************
typedef struct {
    int Jour;
    int Mois;
    int Annee;
} Dat;

typedef struct {
    int IdDonneur;
    char Nom[20];
    char Prenom[20];
    char Sexe[10];
    char GrpSanguin [10];
    int Maladies;
    Dat DateNaissance;
    int NumTel;
    char Id_ETS[20];
} Fiche;



int ajouterFiche(Fiche donneur, char filename[]);
int modifierFiche(int id, Fiche nouv, char *filename);
int supprimerFiche(int id, char *filename);
Fiche chercherFiche(int id, char *filename);
int listeRDVJour(char filename[], char ETS[], int jour, char mois[] , int annee); // retourne les nombres total des rdv à un jour donné dans un ETS 
int listeRDVMois(char filename[], char ETS[], char mois[] , int annee); // retourne les nombres total des rdv à un mois donné dans un ETS 
void afficherFiche (GtkWidget *liste);
void afficherparID (GtkWidget *liste, int CIND);
void afficherRDV (GtkWidget *liste, char IDETS [], int jour, char mois[], int annee);
//***********************************************************WANIS***********************************************************
//***********************************************************AZIZ***********************************************************
typedef struct
{
int RDVDjour, RDVDannee;
char RDVDmois[20];
}Daterdv;

typedef struct
{
int RDVDid;
int RDVcin;
char RDVDhoraire[20];
char RDVD_ID_ETS[50];
Daterdv dt_RDVD;
int RDVDcom;
}RDVD;
typedef struct
{
    char nom[50];
    char region[30];
    int capacite;
    char ID[20];
    int tel;
    char Adresse[30];
    int Etat;
    int principal; 
}ets;


int ajouterRDVD(RDVD p , char filename []);
int modifierRDVD(int id, RDVD nouv, char * filename);
int supprimerRDVD(int id, char * filename);
RDVD chercherRDVD(int id, char * filename);
void historiqueRDVD (int CIN, char * filename);
int capaciteRDVD(char ETS[], char * filename, int cp);
int HoraireDispo(char * filename, char ETS[],int capacite, int jour, char mois[] , int annee);
void afficherRDVD(GtkWidget *liste,char nomfichier[]);
void afficher_HistoRDV(GtkWidget *liste,char nomfichier[]);

//***********************************************************AZIZ***********************************************************
//***********************************************************RAYEN***********************************************************
typedef struct
{
    char nom[50];
    char region[30];
    int capacite;
    char ID[20];
    int tel;
    char Adresse[30];
    int Etat;
    int principal; 
}ETS;

int ajouterETS(ETS ets, char filename []);

int modifierETS(char id[], ETS nouv, char * filename);

int supprimerETS(char id[], char * filename);

ETS chercherETS(char id[], char * filename);

int ETSParRegion(char *filename, char region[], char *aux);

void ETSTriecapacite(char nomFichier[]);

void afficherETS(GtkWidget *liste,char nomfichier[]);

int ne_contient_pas_d_espaces(const char *chaine);
//***********************************************************RAYEN***********************************************************
//***********************************************************BOUZID***********************************************************
typedef struct
{
    int JourGddp,MoisGddp,AnneeGddp;
}dateG;
typedef struct
{
    char IdGddp[20];
    char nom[20];
    char TypeSangGddp[10];
    int QuantiteSangGddp;
    dateG dt_gddp;
    int urgent;
   
}Gddp;

int ajouterGddp(Gddp g, char filename []);

int modifierGddp(char id[], Gddp nouv, char * filename);

int supprimerGddp(char id[], char * filename);

Gddp chercherGddp(char id[], char * filename);

float pourcentage(char nomFichier[], char demandeur[]);

int QuantiteSang(char nomFichier[], char typeSang[]);

int QuantiteDemandee_type(char nomFichier[], char typeSang[]);

void afficher_GDDP(GtkWidget *liste, char namefile[]);

Gddp sang_demande(char nomFichier[]);
//***********************************************************BOUZID***********************************************************

