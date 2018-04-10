/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "DNS.h"

/******************************************************************************/

void dns_1_1 (char *host, char opcion, char *param[]) {
	CLIENT *clnt;
	char	 *resultado;

	#ifndef	DEBUG
		clnt = clnt_create (host, DNS_1, DNSV1, "udp");
		if (clnt == NULL) {
			clnt_pcreateerror (host);
			exit (1);
		}
	#endif	/* DEBUG */

	switch (opcion) {
		case '1':
			resultado = *dns_1_buscar_1(param[0], clnt);
			break;
		case '2':
			resultado = *dns_1_registrar_1(param[0], param[1], clnt);
			break;
		case '3':
			resultado = *dns_1_borrar_1(param[0], clnt);
			break;
	}

	if (resultado == (char *) NULL)
		clnt_perror (clnt, "call failed");
	else
		printf("\nDNS_1: %s\n", resultado);

	#ifndef	DEBUG
		clnt_destroy (clnt);
	#endif	 /* DEBUG */
}

/******************************************************************************/

// void init(){
// 	char *twitter[2]	= {"twitter.com",	"104.244.42.129"	};
// 	char *youtube[2]	= {"youtube.com",	"172.217.9.238"		};
// 	char *google[2] 	= {"google.com",	"172.217.3.110"		};
// 	char *facebook[2] = {"facebook.com","31.13.67.35"			};
// 	char *ugr[2] 			= {"ugr.es",			"150.214.204.231"	};
//
// 	dns_1 ("localhost", '2', twitter);
// 	dns_1 ("localhost", '2', youtube);
// 	dns_1 ("localhost", '2', google);
// 	dns_1 ("localhost", '2', facebook);
// 	dns_1 ("localhost", '2', ugr);
// }

/******************************************************************************/

int main (int argc, char *argv[]) {

	// Declaración de variables
	char *host;
	char opcion;
	char *parametros[1];

	// Asignación de memoria
	parametros[0] = (char *) malloc(50);
	parametros[1] = (char *) malloc(50);

	// Comporbación de atributos
	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}

	// init();

	host = argv[1];

	// Despliegue de menú
	printf("\nLista de Operaciones:"
						"\n\tO: salir"
						"\n\t1: buscar"
						"\n\t2: registrar"
						"\n\t3: borrar");

	// Entrada y gestión de datos del menú.
	do {
		printf("\nOpción: ");
		scanf (" %c", &opcion);

		switch (opcion) {
			case '1':		// Buscar
			case '3':		// Borrar
				printf("\nIntroduce nombre de dominio: ");
				scanf("%s", parametros[0]);
				break;
			case '2':		// Registrar
				printf("\nIntroduce nombre de dominio e IP: ");
				scanf("%s %s", parametros[0], parametros[1]);
				break;
		}

		if ( (opcion == '1') || (opcion == '2') || (opcion == '3') )
			dns_1_1 (host, opcion, parametros);
	} while ( opcion != '0' );

	exit (0);
}
