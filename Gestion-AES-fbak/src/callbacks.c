#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "AES.h"
#include <stdlib.h>
#include <glib.h>
#include <string.h>
#include <stdio.h>


//declarations globale

int RI =0,Dispo =1;
int choix_q=100;
int am=1;
char id_don_m[20];
GtkWidget* window_actuela;

int principal=0,dispo=0;
int mode=1;
char iddd[30];

user d99;
int mod=1;
char CINs[50];

Fiche d;
int idd;

char IDETS[30];
int jour,annee,rech=0;
char mois[30];

char ch[5]="9H";
int c=0;
int choice=0;
int intmid=0;

int u=0;
int quantite=0;



void
on_button_GSDon_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
FILE* f;
f = fopen("DonsEpingle.txt","w");
fclose(f);
GtkWidget *window_acc;
GtkWidget *window_gsdon;
GtkWidget *treeview_gsdon;
GtkWidget *treeview_gsdon_epingle;
window_acc = lookup_widget(button, "window_AccDon");
gtk_widget_destroy(window_acc);
window_gsdon = create_window_GSDon();
gtk_widget_show(window_gsdon);
treeview_gsdon=lookup_widget(window_gsdon,"treeview_GSDon");
treeview_gsdon_epingle=lookup_widget(window_gsdon,"treeview_GSDonEpingle");
vider_GSDon(treeview_gsdon_epingle);
afficher_GSDon(treeview_gsdon);
gtk_tree_selection_set_mode(gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview_gsdon)), GTK_SELECTION_SINGLE);
}


void
on_button_DSang_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_acc;
GtkWidget *window_DS;
GtkWidget *treeview_DS;
window_acc = lookup_widget(button, "window_AccDon");
gtk_widget_destroy(window_acc);
window_DS = create_window_DonDS();
gtk_widget_show(window_DS);
treeview_DS=lookup_widget(window_DS, "treeview_DonDS");
BaseDonnee_QuantiteType("SangDispo.txt","Dons.txt");
afficher_DS(treeview_DS);
}


void
on_button_DonAccLogout_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *w_auth;

window = lookup_widget(button,"window_AccDon");
gtk_widget_destroy(window);

w_auth = create_window_auth();
gtk_widget_show(w_auth);
}


void
on_button_RSang_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_acc;
GtkWidget *window_RS;
GtkWidget *label_RS;
window_acc = lookup_widget(button, "window_AccDon");
gtk_widget_destroy(window_acc);
window_RS = create_window_DonRS();
gtk_widget_show(window_RS);
label_RS=lookup_widget(window_RS,"label_DonRSVD");
BaseDonnee_QuantiteType("SangDispo.txt","Dons.txt");
afficher_RS(label_RS);
}


void
on_treeview_GSDon_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkWidget* window_ajoutmodif;
window_actuela = lookup_widget(treeview, "window_GSDon");
GtkWidget* inputID;
GtkWidget* inputCIN;
GtkWidget* inputETS;
GtkWidget* combobox_typesang;
GtkWidget* spinJ;
GtkWidget* spinM;
GtkWidget* spinA;
GtkWidget* RB1;
GtkWidget* RB2;
GtkWidget* RB3;
GtkWidget* RB_custom;
GtkWidget* RB_Dispo;
GtkWidget* RB_NDispo;
GtkWidget* CB_Rsq;
Don d1;
GtkWidget* input_custom;
GtkTreeIter iter;
gchar* id;
gchar *ts;
gint *qs;
gint *jr;
gint *ms;
gint *ae;
gchar *entry_cin;
char entry_custom[20];
char idd[20];


GtkTreeModel *model = gtk_tree_view_get_model(treeview);
am =2;
if(gtk_tree_model_get_iter(model, &iter, path))
{

gtk_tree_model_get(GTK_LIST_STORE(model), &iter, 0, &id, 1, &ts, 2, &qs, 3, &jr, 4, &ms, 5, &ae, -1);


strcpy(idd, id);
d1 = chercherDon(idd, "Dons.txt");
g_print("%s %d %s %d %d/%d/%d %d %d ]\n",d1.IdDon,d1.cinDon,d1.TypeSangDon,d1.QuantiteSangDon,d1.dt_don.JourDon,d1.dt_don.MoisDon,d1.dt_don.AnneeDon,d1.Rsq_infDon,d1.Etat_DispDon);
strcpy(id_don_m,idd);
gtk_widget_hide(window_actuela);

window_ajoutmodif = create_window_GSDonAjoutModif();
gtk_widget_show(window_ajoutmodif);

gtk_widget_destroy(window_actuela);

inputID = lookup_widget(window_ajoutmodif, "entry_GSDonCodeID");
inputCIN = lookup_widget(window_ajoutmodif, "entry_GSDonCIN");
inputETS = lookup_widget(window_ajoutmodif, "entry_GSDonAM_ID_ETS");
combobox_typesang = lookup_widget(window_ajoutmodif, "comboboxentry_GSDonTypeSang");
spinJ = lookup_widget(window_ajoutmodif, "spinbutton_GSDonAMDJour");
spinM = lookup_widget(window_ajoutmodif, "spinbutton_GSDonAMDMois");
spinA = lookup_widget(window_ajoutmodif, "spinbutton_GSDonAMDAnnee");
input_custom = lookup_widget(window_ajoutmodif, "entry_GSDonAMQCustom");
RB1 = lookup_widget(window_ajoutmodif, "radiobutton_GSDonAMQ1");
RB2 = lookup_widget(window_ajoutmodif, "radiobutton_GSDonAMQ2");
RB3 = lookup_widget(window_ajoutmodif, "radiobutton_GSDonAMQ3");
RB_custom = lookup_widget(window_ajoutmodif, "radiobutton_GSDonAMQCustom");
RB_Dispo = lookup_widget(window_ajoutmodif, "radiobutton_GSDonDispo");
RB_NDispo = lookup_widget(window_ajoutmodif, "radiobutton_GSDonNDispo");
CB_Rsq = lookup_widget(window_ajoutmodif, "checkbutton_GSDonRI");

gtk_entry_set_text(GTK_ENTRY(inputID),id);
gtk_entry_set_text(GTK_ENTRY(inputETS),d1.id_ets);

entry_cin = g_strdup_printf("%d",d1.cinDon);
gtk_entry_set_text(GTK_ENTRY(inputCIN),entry_cin);

char Mat[8][5] = {"a+","a-","b+","b-","ab+","ab-","o+","o-"};
int i=0;
while(i<8 && strcmp(Mat[i],d1.TypeSangDon)!=0)
i++;
gtk_combo_box_set_active(GTK_COMBO_BOX(combobox_typesang), i);

switch(d1.QuantiteSangDon)
{
case 100:
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(RB1), TRUE);
break;
case 300:
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(RB2), TRUE);
break;
case 500:
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(RB3), TRUE);
break;
default:
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(RB_custom), TRUE);
sprintf(entry_custom,"%d",d1.QuantiteSangDon);
gtk_entry_set_text(GTK_ENTRY(input_custom),entry_custom);
break;
}

gtk_spin_button_set_value(spinJ, d1.dt_don.JourDon);
gtk_spin_button_set_value(spinM, d1.dt_don.MoisDon);
gtk_spin_button_set_value(spinA, d1.dt_don.AnneeDon);

if(d1.Rsq_infDon == 1)
gtk_toggle_button_set_active(CB_Rsq, TRUE);
else
gtk_toggle_button_set_active(CB_Rsq, FALSE);

if(d1.Etat_DispDon == 1)
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(RB_Dispo), TRUE);
else
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(RB_NDispo), TRUE);

if (id != NULL) 
g_free(id);
if(ts!=NULL)
g_free(ts);
if(entry_cin!=NULL)
g_free(entry_cin);


}
}


void
on_treeview_GSDonEpingle_row_activated (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkWidget* window_ajoutmodif;
window_actuela = lookup_widget(treeview, "window_GSDon");
GtkWidget* inputID;
GtkWidget* inputCIN;
GtkWidget* inputETS;
GtkWidget* combobox_typesang;
GtkWidget* spinJ;
GtkWidget* spinM;
GtkWidget* spinA;
GtkWidget* RB1;
GtkWidget* RB2;
GtkWidget* RB3;
GtkWidget* RB_custom;
GtkWidget* RB_Dispo;
GtkWidget* RB_NDispo;
GtkWidget* CB_Rsq;
Don d1;
GtkWidget* input_custom;
GtkTreeIter iter;
gchar* id;
gchar *ts;
gint *qs;
gint *jr;
gint *ms;
gint *ae;
gchar *entry_cin;
char entry_custom[20];
char idd[20];


GtkTreeModel *model = gtk_tree_view_get_model(treeview);
am =2;
if(gtk_tree_model_get_iter(model, &iter, path))
{

gtk_tree_model_get(GTK_LIST_STORE(model), &iter, 0, &id, 1, &ts, 2, &qs, 3, &jr, 4, &ms, 5, &ae, -1);


strcpy(idd, id);
d1 = chercherDon(idd, "Dons.txt");
g_print("%s %d %s %d %d/%d/%d %d %d ]\n",d1.IdDon,d1.cinDon,d1.TypeSangDon,d1.QuantiteSangDon,d1.dt_don.JourDon,d1.dt_don.MoisDon,d1.dt_don.AnneeDon,d1.Rsq_infDon,d1.Etat_DispDon);
strcpy(id_don_m,idd);
gtk_widget_hide(window_actuela);

window_ajoutmodif = create_window_GSDonAjoutModif();
gtk_widget_show(window_ajoutmodif);

gtk_widget_destroy(window_actuela);

inputID = lookup_widget(window_ajoutmodif, "entry_GSDonCodeID");
inputCIN = lookup_widget(window_ajoutmodif, "entry_GSDonCIN");
inputETS = lookup_widget(window_ajoutmodif, "entry_GSDonAM_ID_ETS");
combobox_typesang = lookup_widget(window_ajoutmodif, "comboboxentry_GSDonTypeSang");
spinJ = lookup_widget(window_ajoutmodif, "spinbutton_GSDonAMDJour");
spinM = lookup_widget(window_ajoutmodif, "spinbutton_GSDonAMDMois");
spinA = lookup_widget(window_ajoutmodif, "spinbutton_GSDonAMDAnnee");
input_custom = lookup_widget(window_ajoutmodif, "entry_GSDonAMQCustom");
RB1 = lookup_widget(window_ajoutmodif, "radiobutton_GSDonAMQ1");
RB2 = lookup_widget(window_ajoutmodif, "radiobutton_GSDonAMQ2");
RB3 = lookup_widget(window_ajoutmodif, "radiobutton_GSDonAMQ3");
RB_custom = lookup_widget(window_ajoutmodif, "radiobutton_GSDonAMQCustom");
RB_Dispo = lookup_widget(window_ajoutmodif, "radiobutton_GSDonDispo");
RB_NDispo = lookup_widget(window_ajoutmodif, "radiobutton_GSDonNDispo");
CB_Rsq = lookup_widget(window_ajoutmodif, "checkbutton_GSDonRI");

gtk_entry_set_text(GTK_ENTRY(inputID),id);
gtk_entry_set_text(GTK_ENTRY(inputETS),d1.id_ets);

entry_cin = g_strdup_printf("%d",d1.cinDon);
gtk_entry_set_text(GTK_ENTRY(inputCIN),entry_cin);

char Mat[8][5] = {"a+","a-","b+","b-","ab+","ab-","o+","o-"};
int i=0;
while(i<8 && strcmp(Mat[i],d1.TypeSangDon)!=0)
i++;
gtk_combo_box_set_active(GTK_COMBO_BOX(combobox_typesang), i);

switch(d1.QuantiteSangDon)
{
case 100:
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(RB1), TRUE);
break;
case 300:
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(RB2), TRUE);
break;
case 500:
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(RB3), TRUE);
break;
default:
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(RB_custom), TRUE);
sprintf(entry_custom,"%d",d1.QuantiteSangDon);
gtk_entry_set_text(GTK_ENTRY(input_custom),entry_custom);
break;
}

gtk_spin_button_set_value(spinJ, d1.dt_don.JourDon);
gtk_spin_button_set_value(spinM, d1.dt_don.MoisDon);
gtk_spin_button_set_value(spinA, d1.dt_don.AnneeDon);

if(d1.Rsq_infDon == 1)
gtk_toggle_button_set_active(CB_Rsq, TRUE);
else
gtk_toggle_button_set_active(CB_Rsq, FALSE);

if(d1.Etat_DispDon == 1)
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(RB_Dispo), TRUE);
else
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(RB_NDispo), TRUE);

if (id != NULL) 
g_free(id);
if(ts!=NULL)
g_free(ts);
if(entry_cin!=NULL)
g_free(entry_cin);


}

}


void
on_button_BRTVGSDon_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* window_gsdon;
GtkTextView* text_viewbr;
GtkWidget* inputbr;
char idbr[20];
Don donbr;

