#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Team.h"
#include "tools.h"
#include "datetime.h"
#include "menu.h"
#include "datastruct.h"
#include "sort.h"

int compare(int *value1 , int *value2)
{
    return(*value1 - *value2);
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
            case 0:
                    int Goal;
                    int GoalNext;
                    int Erg;
                    int i;
                    int x;
                    for(i=0;i<TeamCounter;i++)
                    {
                        int AnzPlayer = (Teams+TeamCounter)->AnzPlayer;

                        for(x=1;x<AnzPlayer;x++)
                        {
                            Goal = (((Teams+i)->Player)+(x-1))->Goals;
                            GoalNext = (((Teams+i)->Player)+x)->Goals;

                            (int *cmp) (int*,int*) = compare;

                            Erg = cmp(Goal,GoalNext);

                            int ZS;

                            if(Erg == 0)




                        }
                    }

                    break;

            case 1: break;

            case 2: break;

            case 3: ok=1; break;

            default:printf("ERROR:Menuauswahl\n") ; break;
        }
    }while(!ok);
}
