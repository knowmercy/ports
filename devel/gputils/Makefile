# $OpenBSD: Makefile,v 1.14 2017/01/05 13:50:13 benoit Exp $

COMMENT =		GNU PIC assembler and utilities

VERSION =		1.5.0
DISTNAME =		gputils-${VERSION}
CATEGORIES =		devel

HOMEPAGE =		http://gputils.sourceforge.net/

MAINTAINER =		Benoit Lecocq <benoit@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB =		c

MASTER_SITES =		${MASTER_SITE_SOURCEFORGE:=gputils/}
MASTER_SITES0 =		http://www.arcane-labs.net/download/OpenBSD/

DISTFILES =		${DISTNAME}${EXTRACT_SUFX} gputils-testsuite-${VERSION}${EXTRACT_SUFX}:0
DIST_SUBDIR =		gputils

CONFIGURE_STYLE =	autoconf
CONFIGURE_ENV =		"CC=${CC}" "CPP=${CPP}" "CFLAGS=${CFLAGS}" "CPPFLAGS=${CPPFLAGS}" "LDFLAGS=${LDFLAGS}"
CONFIGURE_ARGS +=	--disable-html-doc

USE_GMAKE =		Yes

AUTOCONF_VERSION =	2.69

do-test: fake
	cd ${WRKSRC}/gpasm/testsuite && sh ./test all


DOCFILES =	gputils.lyx gputils.pdf gputils.ps

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gputils
.for FILE in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/doc/${FILE} ${PREFIX}/share/doc/gputils
.endfor

.include <bsd.port.mk>
