static void arbsuma_rec(node_arbreNari* n, node_arbreNari* &nSuma) {
    if (n == NULL) nSuma = NULL;
    else {
        nSuma = new node_arbreNari;
        nSuma->seg = vector<node_arbreNari*>(n->seg.size());;
        nSuma->info = n->info;
        for (int i = 0; i < n->seg.size(); ++i) {
            arbsuma_rec(n->seg[i], nSuma->seg[i]);
            if (n->seg[i] != NULL) nSuma->info += (nSuma->seg[i])->info;
        }
    }
}

/* Pre: cert */
/* Post: asum és un arbre amb la mateixa estructura que el p.i.
         i cada node és la suma del node corresponent al p.i
         i tots els seus descendents al p.i. */
void arbsuma(ArbreNari& asum) const {
    asum.N = this->N;
    arbsuma_rec(primer_node, asum.primer_node);
}
