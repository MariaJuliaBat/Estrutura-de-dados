#include <stdio.h>
#include <stab.h>

void fight(const TipoLutador *timeA, const TipoLutador *timeB, int n, TipoLutador *vencedores) {
    for (int i = 0; i < n; i++) {
        if (timeA[i].forca > timeB[i].forca) {
            vencedores[i] = timeA[i];
        } else {
            vencedores[i] = timeB[i];
        }
    }
}