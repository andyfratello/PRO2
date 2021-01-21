static void maxim_rec(node_arbreNari* n, T& max) {
    if (n != NULL) {
        for (int i = 0; i < n->seg.size(); ++i) {
            maxim_rec(n->seg[i], max);
            if (max < n->info) max = n->info;
        } 
    }
}

/* Pre: el p.i. no és buit */
/* Post: el resultat indica el valor més gran que conté el p.i. */
T maxim() const {
    T max = primer_node->info;
    maxim_rec(primer_node, max);
    return max;
}