window_gsdon = lookup_widget(button, "window_GSDon");
text_viewbr = lookup_widget(window_gsdon, "textview_GSDonVD");
inputbr = lookup_widget(button, "entry_BRTVGSDon");
strcpy(idbr,gtk_entry_get_text(GTK_ENTRY(inputbr)));
donbr = chercherDon(idbr,"Dons.txt");

TextView_BarreRecherche(text_viewbr, donbr);
}


void
on_button_GSDonActualiser_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *objet = GTK_WIDGET(button);
GtkWidget *window_gsdon,*w1;
GtkWidget *treeview_gsdon;
GtkWidget *treeview_gsdon_e;

w1 = lookup_widget(objet,"window_GSDon");
window_gsdon = create_window_GSDon();

gtk_widget_show(window_gsdon);
gtk_widget_hide(w1);

treeview_gsdon = lookup_widget(window_gsdon, "treeview_GSDon");
treeview_gsdon_e = lookup_widget(window_gsdon, "treeview_GSDonEpingle");

afficher_GSDon(treeview_gsdon);
Setup_Treeview_GSDon_Epingle(treeview_gsdon_e);
}


void
on_button_RetourGSDAcc_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_acc;
GtkWidget *window_gsdon;
GtkWidget *treeview_gsdon;
GtkWidget *treeview_gsdon_epingle;
window_gsdon = lookup_widget(button, "window_GSDon");
treeview_gsdon=lookup_widget(window_gsdon,"treeview_GSDon");
treeview_gsdon_epingle=lookup_widget(window_gsdon,"treeview_GSDonEpingle");
vider_GSDon(treeview_gsdon);
vider_GSDon(treeview_gsdon_epingle);
gtk_widget_destroy(window_gsdon);
window_acc = create_window_AccDon();
gtk_widget_show(window_acc);
}


void
on_button_GSDonSuppr_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_gsdon;
GtkWidget *w1;
GtkWidget *treeview_gsdon;
GtkWidget *treeview_gsdon_actualise;
GtkWidget *treeview_gsdon_epingle;
GtkTreeModel *source_model_gsdon;
GtkTreeSelection *source_selection_gsdon;
GtkTreeModel *source_model_gsdon_epingle;
GtkTreeSelection *source_selection_gsdon_epingle;
GtkTreeIter iter_gsdon;
GtkTreeIter iter_gsdon_epingle;
window_gsdon = lookup_widget(button, "window_GSDon");
treeview_gsdon = lookup_widget(window_gsdon, "treeview_GSDon");
treeview_gsdon_epingle = lookup_widget(window_gsdon, "treeview_GSDonEpingle");
source_model_gsdon = gtk_tree_view_get_model(treeview_gsdon);
source_selection_gsdon = gtk_tree_view_get_selection(treeview_gsdon);
source_model_gsdon_epingle = gtk_tree_view_get_model(treeview_gsdon_epingle);
source_selection_gsdon_epingle = gtk_tree_view_get_selection(treeview_gsdon_epingle);
if (gtk_tree_selection_get_selected(source_selection_gsdon, &source_model_gsdon, &iter_gsdon) && gtk_tree_selection_get_selected(source_selection_gsdon_epingle, &source_model_gsdon_epingle, &iter_gsdon_epingle)) 
return;
if (gtk_tree_selection_get_selected(source_selection_gsdon, &source_model_gsdon, &iter_gsdon))
{
// Get data from the selected row in the source TreeView
gchar *data1;
char idd[20];
gtk_tree_model_get(source_model_gsdon, &iter_gsdon, 0, &data1, -1);  // model 6 columns
strcpy(idd,data1);
// supprimer le don
supprimerDon(idd, "Dons.txt");
supprimerDon(idd, "DonsEpingle.txt");

g_free(data1);
}
if (gtk_tree_selection_get_selected(source_selection_gsdon_epingle, &source_model_gsdon_epingle, &iter_gsdon_epingle))
{
// Get data from the selected row in the source TreeView
gchar *data1;
char idd[20];
gtk_tree_model_get(source_model_gsdon_epingle, &iter_gsdon_epingle, 0, &data1, -1);  // model 6 columns
strcpy(idd,data1);
// supprimer le don
supprimerDon(idd, "Dons.txt");
supprimerDon(idd, "DonsEpingle.txt");

g_free(data1);
}
//actualiser le treeview
w1 = create_window_GSDon();
gtk_widget_show(w1);
gtk_widget_hide(window_gsdon);
treeview_gsdon_actualise = lookup_widget(w1, "treeview_GSDon");
vider_GSDon(treeview_gsdon);
afficher_GSDon(treeview_gsdon_actualise);
}


void
on_button_GSDonEpingle_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* window_gsdon;
GtkWidget* treeview_gsdon;
GtkWidget* treeview_gsdon_epingle;
window_gsdon = lookup_widget(button, "window_GSDon");
treeview_gsdon = lookup_widget(window_gsdon, "treeview_GSDon");
treeview_gsdon_epingle = lookup_widget(window_gsdon, "treeview_GSDonEpingle");
Transfer_Row_Selected(treeview_gsdon);
Setup_Treeview_GSDon_Epingle(treeview_gsdon_epingle);
}


void
on_button_GSDonAjout_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* window_ajoutmodif;
GtkWidget* window_gsdon;
GtkWidget* treeview_gsdon;

am = 1;


window_gsdon = lookup_widget(button, "window_GSDon");
treeview_gsdon = lookup_widget(window_gsdon, "treeview_GSDon");
vider_GSDon(treeview_gsdon);
gtk_widget_destroy(window_gsdon);
window_ajoutmodif = create_window_GSDonAjoutModif();
gtk_widget_show(window_ajoutmodif);
initialiser_valeurAM(&RI,&Dispo,&choix_q);
}


void
on_radiobutton_GSDonAMQ1_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
choix_q = 100;
}


void
on_radiobutton_GSDonAMQ2_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
choix_q = 300;
}


void
on_radiobutton_GSDonAMQ3_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
choix_q = 500;
}


void
on_radiobutton_GSDonAMQCustom_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
choix_q = -1;
}


void
on_radiobutton_GSDonNDispo_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
Dispo =0;
}


void
on_button_RetourAMGSDon_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* window_ajoutmodif;
GtkWidget* window_gsdon;
GtkWidget* treeview_gsdon;

window_ajoutmodif = lookup_widget(button, "window_GSDonAjoutModif");
window_gsdon = create_window_GSDon();
treeview_gsdon = lookup_widget(window_gsdon, "treeview_GSDon");
gtk_widget_destroy(window_ajoutmodif);
gtk_widget_show(window_gsdon);
afficher_GSDon(treeview_gsdon);
}




void
on_button_GSDonAMOK_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* window_gsdon;
GtkWidget* window_ajoutmodif;
GtkWidget* treeview_gsdon;
GtkWidget* inputID;
GtkWidget* inputCIN;
GtkWidget* inputETS;
GtkWidget* combobox_typesang;
GtkWidget* spinJ;
GtkWidget* spinM;
GtkWidget* spinA;
GtkWidget* output_label;
Don d;
char cin[15];
GtkWidget* input_custom;
char custom[10];

window_ajoutmodif = lookup_widget(button, "window_GSDonAjoutModif");

inputID = lookup_widget(button, "entry_GSDonCodeID");
inputCIN = lookup_widget(button, "entry_GSDonCIN");
inputETS = lookup_widget(button, "entry_GSDonAM_ID_ETS");
combobox_typesang = lookup_widget(button, "comboboxentry_GSDonTypeSang");
spinJ = lookup_widget(button, "spinbutton_GSDonAMDJour");
spinM = lookup_widget(button, "spinbutton_GSDonAMDMois");
spinA = lookup_widget(button, "spinbutton_GSDonAMDAnnee");
output_label = lookup_widget(button, "label_GSDonResultatAM");
input_custom = lookup_widget(button, "entry_GSDonAMQCustom");

strcpy(custom,gtk_entry_get_text(GTK_ENTRY(input_custom)));
strcpy(d.IdDon,gtk_entry_get_text(GTK_ENTRY(inputID)));
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(inputCIN)));
d.cinDon = atoi(cin);
strcpy(d.TypeSangDon,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_typesang)));
strcpy(d.id_ets,gtk_entry_get_text(GTK_ENTRY(inputETS)));
d.dt_don.JourDon = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinJ));
d.dt_don.MoisDon = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinM));
d.dt_don.AnneeDon = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinA));
d.Rsq_infDon = RI;
d.Etat_DispDon = Dispo;
if(choix_q != -1)
d.QuantiteSangDon = choix_q;
else
d.QuantiteSangDon = atoi(custom);

if(am == 1)
{
ajouterDon(d, "Dons.txt");
gtk_label_set_text(GTK_LABEL(output_label), "Ajoutee ");
}
if(am == 2)
{
modifierDon(id_don_m, d, "Dons.txt");
modifierDon(id_don_m, d, "DonsEpingle.txt");
gtk_label_set_text(GTK_LABEL(output_label), "Modifiee ");
}
gtk_widget_destroy(window_ajoutmodif);
window_gsdon = create_window_GSDon();
gtk_widget_show(window_gsdon);
treeview_gsdon= lookup_widget(window_gsdon, "treeview_GSDon");
afficher_GSDon(treeview_gsdon);
}


void
on_radiobutton_GSDonDispo_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
Dispo =1;
}


void
on_button_RetourDSAccDon_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_acc;
GtkWidget *window_DS;
GtkWidget *treeview_DS;
window_DS = lookup_widget(button, "window_DonDS");
treeview_DS=lookup_widget(window_DS,"treeview_DonDS");
vider_DS(treeview_DS);
gtk_widget_destroy(window_DS);
window_acc = create_window_AccDon();
gtk_widget_show(window_acc);
}


void
on_button_RetourRSAccDon_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_acc;
GtkWidget *window_RS;
window_RS = lookup_widget(button, "window_DonRS");
gtk_widget_destroy(window_RS);
window_acc = create_window_AccDon();
gtk_widget_show(window_acc);
}


void
on_button_GETSAccLogout_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *w_auth;

window = lookup_widget(button,"window_AccGETS");
gtk_widget_destroy(window);

w_auth = create_window_auth();
gtk_widget_show(w_auth);
}


void
on_button_GETSModif_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *objet=GTK_WIDGET(button);
mode =2;
GtkWidget *window_AccGETS;
GtkWidget *window_GETSModif;
window_AccGETS=lookup_widget(objet,"window_AccGETS");
gtk_widget_destroy(window_AccGETS);
window_GETSModif=create_window_GETSModif();
gtk_widget_show(window_GETSModif);
}


void
on_button_GETSSupprim_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *objet=GTK_WIDGET(button);
GtkWidget *window_AccGETS;
GtkWidget *window_GETSSupprimer;
window_AccGETS=lookup_widget(objet,"window_AccGETS");
gtk_widget_destroy(window_AccGETS);
window_GETSSupprimer=create_window_GETSSupprimer();
gtk_widget_show(window_GETSSupprimer);
}


void
on_button_GETSCapacite_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *objet=GTK_WIDGET(button);
GtkWidget *window_AccGETS;
GtkWidget *window_GETSAfficheCapacite;
window_AccGETS=lookup_widget(objet,"window_AccGETS");
gtk_widget_destroy(window_AccGETS);
window_GETSAfficheCapacite=create_window_GETSAfficheCapacite();
gtk_widget_show(window_GETSAfficheCapacite);
ETSTriecapacite("TEST.txt");
GtkWidget *treeviewAffcap;
treeviewAffcap = lookup_widget(window_GETSAfficheCapacite,"treeviewAffcap");
afficherETS(treeviewAffcap,"tricapacite.txt");

}


void
on_button_GETSRegion_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *objet=GTK_WIDGET(button);
GtkWidget *window_AccGETS;
GtkWidget *window_GETSAfficheRegion;
window_AccGETS=lookup_widget(objet,"window_AccGETS");
gtk_widget_destroy(window_AccGETS);
window_GETSAfficheRegion=create_window_GETSAfficheRegion();
gtk_widget_show(window_GETSAfficheRegion);
}


void
on_button_GETSRecherche_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *objet=GTK_WIDGET(button);
GtkWidget *window_AccGETS;
GtkWidget *window_GETSRecherche;
window_AccGETS=lookup_widget(objet,"window_AccGETS");
gtk_widget_destroy(window_AccGETS);
window_GETSRecherche=create_window_GETSRecherche();
gtk_widget_show(window_GETSRecherche);
}


void
on_button_GETSAjout_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *objet=GTK_WIDGET(button);
mode =1;
GtkWidget *window_AccGETS;
GtkWidget *window_GETSAjoutModif;
window_AccGETS=lookup_widget(objet,"window_AccGETS");
gtk_widget_destroy(window_AccGETS);
window_GETSAjoutModif=create_window_GETSAjoutModif();
gtk_widget_show(window_GETSAjoutModif);
}


