# $OpenBSD: Makefile,v 1.7 2017/07/27 11:01:33 sthen Exp $

COMMENT =	GNUstep client framework for salesforce.com

VERSION =	0.9
REVISION =	2
DISTNAME =	DataBasinKit-${VERSION}
SHARED_LIBS +=  DataBasinKit	0.1

HOMEPAGE =	http://gap.nongnu.org/databasin/
MASTER_SITES =	${MASTER_SITE_SAVANNAH:=gap/}

# LGPLv2 or later

MODULES =			x11/gnustep
MODGNUSTEP_IS_FRAMEWORK = 	Yes
WANTLIB +=			pthread
BUILD_DEPENDS +=		x11/gnustep/gui \
				x11/gnustep/webservices

MAKE_FLAGS +=	DataBasinKit_INTERFACE_VERSION=${LIBDataBasinKit_VERSION}

SUBST_VARS +=	VERSION

.include <bsd.port.mk>
