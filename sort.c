#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Team.h"
#include "tools.h"
#include "datetime.h"
#include "menu.h"
#include "datastruct.h"
#include "sort.h"

int compareTrikot(TPlayer *player1 , TPlayer  *player2)
{
    int Trikot1 = player1->Trikotn;
    int Trikot2 = player2->Trikotn;

    return(Trikot1 - Trikot2);
}

int compareBirthday(TPlayer *player1 , TPlayer  *player2)
{
    int Year1 = player1->Birthday->Year;
    int Month1 = player1->Birthday->Month;
    int Day1 = player1->Birthday->Day;

    int Year2 = player2->Birthday->Year;
    int Month2 = player2->Birthday->Month;
    int Day2 = player2->Birthday->Day;


    if( Year1 - Year2 == 0 )
    {
        if(Month1 - Month2 ==0)
        {
            if(Day1 - Day2 == 0)
            {
                return 0;
            }
            else
            {
                if(Day1 - Day2 < 0)
                {
                    return -1;
                }
                else
                {
                    return 1;
                }
            }
        }
        else
        {
            if(Month1 - Month2 < 0)
            {
                return -1;
            }
            else
            {
                return 1;
            }
        }
    }
    else
    {
        if(Year1 - Year2 < 0)
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }

}

int compareName(TPlayer *player1 , TPlayer  *player2)
{
    char * name1 = player1->Playern;
    char * name2 = player2->Playern;
    //printf("name 1 = %s \n nmame2 = %s \n erg = %i \n",name1,name2,(name1-name2));

    return(strcmp(name2,name1));
}

int compareGoal(TPlayer *player1 , TPlayer  *player2)
{
    int Goal1 = player1->Goals;
    int Goal2 = player2->Goals;
    int erg   = Goal1 - Goal2;
    if(erg != 0)
    {
        return(erg);
    }
    else
    {
        return(compareName(player1,player2));
    }
}

void Tausch(TPlayer *player1 , TPlayer *player2 )
{
    TPlayer Zwischen;
    Zwischen   = *player1;
    *player1   = *player2;
    *player2   = Zwischen;
}

int ( *CMP_Goal)        ( TPlayer* , TPlayer*)  = compareGoal;

int ( *CMP_Birthday)    ( TPlayer* , TPlayer*)  = compareBirthday;

int ( *CMP_Trikot)      ( TPlayer* , TPlayer*) = compareTrikot;

int ( *CMP_Name)        ( TPlayer* , TPlayer*) = compareName;

void Fifasort( int (*P_FKT)( TPlayer* , TPlayer* ) )
{
    clearScreen();
    int Erg;
    int i;
    int TC;                         //Teamcounter
    int PC;                         //Playercounter
    for(TC = 0; TC<TeamCounter; TC++)
    {
        int AnzPlayer = (Teams+TC)->AnzPlayer;

        for(PC = 0; PC < (AnzPlayer+1); PC++)
        {
            for(i = (PC+1); i < AnzPlayer; i++)
            {
                    Erg = P_FKT(  (((Teams+TC)->Player)+(PC))
                                 ,(((Teams+TC)->Player)+ i));

                    Tausch((((Teams+TC)->Player)+PC)
                                ,(((Teams+TC)->Player)+  i));
                    //printf("%i von %i || %i == %i || erg 0 %i\n",PC,AnzPlayer,PC,i,Erg);
            }
        }
        printf("Team %s wurde sortiert\n",(Teams+TC)->Teamn);
    }
}

int partition(TPlayer *Player, int ui,int oi,int (*P_FKT)( TPlayer* , TPlayer* ))
{
	int i = ui + 1, j = oi;
	TPlayer *comp = Player + ui;

	while(i<=j)
	{
		while((i<=j) && (P_FKT((Player + i), comp) <= 0 ))
		{
			i++;
		}
		while((j>=i) && (P_FKT((Player + j), comp) >= 0))
		{
			j--;
		}
		if(i < j)
		{
			Tausch(Player + i, Player + j);
			i++;
			i--;
		}
	}
	i--;
	Tausch(comp, Player + i);
	return i;
}

void QSort(TPlayer *A, int ui, int oi, int (*P_FKT)( TPlayer* , TPlayer* ))
{
	int idx;
	if(ui >= oi)
	{
		return;
	}
	else
    {
        idx = partition(A, ui, oi, P_FKT);
        QSort(A, ui, idx - 1, P_FKT);    // linken Teil sortieren
        QSort(A, idx + 1, oi, P_FKT);    // rechten Teil sortieren
    }
}

void QuickSort(TPlayer *A, int Anz, int (*P_FKT)( TPlayer* , TPlayer* ))
{
    //printf("Anzahl der Elemente im Array: %02i\n", Anz);
	QSort(A, 0, Anz - 1, P_FKT);
}

void sort(int (*P_FKT)( TPlayer* , TPlayer* )){
    int Erg;
    int i;
    int TC;                         //Teamcounter
    int PC;                         //Playercounter

    clearScreen();
    for(TC = 0; TC < TeamCounter; TC++)
    {
        int AnzPlayer = (Teams+TC)->AnzPlayer;

        for(PC = 0; PC < (AnzPlayer+1); PC++)
        {
            QuickSort( ((Teams+TC)->Player), AnzPlayer, P_FKT );

        }
        printf("Team %s wurde sortiert\n",(Teams+TC)->Teamn);
    }

}

void sortTeams(void)
{
    int anzmenu=5;                          //ANzahl der menus

    TMTitel ArrMTitel[anzmenu];         //Array von struct TMenuTitel
                                        //in struct char MTitel[]

    //füllen der Titel
    strcpy(ArrMTitel[0].MTitel, "Spieler nach geschossenen Toren sortieren");
    strcpy(ArrMTitel[1].MTitel, "Spieler nach TrikotNummer sortieren");
    strcpy(ArrMTitel[2].MTitel, "Spieler nach Geburtsdatum sortieren");
    strcpy(ArrMTitel[3].MTitel, "Spieler nach Namen sortieren");
    strcpy(ArrMTitel[4].MTitel, "Zurueck zum Hauptmenue");

    char Menutitel[] = {"Spieler Sortieren"};
    int ok=0;

    do{
        int eingabe = getmenu(Menutitel,ArrMTitel,anzmenu);

        switch(eingabe)
        {
            case 0: sort(CMP_Goal);
                    WaitForEnter(); break;

            case 1: sort(CMP_Trikot);
                    WaitForEnter(); break;

            case 2: sort(CMP_Birthday);
                    WaitForEnter(); break;

            case 3: sort(CMP_Name);
                    WaitForEnter(); break;

            case 4: ok=1; break;

            default:printf("ERROR: sort.c Menuauswahl\n") ; break;
        }
    } while(!ok);
}