void
on_radiobutton_GETSAMEtatEtab_NonDisp_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
{
dispo=0;
}
}


void
on_radiobutton_GETSAMEtatEtab_Disp_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
{
dispo=1;
}
}


void
on_checkbutton_GETSAMPrincipal_toggled (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{
principal=1;
}
}


void
on_button_GETSAMConfirmer_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *objet=GTK_WIDGET(button);
ETS E;
GtkWidget *NOM,*ID,*ADRESSE,*TEL,*REGION,*CAPACITE,*RESULTAT,*PRINCIPAL;
char nom[30],id[30],adresse[30],region[30],resultat[30];
char ch_tel[30];
int tel,capacite;

NOM=lookup_widget(objet,"entry_GETSAMNomEtab");
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(NOM)));

ID=lookup_widget(objet,"entry_GETSAM_IDEtab");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(ID)));

ADRESSE=lookup_widget(objet,"entry_GETSAMAdresseEtab");
strcpy(adresse,gtk_entry_get_text(GTK_ENTRY(ADRESSE)));

TEL=lookup_widget(objet,"entry_GETSAMNumTeleEtab");
strcpy(ch_tel,gtk_entry_get_text(GTK_ENTRY(TEL)));
tel=atoi(ch_tel);

REGION=lookup_widget(objet,"comboboxentry_GETSAMRegionEtab");
strcpy(region,gtk_combo_box_get_active_text(GTK_COMBO_BOX(REGION)));

CAPACITE=lookup_widget(objet,"spinbutton_GETSAMCapEtab");
capacite=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(CAPACITE));

strcpy(E.nom,nom);
strcpy(E.ID,id);
strcpy(E.region,region);
strcpy(E.Adresse,adresse);
E.capacite=capacite;
E.tel=tel;
E.principal=principal;
E.Etat=dispo;


RESULTAT=lookup_widget(objet,"label_GETSAMRes");


gtk_entry_set_text(GTK_ENTRY(NOM),"");

gtk_entry_set_text(GTK_ENTRY(ID),"");

gtk_entry_set_text(GTK_ENTRY(ADRESSE),"");

gtk_entry_set_text(GTK_ENTRY(TEL),"");

gtk_combo_box_set_active(GTK_COMBO_BOX (REGION), 0);

gtk_spin_button_set_value(CAPACITE,100);

PRINCIPAL=lookup_widget(objet,"checkbutton_GETSAMPrincipal");
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(PRINCIPAL),FALSE);


if(mode == 1)
{
ajouterETS(E, "TEST.txt");
gtk_label_set_text(GTK_LABEL(RESULTAT),"Votre etablissement a était bien ajouté");
}
if(mode == 2)
{
modifierETS(iddd, E, "TEST.txt");
gtk_label_set_text(GTK_LABEL(RESULTAT),"Votre etablissement a était bien modifié");
}

}


void
on_button_RetourGETSAMAcc_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *objet=GTK_WIDGET(button);
GtkWidget *window_AccGETS;
GtkWidget *window_GETSAjoutModif;
window_GETSAjoutModif=lookup_widget(objet,"window_GETSAjoutModif");
gtk_widget_destroy(window_GETSAjoutModif);
window_AccGETS=create_window_AccGETS();
gtk_widget_show(window_AccGETS);
GtkWidget *treeviewAcc;
treeviewAcc = lookup_widget(window_AccGETS,"treeviewAcc");
afficherETS(treeviewAcc,"TEST.txt");
}


void
on_button_RetourGETSRechAcc_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *objet=GTK_WIDGET(button);
GtkWidget *window_AccGETS;
GtkWidget *window_GETSRecherche;
window_GETSRecherche=lookup_widget(objet,"window_GETSRecherche");
gtk_widget_destroy(window_GETSRecherche);
window_AccGETS=create_window_AccGETS();
gtk_widget_show(window_AccGETS);
GtkWidget *treeviewAcc;
treeviewAcc = lookup_widget(window_AccGETS,"treeviewAcc");
afficherETS(treeviewAcc,"TEST.txt");
}


void
on_button_GETSRechercheOK_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *objet=GTK_WIDGET(button);
   ETS E;
    GtkWidget *ID, *RESULTAT, *INFO;
    char id[30];
    INFO = lookup_widget(objet, "label_GETSRechercheInfos");
    ID = lookup_widget(objet, "entry_GETSRechercheID");
    RESULTAT = lookup_widget(objet, "label_GETSRech");
    strcpy(id, gtk_entry_get_text(GTK_ENTRY(ID)));
    E = chercherETS(id, "TEST.txt");

    if (strcmp(E.ID, "PNT") == 0) {
        gtk_label_set_text(GTK_LABEL(RESULTAT), "Aucun etablissement avec cet ID!");
        gtk_entry_set_text(GTK_ENTRY(ID), "");
    } else {
        char dispo[30];
        char princ[30];

        if (E.Etat == 1) {
            strcpy(dispo, "disponible");
        } else {
            strcpy(dispo, "non disponible");
        }

        if (E.principal == 1) {
            strcpy(princ, "oui");
        } else {
            strcpy(princ, "non");
        }

        char info[900];
        sprintf(info, "Voila les infos de l'etablissement :\n-Nom: %s\n-Region: %s\n-Capacite: %d\n-ID: %s\n-Adresse: %s\n-Tel: %d\n-Etat: %s\n-Principal=%s",
                E.nom, E.region, E.capacite, E.ID, E.Adresse, E.tel, dispo, princ);

        gtk_label_set_text(GTK_LABEL(RESULTAT), "Votre etblissement existe dans la liste des etablissements.");
        gtk_label_set_text(GTK_LABEL(INFO), info);
	gtk_entry_set_text(GTK_ENTRY(ID), "");
    }
}


void
on_button_GETSSupprimerOK_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *objet=GTK_WIDGET(button);
ETS E;
GtkWidget *ID,*RESULTAT;
char id[30];
ID=lookup_widget(objet,"entry_GETSSupprimerID");
RESULTAT=lookup_widget(objet,"label_GETSSupprimer");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(ID)));
E=chercherETS(id,"TEST.txt");
if (strcmp(E.ID,"PNT") == 0)
{
gtk_label_set_text(GTK_LABEL(RESULTAT),"aucun etablissement avec cet ID!");
gtk_entry_set_text(GTK_ENTRY(ID), "");
}
else
{
supprimerETS(id,"TEST.txt");
gtk_label_set_text(GTK_LABEL(RESULTAT),"Etablissement bien supprimé");
gtk_entry_set_text(GTK_ENTRY(ID), "");

}
}


void
on_button_RetourGETSSupprAcc_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *objet=GTK_WIDGET(button);
GtkWidget *window_AccGETS;
GtkWidget *window_GETSSupprimer;
window_GETSSupprimer=lookup_widget(objet,"window_GETSSupprimer");
gtk_widget_destroy(window_GETSSupprimer);
window_AccGETS=create_window_AccGETS();
gtk_widget_show(window_AccGETS);
GtkWidget *treeviewAcc;
treeviewAcc = lookup_widget(window_AccGETS,"treeviewAcc");
afficherETS(treeviewAcc,"TEST.txt");
}


void
on_button_GETSModifOK_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *objet=GTK_WIDGET(button);
ETS E;
GtkWidget *ID,*RESULTAT;
char id[30];
ID=lookup_widget(objet,"entry_GETSModifID");
RESULTAT=lookup_widget(objet,"label_GETSModif");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(ID)));
E=chercherETS(id,"TEST.txt");
if (strcmp(E.ID,"PNT") == 0)
{
gtk_label_set_text(GTK_LABEL(RESULTAT),"aucun etablissement avec cet ID!");
gtk_entry_set_text(GTK_ENTRY(ID),"");
}
else
{
strcpy(iddd,E.ID);
gtk_label_set_text(GTK_LABEL(RESULTAT),"");
GtkWidget *window_GETSModif;
GtkWidget *window_GETSAjoutModif;
window_GETSModif=lookup_widget(objet,"window_GETSModif");
gtk_widget_destroy(window_GETSModif);
window_GETSAjoutModif=create_window_GETSAjoutModif();
gtk_widget_show(window_GETSAjoutModif);


GtkWidget *NOM,*ID,*ADRESSE,*TEL,*REGION,*CAPACITE,*ETATD,*ETATND,*PRINCIPAL;
char nom[30],id[30],adresse[30],region[30],resultat[30];
char ch_tel[30];
int tel,capacite,i=0;

char tab_region[24][30]={"Ariana","Beja","Bizerte","Benarouss","Tataouine","Tozeur","Tunis","Jendouba","Zeghouane","Siliana","Sousse","SidiBouzid","Sfax","Gabes","kebili","kasserine","Gafsa","Kairouane","Kef","Mednine","Monastir","Menouba","Mehdia","Nabeul"};

NOM=lookup_widget(window_GETSAjoutModif,"entry_GETSAMNomEtab");
gtk_entry_set_text(GTK_ENTRY(NOM),E.nom);

ID=lookup_widget(window_GETSAjoutModif,"entry_GETSAM_IDEtab");
gtk_entry_set_text(GTK_ENTRY(ID),E.ID);

ADRESSE=lookup_widget(window_GETSAjoutModif,"entry_GETSAMAdresseEtab");
gtk_entry_set_text(GTK_ENTRY(ADRESSE),E.Adresse);

TEL=lookup_widget(window_GETSAjoutModif,"entry_GETSAMNumTeleEtab");
sprintf(ch_tel,"%d",E.tel);
gtk_entry_set_text(GTK_ENTRY(TEL),ch_tel);


REGION=lookup_widget(window_GETSAjoutModif,"comboboxentry_GETSAMRegionEtab");
while ((i<23)&&(strcmp(tab_region[i],E.region)!=0))
{
i+=1;
}
gtk_combo_box_set_active(GTK_COMBO_BOX (REGION), i);

CAPACITE=lookup_widget(window_GETSAjoutModif,"spinbutton_GETSAMCapEtab");
gtk_spin_button_set_value(CAPACITE,E.capacite);


ETATD=lookup_widget(window_GETSAjoutModif,"radiobutton_GETSAMEtatEtab_Disp");
ETATND=lookup_widget(window_GETSAjoutModif,"radiobutton_GETSAMEtatEtab_NonDisp");
if (E.Etat==1)
{
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(ETATD),TRUE);
}
else
{
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(ETATND),TRUE);
}

PRINCIPAL=lookup_widget(window_GETSAjoutModif,"checkbutton_GETSAMPrincipal");
if (E.principal==1)
{
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(PRINCIPAL),TRUE);
}



}
}


void
on_button_RetourGETSModifAcc_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *objet=GTK_WIDGET(button);
GtkWidget *window_AccGETS;
GtkWidget *window_GETSModif;
window_GETSModif=lookup_widget(objet,"window_GETSModif");
gtk_widget_destroy(window_GETSModif);
window_AccGETS=create_window_AccGETS();
gtk_widget_show(window_AccGETS);
GtkWidget *treeviewAcc;
treeviewAcc = lookup_widget(window_AccGETS,"treeviewAcc");
afficherETS(treeviewAcc,"TEST.txt");
}


void
on_buttonconfirmerAffReg_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *objet=GTK_WIDGET(button);
GtkWidget *w90;
char nomfichier[60]="FichierETS";
char nomregioncombo[30],nomregion[30];
int s;

GtkWidget *comboboxAffregion;
GtkWidget *window_GETSAfficheRegion;
GtkWidget *treeviewAffregion;
window_GETSAfficheRegion=lookup_widget(objet,"window_GETSAfficheRegion");
comboboxAffregion=lookup_widget(window_GETSAfficheRegion, "comboboxAffregion");



strcpy(nomregion,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxAffregion)));

s=ETSParRegion("TEST.txt",nomregion,"aux.txt");

gtk_widget_destroy(window_GETSAfficheRegion);
w90 = create_window_GETSAfficheRegion();
gtk_widget_show(w90);
treeviewAffregion = lookup_widget(w90,"treeviewAffregion");
afficherETS(treeviewAffregion,"aux.txt");

}


void
on_button_RetourAffRegionAcc_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *objet=GTK_WIDGET(button);
GtkWidget *window_AccGETS;
GtkWidget *window_GETSAfficheRegion;
window_GETSAfficheRegion=lookup_widget(objet,"window_GETSAfficheRegion");
gtk_widget_destroy(window_GETSAfficheRegion);
window_AccGETS=create_window_AccGETS();
gtk_widget_show(window_AccGETS);
GtkWidget *treeviewAcc;
treeviewAcc = lookup_widget(window_AccGETS,"treeviewAcc");
afficherETS(treeviewAcc,"TEST.txt");
}


