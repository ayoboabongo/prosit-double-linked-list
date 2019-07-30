#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct
{
    int heure;
    int minute;
    int sec;
}heure;

typedef struct
{
    int ID_alpiniste;
    heure heure_passage1;
    heure heure_passage2;
}avancement;

typedef struct
{
    int numero_s;
    int distance;
    heure record_monte;
    heure record_descente;
    int ID_P1;
    int ID_P2;
    avancement tab[4];
}station;

typedef struct cellule
{
    station S;
    struct cellule *suiv;
    struct cellule *pred;

}cellule;

typedef struct listeDC
{
    cellule *tete;
    cellule *queu;
}LDC;

station saisir(station s);

LDC inserer_queue_LDC(LDC L,station s)

LDC supprimer_station(LDC L,int numero);



#endif // HEADER_H_INCLUDED
