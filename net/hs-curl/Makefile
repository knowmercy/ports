# $OpenBSD: Makefile,v 1.9 2017/11/07 22:37:15 kili Exp $

COMMENT =		Haskell binding to libcurl

DISTNAME =		curl-1.3.8
REVISION =		6
CATEGORIES =		net

HOMEPAGE =		https://github.com/GaloisInc/curl

MAINTAINER =		David Schaefer <dawedawe@gmx.de>

# BSD3
PERMIT_PACKAGE_CDROM =	Yes

MODULES =		lang/ghc

MODGHC_BUILD =		cabal hackage haddock register

MODGHC_PACKAGE_KEY =	CYMsKVICG8A995d32iL7dH

BUILD_DEPENDS =		${RUN_DEPENDS}
RUN_DEPENDS =		net/curl

.include <bsd.port.mk>
