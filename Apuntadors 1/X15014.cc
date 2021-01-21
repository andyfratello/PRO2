static void arbsumes_rec(node_arbre* n, node_arbre* &nSuma) {
    if (n == NULL) nSuma = NULL;
    else {
        nSuma = new node_arbre;
        nSuma->info = n->info;
        
        arbsumes_rec(n->segE, nSuma->segE);
        arbsumes_rec(n->segD, nSuma->segD);
        if (n->segE != NULL) nSuma->info += (nSuma->segE)->info;
        if (n->segD != NULL) nSuma->info += (nSuma->segD)->info;
    }
}

/* Pre: cert */
/* Post: l'arbre asum Ã©s l'arbre suma del p.i. */
void arb_sumes(Arbre<int> &asum) const {
    esborra_node_arbre(asum.primer_node);
    //int sum = 0;
    arbsumes_rec(primer_node, asum.primer_node);
}
