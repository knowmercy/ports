# $OpenBSD: Makefile,v 1.33 2017/11/09 17:38:51 ajacoutot Exp $

COMMENT =		utilities for manipulating XML documents

DISTNAME =		HaXml-1.25.4
CATEGORIES =		textproc
HOMEPAGE =		http://projects.haskell.org/HaXml/
REVISION =		0

MAINTAINER =		David Coppa <dcoppa@openbsd.org>

WANTLIB =		c iconv m pthread util

# GPLv2 / LGPLv2.1
PERMIT_PACKAGE_CDROM =	Yes

MODULES =		lang/ghc

MODGHC_BUILD =		cabal hackage haddock register

MODGHC_PACKAGE_KEY =	B9wvDmvOZoF7ZEYuCxncwg

LIB_DEPENDS +=		converters/libiconv
RUN_DEPENDS +=		devel/hs-random \
			textproc/hs-polyparse>=1.10
BUILD_DEPENDS +=	${RUN_DEPENDS}

.include <bsd.port.mk>
