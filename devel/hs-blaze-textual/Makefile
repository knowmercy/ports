# $OpenBSD: Makefile,v 1.10 2017/11/07 22:02:56 kili Exp $

COMMENT =		fast rendering of common datatypes

DISTNAME =		blaze-textual-0.2.0.8
REVISION =		4
CATEGORIES =		devel

# BSD3
PERMIT_PACKAGE_CDROM =	Yes

MODULES =		lang/ghc

MODGHC_BUILD =		cabal hackage haddock register

MODGHC_PACKAGE_KEY =	GBpTjxtAI31FC7u8S3WLvX

RUN_DEPENDS =		devel/hs-blaze-builder>=0.2.1.4 \
			devel/hs-old-locale \
			devel/hs-text>=0.11.0.2 \
			devel/hs-vector
BUILD_DEPENDS =		${RUN_DEPENDS}

.include <bsd.port.mk>
