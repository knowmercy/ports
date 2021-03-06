# $OpenBSD: Makefile,v 1.52 2017/10/24 12:17:45 juanfra Exp $

COMMENT =		secure webserver
DISTNAME =		hiawatha-10.7
REVISION =		1
CATEGORIES =		www net

HOMEPAGE =		https://www.hiawatha-webserver.org/

MAINTAINER =		Juan Francisco Cantero Hurtado <juanfra@openbsd.org>

# GPLv2 only
PERMIT_PACKAGE_CDROM =	Yes

MASTER_SITES =		${HOMEPAGE}files/

MODULES =		devel/cmake

WANTLIB += c mbedcrypto mbedtls mbedx509 pthread xml2 xslt z

LIB_DEPENDS =		security/polarssl>=2.2.1p0 \
			textproc/libxslt

CONFIGURE_ARGS =	-DWEBROOT_DIR="/var/hiawatha" \
			-DWORK_DIR="/var/db/hiawatha" \
			-DCONFIG_DIR="${SYSCONFDIR}/hiawatha" \
			-DLOG_DIR="/var/log/hiawatha" \
			-DCMAKE_INSTALL_MANDIR="${PREFIX}/man" \
			-DENABLE_XSLT=ON \
			-DPID_DIR="/var/run" \
			-DUSE_SYSTEM_MBEDTLS=ON

CONFIGURE_ENV =		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

NO_TEST =		Yes

pre-configure:
	${SUBST_CMD} ${WRKSRC}/config/hiawatha.conf.in \
		${WRKSRC}/config/cgi-wrapper.conf \
		${WRKSRC}/man/hiawatha.1.in

post-install:
	mv ${WRKINST}${SYSCONFDIR}/hiawatha ${PREFIX}/share/examples/hiawatha
	mv ${WRKINST}/var/hiawatha/index.html ${PREFIX}/share/examples/hiawatha/
	rm -r ${WRKINST}/var

.include <bsd.port.mk>
