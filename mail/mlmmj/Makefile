# $OpenBSD: Makefile,v 1.18 2016/04/09 20:14:48 naddy Exp $

COMMENT=	mailing list manager

DISTNAME=	mlmmj-1.2.19.0
CATEGORIES=    	mail

HOMEPAGE=	http://mlmmj.org/

# MIT
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += c iconv

MASTER_SITES=	http://mlmmj.org/releases/

LIB_DEPENDS=	converters/libiconv

CONFIGURE_STYLE=gnu
CONFIGURE_ARGS+=--enable-receive-strip=yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -liconv"

DOCS=	README* TUNABLES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mlmmj
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${PREFIX}/share/doc/mlmmj
	cd ${WRKSRC} && ${INSTALL_DATA} contrib/receivestrip/README \
		${PREFIX}/share/doc/mlmmj/README.receive-strip

.include <bsd.port.mk>
