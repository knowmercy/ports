# $OpenBSD: Makefile,v 1.29 2017/07/14 16:11:14 ajacoutot Exp $

COMMENT=		CUPS bindings for Python

MODPY_EGG_VERSION=	1.9.73
DISTNAME=		pycups-${MODPY_EGG_VERSION}
PKGNAME=		${DISTNAME:S/^py/py-/}
EXTRACT_SUFX=		.tar.bz2

CATEGORIES=		print

HOMEPAGE=		http://cyberelk.net/tim/software/pycups/

MAINTAINER=		Antoine Jacoutot <ajacoutot@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += cups iconv pthread ${MODPY_WANTLIB}

MASTER_SITES=		http://cyberelk.net/tim/data/pycups/

MODULES=		lang/python

FLAVORS=		python3
FLAVOR?=

LIB_DEPENDS=		print/cups,-libs \
			${MODPY_LIB_DEPENDS}

CFLAGS=			-I${LOCALBASE}/include -DVERSION=\"${MODPY_EGG_VERSION}\"
LDFLAGS=		-L${LOCALBASE}/lib
MAKE_ENV=		PYTHON="${MODPY_BIN}"

NO_TEST=		Yes

.include <bsd.port.mk>
