# $OpenBSD: Makefile,v 1.18 2017/05/08 09:55:26 schwarze Exp $

COMMENT=		tightly integrated, free office package

VERSION=		3.6.1
DISTNAME=		siag-${VERSION}
REVISION=		5
CATEGORIES=		productivity x11

HOMEPAGE=		http://siag.nu/

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += ICE Mowitz SM X11 Xext Xmu Xpm Xt c m ncurses neXtaw
WANTLIB += termcap

MASTER_SITES=		${HOMEPAGE}/pub/siag/

LIB_DEPENDS=		x11/mowitz \
			x11/neXtaw

CONFIGURE_STYLE=	gnu

CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/siag/

CONFIGURE_ENV+=		LDFLAGS="-L${WRKBUILD}/common -L${LOCALBASE}/lib" \
			CPPFLAGS="-I${LOCALBASE}/include"

.include <bsd.port.mk>
