/* Pre: c=C */
/* Post: el p.i. passa a ser la concatenació de C al paràmetre implícit, c és buida */
void concat(Cua &c) {
    if (not c.es_buida()) {
        if (es_buida()) {   // paràm. implícit
            longitud = c.longitud;
            primer_node = c.primer_node;
            ultim_node = c.ultim_node;
        } else {
            longitud += c.longitud;
            ultim_node->seguent = c.primer_node;
            ultim_node = c.ultim_node;
        }
        c.ultim_node = NULL;
        c.primer_node = NULL;
        c.longitud = 0;
    }
}
