#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Team.h"
#include "tools.h"
#include "datetime.h"
#include "menu.h"
#include "datastruct.h"
#include "sort.h"

int compareGoal(TPlayer *player1 , TPlayer  *player2)
{
    int Goal1 = player1->Goals;
    int Goal2 = player2->Goals;

    return(Goal1 - Goal2);
}

int compareTrikot(TPlayer *player1 , TPlayer  *player2)
{
    int Trikot1 = player1->Trikotn;
    int Trikot2 = player2->Trikotn;

    return(Trikot1 - Trikot2);
}


int compareName(TPlayer *player1 , TPlayer  *player2)
{
    char * name1 = player1->Playern;
    char * name2 = player2->Playern;

    printf("name 1 = %s \n nmame2 = %s \n erg = %i \n",name1,name2,(name1-name2));

    return(name1 - name2);
}


void sort(void)
{

    int value1;
    int value2;
    int Erg;
    int TC; //Teamcounter
    int PC; //Playercounter
    for(TC=0;TC<TeamCounter;TC++)
    {
        int AnzPlayer = (Teams+TeamCounter)->AnzPlayer;

        for(PC=1;PC<AnzPlayer;PC++)
        {


        }
    }


}


void sortTeams(void)
{

    int anzmenu=4;                          //ANzahl der menus

    TMTitel ArrMTitel[anzmenu];         //Array von struct TMenuTitel
                                        //in struct char MTitel[]

     //füllen der Titel
     strcpy(ArrMTitel[0].MTitel,"Nach Toren sortieren");
     strcpy(ArrMTitel[1].MTitel,"Nach Trikot sortieren");
     strcpy(ArrMTitel[2].MTitel,"nach Namen sortieren");
     strcpy(ArrMTitel[3].MTitel,"Zurueck");

    char Menutitel[]={"Spieler Sortieren"};

       int ok=0;
    do{
        int eingabe = getmenu(Menutitel,ArrMTitel,anzmenu);

        switch(eingabe)
        {
            case 0: sort(); break;

            case 1: break;

            case 2: break;

            case 3: ok=1; break;

            default:printf("ERROR: sort.c Menuauswahl\n") ; break;
        }
    }while(!ok);
}
