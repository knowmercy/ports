# $OpenBSD: Makefile,v 1.1.1.1 2017/10/20 15:49:14 bcallah Exp $

ONLY_FOR_ARCHS =	amd64 i386

COMMENT =	gather and display CPU architecture information
DISTNAME =	lscpu-${GH_TAGNAME}
CATEGORIES =	sysutils

GH_ACCOUNT =	NanXiao
GH_PROJECT =	lscpu
GH_TAGNAME =	1.0.0

MAINTAINER =	Brian Callahan <bcallah@openbsd.org>

# BSD
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB += c

NO_TEST =	Yes

# hardcoded optimizations removed after this release
pre-configure:
	sed -i 's,-O2,${CFLAGS},g' ${WRKSRC}/Makefile

# install target added after this release
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lscpu ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lscpu.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
