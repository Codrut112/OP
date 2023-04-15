#pragma once
#include "participant.h"
typedef void* ElemType;
typedef void (*DestroyFunction)(ElemType);//functie de distrugere
typedef ElemType (*CopyFct) (ElemType);//functie de copiere
typedef struct {
	ElemType* elems;
	int len;
	int cap;
	DestroyFunction dfnc;
} Repository;

/// <summary>
/// Creeaza o lista noua
/// </summary>
/// <returns> Repository </returns>
Repository* createEmpty();

/// <summary>
/// Dealoca spatiul folosit de lista
/// </summary>
/// <param name="l"> Repository* </param>
/// destfct-functie de distrugere
void destroy(Repository* l);

/// <summary>
/// Adauga un nou element in lista (la finalul acesteia)
/// </summary>
/// <param name="l"> Repository* </param>
/// <param name="el"> Participant </param>
void add(Repository* l, ElemType el);

/// <summary>
/// Returneaza numarul de elemente din lista
/// </summary>
/// <param name="l"> Repository* </param>
/// <returns> int - nr. elemente lista </returns>
int size(Repository* l);

/// <summary>
/// Returneaza participantul de pe pozitia poz
/// </summary>
/// <param name="l"> Repository* </param>
/// <param name="poz"> int, 0 <= poz <= len </param>
/// <returns> Participant </returns>
ElemType get(Repository* l, int poz);

/// <summary>
/// Returneaza o copie a listei
/// </summary>
/// <param name="l"> Repository* </param>
/// <returns> Repository </returns>
Repository* copyRepo(Repository* l,CopyFct cf);

/// <summary>
/// Actualizeaza participantul de pe pozitia poz din lista
/// </summary>
/// <param name="l"> Repository* </param>
/// <param name="poz"> int </param>
/// <param name="p"> Participant </param>
void update(Repository* l, int poz, Participant* p);

/// <summary>
/// Functie care aloca memorie aditionala, daca este necesar
/// </summary>
/// <param name="l"> Repository* </param>
void ensureCapacity(Repository* l);

/// <summary>
/// Sterge participantul de pe pozitia poz din lista
/// </summary>
/// <param name="l"> Repository* </param>
/// <param name="poz"> int </param>
void removeElement(Repository* l, int poz);




/// <returneaza ultimul element al listei>
/// 
/// </summary>
/// <param name="l"></param>
/// <returns></ElemType>
ElemType remove_last(Repository* l);

void testCreate();
void testAdd();
void testCopyRepo();
void testUpdate();
void testRemove();
void testListeDeliste();