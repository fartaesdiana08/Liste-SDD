#include<iostream>

using namespace std;

struct Ferma {
	char* nume;
	int nrAnimale;
};

Ferma creareFerma(const char* nume, int nrAnimale) {
	Ferma f;
	f.nume = (char*)malloc(sizeof(char) * strlen(nume) + 1);
	strcpy(f.nume, nume);
	f.nrAnimale = nrAnimale;
	return f;
}

void afisareFerma(Ferma f) {
	printf("Ferma cu numele %s are %d animale.\n", f.nume, f.nrAnimale);
}

struct nod {
	Ferma info;
	nod* next;
};

nod* creareNod(Ferma info, nod* next) {
	nod* nou = (nod*)malloc(sizeof(nod));
	nou->info = creareFerma(info.nume, info.nrAnimale);
	nou->next = next;
	return nou;
}

nod* inserareInceput(nod* cap, Ferma f) { //unde, ce
	nod* nou = creareNod(f, NULL);
	if (cap) {
		nou->next = cap;
		cap = nou;
		return cap;
	}
	else {
		cap= nou;
		return cap;
	}
}

nod* inserareFinal(nod* cap, Ferma f) {
	nod* nou = creareNod(f, NULL);
	if (cap) {
		nod* p = cap; //adresa de inceput a listei existente
		while (p->next) {
			p = p->next;
		}
		p->next = nou;
		return cap;
	}
	else {
		cap = nou;
		return cap;
	}
}


void afisareLista(nod* cap) {
	if (cap) {
		nod* p = cap;
		while (p) {
			afisareFerma(p->info);
			p = p->next;
		}
	}
}

void main() {
	Ferma f1;
	f1 = creareFerma("Curcanul vesel", 34);
	Ferma f2;
	f2 = creareFerma("Porcellino grasso", 88);
	afisareFerma(f1);
	afisareFerma(f2);
	printf("\n");

	nod* cap = NULL;
	cap = inserareInceput(cap, f1);
	cap = inserareInceput(cap, f2);
	cap = inserareInceput(cap, creareFerma("Ferma 3", 10));
	afisareLista(cap);

	printf("\n");
	nod* cap2 = NULL;
	cap2 = inserareFinal(cap2, creareFerma("Prima ferma", 2));
	cap2 = inserareFinal(cap2, creareFerma("A doua ferma", 4));
	cap2 = inserareFinal(cap2, creareFerma("A treia ferma", 6));
	afisareLista(cap2);
}