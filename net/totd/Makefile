# $OpenBSD: Makefile,v 1.28 2014/08/10 10:20:34 espie Exp $

COMMENT=	DNS proxy that supports IPv6 <==> IPv4 record translation

DISTNAME=	totd-1.5.1
REVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://www.dillema.net/software/totd/

HOMEPAGE=	http://www.dillema.net/software/totd.html

# BSD/ISC (built-in webserver is LGPL but we don't compile it in)
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB=		c

CONFIGURE_STYLE=	gnu
CONFIGURE_ARGS +=	--enable-stf

NO_TEST=		Yes

MAKE_FLAGS=		CC="${CC}" SYSCONFDIR="${SYSCONFDIR}" INSTALL=install

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/totd
	${INSTALL_DATA} ${FILESDIR}/totd.conf.sample ${PREFIX}/share/totd

.include <bsd.port.mk>
