#include<iostream>

using namespace std;

struct Student {
	int id;
	char* nume;
	float inaltime;
};

Student crearestudent(int id, const char* nume, float inaltime) {
	Student s;
	s.id = id;
	s.nume = (char*)malloc(sizeof(char)*(strlen(nume)+1));
	strcpy(s.nume, nume);
	s.inaltime = inaltime;
	return s;
}
void afisareStudent(Student s) {
	printf("\n Studentul cu id ul %d cu numele %s are inaltimea %5.2f", s.id, s.nume, s.inaltime);
}

struct nod {
	Student info;
	nod* next;
};

nod* crearenod(Student info, nod* next) {
	nod* nou = (nod*)malloc(sizeof(nod));
	//nou->info = info;//shallow
	nou->info = crearestudent(info.id, info.nume, info.inaltime);//deep
	nou->next = next;
	return nou;
}

nod* inserareinceput(nod* cap, Student s) {
	nod* nou = crearenod(s, NULL);
	if (cap) {
		nou->next = cap;
		cap = nou;
		return cap;
	}
	else {
		cap = nou;
		return cap;
	}
}

nod* inserarefinal(nod* cap, Student s) {
	nod* nou = crearenod(s, NULL);
	if (cap) {
		nod* p = cap;
		while (p->next) {
			p = p->next;
		}
		p->next = nou;

	}
	else {
		cap = nou;
		return cap;
	}
}

void afisarelista(nod* cap) {
	if (cap) {
		nod* p = cap;
		while (p) {
			afisareStudent(p->info);
			p = p->next;
		}
	}
}



struct nodd {
	Student info;
	nodd* prev;
	nodd* next;
};

nodd* creareNodd(Student info, nodd* prev, nodd* next) {
	nodd* nou = (nodd*)malloc(sizeof(nodd));
	nou->info = info;
	nou->prev = prev;
	nou->next = next;
	return nou;
}

struct LDI {
	nodd* prim;
	nodd* ultim;
};

LDI inserareInceput(LDI lista, Student s) {
	nodd* nou = creareNodd(s, NULL, NULL);
	if (lista.prim) {
		nou->next = lista.prim;
		lista.prim->prev = nou;
		lista.prim = nou;
		return lista;
	}
	else {
		lista.prim = lista.ultim = nou;
		return lista;
	}
}

LDI inserareFinal(LDI lista, Student s) {
	nodd* nou = creareNodd(s, NULL, NULL);
	if (lista.prim) {
		nou->prev = lista.ultim;
		lista.ultim->next = nou;
		lista.ultim = nou;
		return lista;
	}
	else {
		lista.prim = lista.ultim = nou;
		return lista;
	}
}
void afisareinceputfinal(LDI lista) {
	if (lista.prim) {
		nodd* p = lista.prim;
		while (p) {
			afisareStudent(p->info);
			p = p->next;
		}
	}
}
void afisarefinalinceput(LDI lista) {
	if (lista.prim) {
		for (nodd* p = lista.ultim;p != NULL;p = p->prev) {
			afisareStudent(p->info);
		}
	}
}
void main() {
	nod* cap = NULL;
	cap = inserareinceput(cap, crearestudent(100, "Diana", 1.56));
	cap = inserareinceput(cap, crearestudent(123, "Maria", 1.56));
	cap = inserareinceput(cap, crearestudent(675, "Ionut", 1.43));
	cap = inserareinceput(cap, crearestudent(352, "Angela", 1.56));
	cap = inserareinceput(cap, crearestudent(653, "Diana", 1.77));
	cap = inserareinceput(cap, crearestudent(184, "Sorin", 1.56));
	afisarelista(cap);

	LDI lista;
	lista.prim = lista.ultim = NULL;
	lista = inserareFinal(lista, crearestudent(45, "Anca", 1.86));
	lista = inserareFinal(lista, crearestudent(76, "Matei", 1.9 6));
	lista = inserareFinal(lista, crearestudent(25, "Stefan", 1.86));
	lista = inserareFinal(lista, crearestudent(19, "Anca", 1.56));
	afisareinceputfinal(lista);

}