void
on_button_RetourAffCapAcc_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *objet=GTK_WIDGET(button);
GtkWidget *window_AccGETS;
GtkWidget *window_GETSAfficheCapacite;
window_GETSAfficheCapacite=lookup_widget(objet,"window_GETSAfficheCapacite");
gtk_widget_destroy(window_GETSAfficheCapacite);
window_AccGETS=create_window_AccGETS();
gtk_widget_show(window_AccGETS);
GtkWidget *treeviewAcc;
treeviewAcc = lookup_widget(window_AccGETS,"treeviewAcc");
afficherETS(treeviewAcc,"TEST.txt");
}


void
on_button_AdminAffUserRole_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* objet = GTK_WIDGET(button);
GtkWidget *AccAdmin;
GtkWidget *AdminAffUserRole;
GtkWidget *AdminUserRole;
AccAdmin=lookup_widget(button,"window_AccAdmin");
gtk_widget_destroy(AccAdmin);
AdminAffUserRole=create_window_AdminAffUserRole();
gtk_widget_show(AdminAffUserRole);
}


void
on_button_AdminGUser_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* objet = GTK_WIDGET(button);
GtkWidget *AccAdmin;
GtkWidget *AdminGUsers;
GtkWidget *AdminGU;
AccAdmin = lookup_widget(button,"window_AccAdmin");
gtk_widget_destroy(AccAdmin);
AdminGUsers = create_window_AdminGUsers();
gtk_widget_show(AdminGUsers);
AdminGU=lookup_widget(AdminGUsers,"treeview_AdminGU");
afficher_personne(AdminGU);
}


void
on_button_AdminDashboard_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* objet = GTK_WIDGET(button);
GtkWidget *AccAdmin;
GtkWidget *AdminDashboard;
AccAdmin = lookup_widget(button,"window_AccAdmin");

AdminDashboard = create_window_AdminDashboard();
gtk_widget_show(AdminDashboard);
}


void
on_button_AccAdminLogout_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *w_auth;

window = lookup_widget(button,"window_AccAdmin");
gtk_widget_destroy(window);

w_auth = create_window_auth();
gtk_widget_show(w_auth);
}


void
on_button_AdminUserRoleOK_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* objet = GTK_WIDGET(button);
GtkWidget *CHERCHE;
GtkWidget *AdminUserRole;
GtkWidget *AdminAffUserRole;
char ROLE[50];
AdminAffUserRole=lookup_widget(button,"window_AdminAffUserRole");
CHERCHE=lookup_widget(button,"entry_AdminUserRole");
strcpy(ROLE,gtk_entry_get_text(GTK_ENTRY(CHERCHE)));
userrole("user.txt",ROLE);
AdminUserRole=lookup_widget(AdminAffUserRole,"treeview_AdminUserRole");
afficher_role(AdminUserRole);
}


void
on_button_role_actualiser_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *AdminAffUserRole, *click;
GtkWidget *AdminUserRole;
click=lookup_widget(button,"window_AdminAffUserRole");
AdminAffUserRole=create_window_AdminAffUserRole();
gtk_widget_show(AdminAffUserRole);
gtk_widget_hide(click);
AdminUserRole=lookup_widget(AdminAffUserRole,"treeview_AdminUserRole");
afficher_role(AdminUserRole);
}


void
on_button_RetourAdminUserRoleAcc_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* objet = GTK_WIDGET(button);
GtkWidget *AdminAffUserRole;
GtkWidget *AccAdmin;
AdminAffUserRole = lookup_widget(button,"window_AdminAffUserRole");
gtk_widget_destroy(AdminAffUserRole);
AccAdmin = create_window_AccAdmin();
gtk_widget_show(AccAdmin);
}


void
on_button_AdminGURechOK_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* objet = GTK_WIDGET(button);
GtkWidget *CHERCHE;
GtkWidget* resultat;
char CIN[50];
char eq[100];
char d[100];
int x;
user p;
resultat=lookup_widget(objet, "label_resultat");
CHERCHE=lookup_widget(button,"entry_AdminGURech");
strcpy(CIN,gtk_entry_get_text(GTK_ENTRY(CHERCHE)));
x=atoi(CIN);
p=chercher(x,"user.txt");
if (p.cin == -1)
	gtk_label_set_text(GTK_LABEL(resultat), "user doesn't exist");
else
{
	sprintf(eq,"%s %s %s %s %s %s %d/%d/%d ",CIN,p.nom,p.prenom,p.IDETS,p.pwd,p.role,p.dc.j,p.dc.m,p.dc.a);
	if (p.sexe==1)
		strcat(eq,"MALE");
	if (p.sexe==0)
		strcat(eq,"FEMALE");
	if (p.actif==1)
		strcat(eq," Actif");
	if (p.actif==0)
		strcat(eq," NonActif");
	gtk_label_set_text(GTK_LABEL(resultat), eq);
	g_print(eq);
}
}


void
on_button_user_actualiser_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *AdminGUsers, *click;
GtkWidget *AdminGU;
click=lookup_widget(button,"window_AdminGUsers");
AdminGUsers=create_window_AdminGUsers();
gtk_widget_show(AdminGUsers);
gtk_widget_hide(click);
AdminGU=lookup_widget(AdminGUsers,"treeview_AdminGU");

afficher_personne(AdminGU);
}


void
on_button_AdminGUAjout_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
mod=1;
GtkWidget* objet = GTK_WIDGET(button);
GtkWidget *AdminGUsers;
GtkWidget *AdminGUAM;
AdminGUsers = lookup_widget(button,"window_AdminGUsers");
gtk_widget_destroy(AdminGUsers);
AdminGUAM = create_window_AdminGUAM();
gtk_widget_show(AdminGUAM);
}


void
on_button_AdminGUModif_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
mod=2;
GtkWidget* objet = GTK_WIDGET(button);
GtkWidget *CHERCHE;
GtkWidget* resultat;
GtkWidget* window_actuel;
GtkWidget* window_am;

int x;
user p;
resultat=lookup_widget(objet, "label_resultat");
CHERCHE=lookup_widget(button,"entry_AdminGURech");
strcpy(CINs,gtk_entry_get_text(GTK_ENTRY(CHERCHE)));
x=atoi(CINs);
p=chercher(x,"user.txt");

if(p.cin==-1)
gtk_label_set_text(GTK_LABEL(resultat), "user non existant");
else
{

window_actuel = lookup_widget(objet, "window_AdminGUsers");
gtk_widget_destroy(window_actuel);
window_am = create_window_AdminGUAM();
gtk_widget_show(window_am);

GtkWidget* CIN;
GtkWidget* NOM;
GtkWidget* PRENOM;
GtkWidget* ID;
GtkWidget* PWD;
GtkWidget* ROLE;
GtkWidget* JOUR;
GtkWidget* MOIS;
GtkWidget* ANNEE;
GtkWidget* SEXEM;
GtkWidget* SEXEF;
GtkWidget* ACTIF;



char clas[6][50]={"Admin","RespnsableETS","Medecin","Infermier","Donneur","Employer_Bancaire"};
char fed[50];
int i=0;

CIN =lookup_widget(window_am,"entry_AdminGUAMCIN");
NOM=lookup_widget(window_am,"entry_AdminGUAMNom");
PRENOM=lookup_widget(window_am,"entry_AdminGUAMPrenom");
ID=lookup_widget(window_am,"entry_AdminGUAMID");
PWD=lookup_widget(window_am,"entry_pw");
ROLE=lookup_widget(window_am,"comboboxentry_AdminGUAMRole");
JOUR=lookup_widget(window_am,"spinbutton_AdminGUAMDateCreateJour");
MOIS=lookup_widget(window_am,"spinbutton_AdminGUAMDateCreateMois");
ANNEE=lookup_widget(window_am,"spinbutton_AdminGUAMDateCreateAnnee");
SEXEM=lookup_widget(window_am,"radiobutton_AdminGUAMSexeMale");
SEXEF=lookup_widget(window_am,"radiobutton_AdminGUAMSexeFemale");
ACTIF=lookup_widget(window_am,"checkbutton_AdminGUAMActif");

sprintf(fed,"%d",p.cin);
gtk_entry_set_text(GTK_ENTRY(CIN),fed);
gtk_entry_set_text(GTK_ENTRY(NOM),p.nom);
gtk_entry_set_text(GTK_ENTRY(PRENOM),p.prenom);
gtk_entry_set_text(GTK_ENTRY(ID),p.IDETS);
gtk_entry_set_text(GTK_ENTRY(PWD),p.pwd);

while(i<=6 && strcmp(clas[i],p.role)!=0)
i++;
gtk_combo_box_set_active(GTK_COMBO_BOX(ROLE), i);

gtk_spin_button_set_value(JOUR, p.dc.j);
gtk_spin_button_set_value(MOIS, p.dc.m);
gtk_spin_button_set_value(ANNEE, p.dc.a);

if(p.actif == 1)
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(ACTIF), TRUE);
else
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(ACTIF), FALSE);

if(p.sexe == 1)
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(SEXEM), TRUE);
else
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(SEXEF), TRUE);
}
}


void
on_button_AdminGUSupprim_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* objet = GTK_WIDGET(button);
GtkWidget *CHERCHE;
GtkWidget* resultat;
char Cin[50];
int x,p;
resultat=lookup_widget(objet, "label_resultat");
CHERCHE=lookup_widget(button,"entry_AdminGURech");
strcpy(Cin,gtk_entry_get_text(GTK_ENTRY(CHERCHE)));
x=atoi(Cin);
p=supprimer(x,"user.txt");
if (p=1)
{
gtk_label_set_text(GTK_LABEL(resultat), "user supprimer");
}
if (p!=1)
{
gtk_label_set_text(GTK_LABEL(resultat), "erreur");
}
}


void
on_button_RetourAdminGUAcc_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* objet = GTK_WIDGET(button);
GtkWidget *AdminGUser;
GtkWidget *AccAdmin;
AdminGUser = lookup_widget(button,"window_AdminGUsers");
gtk_widget_destroy(AdminGUser);
AccAdmin = create_window_AccAdmin();
gtk_widget_show(AccAdmin);
}


void
on_radiobutton_AdminGUAMSexeMale_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
d99.sexe=1;
}


void
on_radiobutton_AdminGUAMSexeFemale_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
d99.sexe=0;
}


void
on_checkbutton_AdminGUAMActif_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
d99.actif=1;
else
d99.actif=0;
}


void
on_button_AdminGUAMConfirm_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* objet = GTK_WIDGET(button);
user p;
GtkWidget *CIN;
GtkWidget *NOM;
GtkWidget *PRENOM;
GtkWidget *ID;
GtkWidget *PWD;
GtkWidget *combobox_ROLE;
GtkWidget *JOUR;
GtkWidget *MOIS;
GtkWidget *ANNEE;
GtkWidget *SEXEM, *SEXEF;
GtkWidget *ACTIF;

char Cin[55], cinch[50];
int x;

GtkWidget *AdminGUAM;
GtkWidget *AdminGUsers;
GtkWidget *AdminGU;
AdminGUAM=lookup_widget(button,"window_AdminGUAM");
CIN =lookup_widget(button,"entry_AdminGUAMCIN");
NOM=lookup_widget(button,"entry_AdminGUAMNom");
PRENOM=lookup_widget(button,"entry_AdminGUAMPrenom");
ID=lookup_widget(button,"entry_AdminGUAMID");
PWD=lookup_widget(button,"entry_pw");
combobox_ROLE=lookup_widget(button,"comboboxentry_AdminGUAMRole");
JOUR=lookup_widget(button,"spinbutton_AdminGUAMDateCreateJour");
MOIS=lookup_widget(button,"spinbutton_AdminGUAMDateCreateMois");
ANNEE=lookup_widget(button,"spinbutton_AdminGUAMDateCreateAnnee");
SEXEM=lookup_widget(button,"radiobutton_AdminGUAMSexeMale");
SEXEF=lookup_widget(button,"radiobutton_AdminGUAMSexeFemale");
ACTIF=lookup_widget(button,"checkbutton_AdminGUAMActif");

strcpy(cinch,gtk_entry_get_text(GTK_ENTRY(CIN)));
p.cin= atoi(cinch);
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(NOM)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(PRENOM)));
strcpy(p.IDETS,gtk_entry_get_text(GTK_ENTRY(ID)));
strcpy(p.pwd,gtk_entry_get_text(GTK_ENTRY(PWD)));
strcpy(p.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_ROLE)));
p.dc.j = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(JOUR));
p.dc.m = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(MOIS));
p.dc.a = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(ANNEE));

p.sexe=d99.sexe;
p.actif=d99.actif;

x=atoi(CINs);
if(mod == 1)
{
ajouter(p,"user.txt");
gtk_widget_destroy(AdminGUAM);
AdminGUsers = create_window_AdminGUsers();
gtk_widget_show(AdminGUsers);
AdminGU=lookup_widget(AdminGUsers,"treeview_AdminGU");
afficher_personne(AdminGU);
}
if(mod == 2)
{
modifier(x,p,"user.txt");
gtk_widget_destroy(AdminGUAM);
AdminGUsers = create_window_AdminGUsers();
gtk_widget_show(AdminGUsers);
AdminGU=lookup_widget(AdminGUsers,"treeview_AdminGU");
afficher_personne(AdminGU);
}
}


