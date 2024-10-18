//coding utf-8

#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct client
{
    int id;
    string numero;
    string full_name;
    float solde;
    struct client *next;
}CLIENT;

int compteur(CLIENT* );
void Gestion_Compte(void);
void Transaction_Compte(void);

CLIENT *head = NULL;

int main(int argc, char const *argv[])
{
    CLIENT *ptr = NULL;
    int choix = -1;
    while (choix != 3)
    {
        cout << "\t\t\t\t Bienvenue au Menu Principal\n 1. MENU DE GESTION DES COMPTES\n 2. MENU DE TRANSACTIONS\n 3. Quitter\n\n Veuillez saisir un choix : ";
        cin >> choix;
        switch (choix)
        {
        case 1:
            //Opérations sur les comptes
            Gestion_Compte();

            break;
        case 2:
            //Opérations sur les transactions
            Transaction_Compte();

            break;

        case 3:
            while (head != NULL)
            {
                ptr = head;
                head = head->next;
                delete ptr;
            }
            head = 0;
            ptr = 0;
            
            if (head == 0 && ptr == 0)
                cout << "Suppression des compte     [fait] \nLibération de la mémoire    [fait] \nSortie du programme    [fait]  \nÀ bientôt\n";
            
            else cout << "Erreur survenue lors de la fermeture du programme exit = -1";
            break;

        default:
            cout << "Choix invalide, Veuillez réessayer!" << endl;
            break;
        }
    }
    
    return 0;
}

int compteur(CLIENT *mon_client)
{
    int indice = 0;
    if (mon_client == NULL)
        return 1;

    while (mon_client != NULL)
    {
        mon_client = mon_client->next;
        indice += 1;
    }
    return indice;
}

CLIENT* search(int number)
{
    CLIENT *searched = head;
    while (searched != NULL)
    {
        if (searched->id == number)
            return searched;
        
        else
            searched = searched->next;
    }
    return searched;
}

void Gestion_Compte(void)
{
    CLIENT *ptr = NULL;
    int option = -1, indice = 0, ID = 0;
    char confirm = 'n';
    string numero;
    bool checker = false;
    system("clear");
        while (option != 5)
        {
            cout << "\t\t\t\tMENU GESTION DES COMPTES\n" << endl;
            cout << "1. Créer un compte\n 2. Supprimer un compte\n 3. Modifier un compte\n 4. Afficher tous les comptes\n 5. Retourner au menu précédent\n\nVeuillez saisir une option : ";
            cin >> option;
            switch (option)
            {
            case 1:
                //Create an account
                //Pour créer un compte, on va procéder à l'insertion en queue comme en SDD
                ptr = new CLIENT;

                if (ptr != NULL)
                {
                    ptr->id = compteur(head);
                    cout << "Entrer les informations du clients : " << endl;
                    cout << "Nom & Prénom : "; 
                    cin.ignore();
                    getline(cin, ptr->full_name);
                    cout << "Numéro de téléphone : ";
                    cin >> ptr->numero;
                    cout << "Pour l'ouverture du compte, veuillez verser une valeur supérieur ou égale à 15.000 XOF\n Somme : ";
                    while (ptr->solde < 15000)
                    {
                        cin >> ptr->solde;
                        if (ptr->solde < 15000)
                            cout << "\t\t\tErreur ! Veuillez réessayer ! \n Somme : ";
                    }
                    ptr->next = NULL;
                }
                else
                {
                    cout << "Erreur d'allocation !\n";
                    break;
                }
                if (head == NULL)
                    head = ptr;
                
                else
                {
                    CLIENT *parcours = head;
                    while (parcours->next != NULL)
                    {
                        parcours = parcours->next;
                    }
                    parcours->next = ptr;
                }
                cout << "\t\t\t\tVotre compte a été créé avec succès !\n" << endl;
                break;
            
            case 2:
                //Delete an account
                cout << "Veuillez entrer l'ID du client : ";
                while (ID <= 0)
                {
                    cin >> ID;
                    if (ID <= 0)
                        cout << "ID invalide, veuillez réessayer\n ID : ";
                }

                if (head == NULL)
                {
                    cout << "\t\t\tLa liste de clients est vide." << endl;
                    break;
                }
                
                /*ptr = search(ID);
                if (ptr == head)
                {
                    head = head->next;
                    delete ptr;
                    checker = true;
                }*/

                
                ptr = head;
                if (ptr->id == ID)
                {
                    head = head->next;
                    delete ptr;
                    checker = true;
                }
                    
                else
                {
                    CLIENT *ptr1 = ptr->next;
                    while (ptr1 != NULL)
                    {
                        if (ptr->id == ID)
                        {
                            checker = true;
                            break;
                        }
                        else
                        {
                            ptr = ptr1;
                            ptr1 = ptr1->next;
                        }
                    }
                }
                
                if (checker == true)
                {
                    cout << "\t\t\tCompte supprimé avec succès !\n";
                }
                
                break;
            
            case 3:
                //Modify an account
                cout << "Entrer l'ID du client : ";
                cin >> ID;
                ptr = search(ID);
                if (ptr == NULL)
                    cout << "Aucun ID n'y correspond !" << endl;
                
                else
                {
                    //On effectue les modifications à faire
                    cout << "";
                }
                break;
            
            case 4:
                //Show all accounts
                ptr = head;
                if (ptr == NULL)
                    cout << "\n\t\t\tLa liste des comptes est vide !" << endl;
                
                else
                {
                    cout << "\nid     Nom & Prénom        Numéro      Solde" << endl;
                    while (ptr != NULL )
                    {
                        cout << ptr->id << "     " << ptr->full_name << " " << ptr->numero << " " << ptr->solde << endl;
                        ptr = ptr->next;
                        indice++;
                    }
                    cout << "\t\t\t" << indice << " comptes trouvés au total." << endl;
                
                }
                
                break;
            
            case 5:
                break;
            
            default:
                cout << "OPTION INVALIDE, VEUILLEZ RÉESSAYER !\n" << endl;
                break;
            }
        }
    
    cout << "\t\t\tERREUR SURVENUE LORS DE L'OUVERTURE DU FICHIER !" << endl;    
}

