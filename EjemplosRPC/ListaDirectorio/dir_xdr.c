/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "dir.h"

bool_t
xdr_nametype (XDR *xdrs, nametype *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, objp, MAXL))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_namelist (XDR *xdrs, namelist *objp)
{
	register int32_t *buf;

	 if (!xdr_pointer (xdrs, (char **)objp, sizeof (struct namenode), (xdrproc_t) xdr_namenode))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_namenode (XDR *xdrs, namenode *objp)
{
	register int32_t *buf;

	 if (!xdr_nametype (xdrs, &objp->name))
		 return FALSE;
	 if (!xdr_namelist (xdrs, &objp->next))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_readdir_res (XDR *xdrs, readdir_res *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->errno))
		 return FALSE;
	switch (objp->errno) {
	case 0:
		 if (!xdr_namelist (xdrs, &objp->readdir_res_u.list))
			 return FALSE;
		break;
	default:
		break;
	}
	return TRUE;
}