void
on_button_RetourUserAMGUAdmin_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* objet = GTK_WIDGET(button);
GtkWidget *AdminGUAM;
GtkWidget *AdminGUsers;
AdminGUAM = lookup_widget(button,"window_AdminGUAM");
gtk_widget_destroy(AdminGUAM);
AdminGUsers = create_window_AdminGUsers();
gtk_widget_show(AdminGUsers);
}


void
on_button_AdminDashboardCALCUL_clicked (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* objet = GTK_WIDGET(button);
GtkWidget *MALE;
GtkWidget *FEMME;
float nbHomme=0;
float nbFemme=0;
float *h;
float *f;
char nh[50];
char nf[50];
h=&nbHomme;
f=&nbFemme;
MALE=lookup_widget(GTK_WIDGET(button),"entry_AdminDashboardPM");
FEMME=lookup_widget(GTK_WIDGET(button),"entry_AdminDashboardPF");
pourcentageUSER("user.txt",h,f);
sprintf(nh,"%f",nbHomme);
sprintf(nf,"%f",nbFemme);
gtk_entry_set_text(GTK_ENTRY(MALE),nh);
gtk_entry_set_text(GTK_ENTRY(FEMME),nf);
}


void
on_button_RetourDashAcc_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* objet = GTK_WIDGET(button);
GtkWidget *AdminGUser;
GtkWidget *AccAdmin;
AdminGUser = lookup_widget(button,"window_AdminDashboard");
gtk_widget_destroy(AdminGUser);
AccAdmin = create_window_AccAdmin();
gtk_widget_show(AccAdmin);
}


void
on_button_AccGPSLogout_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *w_auth;

window = lookup_widget(button,"window_AccGDPS");
gtk_widget_destroy(window);

w_auth = create_window_auth();
gtk_widget_show(w_auth);
}


void
on_button_GDPS_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_AccGDPS;
  GtkWidget *window_GDPS;
  GtkWidget *treeview_GDPS;
  
  window_AccGDPS = lookup_widget(button, "window_AccGDPS");
  gtk_widget_destroy (window_AccGDPS);

  window_GDPS = create_window_GDPS();
  gtk_widget_show (window_GDPS);

  treeview_GDPS = lookup_widget(window_GDPS, "treeview_GDPS");
  afficher_GDDP(treeview_GDPS, "GDDP.txt");
}


void
on_button_GDPSPourcentage_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_AccGDPS;
  GtkWidget *window_GDPSPourcentage;
  window_AccGDPS = lookup_widget(button, "window_AccGDPS");
  gtk_widget_destroy (window_AccGDPS);
  window_GDPSPourcentage = create_window_GDPSPourcentage();
  gtk_widget_show (window_GDPSPourcentage);
}


void
on_button_GDPSSangPlusDemande_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
Gddp p;
GtkWidget *label_GDPSSPD;
GtkWidget *window_AccGDPS;
  GtkWidget *window_GDPSSPD;
  window_AccGDPS = lookup_widget(button, "window_AccGDPS");
  gtk_widget_destroy (window_AccGDPS);
  window_GDPSSPD = create_window_GDPSSPD();
  gtk_widget_show (window_GDPSSPD);

p = sang_demande("GDDP.txt");
label_GDPSSPD =lookup_widget(window_GDPSSPD,"label_GDPSSPD");
gtk_label_set_text(GTK_LABEL(label_GDPSSPD),p.TypeSangGddp);
}


void
on_treeview_GDPS_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* IdGddp;
gchar* nom;
gchar* TypeSang;
gint* JourGddp;
gint* MoisGddp;
gint* AnneeGddp;
gint* urgent;
Gddp g;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model, &iter, path))
{
gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &IdGddp, 1, &nom,2, &TypeSang, 3, JourGddp, 4, MoisGddp, 5,AnneeGddp, 6,urgent,  -1);

strcpy(g.IdGddp,IdGddp);
strcpy(g.nom,nom);
strcpy(g.TypeSangGddp,TypeSang);
g.dt_gddp.JourGddp;
g.dt_gddp.MoisGddp;
g.dt_gddp.AnneeGddp;
g.urgent;


supprimerGddp(g.IdGddp,"GDDP.txt");
afficher_GDDP(treeview, "GDDP.txt");

}
}


void
on_button_RetourGDPSAcc_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_GDPS;
  GtkWidget *window_AccGDPS;
  window_GDPS = lookup_widget(button, "window_GDPS");
  gtk_widget_destroy (window_GDPS);
  window_AccGDPS = create_window_AccGDPS();
  gtk_widget_show (window_AccGDPS);
}


void
on_button_GDPSAjout_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
  mod =1;
  GtkWidget *window_GDPS;
  GtkWidget *window_GDPSAjoutModif;
  window_GDPS = lookup_widget(button, "window_GDPS");
  gtk_widget_destroy (window_GDPS);
  window_GDPSAjoutModif = create_window_GDPSAjoutModif();
  gtk_widget_show (window_GDPSAjoutModif);
}


void
on_button_GDPSModif_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
mod=2;
GtkWidget *objet = GTK_WIDGET(button);
GtkWidget *window_actuel;
GtkWidget *window_am;
GtkWidget *CHERCHE;
GtkWidget *output;

Gddp g;
char id[20];
int i=0;
CHERCHE = lookup_widget(objet, "entry_GDPSPourcentage");
output = lookup_widget(objet, "label30");

strcpy(id, gtk_entry_get_text(GTK_ENTRY(CHERCHE)));
strcpy(id_don_m, id);

g = chercherGddp(id, "GDDP.txt");

if (strcmp(g.IdGddp, "PNT") == 0) {
    gtk_label_set_text(GTK_LABEL(output), "Gddp non existant");
} else {
    window_actuel = lookup_widget(objet, "window_GDPS");
    gtk_widget_destroy(window_actuel);
    window_am = create_window_GDPSAjoutModif();
    gtk_widget_show(window_am);

    GtkWidget *GDPSAMID;
    GtkWidget *GPDSAMNomDemande;
    GtkWidget *TypeS;
    GtkWidget *quantite1;
    GtkWidget *quantite2;
    GtkWidget *quantite3;
    GtkWidget *Jour;
    GtkWidget *Mois;
    GtkWidget *Annee;
    GtkWidget *urgent;

	GDPSAMID = lookup_widget(window_am, "entry_GDPSAMID_ETS");
	GPDSAMNomDemande = lookup_widget(window_am, "entry_GPDSAMNomDemande");
	TypeS = lookup_widget(window_am, "comboboxentry_GDPSAMTypeSD");
	quantite1 = lookup_widget(window_am, "radiobutton_GDPSAMQuantite1");
	quantite2 = lookup_widget(window_am, "radiobutton_GDPSAMQuantite2");
	quantite3 = lookup_widget(window_am, "radiobutton_GDPSAMQuantite3");
	Jour = lookup_widget(window_am, "spinbutton_GDPSDateCDJour");
	Mois = lookup_widget(window_am, "spinbutton_GDPSDateCDMois");
	Annee = lookup_widget(window_am, "spinbutton_GDPSDateCDAnnee");
	urgent = lookup_widget(window_am, "checkbutton_GDPSAMUrgent");

	gtk_entry_set_text(GTK_ENTRY(GDPSAMID), g.IdGddp);
	gtk_entry_set_text(GTK_ENTRY(GPDSAMNomDemande), g.nom);

	char sang[8][5]={"O-","O+","B-","B+","A-","A+","AB-","AB+"};
	while(i<=8 && strcmp(sang[i],g.TypeSangGddp)!=0)
		i++;	
	gtk_combo_box_set_active(GTK_COMBO_BOX(TypeS), i);


    if (g.QuantiteSangGddp == 1)
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(quantite1), TRUE);
    else if (g.QuantiteSangGddp == 2)
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(quantite2), TRUE);
    else if (g.QuantiteSangGddp == 3)
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(quantite3), TRUE);

    gtk_spin_button_set_value(Jour, g.dt_gddp.JourGddp);
    gtk_spin_button_set_value(Mois, g.dt_gddp.MoisGddp);
    gtk_spin_button_set_value(Annee, g.dt_gddp.AnneeGddp);

    if (g.urgent == 1)
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(urgent), TRUE);
    else
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(urgent), FALSE);
}

}


void
on_button_RetourGDPSPDAcc_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_GDPSPourcentage;
  GtkWidget *window_AccGDPS;
  window_GDPSPourcentage = lookup_widget(button, "window_GDPSPourcentage");
  gtk_widget_destroy (window_GDPSPourcentage);
  window_AccGDPS = create_window_AccGDPS();
  gtk_widget_show (window_AccGDPS);
}


void
on_button_GDPSPNomDemande_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *entry_GDPSPNomDemande;
  GtkWidget *label_GDPSPourcentage;

  char nom[20];
  char aff[10];
  float p;

  entry_GDPSPNomDemande=lookup_widget(button,"entry_GDPSPNomDemande");
  label_GDPSPourcentage=lookup_widget(button,"label_GDPSPourcentage");

  strcpy(nom,gtk_entry_get_text(GTK_ENTRY(entry_GDPSPNomDemande)));
  p=pourcentage("GDDP.txt",nom);

  sprintf(aff, "%.2f%%", p);
  gtk_label_set_text(GTK_LABEL(label_GDPSPourcentage),aff);
}


void
on_button_RetourGDPSSPDAcc_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_GDPSSPD;
  GtkWidget *window_AccGDPS;
  window_GDPSSPD = lookup_widget(button, "window_GDPSSPD");
  gtk_widget_destroy (window_GDPSSPD);
  window_AccGDPS = create_window_AccGDPS();
  gtk_widget_show (window_AccGDPS);
}


void
on_radiobutton_GDPSAMQuantite1_toggled (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
quantite=1;
}


void
on_radiobutton_GDPSAMQuantite2_toggled (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
quantite=2;
}


void
on_radiobutton_GDPSAMQuantite3_toggled (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
quantite=3;
}




void
on_button_GDPSAMConfirmer_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *GDPSAMID, *GPDSAMNomDemande,*TypeSD,*GDPSAMQuantite1,*GDPSAMQuantite2,*GDPSAMQuantite3,*Jour,*Mois,*Annee,*Urgent;
GtkWidget *window_GDPSAjoutModif;
  GtkWidget *window_GDPS;
  GtkWidget *treeview_GDPS;

Gddp g;

window_GDPSAjoutModif=lookup_widget(button,"window_GDPSAjoutModif");

GDPSAMID=lookup_widget(button,"entry_GDPSAMID_ETS");
GPDSAMNomDemande=lookup_widget(button,"entry_GPDSAMNomDemande");
TypeSD=lookup_widget(button,"comboboxentry_GDPSAMTypeSD");

Jour=lookup_widget(button,"spinbutton_GDPSDateCDJour");
Mois=lookup_widget(button,"spinbutton_GDPSDateCDMois");
Annee=lookup_widget(button,"spinbutton_GDPSDateCDAnnee");



strcpy(g.IdGddp,gtk_entry_get_text(GTK_ENTRY(GDPSAMID)));
strcpy(g.nom,gtk_entry_get_text(GTK_ENTRY(GPDSAMNomDemande)));


strcpy(g.TypeSangGddp, gtk_combo_box_get_active_text(GTK_COMBO_BOX(TypeSD)));

g.QuantiteSangGddp = quantite;
g.dt_gddp.JourGddp = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Jour));
g.dt_gddp.MoisGddp = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Mois));
g.dt_gddp.AnneeGddp = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Annee));
g.urgent=u ;


if(mod == 1)
ajouterGddp(g,"GDDP.txt");
else
modifierGddp(id_don_m,g,"GDDP.txt");


  window_GDPSAjoutModif = lookup_widget(button, "window_GDPSAjoutModif");
  gtk_widget_destroy (window_GDPSAjoutModif);
  window_GDPS = create_window_GDPS();
  gtk_widget_show (window_GDPS);

  treeview_GDPS = lookup_widget(window_GDPS, "treeview_GDPS");
  afficher_GDDP(treeview_GDPS, "GDDP.txt");
}


void
on_button_RetourGDPSAMAff_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_GDPS;
  GtkWidget *window_GDPSAjoutModif;
  window_GDPSAjoutModif = lookup_widget(button, "window_GDPSAjoutModif");
  gtk_widget_destroy (window_GDPSAjoutModif);
  window_GDPS = create_window_GDPS();
  gtk_widget_show (window_GDPS);

}


void
on_button_GFD_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_AccGFD;
  GtkWidget *window_GFD;
  window_AccGFD = lookup_widget(button, "window_AccGFD");
  gtk_widget_destroy (window_AccGFD);
  window_GFD = create_window_GFD ();
  gtk_widget_show (window_GFD);
}


