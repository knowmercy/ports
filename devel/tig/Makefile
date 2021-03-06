# $OpenBSD: Makefile,v 1.24 2017/10/05 20:10:12 fcambus Exp $

COMMENT =	ncurses Git repository browser

V =		2.3.0
DISTNAME =	tig-$V

CATEGORIES =	devel

HOMEPAGE =	https://jonas.github.io/tig/

MAINTAINER =	Frederic Cambus <fcambus@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB =	c iconv ncursesw

MASTER_SITES =	https://github.com/jonas/tig/releases/download/tig-$V/

BUILD_DEPENDS =	textproc/asciidoc \
		textproc/xmlto

RUN_DEPENDS =	devel/git

LIB_DEPENDS =	converters/libiconv

USE_GMAKE =	Yes
ALL_TARGET =	all doc-man doc-html

CONFIGURE_STYLE = gnu
CONFIGURE_ARGS += --with-libiconv=${LOCALBASE} DOCBOOK2PDF=false

FAKE_FLAGS =	sysconfdir=${PREFIX}/share/examples/tig

NO_TEST =	Yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tig
	${INSTALL_DATA} ${WRKSRC}/doc/manual.html ${PREFIX}/share/doc/tig
	${INSTALL_MAN} ${WRKSRC}/doc/tig.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/tigrc.5 ${PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/doc/tigmanual.7 ${PREFIX}/man/man7

.include <bsd.port.mk>
