# $OpenBSD: Makefile,v 1.8 2017/06/08 16:03:04 czarkoff Exp $

COMMENT =		losslessly convert images to PDF
MODPY_EGG_VERSION =	0.2.4
DISTNAME =		img2pdf-${MODPY_EGG_VERSION}
CATEGORIES =		graphics
HOMEPAGE =		https://gitlab.mister-muffin.de/josch/img2pdf/

MAINTAINER =		Dmitrij D. Czarkoff <czarkoff@openbsd.org>

# LGPLv3
PERMIT_PACKAGE_CDROM =	Yes

MODULES =		lang/python
MODPY_VERSION =		${MODPY_DEFAULT_VERSION_3}
MODPY_SETUPTOOLS =	Yes
MODPY_PI =		Yes

RUN_DEPENDS =		graphics/py-Pillow${MODPY_FLAVOR}
TEST_DEPENDS =		graphics/py-Pillow${MODPY_FLAVOR}

.include <bsd.port.mk>