void
on_button_GFD_RDV_ETS_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
  rech=0;
  GtkWidget *window_AccGFD;
  GtkWidget *window_GDF_REV_ETS;
  window_AccGFD = lookup_widget(button, "window_AccGFD");
  gtk_widget_destroy (window_AccGFD);
  window_GDF_REV_ETS = create_window_GDF_REV_ETS ();
  gtk_widget_show (window_GDF_REV_ETS);
}


void
on_button_GFDLogout_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *w_auth;

window = lookup_widget(button,"window_AccGFD");
gtk_widget_destroy(window);

w_auth = create_window_auth();
gtk_widget_show(w_auth);
}


void
on_button_GFDAjout_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
  mode=1;
  GtkWidget *window_GFD;
  GtkWidget *window_GFDAM;
  window_GFD = lookup_widget(button, "window_GFD");
  gtk_widget_destroy (window_GFD);
  window_GFDAM = create_window_GFDAM ();
  gtk_widget_show (window_GFDAM);
}


void
on_button_GFDUpdate_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *window_GFD,*w1;
  GtkWidget *treeview_GFD;
  w1=lookup_widget(button, "window_GFD");
  window_GFD = create_window_GFD();
  gtk_widget_show(window_GFD);
  gtk_widget_hide(w1);
  treeview_GFD=lookup_widget(window_GFD,"treeview_GFD");
  afficherFiche (treeview_GFD);
}


void
on_button_GFDAfficher_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *window_GFD;
  GtkWidget *treeview_GFD;
  window_GFD = lookup_widget(button, "window_GFD");
  treeview_GFD=lookup_widget(window_GFD,"treeview_GFD");
  afficherFiche (treeview_GFD);
}


void
on_button_RetourGFDAcc_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *window_GFD;
  GtkWidget *window_AccGFD;
  window_GFD = lookup_widget(button, "window_GFD");
  gtk_widget_destroy (window_GFD);
  window_AccGFD = create_window_AccGFD ();
  gtk_widget_show (window_AccGFD);
}


void
on_button_GFDModif_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
  mode=2;
  GtkWidget *window_GFD;
  GtkWidget *window_GFDAM;
  GtkWidget *inputCIN;
  GtkWidget *outputCIN;

  char id[20];
  char iddonneur[20];
  char numero[20];
  int idd;
  Fiche p;

  inputCIN = lookup_widget(button, "entry_GFDCINrech");
  outputCIN = lookup_widget(button, "label_GFDRechRes");

  strcpy(id,gtk_entry_get_text(GTK_ENTRY(inputCIN)));
  idd=atoi(id);
  p=chercherFiche(idd,"fichesdonneurs.txt");

  if (p.IdDonneur!=idd)
  {
    gtk_label_set_text(GTK_LABEL(outputCIN), "Fiche non existante");
  }
  else
  {
    p.IdDonneur=idd;
    window_GFD = lookup_widget(button, "window_GFD");
    gtk_widget_destroy (window_GFD);
    window_GFDAM = create_window_GFDAM ();
    gtk_widget_show (window_GFDAM);
 
    GtkWidget *inputNOM, *inputPRENOM, *inputCIN, *inputNUMTEL;
    GtkWidget *comboboxentry_GFDAMGroupSang;
    GtkWidget *spinbutton_GFDAMDateNaissanceJour;
    GtkWidget *spinbutton_GFDAMDateNaissanceMois;
    GtkWidget *spinbutton_GFDAMDateNaissanceAnnee;
    GtkWidget *radiobutton_GDFAMSexeH;
    GtkWidget *radiobutton_GDFAMSexeF;
    GtkWidget *checkbutton_GDFAMAntMed;
   
    char GrpSanguin [8][10]={"A+","A-","B+","B-","AB+","AB-","O+","O-"};
    int i=0;
    inputNOM=lookup_widget(window_GFDAM,"entry_GFDAMNom");
    inputPRENOM=lookup_widget(window_GFDAM,"entry_GFDAMPrenom");
    comboboxentry_GFDAMGroupSang=lookup_widget(window_GFDAM,"comboboxentry_GFDAMGroupSang");
    spinbutton_GFDAMDateNaissanceJour=lookup_widget(window_GFDAM,"spinbutton_GFDAMDateNaissanceJour");
    spinbutton_GFDAMDateNaissanceMois=lookup_widget(window_GFDAM,"spinbutton_GFDAMDateNaissanceMois");
    spinbutton_GFDAMDateNaissanceAnnee=lookup_widget(window_GFDAM,"spinbutton_GFDAMDateNaissanceAnnee");
    inputCIN=lookup_widget(window_GFDAM,"entry_GDFAMCIN");
    inputNUMTEL=lookup_widget(window_GFDAM,"entry_GDFAMNumTele");
    radiobutton_GDFAMSexeH=lookup_widget(window_GFDAM,"radiobutton_GDFAMSexeH");
    radiobutton_GDFAMSexeF=lookup_widget(window_GFDAM,"radiobutton_GDFAMSexeF");
    checkbutton_GDFAMAntMed=lookup_widget(window_GFDAM,"checkbutton_GDFAMAntMed");

    gtk_entry_set_text(GTK_ENTRY(inputNOM),p.Nom);
    gtk_entry_set_text(GTK_ENTRY(inputPRENOM),p.Prenom);
    while((i<8) && (strcmp(GrpSanguin[i],p.GrpSanguin)!=0))
    i++;
    gtk_combo_box_set_active(GTK_COMBO_BOX(comboboxentry_GFDAMGroupSang), i);

    gtk_spin_button_set_value(spinbutton_GFDAMDateNaissanceJour, p.DateNaissance.Jour);
    gtk_spin_button_set_value(spinbutton_GFDAMDateNaissanceMois, p.DateNaissance.Mois);
    gtk_spin_button_set_value(spinbutton_GFDAMDateNaissanceAnnee, p.DateNaissance.Annee);

    sprintf(iddonneur, "%d" , p.IdDonneur);
    gtk_entry_set_text(GTK_ENTRY(inputCIN),iddonneur);
    sprintf(numero, "%d" , p.NumTel);
    gtk_entry_set_text(GTK_ENTRY(inputNUMTEL),numero);

    if(strcmp(p.Sexe,"Homme")==0) {
    gtk_toggle_button_set_active(GTK_RADIO_BUTTON(radiobutton_GDFAMSexeH), TRUE);}
    else
    { gtk_toggle_button_set_active(GTK_RADIO_BUTTON(radiobutton_GDFAMSexeF), TRUE);}

    if(p.Maladies == 1) {
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkbutton_GDFAMAntMed),TRUE);}
    else
    {gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkbutton_GDFAMAntMed),FALSE);}
}
}


void
on_button_GFDRechercher_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_GFD;
  GtkWidget *w1;
  GtkWidget *treeview_GFD;
  GtkWidget *inputCIN;
  GtkWidget *outputCIN;

  Fiche p;
  char cin [15];
  int cin1;

  window_GFD = lookup_widget(button, "window_GFD");
  inputCIN = lookup_widget(button, "entry_GFDCINrech");
  outputCIN = lookup_widget(button, "label_GFDRechRes");

  strcpy(cin,gtk_entry_get_text(GTK_ENTRY(inputCIN)));
  cin1=atoi(cin);
  p=chercherFiche(cin1,"fichesdonneurs.txt");
  if (p.IdDonneur==-1)
  {
   gtk_label_set_text(GTK_LABEL(outputCIN), "Fiche non existante");
  }
  else
  {
  gtk_label_set_text(GTK_LABEL(outputCIN), "la fiche est trouvée");
  gtk_widget_hide(window_GFD);
  w1 = create_window_GFD();
  gtk_widget_show(w1);
  treeview_GFD = lookup_widget(w1, "treeview_GFD");
  afficherparID (treeview_GFD, cin1);
  }
}


void
on_button_GFDSupprim_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_GFD;
  GtkWidget *inputCIN;
  GtkWidget *outputCIN;
  Fiche p;
  char cin [15];
  int cin1;
  inputCIN = lookup_widget(button, "entry_GFDCINrech");
  outputCIN = lookup_widget(button, "label_GFDSupprimRes");
  strcpy(cin,gtk_entry_get_text(GTK_ENTRY(inputCIN)));
  cin1=atoi(cin);
  p=chercherFiche(cin1,"fichesdonneurs.txt");
  if (p.IdDonneur!=cin1)
  {gtk_label_set_text(GTK_LABEL(outputCIN), "Fiche non existante");}
  else
  { 
    supprimerFiche(cin1,"fichesdonneurs.txt");
    gtk_label_set_text(GTK_LABEL(outputCIN), "Fiche supprimée");
  }
}


void
on_button_GDFAMConfirmer_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *inputNOM, *inputPRENOM, *inputCIN, *inputNUMTEL;
GtkWidget *window_GDFAM;
GtkWidget *comboboxentry_GFDAMGroupSang;
GtkWidget *spinbutton_GFDAMDateNaissanceJour;
GtkWidget *spinbutton_GFDAMDateNaissanceMois;
GtkWidget *spinbutton_GFDAMDateNaissanceAnnee;
GtkWidget *radiobutton_GDFAMSexeH;
GtkWidget *radiobutton_GDFAMSexeF;
GtkWidget *checkbutton_GDFAMAntMed;

Fiche p;
char numero[20];
char CIN [30];
char cin [15];

window_GDFAM=lookup_widget(button,"window_GFDAM");

inputNOM=lookup_widget(button,"entry_GFDAMNom");
inputPRENOM=lookup_widget(button,"entry_GFDAMPrenom");
comboboxentry_GFDAMGroupSang=lookup_widget(button,"comboboxentry_GFDAMGroupSang");
spinbutton_GFDAMDateNaissanceJour=lookup_widget(button,"spinbutton_GFDAMDateNaissanceJour");
spinbutton_GFDAMDateNaissanceMois=lookup_widget(button,"spinbutton_GFDAMDateNaissanceMois");
spinbutton_GFDAMDateNaissanceAnnee=lookup_widget(button,"spinbutton_GFDAMDateNaissanceAnnee");
inputCIN=lookup_widget(button,"entry_GDFAMCIN");
inputNUMTEL=lookup_widget(button,"entry_GDFAMNumTele");
radiobutton_GDFAMSexeH=lookup_widget(button,"radiobutton_GDFAMSexeH");
radiobutton_GDFAMSexeF=lookup_widget(button,"radiobutton_GDFAMSexeF");
checkbutton_GDFAMAntMed=lookup_widget(button,"checkbutton_GDFAMAntMed");


strcpy (p.Nom,gtk_entry_get_text(GTK_ENTRY(inputNOM)));
strcpy (p.Prenom,gtk_entry_get_text(GTK_ENTRY(inputPRENOM)));
strcpy (p.GrpSanguin, gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry_GFDAMGroupSang)));
p.DateNaissance.Jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_GFDAMDateNaissanceJour));
p.DateNaissance.Mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_GFDAMDateNaissanceMois));
p.DateNaissance.Annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_GFDAMDateNaissanceAnnee));
strcpy (CIN,gtk_entry_get_text(GTK_ENTRY(inputCIN)));
p.IdDonneur=atoi(CIN);
idd=atoi(CIN);
strcpy (numero,gtk_entry_get_text(GTK_ENTRY(inputNUMTEL)));
p.NumTel=atoi(numero);
strcpy(p.Sexe,d.Sexe);
p.Maladies=d.Maladies;

if(mode == 1) 
{
ajouterFiche(p,"fichesdonneurs.txt");
}
if(mode == 2)
{
modifierFiche(idd,p,"fichesdonneurs.txt");
}
}


void
on_button_RetourGDFAMAff_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_GFDAM;
  GtkWidget *window_GFD;
  window_GFDAM = lookup_widget(button, "window_GFDAM");
  gtk_widget_destroy (window_GFDAM);
  window_GFD = create_window_GFD ();
  gtk_widget_show (window_GFD);
}


void
on_radiobutton_GDFAMSexeF_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
strcpy(d.Sexe,"Femme");
}


void
on_radiobutton_GDFAMSexeH_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
strcpy(d.Sexe,"Homme");
}


void
on_checkbutton_GDFAMAntMed_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
d.Maladies=0;
if (gtk_toggle_button_get_active(togglebutton))
{d.Maladies=1;}
}


void
on_button_RetourGDFRDVAcc_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *window_GDF_REV_ETS;
  GtkWidget *window_AccGFD;
  window_GDF_REV_ETS = lookup_widget(button, "window_GDF_REV_ETS");
  gtk_widget_destroy (window_GDF_REV_ETS);
  window_AccGFD = create_window_AccGFD ();
  gtk_widget_show (window_AccGFD);
}


