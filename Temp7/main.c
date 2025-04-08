#include "vectLib.h" 
#include <stdio.h> // per printf e scanf

void print_menu() {
    printf("\n--- Calcolatrice Vettoriale ---\n");
    printf("1. Somma di due vettori\n");
    printf("2. Sottrazione di due vettori\n");
    printf("3. Aggiunta di uno scalare a un vettore\n");
    printf("4. Moltiplicazione di un vettore per uno scalare\n");
    printf("5. Prodotto scalare di due vettori\n");
    printf("6. Concatenazione di due vettori\n");
    printf("7. Inversione di un vettore\n");
    printf("8. Ordinamento di un vettore\n");
    printf("9. Mescolamento casuale di un vettore\n");
    printf("10. Shift a destra di un vettore\n");
    printf("11. Shift a sinistra di un vettore\n");
    printf("12. Rotazione a destra di un vettore\n");
    printf("13. Rotazione a sinistra di un vettore\n");
    printf("14. Slice di un vettore\n");
    printf("15. Calcolo della norma di un vettore\n");
    printf("16. Media degli elementi di un vettore\n");
    printf("17. Valore minimo di un vettore\n");
    printf("18. Valore massimo di un vettore\n");
    printf("19. Somma degli elementi di un vettore\n");
    printf("20. Confronto di due vettori con tolleranza\n");
    printf("21. Applicazione di una funzione a ogni elemento di un vettore\n");
    printf("0. Esci\n");
    printf("Seleziona un'opzione: ");
}


double increment(double x) {
    return x + 1;
}

