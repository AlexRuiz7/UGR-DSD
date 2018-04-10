/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _DNS_H_RPCGEN
#define _DNS_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct registrar_1_argument {
	char *nombre;
	char *ip;
};
typedef struct registrar_1_argument registrar_1_argument;

#define DNS 0x20000001
#define DNSV1 1

#if defined(__STDC__) || defined(__cplusplus)
#define buscar 1
extern  char ** buscar_1(char *, CLIENT *);
extern  char ** buscar_1_svc(char *, struct svc_req *);
#define registrar 2
extern  char ** registrar_1(char *, char *, CLIENT *);
extern  char ** registrar_1_svc(char *, char *, struct svc_req *);
#define borrar 3
extern  char ** borrar_1(char *, CLIENT *);
extern  char ** borrar_1_svc(char *, struct svc_req *);
extern int dns_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define buscar 1
extern  char ** buscar_1();
extern  char ** buscar_1_svc();
#define registrar 2
extern  char ** registrar_1();
extern  char ** registrar_1_svc();
#define borrar 3
extern  char ** borrar_1();
extern  char ** borrar_1_svc();
extern int dns_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_registrar_1_argument (XDR *, registrar_1_argument*);

#else /* K&R C */
extern bool_t xdr_registrar_1_argument ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_DNS_H_RPCGEN */
