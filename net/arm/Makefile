# $OpenBSD: Makefile,v 1.6 2016/12/02 13:27:12 jca Exp $

COMMENT =		terminal status monitor for Tor

V =			1.4.5.0
DISTNAME =		arm-${V}
REVISION =		3

SUBST_VARS +=		V

CATEGORIES =		net

HOMEPAGE =		http://www.atagar.com/arm/

MAINTAINER =		Pascal Stumpf <pascal@stumpf.co>

# GPLv3
PERMIT_PACKAGE_CDROM =	Yes

MASTER_SITES =		http://archive.torproject.org/arm/
EXTRACT_SUFX =		.tar.bz2

MODULES =		lang/python
RUN_DEPENDS =		net/tor \
			devel/desktop-file-utils

NO_TEST =		Yes

WRKDIST =		${WRKDIR}/arm

MODPY_ADJ_FILES =	src/starter.py src/test.py \
	src/resources/torrcOverride/override.py
.for i in ScanSupport.py TorCtl.py StatsSupport.py PathSupport.py \
	GeoIPSupport.py SQLSupport.py TorUtil.py
MODPY_ADJ_FILES += src/TorCtl/${i}
.endfor

pre-configure:
	${SUBST_CMD} ${WRKSRC}/setup.py ${WRKSRC}/arm ${WRKSRC}/install \
		${WRKSRC}/src/resources/arm.1

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/applications
	${INSTALL_DATA_DIR} ${PREFIX}/share/pixmaps
	cd ${PREFIX}/share/applications && ln -s \
		../arm/resources/tor-arm.desktop .
	cd ${PREFIX}/share/pixmaps && ln -s ../arm/resources/tor-arm.svg .

.include <bsd.port.mk>