void
on_button_GDFRDVETS_Calculer_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *window_GDF_REV_ETS;
  GtkWidget *inputIDETS;
  GtkWidget *spinbutton_GDFRDV_DateJour;
  GtkWidget *combobox_GDFRDV_DateMois;
  GtkWidget *spinbutton_GDFRDV_DateAnnee;
  GtkWidget *outputTOTALRDV;
  GtkWidget *outputMOYRDV;

  RDVD RDV;
  char IDETS[30];
  int jour,annee,totalj,totalm;
  char mois[30];
  char totall[30];
  char moyy[30];
  float moy;

  inputIDETS = lookup_widget(button, "entry_GDFRDV_IDETS");
  spinbutton_GDFRDV_DateJour=lookup_widget(button,"spinbutton_GDFRDV_DateJour");
  combobox_GDFRDV_DateMois=lookup_widget(button,"combobox_GDFRDV_DateMois");
  spinbutton_GDFRDV_DateAnnee=lookup_widget(button,"spinbutton_GDFRDV_DateAnnee");
  outputTOTALRDV = lookup_widget(button, "label_GDFRDVDeco20");
  outputMOYRDV = lookup_widget(button, "label_GDFMoyRDV1");

  strcpy (IDETS,gtk_entry_get_text(GTK_ENTRY(inputIDETS)));
  jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_GDFRDV_DateJour));
  strcpy (mois, gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_GDFRDV_DateMois)));
  annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_GDFRDV_DateAnnee));

  totalj=listeRDVJour("RDVD.txt",IDETS,jour,mois,annee);
  totalm=listeRDVMois("RDVD.txt",IDETS,mois,annee);
  moy= (float) totalj/totalm;
  sprintf(totall,"%d",totalj);
  sprintf(moyy,"%.2f",moy);

  gtk_label_set_text(GTK_LABEL(outputTOTALRDV),totall);
  gtk_label_set_text(GTK_LABEL(outputMOYRDV),moyy);
}


void
on_button_GDFRDVChercher_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *inputIDETS;
  GtkWidget *spinbutton_GDFRDV_DateJour;
  GtkWidget *combobox_GDFRDV_DateMois;
  GtkWidget *spinbutton_GDFRDV_DateAnnee;
  GtkWidget *window_GDF_REV_ETS,*w1;
  GtkWidget *treeview_GDFRDVETS;
  char Mat[12][20] = {"Janvier","Fevrier","Mars","Avril","May","Juin","Juillet","Aout","Septembre","Octobre","Novembre","Decembre"};
  int i=0;

  if(rech == 0)
  {
  inputIDETS = lookup_widget(button, "entry_GDFRDV_IDETS");
  spinbutton_GDFRDV_DateJour=lookup_widget(button,"spinbutton_GDFRDV_DateJour");
  combobox_GDFRDV_DateMois=lookup_widget(button,"combobox_GDFRDV_DateMois");
  spinbutton_GDFRDV_DateAnnee=lookup_widget(button,"spinbutton_GDFRDV_DateAnnee");
  window_GDF_REV_ETS = lookup_widget(button, "window_GDF_REV_ETS");
  treeview_GDFRDVETS=lookup_widget(window_GDF_REV_ETS,"treeview_GDFRDVETS");
  rech = 1;
  }
  if(rech == 1)
  {
  inputIDETS = lookup_widget(button, "entry_GDFRDV_IDETS");
  spinbutton_GDFRDV_DateJour=lookup_widget(button,"spinbutton_GDFRDV_DateJour");
  combobox_GDFRDV_DateMois=lookup_widget(button,"combobox_GDFRDV_DateMois");
  spinbutton_GDFRDV_DateAnnee=lookup_widget(button,"spinbutton_GDFRDV_DateAnnee");
  strcpy (IDETS,gtk_entry_get_text(GTK_ENTRY(inputIDETS)));
  jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_GDFRDV_DateJour));
  strcpy (mois, gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_GDFRDV_DateMois)));
  annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_GDFRDV_DateAnnee));

  w1 = lookup_widget(button, "window_GDF_REV_ETS");
  gtk_widget_hide(w1);
  window_GDF_REV_ETS = create_window_GDF_REV_ETS();
  gtk_widget_show(window_GDF_REV_ETS);
  inputIDETS = lookup_widget(window_GDF_REV_ETS, "entry_GDFRDV_IDETS");
  spinbutton_GDFRDV_DateJour=lookup_widget(window_GDF_REV_ETS,"spinbutton_GDFRDV_DateJour");
  combobox_GDFRDV_DateMois=lookup_widget(window_GDF_REV_ETS,"combobox_GDFRDV_DateMois");
  spinbutton_GDFRDV_DateAnnee=lookup_widget(window_GDF_REV_ETS,"spinbutton_GDFRDV_DateAnnee");
  gtk_entry_set_text(GTK_ENTRY(inputIDETS),IDETS);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton_GDFRDV_DateJour),jour);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton_GDFRDV_DateAnnee),annee);
  while(i<12 && strcmp(mois,Mat[i])!=0)
  i++;
  gtk_combo_box_set_active(GTK_COMBO_BOX(combobox_GDFRDV_DateMois),i);
  treeview_GDFRDVETS=lookup_widget(window_GDF_REV_ETS,"treeview_GDFRDVETS");
  }

  strcpy (IDETS,gtk_entry_get_text(GTK_ENTRY(inputIDETS)));
  jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_GDFRDV_DateJour));
  strcpy (mois, gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_GDFRDV_DateMois)));
  annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_GDFRDV_DateAnnee));
  afficherRDV (treeview_GDFRDVETS,IDETS,jour,mois,annee);
}


void
on_button_GRDVDHistorique_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *window_AccGRDVD;
  GtkWidget *window_GRDVDHistorique;
  GtkWidget *treeview_GRDVDHistorique;

  window_AccGRDVD = lookup_widget(button, "window_AccGRDVD");
  gtk_widget_destroy (window_AccGRDVD);
  window_GRDVDHistorique = create_window_GRDVDHistorique ();
  gtk_widget_show (window_GRDVDHistorique);

  treeview_GRDVDHistorique = lookup_widget(window_GRDVDHistorique,"treeview_GRDVDHistorique");
  afficher_HistoRDV(treeview_GRDVDHistorique,"Dons.txt");
}


void
on_button_GRDVD_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *window_AccGRDVD;
  GtkWidget *window_GRDVD;
  GtkWidget *treeview_GRDVD;

  window_AccGRDVD = lookup_widget(button, "window_AccGRDVD");

  gtk_widget_destroy(window_AccGRDVD);
  window_GRDVD = create_window_GRDVD ();
  gtk_widget_show (window_GRDVD);
  
  treeview_GRDVD = lookup_widget(window_GRDVD,"treeview_GRDVD");
  afficherRDVD(treeview_GRDVD,"RDV.txt");
}



void
on_button_GRDVDDisponibilite_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *window_AccGRDVD;
  GtkWidget *window_GRDVDCrenaux1;

  window_AccGRDVD = lookup_widget(button, "window_AccGRDVD");
  gtk_widget_destroy (window_AccGRDVD);
  window_GRDVDCrenaux1 = create_window_GRDVDCrenaux1 ();
  gtk_widget_show (window_GRDVDCrenaux1);
}


void
on_button_GRDVDLogout_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *w_auth;

window = lookup_widget(button,"window_AccGRDVD");
gtk_widget_destroy(window);

w_auth = create_window_auth();
gtk_widget_show(w_auth);
}


void
on_button_RetourHistoAcc_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *window_GRDVDHistorique;
  GtkWidget *window_AccGRDVD;
  window_GRDVDHistorique = lookup_widget(button, "window_GRDVDHistorique");
  gtk_widget_destroy (window_GRDVDHistorique);
  window_AccGRDVD = create_window_AccGRDVD ();
  gtk_widget_show (window_AccGRDVD);
}


void
on_button_GRDVDH_IDOK_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *entry_GRDVDH_ID;
  GtkWidget *window_GRDVDHistorique;
  GtkWidget *treeview_GRDVDHistorique;

  int H_cin;
  char E_cin[20];
  
  entry_GRDVDH_ID=lookup_widget(button,"entry_GRDVDH_ID");
  
  strcpy(E_cin,gtk_entry_get_text(GTK_ENTRY(entry_GRDVDH_ID)));
  H_cin = atoi(E_cin);
  historiqueRDVD(H_cin,"Dons.txt");

  window_GRDVDHistorique = lookup_widget(button, "window_GRDVDHistorique");
  gtk_widget_destroy (window_GRDVDHistorique);
  window_GRDVDHistorique = create_window_GRDVDHistorique ();
  gtk_widget_show (window_GRDVDHistorique);

  treeview_GRDVDHistorique = lookup_widget(window_GRDVDHistorique,"treeview_GRDVDHistorique");
  afficher_HistoRDV(treeview_GRDVDHistorique,"HistoRDV.txt");
}


void
on_button_RetourGRDVDAcc_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *window_GRDVD;
  GtkWidget *window_AccGRDVD;
  window_GRDVD = lookup_widget(button, "window_GRDVD");
  gtk_widget_destroy (window_GRDVD);
  window_AccGRDVD = create_window_AccGRDVD ();
  gtk_widget_show (window_AccGRDVD);
}



void
on_button_GRDVDAjout_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *window_GRDVD;
  GtkWidget *window_GRDVDAM;
  choice=0;
  window_GRDVD = lookup_widget(button, "window_GRDVD");
  gtk_widget_destroy (window_GRDVD);
  window_GRDVDAM = create_window_GRDVDAM ();
  gtk_widget_show (window_GRDVDAM);
}


void
on_button_GRDVDModif_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *win_GRDVD;
  GtkWidget *win_GRDVDAM;
  GtkWidget *treeview_GRDVD;
  GtkWidget *entry_Chercher;
  GtkWidget *entry_ID;
  GtkWidget *entry_IDETS;
  GtkWidget *entry_CIN;
  GtkWidget *spinbutton_DateJour;
  GtkWidget *spinbutton_DateAnnee;
  GtkWidget *comboboxentry_DateMois;
  GtkWidget *checkbutton_Confirmer;
  GtkWidget *radiobutton_Cren1;
  GtkWidget *radiobutton_Cren2;
  GtkWidget *radiobutton_Cren3;
  GtkWidget *radiobutton_Cren4;
  char chmid[20];
  char idaff[20];
  char cinaff[20];
  int i=0;
  char mois[12][10]={"Janvier","Fevrier","Mars","Avril","Mai","Juin","Juillet","Aout","Septembre","Octobre","Novembre","Decembre"};
  RDVD p;

  choice=1;

  entry_Chercher=lookup_widget(button,"entry_GRDVDChercher");
  strcpy(chmid,gtk_entry_get_text(GTK_ENTRY(entry_Chercher)));
  intmid = atoi(chmid);

  win_GRDVD = lookup_widget(button, "window_GRDVD");
  gtk_widget_destroy (win_GRDVD);
  
  win_GRDVDAM = create_window_GRDVDAM ();
  gtk_widget_show (win_GRDVDAM);

  if(intmid!=0)
  {
	entry_ID=lookup_widget(win_GRDVDAM,"entry_GRDVDAMID");
	entry_IDETS=lookup_widget(win_GRDVDAM,"entry_GRDVDAM_IDETS");
	entry_CIN=lookup_widget(win_GRDVDAM,"entry4");
	spinbutton_DateJour=lookup_widget(win_GRDVDAM,"spinbutton_GRDVDAMDateJour");
	spinbutton_DateAnnee=lookup_widget(win_GRDVDAM,"spinbutton_GRDVDAMDateAnnee");
	comboboxentry_DateMois=lookup_widget(win_GRDVDAM,"comboboxentry_GRDVDAMDateMois");
	checkbutton_Confirmer=lookup_widget(win_GRDVDAM,"checkbutton_GRDVDAMConfirmer");
	radiobutton_Cren1=lookup_widget(win_GRDVDAM,"radiobutton_GRDVDAMCren1");
	radiobutton_Cren2=lookup_widget(win_GRDVDAM,"radiobutton_GRDVDAMCren2");
	radiobutton_Cren3=lookup_widget(win_GRDVDAM,"radiobutton_GRDVDAMCren3");
	radiobutton_Cren4=lookup_widget(win_GRDVDAM,"radiobutton_GRDVDAMCren4");
	
	p=chercherRDVD(intmid,"RDV.txt");
	sprintf(idaff, "%d" , p.RDVDid);
	sprintf(cinaff, "%d" , p.RDVcin);
	gtk_entry_set_text(GTK_ENTRY(entry_ID),idaff);
	gtk_entry_set_text(GTK_ENTRY(entry_IDETS),p.RDVD_ID_ETS);
	gtk_entry_set_text(GTK_ENTRY(entry_CIN),cinaff);

	while(i<12 && strcmp(mois[i],p.dt_RDVD.RDVDmois)!=0)
	i++;
	gtk_combo_box_set_active(GTK_COMBO_BOX(comboboxentry_DateMois), i);

	gtk_spin_button_set_value(spinbutton_DateJour,p.dt_RDVD.RDVDjour);
	gtk_spin_button_set_value(spinbutton_DateAnnee,p.dt_RDVD.RDVDannee);

	if(strcmp(p.RDVDhoraire,"9H")==0)
		gtk_toggle_button_set_active(GTK_RADIO_BUTTON(radiobutton_Cren1),TRUE);
	else if(strcmp(p.RDVDhoraire,"11H")==0)
		gtk_toggle_button_set_active(GTK_RADIO_BUTTON(radiobutton_Cren2),TRUE);
	else if(strcmp(p.RDVDhoraire,"14H")==0)
		gtk_toggle_button_set_active(GTK_RADIO_BUTTON(radiobutton_Cren3),TRUE);
	else if(strcmp(p.RDVDhoraire,"16H")==0)
		gtk_toggle_button_set_active(GTK_RADIO_BUTTON(radiobutton_Cren4),TRUE);
	if(p.RDVDcom==1)
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkbutton_Confirmer),TRUE);
  }
  else
  {
  win_GRDVDAM = lookup_widget(button, "window_GRDVDAM");
  gtk_widget_destroy (win_GRDVDAM);
  
  win_GRDVD = create_window_GRDVD ();
  gtk_widget_show (win_GRDVD);

  treeview_GRDVD = lookup_widget(win_GRDVD,"treeview_GRDVD");
  afficherRDVD(treeview_GRDVD,"RDV.txt");
  }
}


