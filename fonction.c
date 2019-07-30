#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <string.h>

void initialiser()
{
    station s;
    int i;
    s.numero_s=1;
    s.record_monte.heure=-1;
    s.record_monte.minute=-1;
    s.record_monte.sec=-1;
    s.record_descente.heure=-1;
    s.record_descente.minute=-1;
    s.record_descente.sec=-1;
    s.ID_P1=-1;
    s.ID_P2=-1;
    for(i=0;i<4;i++)
    {
        s.tab[i].heure_passage1.heure=-1;
        s.tab[i].heure_passage1.minute=-1;
        s.tab[i].heure_passage1.sec=-1;
        s.tab[i].heure_passage2.heure=-1;
        s.tab[i].heure_passage2.minute=-1;
        s.tab[i].heure_passage2.sec=-1;
    }


}

station saisir(station s)
{
    int i;
    do
    {
        printf("Numero de station \n");
        scanf("%d",&s.numero_s);
    }while(s.numero_s<1);
    printf("Distance : \n");
    scanf("%d",s.distance);
   for(i=0;i<4;i++)
   {
       printf("ID alpiniste \n");
       scanf("%d",s.tab[i].ID_alpiniste);
       printf("Heure de premier passage par la station \n");
       scanf("%d %d %d ",&s.tab[i].heure_passage1.heure,&s.tab[i].heure_passage1.minute,&s.tab[i].heure_passage1.sec);
       printf("Heure de deuxieme passage par la station \n");
       scanf("%d %d %d ",&s.tab[i].heure_passage2.heure,&s.tab[i].heure_passage2.minute,&s.tab[i].heure_passage2.sec);
   }

   printf("id alpiniste de record de premier passage \n");
   scanf("%d",&s.ID_P1);
   for(i=0;i<4;i++)
   {
       if(s.ID_P1==s.tab[i].ID_alpiniste)
       {
           s.record_monte.heure=s.tab[i].heure_passage1.heure-8;
           s.record_monte.heure=s.tab[i].heure_passage1.minute;
           s.record_monte.heure=s.tab[i].heure_passage1.sec;
       }

   }

   printf("id alpiniste de record de deuxieme passage \n");
   scanf("%d",&s.ID_P2);
   for(i=0;i<4;i++)
   {
       if(s.ID_P1==s.tab[i].ID_alpiniste)
       {
           s.record_monte.heure=s.tab[i].heure_passage2.heure-8;
           s.record_monte.heure=s.tab[i].heure_passage2.minute;
           s.record_monte.heure=s.tab[i].heure_passage2.sec;
       }

   }

   return s;


}

LDC init_LDC (LDC L)
{
    L.tete = NULL;
    L.queu = NULL;

    return L;

}


LDC inserer_queue_LDC(LDC L,station s)
{
    cellule *nouv;
    nouv=(cellule*)malloc(sizeof(cellule));
    if(!nouv)
        printf("Espace memoire insuffisant \n");
    else
    {
        s=saisir(s);
        nouv->S=s;
        nouv->suiv=NULL;
        nouv->pred=L.queu;
        if(L.tete!=NULL&&L.queu!=NULL)
            L.queu->suiv=nouv;

        else
        {
            L.tete=nouv;
            L.queu=nouv;

        }

    }

    return L;
}

LDC Supprimer_tete_LDC (LDC L)
{
    // la liste est supposée non vide,le contrôle
    // doit etre realisé dans la fonction main()
    cellule* p = L.tete;

    if(L.tete == L.queu) // liste contient 1 seul element
        L = init_LDC(L);
    else  // liste contient plus qu’un element
        {
            L.tete = L.tete -> suiv;
            L.tete -> pred = NULL;
        }
        free(p);

    return L;
}

LDC Supprimer_queue_LDC (LDC L)
{
     // la liste est supposée non vide,le contrôle
     // doit etre realisé dans la fonction main()
     cellule* p = L.queu;

    if(L.tete == L.queu) // liste contient 1 seul element
        L = init_LDC(L);
    else   // liste contient plus qu’un element
        {
            L.queu = L.queu -> pred;
            L.queu -> suiv = NULL;
        }
        free(p);

    return L;
}

LDC supprimer_station(LDC L,int numero)
{
    // la liste est supposée non vide,   // le controle doit etre realisé dans la fonction main()
    cellule* p = L.tete;

    while(p && (p->S.numero_s!= numero.))
        p = p->suiv;

    if(p) // elem existe dans la liste
     {
        if(p == L.tete)
        L = Supprimer_tete_LDC(L);
    else
        {
            if(p == L.queu)
              L = Supprimer_queu_LDC(L);
              else
                {
                    (p->pred)->suiv = p->suiv;
                    (p->suiv)->pred = p->pred;
                     free(p);
                }
        }
     }
    else
        printf("\nErreur : %d à       supprimer introuvable  dans la liste",numero);

    return L;

}