void Transaction_Compte(void)
{
    CLIENT *destinataire = NULL, *expediteur = NULL, *ptr = NULL;
    int option = -1, ID = 0, indice = 0;
    float somme = 0;
    system("clear");

    while (option != 6)
    {
        cout << "MENU TRANSACTION DES COMPTES\n" << endl;
        cout << "1. Verser une somme dans un compte\n2. Retirer une somme d’un compte \n3. Virer une somme d’un compte vers un autre \n4. Afficher un compte \n5. Afficher tous les comptes \n6. Quitter le sous menu (retour au menu principal) \n\n Veuillez saisir une option : ";
        cin >> option;
        switch (option)
        {
        case 1:
            //Versement dans un compte
            cout << "Veuillez entrer l'ID : ";
            while (ID <= 0)
            {
                cin >> ID;
                if (ID <= 0)
                    cout << "ID incorrect, veuillez réessayer : ";
            }
            destinataire = search(ID);
            while (!destinataire) //Boucle si ID expediteur est incorrect
            {
                cout << "\t\t\tAucune correspondance d'ID trouvée !\n Veuillez réessayer : ";
                cin  >> ID;
                destinataire = search(ID);
            }
            cout << "Entrer la somme à verser :";
            somme = 0;
            while (somme <=0)
            {
                cin >> somme;
                if (somme <= 0)
                {
                    cout << "Somme invalide ! Veuillez insérer une somme positive :";
                    cin >> somme;
                }
            }

            destinataire->solde += somme;
            cout << "\t\t\tVersement effectué avec succès !\n";
                //J'ai la flemme de continuer
            break;
        
        case 2:
            //Retirer une somme
            cout << "Veuillez entrer l'ID : ";
            while (ID <= 0)
            {
                cin >> ID;
                if (ID <= 0)
                    cout << "ID incorrect, veuillez réessayer : ";
            }
            expediteur = search(ID);
            while (!expediteur) //Boucle si ID expediteur est incorrect
            {
                cout << "\t\t\tAucune correspondance d'ID trouvée !\n Veuillez réessayer : ";
                cin  >> ID;
                expediteur = search(ID);
            }
            cout << "Entrer la somme à retirer :";
            somme = 0;
            while (somme <=0)
            {
                cin >> somme;
                if (somme <= 0)
                {
                    cout << "Somme invalide ! Veuillez insérer une somme positive :";
                    cin >> somme;
                }
                if (expediteur->solde < somme)
                {
                    cout << "La somme entrée est supérieure à la somme du client !\n Veuillez réessayer : ";
                    cin >> somme;
                }
            }
            expediteur->solde -= somme;
            cout << "\t\t\tRetrait effectué avec succès !\n";
            break;
        
        case 3:
            //Virer une somme d'un compte vers un autre
            cout << "Veuillez entrer l'ID de l'expéditeur: ";
            while (ID <= 0)
            {
                cin >> ID;
                if (ID <= 0)
                    cout << "ID incorrect, veuillez réessayer : ";
            }
            expediteur = search(ID);
            while (!expediteur) //Boucle si ID expediteur est incorrect
            {
                cout << "\t\t\tAucune correspondance d'ID trouvée !\n Veuillez réessayer : ";
                cin  >> ID;
                expediteur = search(ID);
            }
            
            cout << "Veuillez entrer l'ID du destinataire : ";
            ID = 0; //On rentre volontairement dans la boucle
            while (ID <= 0)
            {
                cin >> ID;
                if (ID <= 0)
                    cout << "ID incorrect, veuillez réessayer : ";
            }

            destinataire = search(ID);
            while (!destinataire) //Boucle si ID destinataire est incorrect
            {
                cout << "\t\t\tAucune correspondance d'ID trouvée !\n Veuillez réessayer : ";
                cin  >> ID;
                destinataire = search(ID);
            }

            cout << "Entrer la somme à envoyer :";
            somme = 0;
            while (somme <= 0 || expediteur->solde < somme)
            {
                cin >> somme;
                if (somme <= 0)
                {
                    cout << "Somme invalide ! Veuillez insérer une somme positive :";
                    cin >> somme;
                }
                if (expediteur->solde < somme)
                {
                    cout << "La somme entrée est supérieure à celle de l'expéditeur !\n Veuillez réessayer : ";
                    cin >> somme;
                }
                
            }
            //Maintenant qu'on est plus ou moins sûr que tout est correct, on effectue la transaction
            expediteur->solde -= somme;
            destinataire->solde += somme;
            cout << "Transaction effectuée avec succès !\n";
            
            break;

        case 4:
            //Afficher un compte
            cout << "Entrer l'ID : ";
            ID = 0; //On rentre volontairement dans la boucle
            while (ID <= 0)
            {
                cin >> ID;
                if (ID <= 0)
                    cout << "ID incorrect, veuillez réessayer : ";
            }
            destinataire = search(ID);
            while (!destinataire) //Boucle si ID est incorrect
            {
                cout << "\t\t\tAucune correspondance d'ID trouvée !\n Veuillez réessayer : ";
                cin  >> ID;
                destinataire = search(ID);
            }

            cout << "ID     Nom & Prénom        Numéro    Somme\n";
            cout << destinataire->id << "   " << destinataire->full_name << "   " << destinataire->numero << "    " << destinataire->solde << endl;
            break;

        case 5:
            //Afficher tous les comptes
            ptr = head;
            if (ptr == NULL)
                cout << "\n\t\t\tLa liste des comptes est vide !" << endl;
            
            else
            {
                cout << "\nid     Nom & Prénom        Numéro      Solde" << endl;
                while (ptr != NULL )
                {
                    cout << ptr->id << "     " << ptr->full_name << " " << ptr->numero << " " << ptr->solde << endl;
                    ptr = ptr->next;
                    indice++;
                }
                cout << "\t\t\t" << indice << " comptes trouvés au total." << endl;
            
            }
            break;

        case 6:
            //Menu précédent 
            break;    
        
        default:
            cout << "OPTION INVALIDE, VEUILLEZ RÉESSAYER !" << endl;
            break;
        }
    }
    
}