void
on_button_GRDVDSupprim_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *treeview_GRDVD;
  GtkWidget *window_GRDVD;
  GtkWidget *entry_GRDVDChercher;
  
  char chsuppid[20];
  int intsuppid;

  entry_GRDVDChercher=lookup_widget(button,"entry_GRDVDChercher");

  strcpy(chsuppid,gtk_entry_get_text(GTK_ENTRY(entry_GRDVDChercher)));
  intsuppid = atoi(chsuppid);
  if (intsuppid!=0)
  {
	supprimerRDVD(intsuppid,"RDV.txt");

	window_GRDVD = lookup_widget(button, "window_GRDVD");
	gtk_widget_destroy (window_GRDVD);
	window_GRDVD = create_window_GRDVD ();
	gtk_widget_show (window_GRDVD);

	treeview_GRDVD = lookup_widget(window_GRDVD,"treeview_GRDVD");
	afficherRDVD(treeview_GRDVD,"RDV.txt");
  }
}


void
on_button_GRDVDChercher_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *window_GRDVD;
  GtkWidget *entry_GRDVDChercher;
  GtkWidget *treeview_GRDVD;
  char chid[20];
  int intid;
  RDVD p;

  entry_GRDVDChercher=lookup_widget(button,"entry_GRDVDChercher");

  strcpy(chid,gtk_entry_get_text(GTK_ENTRY(entry_GRDVDChercher)));
  intid = atoi(chid);

	p=chercherRDVD(intid,"RDV.txt");
	if(p.RDVDid!=-1)
	{
		window_GRDVD = lookup_widget(button, "window_GRDVD");
		gtk_widget_destroy (window_GRDVD);
		window_GRDVD = create_window_GRDVD ();
		gtk_widget_show (window_GRDVD);

		treeview_GRDVD = lookup_widget(window_GRDVD,"treeview_GRDVD");
		afficherRDVD(treeview_GRDVD,"RDVDCher.txt");
	}
}


void
on_radiobutton_GRDVDAMCren4_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
 strcpy(ch,"16H");
}


void
on_radiobutton_GRDVDAMCren3_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
 strcpy(ch,"14H");
}


void
on_radiobutton_GRDVDAMCren1_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
 strcpy(ch,"9H");
}


void
on_radiobutton_GRDVDAMCren2_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
 strcpy(ch,"11H");
}


void
on_checkbutton_GRDVDAMConfirmer_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
c=1;
}


void
on_button_RetourGRDVDAMAff_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *window_GRDVD ;
  GtkWidget *window_GRDVDAM ;
  window_GRDVDAM = lookup_widget(button, "window_GRDVDAM");
  gtk_widget_destroy (window_GRDVDAM);
  window_GRDVD = create_window_GRDVD ();
  gtk_widget_show (window_GRDVD);
}


void
on_button_GRDVDAMConfirmer_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *window_GRDVD;
  GtkWidget *window_GRDVDAM;
  GtkWidget *treeview_GRDVD;
  GtkWidget *entry_GRDVDAMID;
  GtkWidget *entry_GRDVDAM_IDETS;
  GtkWidget *entry_GRDVDAM_CIN;
  GtkWidget *spinbutton_GRDVDAMDateJour;
  GtkWidget *spinbutton_GRDVDAMDateAnnee;
  GtkWidget *comboboxentry_GRDVDAMDateMois;
  GtkWidget *checkbutton_GRDVDAMConfirmer;
  RDVD p;
  char cinch[20];
  char idch[20];

  window_GRDVDAM = lookup_widget(button, "window_GRDVDAM");
  entry_GRDVDAMID=lookup_widget(button,"entry_GRDVDAMID");
  entry_GRDVDAM_IDETS=lookup_widget(button,"entry_GRDVDAM_IDETS");
  entry_GRDVDAM_CIN=lookup_widget(button,"entry4");
  spinbutton_GRDVDAMDateJour=lookup_widget(button,"spinbutton_GRDVDAMDateJour");
  spinbutton_GRDVDAMDateAnnee=lookup_widget(button,"spinbutton_GRDVDAMDateAnnee");
  comboboxentry_GRDVDAMDateMois=lookup_widget(button,"comboboxentry_GRDVDAMDateMois");
  checkbutton_GRDVDAMConfirmer=lookup_widget(button,"checkbutton_GRDVDAMConfirmer");

  //g_print("%p \n",comboboxentry_GRDVDAMDateMois);

  strcpy(idch,gtk_entry_get_text(GTK_ENTRY(entry_GRDVDAMID)));
  p.RDVDid=atoi(idch);
  strcpy(cinch,gtk_entry_get_text(GTK_ENTRY(entry_GRDVDAM_CIN)));
  p.RDVcin=atoi(cinch);
  strcpy(p.RDVD_ID_ETS,gtk_entry_get_text(GTK_ENTRY(entry_GRDVDAM_IDETS)));

  p.dt_RDVD.RDVDjour = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbutton_GRDVDAMDateJour));
  p.dt_RDVD.RDVDannee = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbutton_GRDVDAMDateAnnee));
  p.RDVDcom=c;

  strcpy(p.dt_RDVD.RDVDmois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry_GRDVDAMDateMois)));
  strcpy(p.RDVDhoraire,ch);

if(choice==0)
  ajouterRDVD(p,"RDV.txt");

if(choice==1)
  modifierRDVD(intmid,p,"RDV.txt");
  
  gtk_widget_destroy (window_GRDVDAM);
  
  window_GRDVD = create_window_GRDVD ();
  gtk_widget_show (window_GRDVD);

  treeview_GRDVD = lookup_widget(window_GRDVD,"treeview_GRDVD");
  afficherRDVD(treeview_GRDVD,"RDV.txt");

}


void
on_button_RetourCrenGRDVDAM_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *window_GRDVDCrenaux1;
  GtkWidget *window_AccGRDVD;
  window_GRDVDCrenaux1 = lookup_widget(button, "window_GRDVDCrenaux1");
  gtk_widget_destroy (window_GRDVDCrenaux1);
  window_AccGRDVD = create_window_AccGRDVD ();
  gtk_widget_show (window_AccGRDVD);
}


void
on_button_GRDVDCrenChercher_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *entry_GRDVDCrenID_ETS;
  GtkWidget *spinbutton_GRDVDCrenDateJour;
  GtkWidget *spinbutton_GRDVDCrenDateAnnee;
  GtkWidget *comboboxentry_GRDVDCrenDateMois;
  GtkWidget *label;

  char etsch[20];
  int cp,jour,annee,cap;
  char mois[20];
  char aff[40];
cap=0;
  entry_GRDVDCrenID_ETS=lookup_widget(button,"entry_GRDVDCrenID_ETS");
  spinbutton_GRDVDCrenDateJour=lookup_widget(button,"spinbutton_GRDVDCrenDateJour");
  spinbutton_GRDVDCrenDateAnnee=lookup_widget(button,"spinbutton_GRDVDCrenDateAnnee");
  comboboxentry_GRDVDCrenDateMois=lookup_widget(button,"comboboxentry_GRDVDCrenDateMois");

  strcpy(etsch,gtk_entry_get_text(GTK_ENTRY(entry_GRDVDCrenID_ETS)));
  cp=capaciteRDVD(etsch,"TEST.txt",cp);

  jour = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbutton_GRDVDCrenDateJour));
  annee = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbutton_GRDVDCrenDateAnnee));

  strcpy(mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry_GRDVDCrenDateMois)));
  cap=HoraireDispo("RDV.txt",etsch,cp,jour,mois,annee);
  
  sprintf(aff, "%d places disponibles" , cap);
  label = lookup_widget(button, "label_RDVcapacite");
  gtk_label_set_text(GTK_LABEL(label),aff);
}


void
on_button_AffCD1_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *window_GRDVDCrenaux1;
  GtkWidget *window_GRDVDCrenaux2;
  GtkWidget *treeview_GRDVDCrenauxDisponibles;

  window_GRDVDCrenaux1 = lookup_widget(button, "window_GRDVDCrenaux1");
  gtk_widget_destroy (window_GRDVDCrenaux1);
  window_GRDVDCrenaux2 = create_window_GRDVDCrenaux2 ();
  gtk_widget_show (window_GRDVDCrenaux2);

  treeview_GRDVDCrenauxDisponibles = lookup_widget(window_GRDVDCrenaux2,"treeview_GRDVDCrenauxDisponibles");
  afficherRDVD(treeview_GRDVDCrenauxDisponibles,"Dispo.txt");
}


void
on_button_GRDVDRetourCD1_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *window_GRDVDCrenaux1;
  GtkWidget *window_GRDVDCrenaux2;


  window_GRDVDCrenaux2 = lookup_widget(button, "window_GRDVDCrenaux2");
  gtk_widget_destroy (window_GRDVDCrenaux2);
  window_GRDVDCrenaux1 = create_window_GRDVDCrenaux1 ();
  gtk_widget_show (window_GRDVDCrenaux1);
}


void
on_button_RetourCD2Acc_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *window_GRDVDCrenaux2;
  GtkWidget *window_AccGRDVD;
  window_GRDVDCrenaux2 = lookup_widget(button, "window_GRDVDCrenaux2");
  gtk_widget_destroy (window_GRDVDCrenaux2);
  window_AccGRDVD = create_window_AccGRDVD ();
  gtk_widget_show (window_AccGRDVD);
}


void
on_button_auth_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_auth;
GtkWidget *w1,*w2,*w3,*w4,*w5,*w6;
GtkWidget *input;
GtkWidget *inputpw;
GtkWidget *lab;
GtkWidget *tv;
char un[20];
int una,result=0;
char pw[20];
user found;

window_auth = lookup_widget(button, "window_auth");
input = lookup_widget(button, "entry_AuthID");
inputpw = lookup_widget(button, "entry_Authpw");
lab = lookup_widget(button, "label_auth");

strcpy(un,gtk_entry_get_text(GTK_ENTRY(input)));
una = atoi(un);
strcpy(pw,gtk_entry_get_text(GTK_ENTRY(inputpw)));
result = valider(una,pw);
if (result==0)
gtk_label_set_text(GTK_LABEL(lab), "User not Found !");
else
{
found = chercher(una, "user.txt");
if(strcmp(found.role,"Admin")==0)
{
gtk_widget_destroy(window_auth);
w1 = create_window_AccAdmin();
gtk_widget_show(w1);
}
if(strcmp(found.role,"ResponsableETS")==0)
{
gtk_widget_destroy(window_auth);
w2 = create_window_AccGETS();
gtk_widget_show(w2);
tv = lookup_widget(w2, "treeviewAcc");
afficherETS(tv, "TEST.txt");
}
if(strcmp(found.role,"Medecin")==0)
{
gtk_widget_destroy(window_auth);
w3 = create_window_AccDon();
gtk_widget_show(w3);
}
if(strcmp(found.role,"Infirmier")==0)
{
gtk_widget_destroy(window_auth);
w4 = create_window_AccGFD();
gtk_widget_show(w4);
}
if(strcmp(found.role,"Donneur")==0)
{
gtk_widget_destroy(window_auth);
w5 = create_window_AccGRDVD();
gtk_widget_show(w5);
}
if(strcmp(found.role,"Employer_Bancaire")==0)
{
gtk_widget_destroy(window_auth);
w6 = create_window_AccGDPS();
gtk_widget_show(w6);
}
}
}


void
on_checkbutton_GDPSAMUrgent_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{u=1;
}
}


void
on_checkbutton_GSDonRI_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
RI = 1;
}