int main() {
    size_t dim = 5;
    double v1[dim], v2[dim], res[dim];
    double scalar, tol;
    int choice;

    do {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: { // Somma di due vettori
                printf("Inserisci %lu valori per il primo vettore:\n", (unsigned long)dim);
                scanf_vec(v1, dim);
                printf("Inserisci %lu valori per il secondo vettore:\n", (unsigned long)dim);
                scanf_vec(v2, dim);
                add_vec(v1, v2, res, dim);
                printf("Risultato della somma:\n");
                print_vec(res, dim);
                break;
            }

            case 2: { // Sottrazione di due vettori
                printf("Inserisci %lu valori per il primo vettore:\n", (unsigned long)dim);
                scanf_vec(v1, dim);
                printf("Inserisci %lu valori per il secondo vettore:\n", (unsigned long)dim);
                scanf_vec(v2, dim);
                sub_vec(v1, v2, res, dim);
                printf("Risultato della sottrazione:\n");
                print_vec(res, dim);
                break;
            }

            case 3: { // Aggiunta di uno scalare
                printf("Inserisci %lu valori per il vettore:\n", (unsigned long)dim);
                scanf_vec(v1, dim);
                printf("Inserisci lo scalare: ");
                scanf("%lf", &scalar);
                adds_vec(v1, scalar, res, dim);
                printf("Risultato dell'aggiunta dello scalare:\n");
                print_vec(res, dim);
                break;
            }

            case 4: { // Moltiplicazione per uno scalare
                printf("Inserisci %lu valori per il vettore:\n", (unsigned long)dim);
                scanf_vec(v1, dim);
                printf("Inserisci lo scalare: ");
                scanf("%lf", &scalar);
                muls_vec(v1, scalar, res, dim);
                printf("Risultato della moltiplicazione per lo scalare:\n");
                print_vec(res, dim);
                break;
            }

            case 5: { // Prodotto scalare
                printf("Inserisci %lu valori per il primo vettore:\n", (unsigned long)dim);
                scanf_vec(v1, dim);
                printf("Inserisci %lu valori per il secondo vettore:\n", (unsigned long)dim);
                scanf_vec(v2, dim);
                printf("Prodotto scalare: %.2f\n", dot_vec(v1, v2, dim));
                break;
            }

            case 6: { // Concatenazione
                printf("Inserisci %lu valori per il primo vettore:\n", (unsigned long)dim);
                scanf_vec(v1, dim);
                printf("Inserisci %lu valori per il secondo vettore:\n", (unsigned long)dim);
                scanf_vec(v2, dim);
                double concat_res[2 * dim];
                concat_vec(v1, dim, v2, dim, concat_res);
                printf("Risultato della concatenazione:\n");
                print_vec(concat_res, 2 * dim);
                break;
            }

            case 7: { // Inversione
                printf("Inserisci %lu valori per il vettore:\n", (unsigned long)dim);
                scanf_vec(v1, dim);
                reverse_vec(v1, dim);
                printf("Vettore invertito:\n");
                print_vec(v1, dim);
                break;
            }

            case 8: { // Ordinamento
                printf("Inserisci %lu valori per il vettore:\n", (unsigned long)dim);
                scanf_vec(v1, dim);
                sort_vec(v1, dim);
                printf("Vettore ordinato:\n");
                print_vec(v1, dim);
                break;
            }

            case 9: { // Mescolamento
                printf("Inserisci %lu valori per il vettore:\n", (unsigned long)dim);
                scanf_vec(v1, dim);
                shuffle_vec(v1, dim);
                printf("Vettore mescolato:\n");
                print_vec(v1, dim);
                break;
            }

            case 10: { // Shift a destra
                printf("Inserisci %lu valori per il vettore:\n", (unsigned long)dim);
                scanf_vec(v1, dim);
                printf("Inserisci il numero di passi: ");
                scanf("%lu", (unsigned long *)&scalar);
                rshft_vec(v1, scalar, dim);
                printf("Vettore dopo lo shift a destra:\n");
                print_vec(v1, dim);
                break;
            }

            case 11: { // Shift a sinistra
                printf("Inserisci %lu valori per il vettore:\n", (unsigned long)dim);
                scanf_vec(v1, dim);
                printf("Inserisci il numero di passi: ");
                scanf("%lu", (unsigned long *)&scalar);
                lshft_vec(v1, scalar, dim);
                printf("Vettore dopo lo shift a sinistra:\n");
                print_vec(v1, dim);
                break;
            }

            case 12: { // Rotazione a destra
                printf("Inserisci %lu valori per il vettore:\n", (unsigned long)dim);
                scanf_vec(v1, dim);
                printf("Inserisci il numero di passi: ");
                scanf("%lu", (unsigned long *)&scalar);
                rrot_vec(v1, scalar, dim);
                printf("Vettore dopo la rotazione a destra:\n");
                print_vec(v1, dim);
                break;
            }

            case 13: { // Rotazione a sinistra
                printf("Inserisci %lu valori per il vettore:\n", (unsigned long)dim);
                scanf_vec(v1, dim);
                printf("Inserisci il numero di passi: ");
                scanf("%lu", (unsigned long *)&scalar);
                lrot_vec(v1, scalar, dim);
                printf("Vettore dopo la rotazione a sinistra:\n");
                print_vec(v1, dim);
                break;
            }

            case 14: { // Slice
                printf("Inserisci %lu valori per il vettore:\n", (unsigned long)dim);
                scanf_vec(v1, dim);
                int start, n;
                printf("Inserisci l'indice di inizio e il numero di elementi: ");
                scanf("%d %d", &start, &n);
                double slice_res[n];
                slice_vec(v1, slice_res, start, n);
                printf("Risultato dello slice:\n");
                print_vec(slice_res, n);
                break;
            }

            case 15: { // Norma
                printf("Inserisci %lu valori per il vettore:\n", (unsigned long)dim);
                scanf_vec(v1, dim);
                printf("Norma del vettore: %.2f\n", norm_vec(v1, dim));
                break;
            }

            case 16: { // Media
                printf("Inserisci %lu valori per il vettore:\n", (unsigned long)dim);
                scanf_vec(v1, dim);
                printf("Media degli elementi: %.2f\n", mean_vec(v1, dim));
                break;
            }

            case 17: { // Minimo
                printf("Inserisci %lu valori per il vettore:\n", (unsigned long)dim);
                scanf_vec(v1, dim);
                printf("Valore minimo: %.2f\n", min_vec(v1, dim));
                break;
            }

            case 18: { // Massimo
                printf("Inserisci %lu valori per il vettore:\n", (unsigned long)dim);
                scanf_vec(v1, dim);
                printf("Valore massimo: %.2f\n", max_vec(v1, dim));
                break;
            }

            case 19: { // Somma degli elementi
                printf("Inserisci %lu valori per il vettore:\n", (unsigned long)dim);
                scanf_vec(v1, dim);
                printf("Somma degli elementi: %.2f\n", sum_vec(v1, dim));
                break;
            }

            case 20: { // Confronto con tolleranza
                printf("Inserisci %lu valori per il primo vettore:\n", (unsigned long)dim);
                scanf_vec(v1, dim);
                printf("Inserisci %lu valori per il secondo vettore:\n", (unsigned long)dim);
                scanf_vec(v2, dim);
                printf("Inserisci la tolleranza: ");
                scanf("%lf", &tol);
                if (eq_vec(v1, v2, dim, tol)) {
                    printf("I vettori sono uguali entro la tolleranza.\n");
                } else {
                    printf("I vettori non sono uguali entro la tolleranza.\n");
                }
                break;
            }

            case 21: { // Applicazione di una funzione
                printf("Inserisci %lu valori per il vettore:\n", (unsigned long)dim);
                scanf_vec(v1, dim);
                map_vec(v1, dim, increment);
                printf("Vettore dopo l'incremento di uno:\n");
                print_vec(v1, dim);
                break;
            }

            case 0: // Esci
                printf("Uscita dalla calcolatrice.\n");
                break;

            default:
                printf("Opzione non valida. Riprova.\n");
        }
    } while (choice != 0);

    return 0;
}
