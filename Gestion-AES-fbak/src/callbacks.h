#include <gtk/gtk.h>


void
on_button_GSDon_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_DSang_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_DonAccLogout_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_RSang_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview_GSDon_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeview_GSDonEpingle_row_activated (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_BRTVGSDon_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GSDonActualiser_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_RetourGSDAcc_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GSDonSuppr_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GSDonEpingle_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GSDonAjout_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton_GSDonAMQ1_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_GSDonAMQ2_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_GSDonAMQ3_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_GSDonAMQCustom_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_GSDonNDispo_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_RetourAMGSDon_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton_GSDonRI_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GSDonAMOK_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton_GSDonDispo_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_RetourDSAccDon_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_RetourRSAccDon_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GETSAccLogout_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GETSModif_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GETSSupprim_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GETSCapacite_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GETSRegion_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GETSRecherche_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GETSAjout_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton_GETSAMEtatEtab_NonDisp_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_GETSAMEtatEtab_Disp_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_GETSAMPrincipal_toggled (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_GETSAMConfirmer_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_RetourGETSAMAcc_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_RetourGETSRechAcc_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GETSRechercheOK_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GETSSupprimerOK_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_RetourGETSSupprAcc_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GETSModifOK_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_RetourGETSModifAcc_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonconfirmerAffReg_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_RetourAffRegionAcc_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_RetourAffCapAcc_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_AdminAffUserRole_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_AdminGUser_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_AdminDashboard_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_AccAdminLogout_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_AdminUserRoleOK_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_role_actualiser_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_RetourAdminUserRoleAcc_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_AdminGURechOK_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_user_actualiser_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_AdminGUAjout_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_AdminGUModif_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_AdminGUSupprim_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_RetourAdminGUAcc_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton_AdminGUAMSexeMale_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_AdminGUAMSexeFemale_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_AdminGUAMActif_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_AdminGUAMConfirm_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_RetourUserAMGUAdmin_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_AdminDashboardCALCUL_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_RetourDashAcc_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_AccGPSLogout_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GDPS_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GDPSPourcentage_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GDPSSangPlusDemande_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview_GDPS_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_RetourGDPSAcc_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GDPSAjout_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GDPSModif_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_RetourGDPSPDAcc_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GDPSPNomDemande_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_RetourGDPSSPDAcc_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton_GDPSAMQuantite1_toggled (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_GDPSAMQuantite2_toggled (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_GDPSAMQuantite3_toggled (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_GDPSAMUrgent_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GDPSAMConfirmer_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_RetourGDPSAMAff_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GFD_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GFD_RDV_ETS_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GFDLogout_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GFDAjout_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GFDUpdate_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GFDAfficher_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_RetourGFDAcc_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GFDModif_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GFDRechercher_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GFDSupprim_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GDFAMConfirmer_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_RetourGDFAMAff_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton_GDFAMSexeF_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_GDFAMSexeH_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_GDFAMAntMed_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_RetourGDFRDVAcc_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GDFRDVETS_Calculer_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GDFRDVChercher_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GRDVDHistorique_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GRDVD_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GRDVDDisponibilite_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GRDVDLogout_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_RetourHistoAcc_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GRDVDH_IDOK_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_RetourGRDVDAcc_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GRDVDAjout_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GRDVDModif_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GRDVDSupprim_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GRDVDChercher_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton_GRDVDAMCren4_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_GRDVDAMCren3_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_GRDVDAMCren1_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_GRDVDAMCren2_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_GRDVDAMConfirmer_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_RetourGRDVDAMAff_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GRDVDAMConfirmer_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_RetourCrenGRDVDAM_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GRDVDCrenChercher_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_AffCD1_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_GRDVDRetourCD1_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_RetourCD2Acc_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_auth_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton_GDPSAMUrgent_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_GSDonRI_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);
