/* Pre: cert */
/* Post: si m és NULL, el resultat és NULL; en cas contrari, el
    resultat apunta al primer node d'una cadena de nodes que són
    còpia de la cadena que té el node apuntat per m com a primer */
node_pila* copia_node_pila_it(node_pila* m) {
    if (m == NULL) return NULL;
    node_pila* primer;
    node_pila* aux;
    primer = new node_pila;
    aux = primer;
    aux->info = m->info; // (*aux).info = (*m).info
    m = m->seguent;      // m = (*m).seguent
    while (m != NULL) {
        aux->seguent = new node_pila;
        aux = aux->seguent;
        aux->info = m->info;
        m = m->seguent;
    }
    aux->seguent = NULL;
    return primer;
}

/* Pre: cert */
/* Post: El p.i. passa a ser una còpia d'original i qualsevol
    contingut anterior del p.i. ha estat esborrat (excepte si el
    p.i. i original ja eren el mateix objecte) */
Pila& operator=(const Pila& original) {
    if (this != &original) {
        esborra_node_pila(primer_node);
        altura = original.altura;
        primer_node = copia_node_pila_it(original.primer_node);
    }
    return *this;
}
