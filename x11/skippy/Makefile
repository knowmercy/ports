# $OpenBSD: Makefile,v 1.19 2017/10/23 17:11:06 sthen Exp $

COMMENT=		full-screen X11 task-switcher like Apple's Expose

DISTNAME=		skippy-0.5.0
REVISION=		7
CATEGORIES=		x11

MASTER_SITES=		http://thegraveyard.org/files/
EXTRACT_SUFX=		.tar.bz2

HOMEPAGE=		http://thegraveyard.org/skippy.php

# X11
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB=	X11 Xau Xdmcp Xext Xft Xinerama Xrender c expat fontconfig \
		freetype m z xcb Imlib2


NO_TEST=		Yes

LIB_DEPENDS=		graphics/imlib2

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/skippy
	${INSTALL_DATA} ${WRKSRC}/skippyrc-default \
	    ${PREFIX}/share/examples/skippy

.include <bsd.port.mk>
